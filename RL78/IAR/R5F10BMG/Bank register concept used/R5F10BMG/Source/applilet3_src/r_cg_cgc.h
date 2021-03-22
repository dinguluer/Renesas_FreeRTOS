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
* File Name    : r_cg_cgc.h
* Version      : Applilet3 for RL78/F13 V2.02.00.03 [07 Aug 2014]
* Device(s)    : R5F10BMG
* Tool-Chain   : IAR Systems iccrl78
* Description  : This file implements device driver for CGC module.
* Creation Date: 1/11/2021
***********************************************************************************************************************/

#ifndef CGC_H
#define CGC_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Clock operation mode control register (CMC)
*/
/* High-speed system clock pin operation mode (EXCLK, OSCSEL) */
#define _C0_CGC_HISYS_PIN           (0xC0U)
#define _00_CGC_HISYS_PORT          (0x00U) /* X1, X2 as I/O port */
#define _40_CGC_HISYS_OSC           (0x40U) /* X1, X2 as crystal/ceramic resonator connection */
#define _80_CGC_HISYS_PORT1         (0x80U) /* X1, X2 as I/O port */
#define _C0_CGC_HISYS_EXT           (0xC0U) /* X1 as I/O port, X2 as external clock input */
/* Subsystem clock pin operation mode (EXCLKS, OSCSELS) */
#define _30_CGC_SUB_PIN             (0x30U)
#define _00_CGC_SUB_PORT            (0x00U) /* XT1, XT2 as I/O port */
#define _10_CGC_SUB_OSC             (0x10U) /* XT1, XT2 as crystal connection */
#define _20_CGC_SUB_PORT1           (0x20U) /* XT1, XT2 as I/O port */
#define _30_CGC_SUB_EXT             (0x30U) /* XT1 as I/O port, XT2 as external clock input */
/* XT1 oscillator oscillation mode selection (AMPHS1, AMPHS0) */
#define _00_CGC_SUBMODE_DEFAULT     (0x00U)
#define _00_CGC_SUBMODE_LOW         (0x00U) /* low power consumption oscillation */
#define _02_CGC_SUBMODE_NORMAL      (0x02U) /* normal oscillation */
#define _04_CGC_SUBMODE_ULOW        (0x04U) /* ultra-low power consumption oscillation */
/* Control of X1 high-speed system clock oscillation frequency (AMPH) */
#define _00_CGC_SYSOSC_DEFAULT      (0x00U)
#define _00_CGC_SYSOSC_UNDER10M     (0x00U) /* fX <= 10MHz */
#define _01_CGC_SYSOSC_OVER10M      (0x01U) /* fX > 10MHz */

/*
    Clock operation status control register (CSC)
*/
/* Control of high-speed system clock operation (MSTOP) */
#define _00_CGC_HISYS_OPER          (0x00U) /* X1 oscillator/external clock operating */
#define _80_CGC_HISYS_STOP          (0x80U) /* X1 oscillator/external clock stopped */
/* Subsystem clock operation (XTSTOP) */
#define _00_CGC_SUB_OPER            (0x00U) /* XT1 oscillator operating */
#define _40_CGC_SUB_STOP            (0x40U) /* XT1 oscillator stopped */
/* High-speed OCO operation (HIOSTOP) */
#define _00_CGC_HIO_OPER            (0x00U) /* high-speed OCO operating */
#define _01_CGC_HIO_STOP            (0x01U) /* high-speed OCO stopped */

/*
    Oscillation stabilization time counter status register (OSTC)
*/
/* Oscillation stabilization time status (MOST18 - MOST8) */
#define _00_CGC_OSCSTAB_STA0        (0x00U) /* < 2^8/fX */
#define _80_CGC_OSCSTAB_STA8        (0x80U) /* 2^8/fX */
#define _C0_CGC_OSCSTAB_STA9        (0xC0U) /* 2^9/fX */
#define _E0_CGC_OSCSTAB_STA10       (0xE0U) /* 2^10/fX */
#define _F0_CGC_OSCSTAB_STA11       (0xF0U) /* 2^11/fX */
#define _F8_CGC_OSCSTAB_STA13       (0xF8U) /* 2^13/fX */
#define _FC_CGC_OSCSTAB_STA15       (0xFCU) /* 2^15/fX */
#define _FE_CGC_OSCSTAB_STA17       (0xFEU) /* 2^17/fX */
#define _FF_CGC_OSCSTAB_STA18       (0xFFU) /* 2^18/fX */

/*
    Oscillation stabilization time select register (OSTS)
*/
/* Oscillation stabilization time selection (OSTS2 - OSTS0) */
#define _00_CGC_OSCSTAB_SEL8        (0x00U) /* 2^8/fX */
#define _01_CGC_OSCSTAB_SEL9        (0x01U) /* 2^9/fX */
#define _02_CGC_OSCSTAB_SEL10       (0x02U) /* 2^10/fX */
#define _03_CGC_OSCSTAB_SEL11       (0x03U) /* 2^11/fX */
#define _04_CGC_OSCSTAB_SEL13       (0x04U) /* 2^13/fX */
#define _05_CGC_OSCSTAB_SEL15       (0x05U) /* 2^15/fX */
#define _06_CGC_OSCSTAB_SEL17       (0x06U) /* 2^17/fX */
#define _07_CGC_OSCSTAB_SEL18       (0x07U) /* 2^18/fX */

/*
    PLL control register (PLLCTL)
*/
/* Lockup wait counter setting value */
#define _00_CGC_LOCKUP_WAIT_7       (0x00U) /* 2^7/fMAIN */
#define _40_CGC_LOCKUP_WAIT_8       (0x40U) /* 2^8/fMAIN */
#define _80_CGC_LOCKUP_WAIT_9       (0x80U) /* 2^9/fMAIN */
/* PLL output clock selection (PLLDIV1) */
#define _00_CGC_PLL_BELOW_32MHZ     (0x00U) /* when fMAIN <= 32 MHz */
#define _20_CGC_PLL_ABOVE_32MHZ     (0x20U) /* when fMAIN > 32 MHz */
/* PLL output clock division selection (PLLDIV0) */
#define _00_CGC_PLL_DIVISION_2      (0x00U) /* divides the clock frequency by 2 */
#define _10_CGC_PLL_DIVISION_4      (0x10U) /* divides the clock frequency by 4 */
/* Clock mode selection (SELPLL) */
#define _00_CGC_NOSEL_PLL           (0x00U) /* clock through mode */
#define _04_CGC_SEL_PLL             (0x04U) /* PLL clock select mode */
/* PLL output clock (fPLLO) multiplier selection (PLLMUL) */
#define _00_CGC_PLL_MULTIPLY_X12    (0x00U) /* clock through mode */
#define _02_CGC_PLL_MULTIPLY_X16    (0x02U) /* PLL clock select mode */
/* Operating or stopping PLL function (PLLON) */
#define _00_CGC_PLL_STOP            (0x00U) /* PLL operating stopped */
#define _01_CGC_PLL_ENABLE          (0x01U) /* PLL operating */

/*
    PLL status register (PLLSTS)
*/
/* PLL lock state */
#define _00_CGC_PLL_UNLOCKED        (0x00U) /* Unlocked state */
#define _80_CGC_PLL_LOCKED          (0x80U) /* Locked state */

/*
    FMP clock selection division register (MDIV)
*/
/* Division of PLL clock (fMP) */
#define _00_CGC_FMP_DIV_DEFAULT     (0x00U) /* fMP (default) */
#define _01_CGC_FMP_DIV_1           (0x01U) /* fMP/2^1 */
#define _02_CGC_FMP_DIV_2           (0x02U) /* fMP/2^2 */
#define _03_CGC_FMP_DIV_3           (0x03U) /* fMP/2^3 */
#define _04_CGC_FMP_DIV_4           (0x04U) /* fMP/2^4 */
#define _05_CGC_FMP_DIV_5           (0x05U) /* fMP/2^5 */
#define _06_CGC_FMP_DIV_6           (0x06U) /* fMP/2^6 */

/*
    System clock control register (CKC)
*/
/* Status of CPU/peripheral hardware clock fCLK (CLS) */
#define _00_CGC_CPUCLK_MAIN         (0x00U) /* main system clock (fMAIN) */
#define _80_CGC_CPUCLK_SUB          (0x80U) /* subsystem clock (fSUB) */
/* Selection of CPU/peripheral hardware clock fCLK (CSS) */
#define _00_CGC_CPUCLK_SELMAIN      (0x00U) /* main system clock (fMAIN) */
#define _40_CGC_CPUCLK_SELSUB       (0x40U) /* subsystem clock (fSUB) */
/* Status of Main system clock fMAIN (MCS) */
#define _00_CGC_MAINCLK_HIO         (0x00U) /* high-speed OCO clock (fIH) */
#define _20_CGC_MAINCLK_HISYS       (0x20U) /* high-speed system clock (fMX) */
/* Selection of Main system clock fMAIN (MCM0) */
#define _00_CGC_MAINCLK_SELHIO      (0x00U) /* high-speed OCO clock (fIH) */
#define _10_CGC_MAINCLK_SELHISYS    (0x10U) /* high-speed system clock (fMX) */

/*
    Operation speed mode control register (OSMC)
*/
/* Setting in subsystem clock HALT mode (RTCLPC) */
#define _00_CGC_SUBINHALT_ON        (0x00U) /* enables supply of subsystem clock to peripheral functions */
#define _80_CGC_SUBINHALT_OFF       (0x80U) /* stops supply to peripheral functions other than RTC and interval timer */
/* RTC macro operation clock (WUTMMCK0) */
#define _00_CGC_RTC_CLK_OTHER       (0x00U) /* Other than fIL */
#define _10_CGC_RTC_CLK_FIL         (0x10U) /* use fIL clock */

/*
    Illegal memory access detection control register (IAWCTL)
*/
/* Illegal memory access detection control (IAWEN) */
#define _00_CGC_ILLEGAL_ACCESS_OFF  (0x00U) /* disables illegal memory access detection */
#define _80_CGC_ILLEGAL_ACCESS_ON   (0x80U) /* enables illegal memory access detection */
/* RAM guard area (GRAM1, GRAM0) */
#define _00_CGC_RAM_GUARD_OFF       (0x00U) /* invalid, it is possible to write RAM */
#define _10_CGC_RAM_GUARD_AREA0     (0x10U) /* 128 bytes from RAM bottom address */
#define _20_CGC_RAM_GUARD_AREA1     (0x20U) /* 256 bytes from RAM bottom address */
#define _30_CGC_RAM_GUARD_AREA2     (0x30U) /* 512 bytes from RAM bottom address */
/* PORT register guard (GPORT) */
#define _00_CGC_PORT_GUARD_OFF      (0x00U) /* invalid, it is possible to write PORT register */
#define _04_CGC_PORT_GUARD_ON       (0x04U) /* valid, it is impossible to write PORT register, but possible for read */
/* Interrupt register guard (GINT) */
#define _00_CGC_INT_GUARD_OFF       (0x00U) /* invalid, it is possible to write interrupt register */
#define _02_CGC_INT_GUARD_ON        (0x02U) /* valid, it is impossible to write , but possible for read */
/* CSC register guard (GCSC) */
#define _00_CGC_CSC_GUARD_OFF       (0x00U) /* invalid, it is possible to write CSC register */
#define _01_CGC_CSC_GUARD_ON        (0x01U) /* valid, it is impossible to write CSC register, but possible for read */

/*
    RTC clock selection register (RTCCL)
*/
/* Operation clock source selection for RTC (RTCCL7) */
#define _00_CGC_RTC_FMX             (0x00U) /* RTC uses External Main clock (fMX) */
#define _80_CGC_RTC_FIH             (0x80U) /* RTC uses Internal high speed clock (fIH) */
/* Operation selection of RTC macro (RTCCL6,RTCCKS1 - RTCCKS0)  */
#define _00_CGC_RTC_FSUB            (0x00U) /* RTC uses sub clock */
#define _02_CGC_RTC_DIV128          (0x02U) /* RTC uses high-speed clock / 128 */
#define _03_CGC_RTC_DIV256          (0x03U) /* RTC uses high-speed clock / 256 */
#define _42_CGC_RTC_DIV122          (0x42U) /* RTC uses high-speed clock / 122 */
#define _43_CGC_RTC_DIV244          (0x43U) /* RTC uses high-speed clock / 244 */


/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define CGC_PLLWAITTIME             (800U) /* change the waiting time according to the system */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/
typedef enum
{
    HIOCLK, 
    SYSX1CLK, 
    SYSEXTCLK, 
    SUBXT1CLK, 
    SUBEXTCLK
} clock_mode_t;

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_CGC_Create(void);
void R_CGC_Get_ResetSource(void);

/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
