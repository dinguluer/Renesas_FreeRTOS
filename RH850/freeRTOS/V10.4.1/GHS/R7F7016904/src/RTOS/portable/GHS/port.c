/*
    FreeRTOS V9.0.0 - Copyright (C) 2016 Real Time Engineers Ltd.
    All rights reserved

    VISIT http://www.FreeRTOS.org TO ENSURE YOU ARE USING THE LATEST VERSION.

    This file is part of the FreeRTOS distribution.

    FreeRTOS is free software; you can redistribute it and/or modify it under
    the terms of the GNU General Public License (version 2) as published by the
    Free Software Foundation >>>> AND MODIFIED BY <<<< the FreeRTOS exception.

 ***************************************************************************
    >>!   NOTE: The modification to the GPL is included to allow you to     !<<
    >>!   distribute a combined work that includes FreeRTOS without being   !<<
    >>!   obliged to provide the source code for proprietary components     !<<
    >>!   outside of the FreeRTOS kernel.                                   !<<
 ***************************************************************************

    FreeRTOS is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE.  Full license text is available on the following
    link: http://www.freertos.org/a00114.html

 ***************************************************************************
 *                                                                       *
 *    FreeRTOS provides completely free yet professionally developed,    *
 *    robust, strictly quality controlled, supported, and cross          *
 *    platform software that is more than just the market leader, it     *
 *    is the industry's de facto standard.                               *
 *                                                                       *
 *    Help yourself get started quickly while simultaneously helping     *
 *    to support the FreeRTOS project by purchasing a FreeRTOS           *
 *    tutorial book, reference manual, or both:                          *
 *    http://www.FreeRTOS.org/Documentation                              *
 *                                                                       *
 ***************************************************************************

    http://www.FreeRTOS.org/FAQHelp.html - Having a problem?  Start by reading
    the FAQ page "My application does not run, what could be wrong?".  Have you
    defined configASSERT()?

    http://www.FreeRTOS.org/support - In return for receiving this top quality
    embedded software for free we request you assist our global community by
    participating in the support forum.

    http://www.FreeRTOS.org/training - Investing in training allows your team to
    be as productive as possible as early as possible.  Now you can receive
    FreeRTOS training directly from Richard Barry, CEO of Real Time Engineers
    Ltd, and the world's leading authority on the world's leading RTOS.

    http://www.FreeRTOS.org/plus - A selection of FreeRTOS ecosystem products,
    including FreeRTOS+Trace - an indispensable productivity tool, a DOS
    compatible FAT file system, and our tiny thread aware UDP/IP stack.

    http://www.FreeRTOS.org/labs - Where new FreeRTOS products go to incubate.
    Come and try FreeRTOS+TCP, our new open source TCP/IP stack for FreeRTOS.

    http://www.OpenRTOS.com - Real Time Engineers ltd. license FreeRTOS to High
    Integrity Systems ltd. to sell under the OpenRTOS brand.  Low cost OpenRTOS
    licenses offer ticketed support, indemnification and commercial middleware.

    http://www.SafeRTOS.com - High Integrity Systems also provide a safety
    engineered and independently SIL3 certified version for use in safety and
    mission critical applications that require provable dependability.

    1 tab == 4 spaces!
 */

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
//#include "FreeRTOS.h"
//#include "task.h"
#include "Config_OSTM0.h"
/* Critical nesting should be initialised to a non zero value so interrupts don't
   accidentally get enabled before the scheduler is started. */
#define portINITIAL_CRITICAL_NESTING    (( StackType_t )10)

/* The PSW value assigned to tasks when they start to run for the first time. */
#define portPSW                         (( StackType_t )0x00000000)

#define OSTM0CMP                        *((volatile uint32 *)0xFFDD8000ul)
#define OSTM0TS                         *((volatile uint8 *)0xFFDD8014ul)
#define OSTM0TT                         *((volatile uint8 *)0xFFDD8018ul)
#define OSTM0CTL                        *((volatile uint8 *)0xFFDD8020ul)
#define INTOSTM0_CTL                    *((volatile uint16 *)0xFFFFB094ul)

/* We require the address of the pxCurrentTCB variable, but don't want to know
   any details of its type. */
typedef void TCB_t;
extern volatile TCB_t * volatile pxCurrentTCB;

/* Keeps track of the nesting level of critical sections. */
volatile StackType_t usCriticalNesting = portINITIAL_CRITICAL_NESTING;
/*-----------------------------------------------------------*/

/* Sets up the timer to generate the tick interrupt. */
static void prvSetupTimerInterrupt(void);

/*-----------------------------------------------------------*/
StackType_t * pxPortInitialiseStack(StackType_t * pxTopOfStack, TaskFunction_t pxCode, void * pvParameters)
{
    *pxTopOfStack = ( StackType_t )pxCode;               /* Task function start address */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t )pxCode;               /* Task function start address */
    pxTopOfStack--;
    *pxTopOfStack = portPSW;                                /* Initial PSW value */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t )0x20202020;           /* Initial Value of R20 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t )0x21212121;           /* Initial Value of R21 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t )0x22222222;           /* Initial Value of R22 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t )0x23232323;           /* Initial Value of R23 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t )0x24242424;           /* Initial Value of R24 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t )0x25252525;           /* Initial Value of R25 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t )0x26262626;           /* Initial Value of R26 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t )0x27272727;           /* Initial Value of R27 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t )0x28282828;           /* Initial Value of R28 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t )0x29292929;           /* Initial Value of R29 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t )0x30303030;           /* Initial Value of R30 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t )0x19191919;           /* Initial Value of R19 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t )0x18181818;           /* Initial Value of R18 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t )0x17171717;           /* Initial Value of R17 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t )0x16161616;           /* Initial Value of R16 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t )0x15151515;           /* Initial Value of R15 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t )0x14141414;           /* Initial Value of R14 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t )0x13131313;           /* Initial Value of R13 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t )0x12121212;           /* Initial Value of R12 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t )0x11111111;           /* Initial Value of R11 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t )0x10101010;           /* Initial Value of R10 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t )0x99999999;           /* Initial Value of R09 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t )0x88888888;           /* Initial Value of R08 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t )0x77777777;           /* Initial Value of R07 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t )pvParameters;           /* R6 is expected to hold the function parameter*/
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t )0x22222222;           /* Initial Value of R02 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t )0x11111111;          /* Initial Value of R01 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t )portNO_CRITICAL_SECTION_NESTING;

    /*
     * Return a pointer to the top of the stack we have generated so this can
     * be stored in the task control block for the task.
     */
    return pxTopOfStack;
}
/*-----------------------------------------------------------*/

BaseType_t xPortStartScheduler(void)
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


void vPortEndScheduler(void)
{
    /* It is unlikely that the RH850 port will get stopped.  If required simply
       disable the tick interrupt here. */

    /* returning stack/reg to state before RTOS begun not implemented */
    //INTOSTM0_CTL = 0;
    //OSTM0TT      = 1;
    R_Config_OSTM0_Stop();
}
/*-----------------------------------------------------------*/

/*
 * Hardware initialisation to generate the RTOS tick.
 */
static void prvSetupTimerInterrupt(void)
{
//    OSTM0TT = 1;                /* OSTM0 operation disable */

//    OSTM0CTL = 0x00;            /* OSTM0 interrupt disable and set to interval mode */

//    OSTM0CMP = (configCPU_CLOCK_HZ / configTICK_RATE_HZ);

//    INTOSTM0_CTL = 0x4F;        /*EI OSTM0 interrupt enable */

//    OSTM0TS = 1;                /* OSTM0 operation enable*/

//    __asm("ei");
    R_Config_OSTM0_Start();
}
/*-----------------------------------------------------------*/

/* Assembly MACRO */
asm void portSAVE_CONTEXT( void)
{
    prepare {r20,r21,r22,r23,r24,r25,r26,r27,r28,r29,r30},68,sp;     // save general purpose registers
    sst.w   r19,64[ep];                                                   // #if Using the Small/Large data model
    sst.w   r18,60[ep];
    sst.w   r17,56[ep];
    sst.w   r16,52[ep];
    sst.w   r15,48[ep];
    sst.w   r14,44[ep];
    sst.w   r13,40[ep];
    sst.w   r12,36[ep];
    sst.w   r11,32[ep];
    sst.w   r10,28[ep];
    sst.w   r9,24[ep];
    sst.w   r8,20[ep];
    sst.w   r7,16[ep];
    sst.w   r6,12[ep];
    sst.w   r2,8[ep];
    sst.w   r1,4[ep];
    MOVHI   hi(_usCriticalNesting),r0,r1;    // save usCriticalNesting value to stack
    ld.w    lo(_usCriticalNesting)[r1],r2;
    sst.w   r2,0[ep];
    MOVHI   hi(_pxCurrentTCB),r0,r1;         // save SP to top of current TCB
    ld.w    lo(_pxCurrentTCB)[r1],r2;
    st.w    sp,0[r2];
}

/* Assembly MACRO */
asm void portRESTORE_CONTEXT( void)
{
    MOVHI   hi(_pxCurrentTCB),r0,r1;         // get Stackpointer address
    ld.w    lo(_pxCurrentTCB)[r1],sp;
    MOV     sp,r1;
    ld.w    0[r1],sp;                        // load stackpointer
    MOV     sp,ep;                           // set stack pointer to element pointer
    sld.w   0[ep],r1;                        // load usCriticalNesting value from stack
    MOVHI   hi(_usCriticalNesting),r0,r2;
    st.w    r1,lo(_usCriticalNesting)[r2];
    sld.w   4[ep],r1;                        // restore general purpose registers
    sld.w   8[ep],r2;
    sld.w   12[ep],r6;
    sld.w   16[ep],r7;
    sld.w   20[ep],r8;
    sld.w   24[ep],r9;
    sld.w   28[ep],r10;
    sld.w   32[ep],r11;
    sld.w   36[ep],r12;
    sld.w   40[ep],r13;
    sld.w   44[ep],r14;
    sld.w   48[ep],r15;
    sld.w   52[ep],r16;
    sld.w   56[ep],r17;
    sld.w   60[ep],r18;
    sld.w   64[ep],r19;
    dispose 68,{r20,r21,r22,r23,r24,r25,r26,r27,r28,r29,r30};
}


/* Load context of the first task */
#pragma ghs noprologue
void vPortStart(void)
{
    portRESTORE_CONTEXT();                              // restore the context of whichever task the ...
    __asm__ __volatile__("ld.w    0[sp],lp  \n\t"
                         "ldsr    lp,5  \n\t"           //restore PSW
                         "DI  \n\t"
                         "ld.w    4[sp],lp  \n\t"       //restore LP
                         "ld.w    8[sp],lp  \n\t"       //restore LP
                         "ADD     0x0C,sp  \n\t"        //set SP to right position
                         "EI  \n\t"
                         "jmp             [lp] \n\t"
                         );

}


/* Switch between task of diffrent priority : using TRAP interrupt */
#pragma ghs noprologue
void vPortYield(void)
{
    __asm__ __volatile__("add     -0x0C,sp  \n\t"                        // prepare stack to save necessary values
                         "st.w    lp,8[sp]  \n\t"                       // store LP to stack
                         "stsr    0,r31  \n\t"
                         "st.w    lp,4[sp]  \n\t"                       // store EIPC to stack
                         "stsr    1,lp  \n\t"
                         "st.w    lp,0[sp]  \n\t"                       // store EIPSW to stack
                         );
                         portSAVE_CONTEXT();                        // save the context of the current task.
    __asm__ __volatile__("jarl    _vTaskSwitchContext,lp  \n\t"         // call the scheduler.
                         );
                         portRESTORE_CONTEXT();                     // Restore the context of whichever task the ...                                                                 // ... scheduler decided should run.
    __asm__ __volatile__("ld.w    0[sp],lp  \n\t"                       // restore EIPSW from stack
                         "ldsr    lp,1  \n\t"
                         "ld.w    4[sp],lp  \n\t"                       // restore EIPC from stack
                         "ldsr    lp,0  \n\t"
                         "ld.w    8[sp],lp  \n\t"                       // restore LP from stack
                         "add     0x0C,sp  \n\t"                        // set SP to right position
                         "EIRET \n\t"
                         );

}

#pragma ghs noprologue
void r_Config_OSTM0_interrupt(void)
{
    __asm__ __volatile__("add     -0x0C,sp  \n\t"                       // prepare stack to save necessary values
                         "st.w    lp,8[sp]  \n\t"                       // store LP to stack
                         "stsr    0,r31  \n\t"
                         "st.w    lp,4[sp]  \n\t"                       // store EIPC to stack (SR2,0)
                         "stsr    1,lp  \n\t"
                         "st.w    lp,0[sp]  \n\t"                       // store EIPSW to stack (SR3,0)
                         );
                         portSAVE_CONTEXT();                        // save the context of the current task.

    __asm__ __volatile__("jarl    _xTaskIncrementTick,lp  \n\t"         // call the timer tick function.
                         "jarl    _vTaskSwitchContext,lp  \n\t"         // call the scheduler.
                         );

                         portRESTORE_CONTEXT();                     // Restore the context of whichever task the ...
                                                                 // ... scheduler decided should run.
    __asm__ __volatile__("ld.w    0[sp],lp  \n\t"                       // restore EIPSW from stack(SR3,0)
                         "ldsr    lp,1  \n\t"
                         "ld.w    4[sp],lp  \n\t"                       // restore EIPC from stack(SR2,0)
                         "ldsr    lp,0  \n\t"
                         "ld.w    8[sp],lp  \n\t"                       // restore LP from stack
                         "add     0x0C,sp  \n\t"                        // set SP to right position
                         "EIRET \n\t"
                         );
}
