/*
 * FreeRTOS Kernel V10.4.1
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 * 1 tab == 4 spaces!
 */

/* Standard includes. */
#include <stdlib.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
//#include "Config_OSTM0.h"
//#include "Config_TAUJ0_0.h"
#include "r_cg_timer.h"

//#define configDATA_MODE 1


extern void vPortStart(void);
void portSAVE_CONTEXT(void);
void portRESTORE_CONTEXT(void);
void trap_set(void);

/* Critical nesting should be initialised to a non zero value so interrupts don't
accidentally get enabled before the scheduler is started. */
#define portINITIAL_CRITICAL_NESTING  (( StackType_t ) 10)

/* Initial PSW value allocated to a newly created task.
 *   1100011000000000
 *   ||||||||-------------- Fill byte
 *   |||||||--------------- Carry Flag cleared
 *   |||||----------------- In-service priority Flags set to low level
 *   ||||------------------ Register bank Select 0 Flag cleared : bit 3 : RBS0
 *   |||------------------- Auxiliary Carry Flag cleared
 *   ||-------------------- Register bank Select 1 Flag cleared : bit 5 : RBS1
 *   |--------------------- Zero Flag set
 *   ---------------------- Global Interrupt Flag set (enabled)

 Register bank select flags (RBS0, RBS1)
 These are 2-bit flags to select one of the four register banks.
 In these flags, the 2-bit information that indicates the register bank selected by SEL RBn instruction execution is
 stored.

 */
#define portPSW		  ( 0xc6UL )  //0b11000110

/* We require the address of the pxCurrentTCB variable, but don't want to know
any details of its type. */
typedef void TCB_t;
extern volatile TCB_t * volatile pxCurrentTCB;

/* Keeps track of the nesting level of critical sections. */
volatile StackType_t usCriticalNesting = portINITIAL_CRITICAL_NESTING;
/*-----------------------------------------------------------*/

/* Sets up the timer to generate the tick interrupt. */
static void prvSetupTimerInterrupt( void );

static void prvTaskExitError( void )
{
    /* A function that implements a task must not exit or attempt to return to
    its caller as there is nothing to return to.  If a task wants to exit it
    should instead call vTaskDelete( NULL ).

    Artificially force an assert() to be triggered if configASSERT() is
    defined, then stop here so application writers can catch the error. */
    configASSERT( usCriticalNesting == ~0U );
    portDISABLE_INTERRUPTS();
    for( ;; );
}

/*-----------------------------------------------------------*/
StackType_t * pxPortInitialiseStack(StackType_t * pxTopOfStack, TaskFunction_t pxCode, void * pvParameters)
{
uint32_t *pulLocal;

	/* With large code and large data sizeof( StackType_t ) == 2, and
	sizeof( StackType_t * ) == 4.  With small code and small data
	sizeof( StackType_t ) == 2 and sizeof( StackType_t * ) == 2. */

    #if __RL78_MEDIUM__ == 1
	{
		/* Parameters are passed in on the stack, and written using a 32-bit value
		hence a space is left for the second two bytes. */
		pxTopOfStack--;

		/* Write in the parameter value. */
		pulLocal =  ( uint32_t * ) pxTopOfStack;
		*pulLocal = ( uint32_t ) pvParameters;
		pxTopOfStack--;

		/* The return address, leaving space for the first two bytes of	the
		32-bit value.  See the comments above the prvTaskExitError() prototype
		at the top of this file. */
		pxTopOfStack--;
		pulLocal = ( uint32_t * ) pxTopOfStack;
		*pulLocal = ( uint32_t ) prvTaskExitError;
		pxTopOfStack--;

		/* The start address / PSW value is also written in as a 32-bit value,
		so leave a space for the second two bytes. */
		pxTopOfStack--;

		/* Task function start address combined with the PSW. */
		pulLocal = ( uint32_t * ) pxTopOfStack;
		*pulLocal = ( ( ( uint32_t ) pxCode ) | ( portPSW << 24UL ) );
		pxTopOfStack--;

		/* An initial value for the AX register. */
		*pxTopOfStack = ( StackType_t ) 0x1111;
		pxTopOfStack--;
	}
	#else
	{
		/* The return address, leaving space for the first two bytes of	the
		32-bit value.  See the comments above the prvTaskExitError() prototype
		at the top of this file. */
		pxTopOfStack--;
		pulLocal = ( uint32_t * ) pxTopOfStack;
		*pulLocal = ( uint32_t ) prvTaskExitError;
		pxTopOfStack--;

		/* Task function.  Again as it is written as a 32-bit value a space is
		left on the stack for the second two bytes. */
		pxTopOfStack--;

		/* Task function start address combined with the PSW. */
		pulLocal = ( uint32_t * ) pxTopOfStack;
		*pulLocal = ( ( ( uint32_t ) pxCode ) | ( portPSW << 24UL ) );
		pxTopOfStack--;

		/* The parameter is passed in AX. */
		*pxTopOfStack = ( StackType_t ) pvParameters;
		pxTopOfStack--;
	}
	#endif

	/* An initial value for the HL register. */
	*pxTopOfStack = ( StackType_t ) 0x2222;
	pxTopOfStack--;

	/* CS and ES registers. */
	*pxTopOfStack = ( StackType_t ) 0x0F00;
	pxTopOfStack--;

	/* The remaining general purpose registers DE and BC */
	*pxTopOfStack = ( StackType_t ) 0xDEDE;
	pxTopOfStack--;
	*pxTopOfStack = ( StackType_t ) 0xBCBC;
	pxTopOfStack--;

    /* The other two register banks...
       register bank 3 : is dedicated for use by interrupts so is not saved as part of the task context. */
    pxTopOfStack -= 8;

	/* Finally the critical section nesting count is set to zero when the task
	first starts. */
	*pxTopOfStack = ( StackType_t ) portNO_CRITICAL_SECTION_NESTING;

    /*
     * Return a pointer to the top of the stack we have generated so this can
     * be stored in the task control block for the task.
     */
    return pxTopOfStack;
}
/*-----------------------------------------------------------*/


BaseType_t xPortStartScheduler( void )
{
	/* Setup the hardware to generate the tick.  Interrupts are disabled when
	this function is called. */
	prvSetupTimerInterrupt();

	/* Restore the context of the first task that is going to run. */
	vPortStart();

	/* Should not get here as the tasks are now running! */
	return pdTRUE;
}
/*-----------------------------------------------------------*/

void vPortEndScheduler( void )
{
	/* It is unlikely that the V850ES/Fx3 port will get stopped.  If required simply
	disable the tick interrupt here. */
    //--> dineshR_Config_OSTM0_Stop();
    R_TAU0_Channel0_Stop();
}
/*-----------------------------------------------------------*/

/*
 * Hardware initialisation to generate the RTOS tick.  This uses
 */
static void prvSetupTimerInterrupt( void )
{
    DI();
    //--> dineshR_Config_OSTM0_Start();
    //R_Config_TAUJ0_0_Start();
    R_TAU0_Channel0_Start();
}
/*-----------------------------------------------------------*/


//===============================================================


