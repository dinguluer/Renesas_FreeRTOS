/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIESREGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
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
* Copyright (C) 2012, 2014 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_wdt.c
* Version      : Applilet3 for RL78/F13 V2.02.00.03 [07 Aug 2014]
* Device(s)    : R5F10BMG
* Tool-Chain   : IAR Systems iccrl78
* Description  : This file implements device driver for WDT module.
* Creation Date: 1/11/2021
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_wdt.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_WDT_Create
* Description  : This function initializes the watchdogtimer.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_WDT_Create(void)
{
    WDTIMK = 1U;    /* disable INTWDTI interrupt */
    WDTIIF = 0U;    /* clear INTWDTI interrupt flag */
    /* Set INTWDTI low priority */
    WDTIPR1 = 1U;
    WDTIPR0 = 1U;
    WDTIMK = 0U;    /* enable INTWDTI interrupt */
}

/***********************************************************************************************************************
* Function Name: R_WDT_Restart
* Description  : This function restarts the watchdog timer.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_WDT_Restart(void)
{
    WDTE = 0xACU;     /* restart watchdog timer */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
