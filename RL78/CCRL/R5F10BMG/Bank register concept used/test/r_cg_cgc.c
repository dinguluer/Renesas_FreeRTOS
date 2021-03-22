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
* Copyright (C) 2012, 2019 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_cgc.c
* Version      : CodeGenerator for RL78/F13 V2.03.05.02 [20 Nov 2019]
* Device(s)    : R5F10BMG
* Tool-Chain   : CCRL
* Description  : This file implements device driver for CGC module.
* Creation Date: 12/24/2020
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_cgc.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_CGC_Create
* Description  : This function initializes the clock generator.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_CGC_Create(void)
{
    volatile uint32_t w_count;
    uint8_t           temp_stab_set;
    uint8_t           temp_stab_wait; 

    /* Set fSL */
    SELLOSC = 1U;
    /* Set fMX */
    CMC = _40_CGC_HISYS_OSC | _00_CGC_SUB_PORT | _00_CGC_SYSOSC_UNDER10M | _00_CGC_SUBMODE_DEFAULT;
    OSTS = _07_CGC_OSCSTAB_SEL18;
    MSTOP = 0U;
    temp_stab_set = _FF_CGC_OSCSTAB_STA18;

    do
    {
        temp_stab_wait = OSTC;
        temp_stab_wait &= temp_stab_set;
    }
    while (temp_stab_wait != temp_stab_set);

    /* Set fMAIN */
    MCM0 = 1U;

    while (MCS == 0U)
    {
        ;
    }

    /* Set fPLL */
    PLLCTL = _40_CGC_LOCKUP_WAIT_8 | _00_CGC_PLL_BELOW_32MHZ | _00_CGC_PLL_DIVISION_2 | _02_CGC_PLL_MULTIPLY_X16;

    /* Change the waiting time according to the system */    
    for (w_count = 0U; w_count <= CGC_PLLWAITTIME; w_count++)
    {
        NOP();
    }

    PLLON = 1U;

    while ((PLLSTS & 0x80U) == 0U)
    {
        ;
    }

    MDIV = _00_CGC_FMP_DIV_DEFAULT;
    /* Set fMP to PLL clock select mode */
    SELPLL = 1U;

    while ((PLLSTS & 0x88U) != 0x88U)
    {
        ;
    }

    /* Set fSUB */
    XTSTOP = 1U;
    /* Set fCLK */
    CSS = 0U;
    /* Set fIH */
    HIOSTOP = 0U;
    /* Set RTC clock source */
    RTCCL = _00_CGC_RTC_FMX;
    RTCCL |= _42_CGC_RTC_DIV122;
    /* Set Timer RD clock source to fCLK, fMP */
    TRD_CKSEL = 0U;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
