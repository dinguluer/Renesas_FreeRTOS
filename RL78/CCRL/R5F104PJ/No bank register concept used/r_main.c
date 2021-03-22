/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2011, 2020 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_main.c
* Version      : CodeGenerator for RL78/G14 V2.05.05.01 [25 Nov 2020]
* Device(s)    : R5F104PJ
* Tool-Chain   : CCRL
* Description  : This file implements main function.
* Creation Date: 2/16/2021
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_cgc.h"
#include "r_cg_timer.h"
#include "r_cg_wdt.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "event_groups.h"
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
//unsigned int testcount2 = 7;
//unsigned int testcount3 = 0;
#define RTOS_TIMING_10MS         100U //10 msec = 10*10-3 i.e = 1/10^-2 = 100  // 1 msec ISR
//#define RTOS_TIMING_10MS         1000U  //1 msec = 1*10-3  // 1 msec ISR

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
volatile float aaa = 1.21;
volatile float bbb = 0;
volatile unsigned int ccc = 0;

volatile float aaa_1 = 1.21;
volatile float bbb_1 = 0;
volatile unsigned int ccc_1 = 0;

volatile float aaa_3 = 1.21;
volatile float bbb_3 = 0;
volatile unsigned int ccc_3 = 0;

uint8_t test = 0;
static void  vLED_1_Task(void *pvParameters)
{
    TickType_t xLastWakeTime;
    //const TickType_t xFrequency = 10;

    testcount1++;
    xLastWakeTime = xTaskGetTickCount ();
    for( ;; )
    {
        //vTaskDelay(1000/portTICK_RATE_MS);
        // Wait for the next cycle.
        //vTaskDelayUntil( &xLastWakeTime, xFrequency );
        vTaskDelayUntil(&xLastWakeTime, RTOS_TIMING_10MS);
        testcount1++;

        bbb_1 = aaa_1+testcount1;
        ccc_1 = bbb_1;

        if(testcount1 == 2000)
        {
            testcount1 = 0;
        }

    }
    vTaskDelete( NULL );

}


static void  vLED_2_Task(void *pvParameters)
{
    TickType_t xLastWakeTime;
    //const TickType_t xFrequency = 10;
    testcount2++;
    xLastWakeTime = xTaskGetTickCount ();
    //EI();
    
    for( ;; )
    {
        bbb = aaa+testcount2;
        ccc = bbb;
        //vTaskDelay(500/portTICK_RATE_MS);
        /* Wait until it is time to check all the other tasks again. */
        //vTaskDelayUntil( &xLastWakeTime, xFrequency );
        vTaskDelayUntil(&xLastWakeTime, RTOS_TIMING_10MS);

        testcount2++;
        //break;


        if(testcount2 == 2000)
        {
            testcount2 = 0;
        }
    }
    vTaskDelete( NULL );

}

static void  vLED_3_Task(void *pvParameters)
{
    TickType_t xLastWakeTime;
    //const TickType_t xFrequency = 10;
    //R_Config_TAUJ0_0_Start();
    testcount3++;
    xLastWakeTime = xTaskGetTickCount ();
    for( ;; )
    {
        bbb_3 = aaa_3+testcount3;
        ccc_3 = bbb_3;

        //vTaskDelay(2000/portTICK_RATE_MS);
        /* Wait until it is time to check all the other tasks again. */
        //vTaskDelayUntil( &xLastWakeTime, xFrequency );
        vTaskDelayUntil(&xLastWakeTime, RTOS_TIMING_10MS);
        testcount3++;
        //break;


        if(testcount3 == 2000)
        {
            testcount3 = 0;
        }
    }
    vTaskDelete( NULL );

}

/* End user code. Do not edit comment generated here */
void R_MAIN_UserInit(void);

/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{
    R_MAIN_UserInit();
    /* Start user code. Do not edit comment generated here */
    //P0 = testcount2;
    xTaskCreate( vLED_1_Task, ( signed portCHAR * ) "LED1", TASK_ONE_STACK_SIZE, NULL, tskIDLE_PRIORITY+1, &LED_1_handle1 );
    xTaskCreate( vLED_2_Task, ( signed portCHAR * ) "LED2", TASK_TWO_STACK_SIZE, NULL, tskIDLE_PRIORITY+3, &LED_2_handle2 );
    xTaskCreate( vLED_3_Task, ( signed portCHAR * ) "LED3", TASK_THREE_STACK_SIZE, NULL, tskIDLE_PRIORITY+2, &LED_3_handle3 );
    vTaskStartScheduler();

    while (1U)
    {
        ;
    }
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: R_MAIN_UserInit
* Description  : This function adds user code before implementing main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_MAIN_UserInit(void)
{
    /* Start user code. Do not edit comment generated here */
    //EI();
    NOP();
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
