//============================================================================
// Includes
//============================================================================
#include "../tgt/device.h"
#include "typeDefine.h"
#include "clock/clock.h"
#include "Config_OSTM0/Config_OSTM0.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"
/* Start user code for include. Do not edit comment generated here */
#define RTOS_TIMING_10MS         100U

/* RTOS task handlers */
/* PRQA S 3218 5 #To support future software modification */
static TaskHandle_t LED_1_handle1 = NULL;
static TaskHandle_t LED_2_handle2          = NULL;
static TaskHandle_t LED_3_handle3          = NULL;

static void vLED_1_Task( void *pvParameters );
static void vLED_2_Task( void *pvParameters );
static void vLED_3_Task( void *pvParameters );
unsigned int testcount1 = 0;
unsigned int testcount2 = 0;
unsigned int testcount3 = 0;
unsigned int testcount[3];

//============================================================================
// Defines
//============================================================================



//============================================================================
// Prototypes
//============================================================================
int main( void );

//============================================================================
// Variables
//============================================================================
unsigned char TmrCounter;


/* Start user code for global. Do not edit comment generated here */
static void  vLED_1_Task(void *pvParameters)
{
    TickType_t xLastWakeTime;
    //const TickType_t xFrequency = 10;
    xLastWakeTime = xTaskGetTickCount ();
    for( ;; )
    {
        //vTaskDelay(1000/portTICK_RATE_MS);
        // Wait for the next cycle.
        //vTaskDelayUntil( &xLastWakeTime, xFrequency );
        vTaskDelayUntil(&xLastWakeTime, RTOS_TIMING_10MS);
        testcount1++;
        testcount[0]++;

        if(testcount1 == 2000)
        {
            testcount1 = 0;
            testcount[0] = 0;
        }

    }
    vTaskDelete( NULL );

}


static void  vLED_2_Task(void *pvParameters)
{
    TickType_t xLastWakeTime;
    //const TickType_t xFrequency = 10;
    xLastWakeTime = xTaskGetTickCount ();

    for( ;; )
    {
        //vTaskDelay(500/portTICK_RATE_MS);
        /* Wait until it is time to check all the other tasks again. */
        //vTaskDelayUntil( &xLastWakeTime, xFrequency );
        vTaskDelayUntil(&xLastWakeTime, RTOS_TIMING_10MS);

        testcount2++;
        testcount[1]++;
        //break;


        if(testcount2 == 2000)
        {
            testcount2 = 0;
            testcount[1] = 0;
        }
    }
    vTaskDelete( NULL );

}

static void  vLED_3_Task(void *pvParameters)
{
    TickType_t xLastWakeTime;
    //const TickType_t xFrequency = 10;
    xLastWakeTime = xTaskGetTickCount ();
    for( ;; )
    {
        //vTaskDelay(2000/portTICK_RATE_MS);
        /* Wait until it is time to check all the other tasks again. */
        //vTaskDelayUntil( &xLastWakeTime, xFrequency );
        vTaskDelayUntil(&xLastWakeTime, RTOS_TIMING_10MS);
        testcount3++;
        testcount[2]++;
        //break;


        if(testcount3 == 2000)
        {
            testcount3 = 0;
            testcount[2] = 0;
        }
    }
    vTaskDelete( NULL );

}


//============================================================================
// Interrupt Service Routines - ISR
//============================================================================

void delay(void)
{
    unsigned long i;
    //unsigned long j;
    for( i=0; i<0xFFFFu;i++)
    {
        //for(j=0; j<0xFFFFu;j++)
        //{
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
            asm("nop");
        //}

    }


}

///* Assembly MACRO */
//asm void inline_ASM_function( void)
//{
//  nop;
//  nop;
//  //trap 0;
//}


///* These two result in function call */
//#pragma ghs noprologue
//void inline_ASM_function(void)
//{
//    __asm__ __volatile__("nop  \n\t"
//                         "nop  \n\t"
//                         "jmp             [lp] \n\t"
//                         );

//}
//inline void inline_ASM_function(void)
//{
//    __asm__ __volatile__("nop  \n\t"
//                         "nop  \n\t"
//                         "jmp             [lp] \n\t"
//                         );

//}

//============================================================================
// Main function
//============================================================================
int main(void)
{
    // disable global interrupt
    __DI() ;

    //inline_ASM_function();

    // initialize clocks
    init_clocks();

    // initialize OSTM0
    R_Config_OSTM0_Create();

    // Enable global interrupt
    __EI() ;

    xTaskCreate( vLED_1_Task, ( signed portCHAR * ) "LED1", TASK_ONE_STACK_SIZE, NULL, tskIDLE_PRIORITY+1, &LED_1_handle1 );
    xTaskCreate( vLED_2_Task, ( signed portCHAR * ) "LED2", TASK_TWO_STACK_SIZE, NULL, tskIDLE_PRIORITY+3, &LED_2_handle2 );
    xTaskCreate( vLED_3_Task, ( signed portCHAR * ) "LED3", TASK_THREE_STACK_SIZE, NULL, tskIDLE_PRIORITY+2, &LED_3_handle3 );
    vTaskStartScheduler();

    while(1)
    {
        asm("nop");
        asm("nop");
    }

  return 0;
}


