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
* File Name    : r_cg_timer.h
* Version      : Applilet3 for RL78/F13 V2.02.00.03 [07 Aug 2014]
* Device(s)    : R5F10BMG
* Tool-Chain   : IAR Systems iccrl78
* Description  : This file implements device driver for TAU module.
* Creation Date: 1/11/2021
***********************************************************************************************************************/

#ifndef TAU_H
#define TAU_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Peripheral Enable Register 0 (PER0)
*/
/* Control of timer array unit 0 input clock (TAU0EN) */
#define _00_TAU0_CLOCK_STOP                     (0x00U)   /* stops supply of input clock */
#define _01_TAU0_CLOCK_SUPPLY                   (0x01U)   /* supplies input clock */
/* Control of timer array unit 1 input clock (TAU1EN) */
#define _00_TAU1_CLOCK_STOP                     (0x00U)   /* stops supply of input clock */
#define _02_TAU1_CLOCK_SUPPLY                   (0x02U)   /* supplies input clock */

/*
    Timer Clock Select Register m (TPSm)
*/
/* Operating mode and clear mode selection (PRSm03 - PRSm00) */
#define _0000_TAU_CKM0_FCLK_0                   (0x0000U) /* ckm0 - fCLK */
#define _0001_TAU_CKM0_FCLK_1                   (0x0001U) /* ckm0 - fCLK/2^1 */
#define _0002_TAU_CKM0_FCLK_2                   (0x0002U) /* ckm0 - fCLK/2^2 */
#define _0003_TAU_CKM0_FCLK_3                   (0x0003U) /* ckm0 - fCLK/2^3 */
#define _0004_TAU_CKM0_FCLK_4                   (0x0004U) /* ckm0 - fCLK/2^4 */
#define _0005_TAU_CKM0_FCLK_5                   (0x0005U) /* ckm0 - fCLK/2^5 */
#define _0006_TAU_CKM0_FCLK_6                   (0x0006U) /* ckm0 - fCLK/2^6 */
#define _0007_TAU_CKM0_FCLK_7                   (0x0007U) /* ckm0 - fCLK/2^7 */
#define _0008_TAU_CKM0_FCLK_8                   (0x0008U) /* ckm0 - fCLK/2^8 */
#define _0009_TAU_CKM0_FCLK_9                   (0x0009U) /* ckm0 - fCLK/2^9 */
#define _000A_TAU_CKM0_FCLK_10                  (0x000AU) /* ckm0 - fCLK/2^10 */
#define _000B_TAU_CKM0_FCLK_11                  (0x000BU) /* ckm0 - fCLK/2^11 */
#define _000C_TAU_CKM0_FCLK_12                  (0x000CU) /* ckm0 - fCLK/2^12 */
#define _000D_TAU_CKM0_FCLK_13                  (0x000DU) /* ckm0 - fCLK/2^13 */
#define _000E_TAU_CKM0_FCLK_14                  (0x000EU) /* ckm0 - fCLK/2^14 */
#define _000F_TAU_CKM0_FCLK_15                  (0x000FU) /* ckm0 - fCLK/2^15 */
/* Operating mode and clear mode selection (PRSm13 - PRSm10) */
#define _0000_TAU_CKM1_FCLK_0                   (0x0000U) /* ckm1 - fCLK */
#define _0010_TAU_CKM1_FCLK_1                   (0x0010U) /* ckm1 - fCLK/2^1 */
#define _0020_TAU_CKM1_FCLK_2                   (0x0020U) /* ckm1 - fCLK/2^2 */
#define _0030_TAU_CKM1_FCLK_3                   (0x0030U) /* ckm1 - fCLK/2^3 */
#define _0040_TAU_CKM1_FCLK_4                   (0x0040U) /* ckm1 - fCLK/2^4 */
#define _0050_TAU_CKM1_FCLK_5                   (0x0050U) /* ckm1 - fCLK/2^5 */
#define _0060_TAU_CKM1_FCLK_6                   (0x0060U) /* ckm1 - fCLK/2^6 */
#define _0070_TAU_CKM1_FCLK_7                   (0x0070U) /* ckm1 - fCLK/2^7 */
#define _0080_TAU_CKM1_FCLK_8                   (0x0080U) /* ckm1 - fCLK/2^8 */
#define _0090_TAU_CKM1_FCLK_9                   (0x0090U) /* ckm1 - fCLK/2^9 */
#define _00A0_TAU_CKM1_FCLK_10                  (0x00A0U) /* ckm1 - fCLK/2^10 */
#define _00B0_TAU_CKM1_FCLK_11                  (0x00B0U) /* ckm1 - fCLK/2^11 */
#define _00C0_TAU_CKM1_FCLK_12                  (0x00C0U) /* ckm1 - fCLK/2^12 */
#define _00D0_TAU_CKM1_FCLK_13                  (0x00D0U) /* ckm1 - fCLK/2^13 */
#define _00E0_TAU_CKM1_FCLK_14                  (0x00E0U) /* ckm1 - fCLK/2^14 */
#define _00F0_TAU_CKM1_FCLK_15                  (0x00F0U) /* ckm1 - fCLK/2^15 */
/* Operating mode and clear mode selection (PRSm21 - PRSm20) */
#define _0000_TAU_CKM2_FCLK_1                   (0x0000U) /* ckm2 - fCLK/2^1 */
#define _0100_TAU_CKM2_FCLK_2                   (0x0100U) /* ckm2 - fCLK/2^2 */
#define _0200_TAU_CKM2_FCLK_4                   (0x0200U) /* ckm2 - fCLK/2^4 */
#define _0300_TAU_CKM2_FCLK_6                   (0x0300U) /* ckm2 - fCLK/2^6 */
/* Operating mode and clear mode selection (PRSm31 - PRSm30) */
#define _0000_TAU_CKM3_FCLK_8                   (0x0000U) /* ckm2 - fCLK/2^8 */
#define _1000_TAU_CKM3_FCLK_10                  (0x1000U) /* ckm2 - fCLK/2^10 */
#define _2000_TAU_CKM3_FCLK_12                  (0x2000U) /* ckm2 - fCLK/2^12 */
#define _3000_TAU_CKM3_FCLK_14                  (0x3000U) /* ckm2 - fCLK/2^14 */

/*
    Timer Mode Register mn (TMRmn)
*/
/* Selection of macro clock (MCK) of channel n (CKSmn1 - CKSmn0) */
#define _0000_TAU_CLOCK_SELECT_CKM0             (0x0000U) /* operation clock CK0 set by PRS register */ 
#define _8000_TAU_CLOCK_SELECT_CKM1             (0x8000U) /* operation clock CK1 set by PRS register */
#define _4000_TAU_CLOCK_SELECT_CKM2             (0x4000U) /* operation clock CK2 set by PRS register */
#define _C000_TAU_CLOCK_SELECT_CKM3             (0xC000U) /* operation clock CK3 set by PRS register */
/* Selection of count clock (CCK) of channel n (CCSmn) */
#define _0000_TAU_CLOCK_MODE_CKS                (0x0000U) /* macro clock MCK specified by CKSmn bit */  
#define _1000_TAU_CLOCK_MODE_TIMN               (0x1000U) /* valid edge of input signal input from TImn pin */
/* Selection of slave/master of channel n (MASTERmn) */
#define _0000_TAU_COMBINATION_SLAVE             (0x0000U) /* operates as slave channel */
#define _0800_TAU_COMBINATION_MASTER            (0x0800U) /* operates as master channel */
/* Operation explanation of channel 1 or 3 (SPLIT) */
#define _0000_TAU_16BITS_MODE                   (0x0000U) /* operates as 16 bits timer */  
#define _0800_TAU_8BITS_MODE                    (0x0800U) /* operates as 8 bits timer */
/* Setting of start trigger or capture trigger of channel n (STSmn2 - STSmn0) */
#define _0000_TAU_TRIGGER_SOFTWARE              (0x0000U) /* only software trigger start is valid */
#define _0100_TAU_TRIGGER_TIMN_VALID            (0x0100U) /* TImn input edge is used as a start/capture trigger */
#define _0200_TAU_TRIGGER_TIMN_BOTH             (0x0200U) /* TImn input edges are used as a start/capture trigger */
#define _0400_TAU_TRIGGER_MASTER_INT            (0x0400U) /* interrupt signal of the master channel is used */
/* Selection of TImn pin input valid edge (CISmn1 - CISmn0) */
#define _0000_TAU_TIMN_EDGE_FALLING             (0x0000U) /* falling edge */
#define _0040_TAU_TIMN_EDGE_RISING              (0x0040U) /* rising edge */
#define _0080_TAU_TIMN_EDGE_BOTH_LOW            (0x0080U) /* both edges (when low-level width is measured) */
#define _00C0_TAU_TIMN_EDGE_BOTH_HIGH           (0x00C0U) /* both edges (when high-level width is measured) */
/* Operation mode of channel n (MDmn3 - MDmn0) */
#define _0000_TAU_MODE_INTERVAL_TIMER           (0x0000U) /* interval timer mode */
#define _0004_TAU_MODE_CAPTURE                  (0x0004U) /* capture mode */
#define _0006_TAU_MODE_EVENT_COUNT              (0x0006U) /* event counter mode */
#define _0008_TAU_MODE_ONE_COUNT                (0x0008U) /* one count mode */
#define _000C_TAU_MODE_HIGHLOW_MEASURE          (0x000CU) /* high-/low-level width measurement mode */
#define _0001_TAU_MODE_PWM_MASTER               (0x0001U) /* PWM Function (Master Channel) mode */
#define _0009_TAU_MODE_PWM_SLAVE                (0x0009U) /* PWM Function (Slave Channel) mode */
#define _0008_TAU_MODE_ONESHOT                  (0x0008U) /* one-shot pulse output mode */
/* Setting of starting counting and interrupt (MDmn0) */
#define _0000_TAU_START_INT_UNUSED              (0x0000U) /* interrupt is not generated when counting is started */
#define _0001_TAU_START_INT_USED                (0x0001U) /* interrupt is generated when counting is started */

/*
    Timer Status Register mn (TSRmn)
*/
/* Counter overflow status of channel n (OVF) */
#define _0000_TAU_OVERFLOW_NOT_OCCURS           (0x0000U) /* overflow does not occur */
#define _0001_TAU_OVERFLOW_OCCURS               (0x0001U) /* overflow occurs */

/*
    Timer Channel Enable Status Register m (TEm)
*/
/* Indication of operation enable/stop status of channel 0 (TEm0) */
#define _0000_TAU_CH0_OPERATION_STOP            (0x0000U) /* operation is stopped */
#define _0001_TAU_CH0_OPERATION_ENABLE          (0x0001U) /* operation is enabled */
/* Indication of operation enable/stop status of channel 1 (TEm1) */
#define _0000_TAU_CH1_OPERATION_STOP            (0x0000U) /* operation is stopped */
#define _0002_TAU_CH1_OPERATION_ENABLE          (0x0002U) /* operation is enabled */
/* Indication of operation enable/stop status of channel 2 (TEm2) */
#define _0000_TAU_CH2_OPERATION_STOP            (0x0000U) /* operation is stopped */
#define _0004_TAU_CH2_OPERATION_ENABLE          (0x0004U) /* operation is enabled */
/* Indication of operation enable/stop status of channel 3 (TEm3) */
#define _0000_TAU_CH3_OPERATION_STOP            (0x0000U) /* operation is stopped */
#define _0008_TAU_CH3_OPERATION_ENABLE          (0x0008U) /* operation is enabled */
/* Indication of operation enable/stop status of channel 4 (TEm4) */
#define _0000_TAU_CH4_OPERATION_STOP            (0x0000U) /* operation is stopped */
#define _0010_TAU_CH4_OPERATION_ENABLE          (0x0010U) /* operation is enabled */
/* Indication of operation enable/stop status of channel 5 (TEm5) */
#define _0000_TAU_CH5_OPERATION_STOP            (0x0000U) /* operation is stopped */
#define _0020_TAU_CH5_OPERATION_ENABLE          (0x0020U) /* operation is enabled */
/* Indication of operation enable/stop status of channel 6 (TEm6) */
#define _0000_TAU_CH6_OPERATION_STOP            (0x0000U) /* operation is stopped */
#define _0040_TAU_CH6_OPERATION_ENABLE          (0x0040U) /* operation is enabled */
/* Indication of operation enable/stop status of channel 7 (TEm7) */
#define _0000_TAU_CH7_OPERATION_STOP            (0x0000U) /* operation is stopped */
#define _0080_TAU_CH7_OPERATION_ENABLE          (0x0080U) /* operation is enabled */
/* Indication of operation enable/stop status of channel 1 higher 8 bits (TEHm1) */
#define _0000_TAU_CH1_H8_OPERATION_STOP         (0x0000U) /* operation is stopped */
#define _0200_TAU_CH1_H8_OPERATION_ENABLE       (0x0200U) /* operation is enabled */
/* Indication of operation enable/stop status of channel 3 higher 8 bits (TEHm3) */
#define _0000_TAU_CH3_H8_OPERATION_STOP         (0x0000U) /* operation is stopped */
#define _0800_TAU_CH3_H8_OPERATION_ENABLE       (0x0800U) /* operation is enabled */

/*
    Timer Channel Start Register m (TSm)
*/
/* Operation enable (start) trigger of channel 0 (TSm0) */
#define _0000_TAU_CH0_START_TRG_OFF             (0x0000U) /* no trigger operation */
#define _0001_TAU_CH0_START_TRG_ON              (0x0001U) /* operation is enabled (start trigger is generated) */
/* Operation enable (start) trigger of channel 1 (TSm1) */
#define _0000_TAU_CH1_START_TRG_OFF             (0x0000U) /* no trigger operation */
#define _0002_TAU_CH1_START_TRG_ON              (0x0002U) /* operation is enabled (start trigger is generated) */
/* Operation enable (start) trigger of channel 2 (TSm2) */
#define _0000_TAU_CH2_START_TRG_OFF             (0x0000U) /* no trigger operation */
#define _0004_TAU_CH2_START_TRG_ON              (0x0004U) /* operation is enabled (start trigger is generated) */
/* Operation enable (start) trigger of channel 3 (TSm3) */
#define _0000_TAU_CH3_START_TRG_OFF             (0x0000U) /* no trigger operation */
#define _0008_TAU_CH3_START_TRG_ON              (0x0008U) /* operation is enabled (start trigger is generated) */
/* Operation enable (start) trigger of channel 4 (TSm4) */
#define _0000_TAU_CH4_START_TRG_OFF             (0x0000U) /* no trigger operation */
#define _0010_TAU_CH4_START_TRG_ON              (0x0010U) /* operation is enabled (start trigger is generated) */
/* Operation enable (start) trigger of channel 5 (TSm5) */
#define _0000_TAU_CH5_START_TRG_OFF             (0x0000U) /* no trigger operation */
#define _0020_TAU_CH5_START_TRG_ON              (0x0020U) /* operation is enabled (start trigger is generated) */
/* Operation enable (start) trigger of channel 6 (TSm6) */
#define _0000_TAU_CH6_START_TRG_OFF             (0x0000U) /* no trigger operation */
#define _0040_TAU_CH6_START_TRG_ON              (0x0040U) /* operation is enabled (start trigger is generated) */
/* Operation enable (start) trigger of channel 7 (TSm7) */
#define _0000_TAU_CH7_START_TRG_OFF             (0x0000U) /* no trigger operation */
#define _0080_TAU_CH7_START_TRG_ON              (0x0080U) /* operation is enabled (start trigger is generated) */
/* Operation enable (start) trigger of channel 1 higher 8 bits (TSHm1) */
#define _0000_TAU_CH1_H8_START_TRG_OFF          (0x0000U) /* no trigger operation */
#define _0200_TAU_CH1_H8_START_TRG_ON           (0x0200U) /* operation is enabled (start trigger is generated) */
/* Operation enable (start) trigger of channel 3 higher 8 bits (TSHm3) */
#define _0000_TAU_CH3_H8_START_TRG_OFF          (0x0000U) /* no trigger operation */
#define _0800_TAU_CH3_H8_START_TRG_ON           (0x0800U) /* operation is enabled (start trigger is generated) */

/*
    Timer Channel Stop Register m (TTm)
*/
/* Operation stop trigger of channel 0 (TTm0) */
#define _0000_TAU_CH0_STOP_TRG_OFF              (0x0000U) /* no trigger operation */
#define _0001_TAU_CH0_STOP_TRG_ON               (0x0001U) /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 1 (TTm1) */
#define _0000_TAU_CH1_STOP_TRG_OFF              (0x0000U) /* no trigger operation */
#define _0002_TAU_CH1_STOP_TRG_ON               (0x0002U) /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 2 (TTm2) */
#define _0000_TAU_CH2_STOP_TRG_OFF              (0x0000U) /* no trigger operation */
#define _0004_TAU_CH2_STOP_TRG_ON               (0x0004U) /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 3 (TTm3) */
#define _0000_TAU_CH3_STOP_TRG_OFF              (0x0000U) /* no trigger operation */
#define _0008_TAU_CH3_STOP_TRG_ON               (0x0008U) /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 4 (TTm4) */
#define _0000_TAU_CH4_STOP_TRG_OFF              (0x0000U) /* no trigger operation */
#define _0010_TAU_CH4_STOP_TRG_ON               (0x0010U) /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 5 (TTm5) */
#define _0000_TAU_CH5_STOP_TRG_OFF              (0x0000U) /* no trigger operation */
#define _0020_TAU_CH5_STOP_TRG_ON               (0x0020U) /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 6 (TTm6) */
#define _0000_TAU_CH6_STOP_TRG_OFF              (0x0000U) /* no trigger operation */
#define _0040_TAU_CH6_STOP_TRG_ON               (0x0040U) /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 7 (TTm7) */
#define _0000_TAU_CH7_STOP_TRG_OFF              (0x0000U) /* no trigger operation */
#define _0080_TAU_CH7_STOP_TRG_ON               (0x0080U) /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 1 higher 8 bits (TTHm1) */
#define _0000_TAU_CH1_H8_STOP_TRG_OFF           (0x0000U) /* no trigger operation */
#define _0200_TAU_CH1_H8_STOP_TRG_ON            (0x0200U) /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 3 higher 8 bits (TTHm3) */
#define _0000_TAU_CH3_H8_STOP_TRG_OFF           (0x0000U) /* no trigger operation */
#define _0800_TAU_CH3_H8_STOP_TRG_ON            (0x0800U) /* operation is stopped (stop trigger is generated) */

/*
    Timer Input Select Register m (TIS0)
*/
/* Selection of timer input used with TAU0 channel 1 (TIS02 - TIS00) */
#define _00_TAU_CH1_INPUT_TI01                  (0x00U)   /* input signal of timer input pin (TI01) */
#define _01_TAU_CH1_INPUT_ELC                   (0x01U)   /* input signal of timer input pin (ELC) */
#define _02_TAU_CH1_INPUT_TI01                  (0x02U)   /* input signal of timer input pin (TI01) */
#define _03_TAU_CH1_INPUT_TI01                  (0x03U)   /* input signal of timer input pin (TI01) */
#define _04_TAU_CH1_INPUT_FIL                   (0x04U)   /* internal low speed oscillation clock (fIL) */
#define _05_TAU_CH1_INPUT_FSL                   (0x05U)   /* low speed on-chip oscillator clock (fSL) */
/* Selection of timer input used with TAU0 channel 0 (TIS04) */
#define _00_TAU_CH0_INPUT_TI00                  (0x00U)   /* input signal of timer input pin (TI00) */
#define _10_TAU_CH0_INPUT_ELC                   (0x10U)   /* event input signal from ELC */
/* Selection of timer input used with TAU0 channel 2 (TIS06) */
#define _00_TAU_CH2_INPUT_TI02                  (0x00U)   /* input signal of timer input pin (TI02) */
#define _40_TAU_CH2_INPUT_ELC                   (0x40U)   /* event input signal from ELC */
/* Selection of timer input used with TAU0 channel 3 (TIS07) */
#define _00_TAU_CH3_INPUT_TI03                  (0x00U)   /* input signal of timer input pin (TI03) */
#define _80_TAU_CH3_INPUT_ELC                   (0x80U)   /* event input signal from ELC */

/*
    Timer Input Select Register m (TIS1)
*/
/* Selection of timer input used with TAU0 channel 4 (TIS10) */
#define _00_TAU_CH4_INPUT_TI04                  (0x00U)   /* input signal of timer input pin (TI04) */
#define _01_TAU_CH4_INPUT_TI03                  (0x01U)   /* input signal of timer input pin (TI03) */
/* Selection of timer input used with TAU0 channel 5 (TIS12) */
#define _00_TAU_CH5_INPUT_TI05                  (0x00U)   /* input signal of timer input pin (TI05) */
#define _04_TAU_CH5_INPUT_TI03                  (0x04U)   /* input signal of timer input pin (TI03) */
/* Selection of timer input used with TAU0 channel 6 (TIS14) */
#define _00_TAU_CH6_INPUT_TI06                  (0x00U)   /* input signal of timer input pin (TI06) */
#define _10_TAU_CH6_INPUT_RTC1HZ                (0x10U)   /* RTC1HZ output signal */
/* Selection of timer input used with TAU0 channel 7 (TIS17 - TIS16) */
#define _00_TAU_CH7_INPUT_TI07                  (0x00U)   /* input signal of timer input pin (TI07) */
#define _40_TAU_CH7_INPUT_RTC1HZ                (0x40U)   /* RTC1HZ output signal */
#define _80_TAU_CH7_INPUT_RXD0                  (0x80U)   /* input signal of RXD0 pin */

/*
    Timer Input Select Register m (TIS2)
*/
/* Selection of timer input used with TAU1 channel 6 (TIS22) */
#define _00_TAU_CH6_INPUT_TI16                  (0x00U)   /* input signal of timer input pin (TI16) */
#define _04_TAU_CH6_INPUT_RTC1HZ                (0x04U)   /* RTC1HZ output signal */
/* Selection of timer input used with TAU1 channel 7 (TIS23) */
#define _00_TAU_CH7_INPUT_TI17                  (0x00U)   /* input signal of timer input pin (TI17) */
#define _08_TAU_CH7_INPUT_RTC1HZ                (0x08U)   /* RTC1HZ output signal */

/*
    Timer Output Enable Register m (TOEm)
*/
/* Timer output enable/disable of channel 0 (TOEm0) */
#define _0001_TAU_CH0_OUTPUT_ENABLE             (0x0001U) /* the TOm0 operation enabled by count operation */
#define _0000_TAU_CH0_OUTPUT_DISABLE            (0x0000U) /* the TOm0 operation stopped by count operation */
/* Timer output enable/disable of channel 1 (TOEm1) */
#define _0002_TAU_CH1_OUTPUT_ENABLE             (0x0002U) /* the TOm1 operation enabled by count operation */
#define _0000_TAU_CH1_OUTPUT_DISABLE            (0x0000U) /* the TOm1 operation stopped by count operation */
/* Timer output enable/disable of channel 2 (TOEm2) */
#define _0004_TAU_CH2_OUTPUT_ENABLE             (0x0004U) /* the TOm2 operation enabled by count operation */
#define _0000_TAU_CH2_OUTPUT_DISABLE            (0x0000U) /* the TOm2 operation stopped by count operation */
/* Timer output enable/disable of channel 3 (TOEm3) */
#define _0008_TAU_CH3_OUTPUT_ENABLE             (0x0008U) /* the TOm3 operation enabled by count operation */
#define _0000_TAU_CH3_OUTPUT_DISABLE            (0x0000U) /* the TOm3 operation stopped by count operation */
/* Timer output enable/disable of channel 4 (TOEm4) */
#define _0010_TAU_CH4_OUTPUT_ENABLE             (0x0010U) /* the TOm4 operation enabled by count operation */
#define _0000_TAU_CH4_OUTPUT_DISABLE            (0x0000U) /* the TOm4 operation stopped by count operation */
/* Timer output enable/disable of channel 5 (TOEm5) */
#define _0020_TAU_CH5_OUTPUT_ENABLE             (0x0020U) /* the TOm5 operation enabled by count operation */
#define _0000_TAU_CH5_OUTPUT_DISABLE            (0x0000U) /* the TOm5 operation stopped by count operation */
/* Timer output enable/disable of channel 6 (TOEm6) */
#define _0040_TAU_CH6_OUTPUT_ENABLE             (0x0040U) /* the TOm6 operation enabled by count operation */
#define _0000_TAU_CH6_OUTPUT_DISABLE            (0x0000U) /* the TOm6 operation stopped by count operation */
/* Timer output enable/disable of channel 7 (TOEm7) */
#define _0080_TAU_CH7_OUTPUT_ENABLE             (0x0080U) /* the TOm7 operation enabled by count operation */
#define _0000_TAU_CH7_OUTPUT_DISABLE            (0x0000U) /* the TOm7 operation stopped by count operation */

/*
    Timer Output Register m (TOm)
*/
/* Timer output of channel 0 (TOm0) */
#define _0000_TAU_CH0_OUTPUT_VALUE_0            (0x0000U) /* timer output value is "0" */
#define _0001_TAU_CH0_OUTPUT_VALUE_1            (0x0001U) /* timer output value is "1" */
/* Timer output of channel 1 (TOm1) */
#define _0000_TAU_CH1_OUTPUT_VALUE_0            (0x0000U) /* timer output value is "0" */
#define _0002_TAU_CH1_OUTPUT_VALUE_1            (0x0002U) /* timer output value is "1" */
/* Timer output of channel 2 (TOm2) */
#define _0000_TAU_CH2_OUTPUT_VALUE_0            (0x0000U) /* timer output value is "0" */
#define _0004_TAU_CH2_OUTPUT_VALUE_1            (0x0004U) /* timer output value is "1" */
/* Timer output of channel 3 (TOm3) */
#define _0000_TAU_CH3_OUTPUT_VALUE_0            (0x0000U) /* timer output value is "0" */
#define _0008_TAU_CH3_OUTPUT_VALUE_1            (0x0008U) /* timer output value is "1" */
/* Timer output of channel 4 (TOm4) */
#define _0000_TAU_CH4_OUTPUT_VALUE_0            (0x0000U) /* timer output value is "0" */
#define _0010_TAU_CH4_OUTPUT_VALUE_1            (0x0010U) /* timer output value is "1" */
/* Timer output of channel 5 (TOm5) */
#define _0000_TAU_CH5_OUTPUT_VALUE_0            (0x0000U) /* timer output value is "0" */
#define _0020_TAU_CH5_OUTPUT_VALUE_1            (0x0020U) /* timer output value is "1" */
/* Timer output of channel 6 (TOm6) */
#define _0000_TAU_CH6_OUTPUT_VALUE_0            (0x0000U) /* timer output value is "0" */
#define _0040_TAU_CH6_OUTPUT_VALUE_1            (0x0040U) /* timer output value is "1" */
/* Timer output of channel 7 (TOm7) */
#define _0000_TAU_CH7_OUTPUT_VALUE_0            (0x0000U) /* timer output value is "0" */
#define _0080_TAU_CH7_OUTPUT_VALUE_1            (0x0080U) /* timer output value is "1" */

/*
    Timer Output Level Register 0 (TOLm)
*/
/* Control of timer output level of channel 1 (TOLm1) */
#define _0000_TAU_CH1_OUTPUT_LEVEL_H            (0x0000U) /* positive logic output (active-high) */
#define _0002_TAU_CH1_OUTPUT_LEVEL_L            (0x0002U) /* inverted output (active-low) */
/* Control of timer output level of channel 2 (TOLm2) */
#define _0000_TAU_CH2_OUTPUT_LEVEL_H            (0x0000U) /* positive logic output (active-high) */
#define _0004_TAU_CH2_OUTPUT_LEVEL_L            (0x0004U) /* inverted output (active-low) */
/* Control of timer output level of channel 3 (TOLm3) */
#define _0000_TAU_CH3_OUTPUT_LEVEL_H            (0x0000U) /* positive logic output (active-high) */
#define _0008_TAU_CH3_OUTPUT_LEVEL_L            (0x0008U) /* inverted output (active-low) */
/* Control of timer output level of channel 4 (TOLm4) */
#define _0000_TAU_CH4_OUTPUT_LEVEL_H            (0x0000U) /* positive logic output (active-high) */
#define _0010_TAU_CH4_OUTPUT_LEVEL_L            (0x0010U) /* inverted output (active-low) */
/* Control of timer output level of channel 5 (TOLm5) */
#define _0000_TAU_CH5_OUTPUT_LEVEL_H            (0x0000U) /* positive logic output (active-high) */
#define _0020_TAU_CH5_OUTPUT_LEVEL_L            (0x0020U) /* inverted output (active-low) */
/* Control of timer output level of channel 6 (TOLm6) */
#define _0000_TAU_CH6_OUTPUT_LEVEL_H            (0x0000U) /* positive logic output (active-high) */
#define _0040_TAU_CH6_OUTPUT_LEVEL_L            (0x0040U) /* inverted output (active-low) */
/* Control of timer output level of channel 7 (TOLm7) */
#define _0000_TAU_CH7_OUTPUT_LEVEL_H            (0x0000U) /* positive logic output (active-high) */
#define _0080_TAU_CH7_OUTPUT_LEVEL_L            (0x0080U) /* inverted output (active-low) */

/*
    Timer Output Mode Register m (TOMm)
*/
/* Control of timer output mode of channel 1 (TOMm1) */
#define _0000_TAU_CH1_OUTPUT_TOGGLE             (0x0000U) /* toggle operation mode */
#define _0002_TAU_CH1_OUTPUT_COMBIN             (0x0002U) /* combination operation mode */
/* Control of timer output mode of channel 2 (TOMm2) */
#define _0000_TAU_CH2_OUTPUT_TOGGLE             (0x0000U) /* toggle operation mode */
#define _0004_TAU_CH2_OUTPUT_COMBIN             (0x0004U) /* combination operation mode */
/* Control of timer output mode of channel 3 (TOMm3) */
#define _0000_TAU_CH3_OUTPUT_TOGGLE             (0x0000U) /* toggle operation mode */
#define _0008_TAU_CH3_OUTPUT_COMBIN             (0x0008U) /* combination operation mode */
/* Control of timer output mode of channel 4 (TOMm4) */
#define _0000_TAU_CH4_OUTPUT_TOGGLE             (0x0000U) /* toggle operation mode */
#define _0010_TAU_CH4_OUTPUT_COMBIN             (0x0010U) /* combination operation mode */
/* Control of timer output mode of channel 5 (TOMm5) */
#define _0000_TAU_CH5_OUTPUT_TOGGLE             (0x0000U) /* toggle operation mode */
#define _0020_TAU_CH5_OUTPUT_COMBIN             (0x0020U) /* combination operation mode */
/* Control of timer output mode of channel 6 (TOMm6) */
#define _0000_TAU_CH6_OUTPUT_TOGGLE             (0x0000U) /* toggle operation mode */
#define _0040_TAU_CH6_OUTPUT_COMBIN             (0x0040U) /* combination operation mode */
/* Control of timer output mode of channel 7 (TOMm7) */
#define _0000_TAU_CH7_OUTPUT_TOGGLE             (0x0000U) /* toggle operation mode */
#define _0080_TAU_CH7_OUTPUT_COMBIN             (0x0080U) /* combination operation mode */

#define _0000_TAU_PWM_DELAY_CLEAR               (0x0000U) /* clear PWM output delay control register */

/*
    PWM output delay control register 1 (PWMDLY1)
*/
/* Control of PWM output delay time of TAU0 TO01 */
#define _0000_TO01_OUTPUT_DELAY_0               (0x0000U) /* no delay */
#define _0004_TO01_OUTPUT_DELAY_1               (0x0004U) /* delay 1 cycle */
#define _0008_TO01_OUTPUT_DELAY_2               (0x0008U) /* delay 2 cycles */
#define _000C_TO01_OUTPUT_DELAY_3               (0x000CU) /* delay 3 cycles */
/* Control of PWM output delay time of TAU0 TO02 */
#define _0000_TO02_OUTPUT_DELAY_0               (0x0000U) /* no delay */
#define _0010_TO02_OUTPUT_DELAY_1               (0x0010U) /* delay 1 cycle */
#define _0020_TO02_OUTPUT_DELAY_2               (0x0020U) /* delay 2 cycles */
#define _0030_TO02_OUTPUT_DELAY_3               (0x0030U) /* delay 3 cycles */
/* Control of PWM output delay time of TAU0 TO03 */
#define _0000_TO03_OUTPUT_DELAY_0               (0x0000U) /* no delay */
#define _0040_TO03_OUTPUT_DELAY_1               (0x0040U) /* delay 1 cycle */
#define _0080_TO03_OUTPUT_DELAY_2               (0x0080U) /* delay 2 cycles */
#define _00C0_TO03_OUTPUT_DELAY_3               (0x00C0U) /* delay 3 cycles */
/* Control of PWM output delay time of TAU0 TO04 */
#define _0000_TO04_OUTPUT_DELAY_0               (0x0000U) /* no delay */
#define _0100_TO04_OUTPUT_DELAY_1               (0x0100U) /* delay 1 cycle */
#define _0200_TO04_OUTPUT_DELAY_2               (0x0200U) /* delay 2 cycles */
#define _0300_TO04_OUTPUT_DELAY_3               (0x0300U) /* delay 3 cycles */
/* Control of PWM output delay time of TAU0 TO05 */
#define _0000_TO05_OUTPUT_DELAY_0               (0x0000U) /* no delay */
#define _0400_TO05_OUTPUT_DELAY_1               (0x0400U) /* delay 1 cycle */
#define _0800_TO05_OUTPUT_DELAY_2               (0x0800U) /* delay 2 cycles */
#define _0C00_TO05_OUTPUT_DELAY_3               (0x0C00U) /* delay 3 cycles */
/* Control of PWM output delay time of TAU0 TO06 */
#define _0000_TO06_OUTPUT_DELAY_0               (0x0000U) /* no delay */
#define _1000_TO06_OUTPUT_DELAY_1               (0x1000U) /* delay 1 cycle */
#define _2000_TO06_OUTPUT_DELAY_2               (0x2000U) /* delay 2 cycles */
#define _3000_TO06_OUTPUT_DELAY_3               (0x3000U) /* delay 3 cycles */
/* Control of PWM output delay time of TAU0 TO07 */
#define _0000_TO07_OUTPUT_DELAY_0               (0x0000U) /* no delay */
#define _4000_TO07_OUTPUT_DELAY_1               (0x4000U) /* delay 1 cycle */
#define _8000_TO07_OUTPUT_DELAY_2               (0x8000U) /* delay 2 cycles */
#define _C000_TO07_OUTPUT_DELAY_3               (0xC000U) /* delay 3 cycles */

/*
    PWM output delay control register 2 (PWMDLY2)
*/
/* Control of PWM output delay time of TAU1 TO11 */
#define _0000_TO11_OUTPUT_DELAY_0               (0x0000U) /* no delay */
#define _0004_TO11_OUTPUT_DELAY_1               (0x0004U) /* delay 1 cycle */
#define _0008_TO11_OUTPUT_DELAY_2               (0x0008U) /* delay 2 cycles */
#define _000C_TO11_OUTPUT_DELAY_3               (0x000CU) /* delay 3 cycles */
/* Control of PWM output delay time of TAU1 TO12 */
#define _0000_TO12_OUTPUT_DELAY_0               (0x0000U) /* no delay */
#define _0010_TO12_OUTPUT_DELAY_1               (0x0010U) /* delay 1 cycle */
#define _0020_TO12_OUTPUT_DELAY_2               (0x0020U) /* delay 2 cycles */
#define _0030_TO12_OUTPUT_DELAY_3               (0x0030U) /* delay 3 cycles */
/* Control of PWM output delay time of TAU1 TO13 */
#define _0000_TO13_OUTPUT_DELAY_0               (0x0000U) /* no delay */
#define _0040_TO13_OUTPUT_DELAY_1               (0x0040U) /* delay 1 cycle */
#define _0080_TO13_OUTPUT_DELAY_2               (0x0080U) /* delay 2 cycles */
#define _00C0_TO13_OUTPUT_DELAY_3               (0x00C0U) /* delay 3 cycles */

/*
    Noise Filter Enable Register 1 (NFEN1)
*/
/* Enable/disable using noise filter of TI07 pin input signal (TNFEN07) */
#define _00_TAU_CH7_NOISE_OFF                   (0x00U)   /* noise filter OFF */
#define _80_TAU_CH7_NOISE_ON                    (0x80U)   /* noise filter ON */
/* Enable/disable using noise filter of TI06 pin input signal (TNFEN06) */
#define _00_TAU_CH6_NOISE_OFF                   (0x00U)   /* noise filter OFF */
#define _40_TAU_CH6_NOISE_ON                    (0x40U)   /* noise filter ON */
/* Enable/disable using noise filter of TI05 pin input signal (TNFEN05) */
#define _00_TAU_CH5_NOISE_OFF                   (0x00U)   /* noise filter OFF */
#define _20_TAU_CH5_NOISE_ON                    (0x20U)   /* noise filter ON */
/* Enable/disable using noise filter of TI04 pin input signal (TNFEN04) */
#define _00_TAU_CH4_NOISE_OFF                   (0x00U)   /* noise filter OFF */
#define _10_TAU_CH4_NOISE_ON                    (0x10U)   /* noise filter ON */
/* Enable/disable using noise filter of TI03 pin input signal (TNFEN03) */
#define _00_TAU_CH3_NOISE_OFF                   (0x00U)   /* noise filter OFF */
#define _08_TAU_CH3_NOISE_ON                    (0x08U)   /* noise filter ON */
/* Enable/disable using noise filter of TI02 pin input signal (TNFEN02) */
#define _00_TAU_CH2_NOISE_OFF                   (0x00U)   /* noise filter OFF */
#define _04_TAU_CH2_NOISE_ON                    (0x04U)   /* noise filter ON */
/* Enable/disable using noise filter of TI01 pin input signal (TNFEN01) */
#define _00_TAU_CH1_NOISE_OFF                   (0x00U)   /* noise filter OFF */
#define _02_TAU_CH1_NOISE_ON                    (0x02U)   /* noise filter ON */
/* Enable/disable using noise filter of TI00 pin input signal (TNFEN00) */
#define _00_TAU_CH0_NOISE_OFF                   (0x00U)   /* noise filter OFF */
#define _01_TAU_CH0_NOISE_ON                    (0x01U)   /* noise filter ON */

/*
    Format of Peripheral Enable Register 1 (PER1)
*/
/* Control of timer RJ0 input clock supply (TRJ0EN) */
#define _00_TMRJ_CLOCK_STOP                     (0x00U)    /* stops input clock supply */
#define _01_TMRJ_CLOCK_ENABLE                   (0x01U)    /* enables input clock supply */

/* 
    Timer RJ Control Register (TRJCR0)
*/
/* Timer RJ count start bit (TSTART) */
#define _00_TMRJ_COUNT_STOP                     (0x00U)    /* count stops */
#define _01_TMRJ_COUNT_START                    (0x01U)    /* count starts */
/* Timer RJ count status flag (TCSTF) */
#define _00_TMRJ_STATUS_STOP                    (0x00U)    /* count stops */
#define _02_TMRJ_STATUS_COUNT                   (0x02U)    /* during count */
/* Timer RJ count forcible stop bit (TSTOP) */
#define _00_TMRJ_FORCIBLE_STOP_DISABLE          (0x00U)    /* the count is not forcibly stopped */
#define _04_TMRJ_FORCIBLE_STOP_ENABLE           (0x04U)    /* the count is forcibly stopped */
/* Active edge judgment flag (TEDGF) */
#define _00_TMRJ_ACTIVE_EDGE_RECEIVED           (0x00U)    /* active edge not received */
#define _10_TMRJ_ACTIVE_EDGE_UNRECEIVED         (0x10U)    /* active edge received (end of measurement period) */
/* Timer RJ underflow flag (TUNDF) */
#define _00_TMRJ_UNDERFLOW_NOOCCUR              (0x00U)    /* no underflow */
#define _20_TMRJ_UNDERFLOW_OCCUR                (0x20U)    /* underflow */

/* 
    Timer RJ I/O Control Register (TRJIOC0)
*/
#define _00_TMRJ_TRJIOC_INITIAL_VALUE           (0x00U)
/* TRJIO polarity switch bit (TEDGSEL) */
#define _00_TMRJ_TRJIO_POLARITY_0               (0x00U)    /* TRJIO polarity switch bit = 0  */
#define _01_TMRJ_TRJIO_POLARITY_1               (0x01U)    /* TRJIO polarity switch bit = 1 */
/* TRJO output enable bit (TOENA) */
#define _00_TMRJ_TRJO_OUTPUT_DISABLE            (0x00U)    /* TRJO output disable */
#define _04_TMRJ_TRJO_OUTPUT_ENABLE             (0x04U)    /* TRJO output */ 
/* TRJIO input filter select bit (TIPF1, TIPF0) */
#define _00_TMRJ_TRJIO_FILTER_UNUSED            (0x00U)    /* no filter */
#define _10_TMRJ_TRJIO_FILTER_FCLK              (0x10U)    /* filter with fCLK sampling */
#define _20_TMRJ_TRJIO_FILTER_FCLK8             (0x20U)    /* filter with fCLK/8 sampling */
#define _30_TMRJ_TRJIO_FILTER_FCLK32            (0x30U)    /* filter with fCLK/32 sampling */
/* TRJIO event input control bit (TIOGT1, TIOGT0) */
#define _00_TMRJ_EVENT_ENABLE_ALWAYS            (0x00U)    /* event is counted */
#define _40_TMRJ_EVENT_ENABLE_INTP4             (0x40U)    /* event is counted during INTP4 specified period */
#define _80_TMRJ_EVENT_ENABLE_PWM               (0x80U)    /* event is counted during PWM signal period */

/* 
    Timer RJ Mode Register (TRJMR0)
*/
/* Timer RJ operating mode select bit (TMOD2 - TMOD0) */
#define _00_TMRJ_MODE_TIMER                     (0x00U)    /* timer mode */
#define _01_TMRJ_MODE_PULSE_OUTPUT              (0x01U)    /* pulse output mode */
#define _02_TMRJ_MODE_EVENT_COUNTER             (0x02U)    /* event counter mode */
#define _03_TMRJ_MODE_PULSE_WIDTH               (0x03U)    /* pulse width measurement mode */
#define _04_TMRJ_MODE_PULSE_PERIOD              (0x04U)    /* pulse period measurement mode */
/* TRJIO input polarity select bit (TEDGPL) */
#define _00_TMRJ_TRJIO_POLARITY_ONE             (0x00U)    /* one edge */
#define _08_TMRJ_TRJIO_POLARITY_BOTH            (0x08U)    /* both edges */
/* Timer RJ count source select bit (TCK2 - TCK0) */
#define _00_TMRJ_COUNT_SOURCE_FCLK              (0x00U)    /* fCLK */
#define _10_TMRJ_COUNT_SOURCE_FCLK8             (0x10U)    /* fCLK8 */
#define _30_TMRJ_COUNT_SOURCE_FCLK2             (0x30U)    /* fCLK2 */
#define _40_TMRJ_COUNT_SOURCE_FIL               (0x40U)    /* fIL */
#define _60_TMRJ_COUNT_SOURCE_FSL               (0x60U)    /* fSL */

/*
    Timer RJ event pin selection register 0 (TRJISR0)
*/
/* PWM signal selection (RCCPSEL1, RCCPSEL0) */
#define _00_TMRJ_PWM_TRDIOD1                    (0x00U)    /* TRDIOD1 */
#define _01_TMRJ_PWM_TRDIOC1                    (0x01U)    /* TRDIOC1 */
#define _02_TMRJ_PWM_TO02                       (0x02U)    /* TO02 */
#define _03_TMRJ_PWM_TO03                       (0x03U)    /* TO03 */
/* PWM signal and INTP4 polarity selection (RCCPSEL2) */
#define _00_TMRJ_PWM_POLARITY_L                 (0x00U)    /* L period is counted */
#define _04_TMRJ_PWM_POLARITY_H                 (0x04U)    /* H period is counted */

/* 
     Peripheral enable register 1 (PER1)
*/
/* Control of timer RD input clock supply (TRD0EN) */
#define _00_TMRD_NOSUPPLY                       (0x00U)   /* stops input clock supply */
#define _10_TMRD_SUPPLY                         (0x10U)   /* enables input clock supply */

/* 
    Timer RD ELC Register (TRDELC)
*/
/* ELC event input 0 select for timer RD input capture D0 (ELCICE0) */
#define _00_TMRD0_INPUTCAPTURE                  (0x00U)   /* input capture D0 is selected */
#define _01_TMRD0_ELC                           (0x01U)   /* the event link controller (ELC) is not selected */
/* ELC event input 0 enable for timer RD pulse output forced cutoff (ELCOBE0) */
#define _00_TMRD0_CUTOFF_DISABLED               (0x00U)   /* forced cutoff is disabled */
#define _02_TMRD0_CUTOFF_ENABLED                (0x02U)   /* forced cutoff is enabled */
/* ELC event input 1 select for timer RD input capture D1 (ELCICE1) */
#define _00_TMRD1_INPUTCAPTURE                  (0x00U)   /* input capture D1 is selected */
#define _10_TMRD1_ELC                           (0x10U)   /* event link controller (ELC) is selected */
/* ELC event input 1 enable for timer RD pulse output forced cutoff (ELCOBE1) */
#define _00_TMRD1_CUTOFF_DISABLED               (0x00U)   /* forced cutoff is disabled */
#define _20_TMRD1_CUTOFF_ENABLED                (0x20U)   /* forced cutoff is enabled */

/*
    Timer RD Start Register (TRDSTR)
*/
#define _03_TRD_COUNT_STATR_INITIAL_VALUE       (0x03U)   /* trd0/trd1 count satrts */
/* TRD0 count start flag (TSTART0) */
#define _00_TMRD_TRD0_COUNT_STOP                (0x00U)   /* trd0 count stops */
#define _01_TMRD_TRD0_COUNT_START               (0x01U)   /* trd0 count starts */
/* TRD1 count start flag (TSTART1) */
#define _00_TMRD_TRD1_COUNT_STOP                (0x00U)   /* trd1 count stops */
#define _02_TMRD_TRD1_COUNT_START               (0x02U)   /* trd1 count starts */
/* TRD0 count operation select bit (CSEL0) */
#define _00_TMRD_TRD0_COUNT_STOP_MATCH          (0x00U)   /* count stops at the compare match */
#define _04_TMRD_TRD0_COUNT_CONTINUES           (0x04U)   /* count continues after the compare match */
/* TRD1 count operation select bit (CSEL1) */
#define _00_TMRD_TRD1_COUNT_STOP_MATCH          (0x00U)   /* count stops at the compare match */
#define _08_TMRD_TRD1_COUNT_CONTINUES           (0x08U)   /* count continues after the compare match */

/* 
    Timer RD Mode Register (TRDMR)
*/
/* Timer RD synchronous bit (SYNC) */
#define _00_TMRD_INDEPENDENTLY                  (0x00U)   /* registers TRD0 and TRD1 operate independently */
#define _01_TMRD_SYNCHRONOUSLY                  (0x01U)   /* registers TRD0 and TRD1 operate synchronously */
/* TRDGRC0 register function select bit (BFC0) */
#define _00_TMRD_TRDGRC0_GENERAL                (0x00U)   /* general register */
#define _10_TMRD_TRDGRC0_BUFFER                 (0x10U)   /* buffer register of TRDGRA0 register */
/* TRDGRD0 register function select bit (BFD0) */
#define _00_TMRD_TRDGRD0_GENERAL                (0x00U)   /* general register */
#define _20_TMRD_TRDGRD0_BUFFER                 (0x20U)   /* buffer register of TRDGRB0 register */
/* TRDGRC1 register function select bit (BFC1) */
#define _00_TMRD_TRDGRC1_GENERAL                (0x00U)   /* general register */
#define _40_TMRD_TRDGRC1_BUFFER                 (0x40U)   /* buffer register of TRDGRA1 register */
/* TRDGRD1 register function select bit (BFD1) */
#define _00_TMRD_TRDGRD1_GENERAL                (0x00U)   /* general register */
#define _80_TMRD_TRDGRD1_BUFFER                 (0x80U)   /* buffer register of TRDGRB1 register */

/* 
    Timer RD PWM Mode Register (TRDPMR)
*/
/* PWM mode of TRDIOB0 select bit (PWMB0) */
#define _00_TMRD_TRDIOB0_TIMER_MODE             (0x00U)   /* TRDIOB0 used as timer mode */
#define _01_TMRD_TRDIOB0_PWM_MODE               (0x01U)   /* TRDIOB0 used as PWM mode */
/* PWM mode of TRDIOC0 select bit (PWMC0) */
#define _00_TMRD_TRDIOC0_TIMER_MODE             (0x00U)   /* TRDIOC0 used as timer mode */
#define _02_TMRD_TRDIOC0_PWM_MODE               (0x02U)   /* TRDIOC0 used as PWM mode */
/* PWM mode of TRDIOD0 select bit (PWMD0) */
#define _00_TMRD_TRDIOD0_TIMER_MODE             (0x00U)   /* TRDIOD0 used as timer mode */
#define _04_TMRD_TRDIOD0_PWM_MODE               (0x04U)   /* TRDIOD0 used as PWM mode */
/* PWM mode of TRDIOB1 select bit (PWMB1) */
#define _00_TMRD_TRDIOB1_TIMER_MODE             (0x00U)   /* TRDIOB1 used as timer mode */
#define _10_TMRD_TRDIOB1_PWM_MODE               (0x10U)   /* TRDIOB1 used as PWM mode */
/* PWM mode of TRDIOC1 select bit (PWMC1) */
#define _00_TMRD_TRDIOC1_TIMER_MODE             (0x00U)   /* TRDIOC1 used as timer mode */
#define _20_TMRD_TRDIOC1_PWM_MODE               (0x20U)   /* TRDIOC1 used as PWM mode */
/* PWM mode of TRDIOD1 select bit (PWMD1) */
#define _00_TMRD_TRDIOD1_TIMER_MODE             (0x00U)   /* TRDIOD1 used as timer mode */
#define _40_TMRD_TRDIOD1_PWM_MODE               (0x40U)   /* TRDIOD1 used as PWM mode */

/* 
    Timer RD Function Control Register (TRDFCR)
*/
/* Combination mode select bit (CMD1, CMD0) */
#define _00_TMRD_TRANSFER_DEFAULT               (0x00U)   /* in timer mode, PWM mode, or PWM3 mode */
#define _01_TMRD_TRANSFER_RESET_SYNCHRONOUS     (0x01U)   /* in reset synchronous PWM mode */
#define _02_TMRD_TRANSFER_TMRD1_UNDERFLOW       (0x02U)   /* transfer from buffer register to general register */
#define _03_TMRD_TRANSFER_TMRD0_MATCH           (0x03U)   /* transfer from buffer register to general register */
/* Normal-phase output level select bit (OLS0) */
#define _00_TMRD_NORMAL_PHASE_LEVEl_HL          (0x00U)   /* initial output "H", Active level "L" */
#define _04_TMRD_NORMAL_PHASE_LEVEl_LH          (0x04U)   /* initial output "L", Active level "H" */
/* Counter-phase output level select bit (OLS1) */
#define _00_TMRD_COUNTER_PHASE_LEVEl_HL         (0x00U)   /* initial output "H", Active level "L" */
#define _08_TMRD_COUNTER_PHASE_LEVEl_LH         (0x08U)   /* initial output "L", Active level "H" */
/* External clock input select bit (STCLK) */
#define _00_TMRD_EXTERNAL_CLOCK_DISABLE         (0x00U)   /* external clock input disabled */
#define _40_TMRD_EXTERNAL_CLOCK_ENABLE          (0x40U)   /* external clock input enabled  */
/* PWM3 mode select bit (PWM3) */   
#define _00_TMRD_PWM3_MODE                      (0x00U)   /* PWM3 mode */
#define _80_TMRD_OTHER_MODE                     (0x80U)   /* other mode */

/* 
    Timer RD Output Master Enable Register 1 (TRDOER1)
*/
#define _F0_TMRD_CHANNEL0_OUTPUT_DEFAULT        (0xF0U)
#define _0F_TMRD_CHANNEL1_OUTPUT_DEFAULT        (0x0FU)
/* TRDIOA0 output disable bit (EA0) */
#define _00_TMRD_TRDIOA0_OUTPUT_ENABLE          (0x00U)   /* enable output */
#define _01_TMRD_TRDIOA0_OUTPUT_DISABLE         (0x01U)   /* disable output */
/* TRDIOB0 output disable bit (EB0) */
#define _00_TMRD_TRDIOB0_OUTPUT_ENABLE          (0x00U)   /* enable output */
#define _02_TMRD_TRDIOB0_OUTPUT_DISABLE         (0x02U)   /* disable output */
/* TRDIOC0 output disable bit (EC0) */
#define _00_TMRD_TRDIOC0_OUTPUT_ENABLE          (0x00U)   /* enable output */
#define _04_TMRD_TRDIOC0_OUTPUT_DISABLE         (0x04U)   /* disable output */
/* TRDIOD0 output disable bit (ED0) */
#define _00_TMRD_TRDIOD0_OUTPUT_ENABLE          (0x00U)   /* enable output */
#define _08_TMRD_TRDIOD0_OUTPUT_DISABLE         (0x08U)   /* disable output */
/* TRDIOA1 output disable bit (EA1) */
#define _00_TMRD_TRDIOA1_OUTPUT_ENABLE          (0x00U)   /* enable output */
#define _10_TMRD_TRDIOA1_OUTPUT_DISABLE         (0x10U)   /* disable output */
/* TRDIOB1 output disable bit (EB1) */
#define _00_TMRD_TRDIOB1_OUTPUT_ENABLE          (0x00U)   /* enable output */
#define _20_TMRD_TRDIOB1_OUTPUT_DISABLE         (0x20U)   /* disable output */
/* TRDIOC1 output disable bit (EC1) */
#define _00_TMRD_TRDIOC1_OUTPUT_ENABLE          (0x00U)   /* enable output */
#define _40_TMRD_TRDIOC1_OUTPUT_DISABLE         (0x40U)   /* disable output */
/* TRDIOD1 output disable bit (ED1) */
#define _00_TMRD_TRDIOD1_OUTPUT_ENABLE          (0x00U)   /* enable output */
#define _80_TMRD_TRDIOD1_OUTPUT_DISABLE         (0x80U)   /* disable output */

/* 
    Timer RD Output Master Enable Register 2 (TRDOER2)
*/
/* INT0 of pulse output forced cutoff signal input enabled bit (PTO) */
#define _00_TMRD_ALL_OUTPUT_DISABLE             (0x00U)   /* pulse output forced cutoff input disabled */
#define _80_TMRD_ALL_OUTPUT_ENABLE              (0x80U)   /* pulse output forced cutoff input enabled */
/* Forced cutoff flag (SHUTS) */
#define _00_TMRD_INTERCEPTION_STOP              (0x00U)   /* not forcibly cut off */
#define _01_TMRD_INTERCEPTION                   (0x01U)   /* forcibly cut off */

/* 
    Timer RD Output Control Register (TRDOCR)
*/
/* TRDIOA0 output level select bit (TOA0) */
#define _00_TMRD_TRDIOA0_INITIAL_OUTPUT_L       (0x00U)   /* initial output "L" or inactive level */
#define _01_TMRD_TRDIOA0_INITIAL_OUTPUT_H       (0x01U)   /* initial output "H" or active level */
/* TRDIOB0 output level select bit (TOB0) */
#define _00_TMRD_TRDIOB0_INITIAL_OUTPUT_L       (0x00U)   /* initial output "L" or inactive level */
#define _02_TMRD_TRDIOB0_INITIAL_OUTPUT_H       (0x02U)   /* initial output "H" or active level */
/* TRDIOC0 output level select bit (TOC0) */
#define _00_TMRD_TRDIOC0_INITIAL_OUTPUT_L       (0x00U)   /* initial output "L" or inactive level */
#define _04_TMRD_TRDIOC0_INITIAL_OUTPUT_H       (0x04U)   /* initial output "H" or active level */
/* TRDIOD0 output level select bit (TOD0) */
#define _00_TMRD_TRDIOD0_INITIAL_OUTPUT_L       (0x00U)   /* initial output "L" or inactive level */
#define _08_TMRD_TRDIOD0_INITIAL_OUTPUT_H       (0x08U)   /* initial output "H" or active level */
/* TRDIOA1 output level select bit (TOA1) */
#define _00_TMRD_TRDIOA1_INITIAL_OUTPUT_L       (0x00U)   /* initial output "L" or inactive level */
#define _10_TMRD_TRDIOA1_INITIAL_OUTPUT_H       (0x10U)   /* initial output "H" or active level */
/* TRDIOB1 output level select bit (TOB1) */
#define _00_TMRD_TRDIOB1_INITIAL_OUTPUT_L       (0x00U)   /* initial output "L" or inactive level */
#define _20_TMRD_TRDIOB1_INITIAL_OUTPUT_H       (0x20U) /* initial output "H" or active level */
/* TRDIOC1 output level select bit (TOC1) */
#define _00_TMRD_TRDIOC1_INITIAL_OUTPUT_L       (0x00U)   /* initial output "L" or inactive level */
#define _40_TMRD_TRDIOC1_INITIAL_OUTPUT_H       (0x40U)   /* initial output "H" or active level */
/* TRDIOD1 output level select bit (TOD1) */
#define _00_TMRD_TRDIOD1_INITIAL_OUTPUT_L       (0x00U)   /* initial output "L" or inactive level */
#define _80_TMRD_TRDIOD1_INITIAL_OUTPUT_H       (0x80U)   /* initial output "H" or active level */

/* 
    Timer RD Digital Filter Function Select Register i (TRDDFi)
*/
/* TRDIOA pin digital filter function select bit (DFA) */
#define _00_TMRD_TRDIOA_DIGITAL_FILTER_DISABLE  (0x00U)   /* TRDIOA pin digital filter function is not used */
#define _01_TMRD_TRDIOA_DIGITAL_FILTER_ENABLE   (0x01U)   /* TRDIOA pin digital filter function is used */
/* TRDIOB pin digital filter function select bit (DFB) */
#define _00_TMRD_TRDIOB_DIGITAL_FILTER_DISABLE  (0x00U)   /* TRDIOB pin digital filter function is not used */
#define _02_TMRD_TRDIOB_DIGITAL_FILTER_ENABLE   (0x02U)   /* TRDIOB pin digital filter function is used */
/* TRDIOD pin pulse forced cutoff control (DFB, DFA) */
#define _00_TMRD_TRDIOD_FORCEDCUTOFF_DISABLE    (0x00U)   /* forced cutoff disabled */
#define _01_TMRD_TRDIOD_HIGHIMPEDANCE_OUTPUT    (0x01U)   /* high-impedance output */
#define _02_TMRD_TRDIOD_LOW_OUTPUT              (0x02U)   /* low output */
#define _03_TMRD_TRDIOD_HIGH_OUTPUT             (0x03U)   /* high output */
/* TRDIOC pin digital filter function select bit (DFC) */
#define _00_TMRD_TRDIOC_DIGITAL_FILTER_DISABLE  (0x00U)   /* TRDIOC pin digital filter function is not used */
#define _04_TMRD_TRDIOC_DIGITAL_FILTER_ENABLE   (0x04U)   /* TRDIOC pin digital filter function is used */
/* TRDIOD pin digital filter function select bit (DFD) */
#define _00_TMRD_TRDIOD_DIGITAL_FILTER_DISABLE  (0x00U)   /* TRDIOD pin digital filter function is not used */
#define _08_TMRD_TRDIOD_DIGITAL_FILTER_ENABLE   (0x08U)   /* TRDIOD pin digital filter function is used */
/* TRDIOC pin pulse forced cutoff control (DFD, DFC) */
#define _00_TMRD_TRDIOC_FORCEDCUTOFF_DISABLE    (0x00U)   /* forced cutoff disabled */
#define _04_TMRD_TRDIOC_HIGHIMPEDANCE_OUTPUT    (0x04U)   /* high-impedance output */
#define _08_TMRD_TRDIOC_LOW_OUTPUT              (0x08U)   /* low output */
#define _0C_TMRD_TRDIOC_HIGH_OUTPUT             (0x0CU)   /* high output */
/* TRDIOB pin pulse forced cutoff control (PENB1, PENB0) */
#define _00_TMRD_TRDIOB_FORCEDCUTOFF_DISABLE    (0x00U)   /* forced cutoff disabled */
#define _10_TMRD_TRDIOB_HIGHIMPEDANCE_OUTPUT    (0x10U)   /* high-impedance output */
#define _20_TMRD_TRDIOB_LOW_OUTPUT              (0x20U)   /* low output */
#define _30_TMRD_TRDIOB_HIGH_OUTPUT             (0x30U)   /* high output */
/* Clock select bits for digital filter function (DFCK1, DFCK0) */
#define _00_TMRD_DIGITAL_FILTER_CLOCK_F32       (0x00U)   /* fCLK/2^5 */
#define _40_TMRD_DIGITAL_FILTER_CLOCK_F8        (0x40U)   /* fCLK/2^3 */
#define _80_TMRD_DIGITAL_FILTER_CLOCK_F1        (0x80U)   /* fCLK */
#define _C0_TMRD_DIGITAL_FILTER_CLOCK_SOURCE    (0xC0U)   /* count source */
/* TRDIOA pin pulse forced cutoff control (DFCK1, DFCK0) */
#define _00_TMRD_TRDIOA_FORCEDCUTOFF_DISABLE    (0x00U)   /* forced cutoff disabled */
#define _40_TMRD_TRDIOA_HIGHIMPEDANCE_OUTPUT    (0x40U)   /* high-impedance output */
#define _80_TMRD_TRDIOA_LOW_OUTPUT              (0x80U)   /* low output */
#define _C0_TMRD_TRDIOA_HIGH_OUTPUT             (0xC0U)   /* high output */

/* 
    Timer RD Control Register i (TRDCRi)
*/
/* Count source select bit (TCK2 - TCK0) */
#define _00_TMRD_INTERNAL_CLOCK_F1              (0x00U)   /* fCLK */
#define _00_TMRD_INTERNAL_CLOCK_FIH             (0x00U)   /* fIH */
#define _00_TMRD_INTERNAL_CLOCK_FPLL            (0x00U)   /* fPLL */
#define _00_TMRD_INTERNAL_CLOCK_FSL             (0x00U)   /* fSL */
#define _01_TMRD_INTERNAL_CLOCK_F2              (0x01U)   /* fCLK/2 */
#define _02_TMRD_INTERNAL_CLOCK_F4              (0x02U)   /* fCLK/2^2 */
#define _03_TMRD_INTERNAL_CLOCK_F8              (0x03U)   /* fCLK/2^3 */
#define _04_TMRD_INTERNAL_CLOCK_F32             (0x04U)   /* fCLK/2^5 */
#define _05_TMRD_INTERNAL_CLOCK_TRDCLK          (0x05U)   /* TRDCLK input */
/* External clock edge select bit (CKEG1, CKEG0) */
#define _00_TMRD_EXTERNAL_CLOCK_EDGE_RISING     (0x00U)   /* count at the rising edge */
#define _08_TMRD_EXTERNAL_CLOCK_EDGE_FALLING    (0x08U)   /* count at the falling edge */
#define _10_TMRD_EXTERNAL_CLOCK_EDGE_BOTH       (0x10U)   /* count at both edges */
/* TRDi counter clear select bit (CCLR2 - CCLR0) */
#define _00_TMRD_COUNTER_CLEAR_DISABLE          (0x00U)   /* disable clear (free-running operation) */
#define _20_TMRD_COUNTER_CLEAR_TRDGRA           (0x20U)   /* clear with the TRDGRAi register */
#define _40_TMRD_COUNTER_CLEAR_TRDGRB           (0x40U)   /* clear with the TRDGRBi register */
#define _60_TMRD_COUNTER_CLEAR_SYNCHRONOUS      (0x60U)   /* synchronous clear */
#define _A0_TMRD_COUNTER_CLEAR_TRDGRC           (0xA0U)   /* clear by input capture with TRDGRCi register */
#define _C0_TMRD_COUNTER_CLEAR_TRDGRD           (0xC0U)   /* clear by input capture with TRDGRDi register */

/* 
    Timer RD I/O Control Register Ai (TRDIORAi)
*/
/* TRDGRA control bit (IOA1, IOA0) */
#define _00_TMRD_TRDGRA_CAPTURE_RISING          (0x00U)   /* input capture to the TRDGRAi register at the rising edge */
#define _01_TMRD_TRDGRA_CAPTURE_FALLING         (0x01U)   /* input capture to TRDGRAi register at falling edge */
#define _02_TMRD_TRDGRA_CAPTURE_BOTH            (0x02U)   /* input capture to the TRDGRAi register at the both edges */
#define _00_TMRD_TRDGRA_COMPARE_OUTPUT_DISABLE  (0x00U)   /* pin output by compare match is disabled */
#define _01_TMRD_TRDGRA_COMPARE_OUTPUT_LOW      (0x01U)   /* "L" output by compare match with the TRDGRAi register */
#define _02_TMRD_TRDGRA_COMPARE_OUTPUT_HIGH     (0x02U)   /* "H" output by compare match with the TRDGRAi register */
#define _03_TMRD_TRDGRA_COMPARE_OUTPUT_TOGGLE   (0x03U)   /* toggle output by compare match with the TRDGRAi register */
/* TRDGRA mode select bit (IOA2) */
#define _00_TMRD_TRDGRA_COMPARE                 (0x00U)   /* output compare */
#define _04_TMRD_TRDGRA_CAPTURE                 (0x04U)   /* input capture */
/* TRDGRB control bit (IOB1, IOB0) */
#define _00_TMRD_TRDGRB_CAPTURE_RISING          (0x00U)   /* input capture to the TRDGRBi register at the rising edge */
#define _10_TMRD_TRDGRB_CAPTURE_FALLING         (0x10U)   /* input capture to TRDGRBi register at falling edge */
#define _20_TMRD_TRDGRB_CAPTURE_BOTH            (0x20U)   /* input capture to the TRDGRBi register at the both edges */
#define _00_TMRD_TRDGRB_COMPARE_OUTPUT_DISABLE  (0x00U)   /* disable output prohibition by compare agreement */
#define _10_TMRD_TRDGRB_COMPARE_OUTPUT_LOW      (0x10U)   /* "L" output by compare match with the TRDGRBi register */
#define _20_TMRD_TRDGRB_COMPARE_OUTPUT_HIGH     (0x20U)   /* "H" output by compare match with the TRDGRBi register */
#define _30_TMRD_TRDGRB_COMPARE_OUTPUT_TOGGLE   (0x30U)   /* toggle output by compare match with the TRDGRBi register */
/* TRDGRB mode select bit (IOB2) */
#define _00_TMRD_TRDGRB_COMPARE                 (0x00U)   /* output compare */
#define _40_TMRD_TRDGRB_CAPTURE                 (0x40U)   /* input capture */

/* 
    Timer RD I/O Control Register Ci (TRDIORCi)
*/
/* TRDGRC control bit (IOC1, IOC0) */
#define _00_TMRD_TRDGRC_CAPTURE_RISING          (0x00U)   /* input capture to the TRDGRCi register at rising edge */
#define _01_TMRD_TRDGRC_CAPTURE_FALLING         (0x01U)   /* input capture to TRDGRCi register at falling edge */
#define _02_TMRD_TRDGRC_CAPTURE_BOTH            (0x02U)   /* input capture to the TRDGRCi register at the both edges */
#define _00_TMRD_TRDGRC_COMPARE_OUTPUT_DISABLE  (0x00U)   /* disable pin output by the compare match */
#define _01_TMRD_TRDGRC_COMPARE_OUTPUT_LOW      (0x01U)   /* "L" output by compare match with the TRDGRCi register */
#define _02_TMRD_TRDGRC_COMPARE_OUTPUT_HIGH     (0x02U)   /* "H" output by compare match with the TRDGRCi register */
#define _03_TMRD_TRDGRC_COMPARE_OUTPUT_TOGGLE   (0x03U)   /* toggle output by compare match with the TRDGRCi register */
/* TRDGRC mode select bit (IOC2) */
#define _00_TMRD_TRDGRC_COMPARE                 (0x00U)   /* output compare */
#define _04_TMRD_TRDGRC_CAPTURE                 (0x04U)   /* input capture */
/* TRDGRC register function select bit (IOC3) */
#define _00_TMRD_TRDGRC_OUTPUT_REGISTER         (0x00U)   /* output register */
#define _08_TMRD_TRDGRC_GENERAL_BUFFER_REGISTER (0x08U)   /* general register or buffer register */
/* TRDGRD control bit (IOD1, IOD0) */
#define _00_TMRD_TRDGRD_CAPTURE_RISING          (0x00U)   /* input capture to TRDGRDi register at rising edge */
#define _10_TMRD_TRDGRD_CAPTURE_FALLING         (0x10U)   /* input capture to TRDGRDi register at falling edge */
#define _20_TMRD_TRDGRD_CAPTURE_BOTH            (0x20U)   /* input capture to TRDGRDi register at both edges */
#define _00_TMRD_TRDGRD_COMPARE_OUTPUT_DISABLE  (0x00U)   /* disable pin output by the compare match */
#define _10_TMRD_TRDGRD_COMPARE_OUTPUT_LOW      (0x10U)   /* "L" output by compare match with the TRDGRDi register */
#define _20_TMRD_TRDGRD_COMPARE_OUTPUT_HIGH     (0x20U)   /* "H" output by compare match with the TRDGRDi register */
#define _30_TMRD_TRDGRD_COMPARE_OUTPUT_TOGGLE   (0x30U)   /* toggle output by compare match with the TRDGRDi register */
/* TRDGRD mode select bit (IOD2) */
#define _00_TMRD_TRDGRD_COMPARE                 (0x00U)   /* output compare */
#define _40_TMRD_TRDGRD_CAPTURE                 (0x40U)   /* input capture */
/* TRDGRD register function select bit (IOD3) */
#define _00_TMRD_TRDGRD_OUTPUT_REGISTER         (0x00U)   /* output register */
#define _80_TMRD_TRDGRD_GENERAL_BUFFER_REGISTER (0x80U)   /* general register or buffer register */

/* 
    Timer RD Status Register 0 (TRDSR0)
*/
#define _E0_TMRD_TRDSR0_DEFAULT_VALUR           (0xE0U)   /* TRDSR0 register default value */
/* Input capture/compare match flag A (IMFA) */
#define _00_TMRD0_INTA_FLAG_CLEAR               (0x00U)   /* interrupt A not generate */
#define _01_TMRD0_INTA_GENERATE_FLAG            (0x01U)   /* interrupt A generate */
/* Input capture/compare match flag B (IMFB) */
#define _00_TMRD0_INTB_FLAG_CLEAR               (0x00U)   /* interrupt B not generate */
#define _02_TMRD0_INTB_GENERATE_FLAG            (0x02U)   /* interrupt B generate */
/* Input capture/compare match flag C (IMFC) */
#define _00_TMRD0_INTC_FLAG_CLEAR               (0x00U)   /* interrupt C not generate */
#define _04_TMRD0_INTC_GENERATE_FLAG            (0x04U)   /* interrupt C generate */
/* Input capture/compare match flag D (IMFD) */
#define _00_TMRD0_INTD_FLAG_CLEAR               (0x00U)   /* interrupt D not generate */
#define _08_TMRD0_INTD_GENERATE_FLAG            (0x08U)   /* interrupt D generate */
/* Overflow flag (OVF) */
#define _00_TMRD0_INTOV_FLAG_CLEAR              (0x00U)   /* interrupt overflow not generate */
#define _10_TMRD0_INTOV_GENERATE_FLAG           (0x10U)   /* interrupt overflow generate */

/* 
    Timer RD Status Register 1 (TRDSR1)
*/
#define _C0_TMRD_TRDSR1_DEFAULT_VALUR           (0xC0U)   /* TRDSR1 register default value */
/* Input capture/compare match flag A (IMFA) */
#define _00_TMRD1_INTA_FLAG_CLEAR               (0x00U)   /* interrupt A not generate */
#define _01_TMRD1_INTA_GENERATE_FLAG            (0x01U)   /* interrupt A generate */
/* Input capture/compare match flag B (IMFB) */
#define _00_TMRD1_INTB_FLAG_CLEAR               (0x00U)   /* interrupt B not generate */
#define _02_TMRD1_INTB_GENERATE_FLAG            (0x02U)   /* interrupt B generate */
/* Input capture/compare match flag C (IMFC) */
#define _00_TMRD1_INTC_FLAG_CLEAR               (0x00U)   /* interrupt C not generate */
#define _04_TMRD1_INTC_GENERATE_FLAG            (0x04U)   /* interrupt C generate */
/* Input capture/compare match flag D (IMFD) */
#define _00_TMRD1_INTD_FLAG_CLEAR               (0x00U)   /* interrupt D not generate */
#define _08_TMRD1_INTD_GENERATE_FLAG            (0x08U)   /* interrupt D generate */
/* Overflow flag (OVF) */
#define _00_TMRD1_INTOV_FLAG_CLEAR              (0x00U)   /* interrupt overflow not generate */
#define _10_TMRD1_INTOV_GENERATE_FLAG           (0x10U)   /* interrupt overflow generate */

/* 
    Timer RD Interrupt Enable Register i (TRDIERi)
*/
/* Input capture/compare match interrupt enable bit A (IMIEA) */
#define _00_TMRD_IMIA_DISABLE                   (0x00U)   /* disable interrupt (IMIA) by the IMFA bit */
#define _01_TMRD_IMIA_ENABLE                    (0x01U)   /* enable interrupt (IMIA) by the IMFA bit */
/* Input capture/compare match interrupt enable bit B (IMIEB) */
#define _00_TMRD_IMIB_DISABLE                   (0x00U)   /* disable interrupt (IMIB) by the IMFB bit */
#define _02_TMRD_IMIB_ENABLE                    (0x02U)   /* enable interrupt (IMIB) by the IMFB bit */
/* Input capture/compare match interrupt enable bit C (IMIEC) */
#define _00_TMRD_IMIC_DISABLE                   (0x00U)   /* disable interrupt (IMIC) by the IMFC bit */
#define _04_TMRD_IMIC_ENABLE                    (0x04U)   /* enable interrupt (IMIC) by the IMFC bit */
/* Input capture/compare match interrupt enable bit D (IMIED) */
#define _00_TMRD_IMID_DISABLE                   (0x00U)   /* disable interrupt (IMID) by the IMFD bit */
#define _08_TMRD_IMID_ENABLE                    (0x08U)   /* enable interrupt (IMId) by the IMFD bit */
/* Overflow/underflow interrupt enable bit (OVIE) */
#define _00_TMRD_OVIE_DISABLE                   (0x00U)   /* disable interrupt (OVI) by the OVF or UDF bit */
#define _10_TMRD_OVIE_ENABLE                    (0x10U)   /* enable interrupt (OVI) by the OVF or UDF bit */

#define _0000_TMRD_PWM_DELAY_CLEAR              (0x0000U) /* clear PWM output delay control register */

/*
    PWM output delay control register 0 (PWMDLY0)
*/
/* Control of PWM output delay time of TRDIOA0 */
#define _0000_TMRD_TRDIOA0_OUTPUT_DELAY_0       (0x0000U) /* no delay */
#define _0001_TMRD_TRDIOA0_OUTPUT_DELAY_1       (0x0001U) /* delay 1 cycle */
#define _0002_TMRD_TRDIOA0_OUTPUT_DELAY_2       (0x0002U) /* delay 2 cycles */
#define _0003_TMRD_TRDIOA0_OUTPUT_DELAY_3       (0x0003U) /* delay 3 cycles */
/* Control of PWM output delay time of TRDIOB0 */
#define _0000_TMRD_TRDIOB0_OUTPUT_DELAY_0       (0x0000U) /* no delay */
#define _0004_TMRD_TRDIOB0_OUTPUT_DELAY_1       (0x0004U) /* delay 1 cycle */
#define _0008_TMRD_TRDIOB0_OUTPUT_DELAY_2       (0x0008U) /* delay 2 cycles */
#define _000C_TMRD_TRDIOB0_OUTPUT_DELAY_3       (0x000CU) /* delay 3 cycles */
/* Control of PWM output delay time of TRDIOC0 */
#define _0000_TMRD_TRDIOC0_OUTPUT_DELAY_0       (0x0000U) /* no delay */
#define _0010_TMRD_TRDIOC0_OUTPUT_DELAY_1       (0x0010U) /* delay 1 cycle */
#define _0020_TMRD_TRDIOC0_OUTPUT_DELAY_2       (0x0020U) /* delay 2 cycles */
#define _0030_TMRD_TRDIOC0_OUTPUT_DELAY_3       (0x0030U) /* delay 3 cycles */
/* Control of PWM output delay time of TRDIOD0 */
#define _0000_TMRD_TRDIOD0_OUTPUT_DELAY_0       (0x0000U) /* no delay */
#define _0040_TMRD_TRDIOD0_OUTPUT_DELAY_1       (0x0040U) /* delay 1 cycle */
#define _0080_TMRD_TRDIOD0_OUTPUT_DELAY_2       (0x0080U) /* delay 2 cycles */
#define _00C0_TMRD_TRDIOD0_OUTPUT_DELAY_3       (0x00C0U) /* delay 3 cycles */
/* Control of PWM output delay time of TRDIOA1 */
#define _0000_TMRD_TRDIOA1_OUTPUT_DELAY_0       (0x0000U) /* no delay */
#define _0100_TMRD_TRDIOA1_OUTPUT_DELAY_1       (0x0100U) /* delay 1 cycle */
#define _0200_TMRD_TRDIOA1_OUTPUT_DELAY_2       (0x0200U) /* delay 2 cycles */
#define _0300_TMRD_TRDIOA1_OUTPUT_DELAY_3       (0x0300U) /* delay 3 cycles */
/* Control of PWM output delay time of TRDIOB1 */
#define _0000_TMRD_TRDIOB1_OUTPUT_DELAY_0       (0x0000U) /* no delay */
#define _0400_TMRD_TRDIOB1_OUTPUT_DELAY_1       (0x0400U) /* delay 1 cycle */
#define _0800_TMRD_TRDIOB1_OUTPUT_DELAY_2       (0x0800U) /* delay 2 cycles */
#define _0C00_TMRD_TRDIOB1_OUTPUT_DELAY_3       (0x0C00U) /* delay 3 cycles */
/* Control of PWM output delay time of TRDIOC1 */
#define _0000_TMRD_TRDIOC1_OUTPUT_DELAY_0       (0x0000U) /* no delay */
#define _1000_TMRD_TRDIOC1_OUTPUT_DELAY_1       (0x1000U) /* delay 1 cycle */
#define _2000_TMRD_TRDIOC1_OUTPUT_DELAY_2       (0x2000U) /* delay 2 cycles */
#define _3000_TMRD_TRDIOC1_OUTPUT_DELAY_3       (0x3000U) /* delay 3 cycles */
/* Control of PWM output delay time of TRDIOD1 */
#define _0000_TMRD_TRDIOD1_OUTPUT_DELAY_0       (0x0000U) /* no delay */
#define _4000_TMRD_TRDIOD1_OUTPUT_DELAY_1       (0x4000U) /* delay 1 cycle */
#define _8000_TMRD_TRDIOD1_OUTPUT_DELAY_2       (0x8000U) /* delay 2 cycles */
#define _C000_TMRD_TRDIOD1_OUTPUT_DELAY_3       (0xC000U) /* delay 3 cycles */

/* 
    Timer RD PWM Mode Output Level Control Register i (TRDPOCRi)
*/
/* PWM mode output level control bit B (POLB) */
#define _00_TMRD_TRDIOB_OUTPUT_ACTIVE_L         (0x00U)   /* "L" active TRDIOBi output level is selected */
#define _01_TMRD_TRDIOB_OUTPUT_ACTIVE_H         (0x01U)   /* "H" active TRDIOBi output level is selected */
/* PWM mode output level control bit C (POLC) */
#define _00_TMRD_TRDIOC_OUTPUT_ACTIVE_L         (0x00U)   /* "L" active TRDIOCi output level is selected */
#define _02_TMRD_TRDIOC_OUTPUT_ACTIVE_H         (0x02U)   /* "H" active TRDIOCi output level is selected */
/* PWM mode output level control bit D (POLD) */
#define _00_TMRD_TRDIOD_OUTPUT_ACTIVE_L         (0x00U)   /* "L" active TRDIODi output level is selected */
#define _04_TMRD_TRDIOD_OUTPUT_ACTIVE_H         (0x04U)   /* "H" active TRDIODi output level is selected */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
/* 16-bit timer data register 00 (TDR00) */
#define _9C3F_TAU_TDR00_VALUE                   (0x9C3FU)
/* Clock divisor for TAU0 channel 0 */
#define _0008_TAU0_CHANNEL0_DIVISOR             (0x0008U)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/
typedef enum
{
    TMCHANNELA,
    TMCHANNELB,
    TMCHANNELC,
    TMCHANNELD,
    TMCHANNELELC
} timer_channel_t;

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_TAU0_Create(void);
void R_TAU0_Channel0_Start(void);
void R_TAU0_Channel0_Stop(void);

/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
