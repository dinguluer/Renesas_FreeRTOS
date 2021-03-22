#include "device.h"
//#include "../../device_device_file_download/device.h"
#include "../typeDefine.h"

#define MAIN_OSC_8MHZ  1
//#define MAIN_OSC_16MHZ  1
//#define MAIN_OSC_20MHZ  1

//============================================================================
// Sub Functions
//============================================================================

void init_clocks(void)
{
#if MAIN_OSC_8MHZ

    /*********** Enable HS ON-chip Oscillator -- to provide clock for -- Main Oscillator controller & PLLk controller *********************************/

        /* Stable and active fRH clock is indicated by ROSCS.ROSCCLKACT = 1 */
      if((CLKCTL.ROSCS&0x04u) != 0x4u)                                       /* Check if MainOsc needs to be started */
      {
          //unstop the HS On chip oscillator -- ROSCDISTRG = 0;
          protected_write_test(WPROTR.PROTCMD0, WPROTR.PROTS0,CLKCTL.ROSCE,0x00000000UL);
          //Stable and active fRH clock is indicated by ROSCS.ROSCCLKACT = 1
          while((CLKCTL.ROSCS & 0x04)!= 0x04u);
      }
      asm("nop");


    /*********** Enable MAIN Oscillator *********************************/
      /* Prepare 8MHz MainOsc */
    if((CLKCTL.MOSCS&0x04u) != 0x4u)                                       /* Check if MainOsc needs to be started */
    {
     CLKCTL.MOSCC=0x06;                                                    /* Set MainOSC gain for 8MHz */
     CLKCTL.MOSCST=0x000044C0UL;       /* Set MainOSC stabilization time = 0x8000/fih = 0x8000/8,000,000 = 0.004096=  ~4.1ms */
     protected_write_test(WPROTR.PROTCMD0,WPROTR.PROTS0,CLKCTL.MOSCE,0x01u);      /* Trigger Enable (protected write) */
     while ((CLKCTL.MOSCS&0x04u) != 0x04u);                                /* Wait for active MainOSC i.e , MOSCCLKACT = 1 */
    }

    /************ PLL1 : PLL without SSCG (PLL1) ********************/
    /* Prepare clock to PLL1 : CKSC_PLL1IS_CTL.PLLISCSID = 0x01 : MainOSC   --> default value of this register after reset : 0x01*/
    protected_write_test(WPROTR.PROTCMD1,WPROTR.PROTS1,CLKCTL.CKSC_PLL1IS_CTL,0x01u);      /* Enable clock to PLL */

    /* Prepare PLL1*/
    if((CLKCTL.PLL1S&0x04u) != 0x04u)                                       /* Check if PLL needs to be started */
    {
      /* Prepare PLL1*/
      CLKCTL.PLL1C=0x0001033BUL;                                          /* 8 MHz MainOSC -> VCOOUT = 480MHz-> PLLOUT = 80MHz */
      protected_write_test(WPROTR.PROTCMD1,WPROTR.PROTS1,CLKCTL.PLL1E,0x01u);  /* Enable PLL */
      while((CLKCTL.PLL1S&0x04u) != 0x04u);                             /* Wait for active PLL : PLLCLKACT = 1*/
    }

    /* CPLLOUT = VCOOUT × 1/4 = 120 MHz (for Premium Device) */
    protected_write_test(WPROTR.PROTCMD1,WPROTR.PROTS1,CLKCTL.CKSC_CPUCLKD_CTL,0x11);
    while(CLKCTL.CKSC_CPUCLKD_ACT!=0x11);

    /* CPLLOUT -> CPU Clock */
    protected_write_test(WPROTR.PROTCMD1,WPROTR.PROTS1,CLKCTL.CKSC_CPUCLKS_CTL,0x03u);
    while(CLKCTL.CKSC_CPUCLKS_ACT!=0x03u);

    /* PPLLOUT -> PPLLCLK = 80MHz */
    protected_write_test(WPROTR.PROTCMD1,WPROTR.PROTS1,CLKCTL.CKSC_PPLLCLKS_CTL,0x3);
    while(CLKCTL.CKSC_PPLLCLKS_ACT!=0x3);

#elif  def MAIN_OSC_16MHZ

    /*********** Enable HS ON-chip Oscillator -- to provide clock for -- Main Oscillator controller & PLLk controller *********************************/

        /* Stable and active fRH clock is indicated by ROSCS.ROSCCLKACT = 1 */
      if((CLKCTL.ROSCS&0x04u) != 0x4u)                                       /* Check if MainOsc needs to be started */
      {
          //unstop the HS On chip oscillator -- ROSCDISTRG = 0;
          protected_write_test(WPROTR.PROTCMD0, WPROTR.PROTS0,CLKCTL.ROSCE,0x00000000UL);
          //Stable and active fRH clock is indicated by ROSCS.ROSCCLKACT = 1
          while((CLKCTL.ROSCS & 0x04)!= 0x04u);
      }
      asm("nop");


    /*********** Enable MAIN Oscillator *********************************/
      /* Prepare 16MHz MainOsc */
    if((CLKCTL.MOSCS&0x04u) != 0x4u)                                       /* Check if MainOsc needs to be started */
    {
     CLKCTL.MOSCC=0x06;                                                    /* Set MainOSC gain for 16MHz */
     CLKCTL.MOSCST=0x00008000;       /* Set MainOSC stabilization time = 0x8000/fih = 0x8000/8,000,000 = 0.004096=  ~4.1ms */
     protected_write_test(WPROTR.PROTCMD0,WPROTR.PROTS0,CLKCTL.MOSCE,0x01u);      /* Trigger Enable (protected write) */
     while ((CLKCTL.MOSCS&0x04u) != 0x04u);                                /* Wait for active MainOSC i.e , MOSCCLKACT = 1 */
    }

    /************ PLL1 : PLL without SSCG (PLL1) ********************/
    /* Prepare clock to PLL1 : CKSC_PLL1IS_CTL.PLLISCSID = 0x01 : MainOSC   --> default value of this register after reset : 0x01*/
    protected_write_test(WPROTR.PROTCMD1,WPROTR.PROTS1,CLKCTL.CKSC_PLL1IS_CTL,0x01u);      /* Enable clock to PLL */

    /* Prepare PLL1*/
    if((CLKCTL.PLL1S&0x04u) != 0x04u)                                       /* Check if PLL needs to be started */
    {
      /* Prepare PLL1*/
      CLKCTL.PLL1C=0x00010B3B;                                          /* 16 MHz MainOSC -> VCOOUT = 480MHz-> PLLOUT = 80MHz */
      protected_write_test(WPROTR.PROTCMD1,WPROTR.PROTS1,CLKCTL.PLL1E,0x01u);  /* Enable PLL */
      while((CLKCTL.PLL1S&0x04u) != 0x04u);                             /* Wait for active PLL : PLLCLKACT = 1*/
    }

    /* CPLLOUT = VCOOUT × 1/4 = 120 MHz (for Premium Device) */
    protected_write_test(WPROTR.PROTCMD1,WPROTR.PROTS1,CLKCTL.CKSC_CPUCLKD_CTL,0x11);
    while(CLKCTL.CKSC_CPUCLKD_ACT!=0x11);

    /* CPLLOUT -> CPU Clock */
    protected_write_test(WPROTR.PROTCMD1,WPROTR.PROTS1,CLKCTL.CKSC_CPUCLKS_CTL,0x03u);
    while(CLKCTL.CKSC_CPUCLKS_ACT!=0x03u);

    /* PPLLOUT -> PPLLCLK = 80MHz */
    protected_write_test(WPROTR.PROTCMD1,WPROTR.PROTS1,CLKCTL.CKSC_PPLLCLKS_CTL,0x3);
    while(CLKCTL.CKSC_PPLLCLKS_ACT!=0x3);

#elif  def MAIN_OSC_20MHZ  // Crystal : 20 MHZ

    /*********** Enable HS ON-chip Oscillator -- to provide clock for -- Main Oscillator controller & PLLk controller *********************************/

        /* Stable and active fRH clock is indicated by ROSCS.ROSCCLKACT = 1 */
      if((CLKCTL.ROSCS&0x04u) != 0x4u)                                       /* Check if MainOsc needs to be started */
      {
          //unstop the HS On chip oscillator -- ROSCDISTRG = 0;
          protected_write_test(WPROTR.PROTCMD0, WPROTR.PROTS0,CLKCTL.ROSCE,0x00000000UL);
          //Stable and active fRH clock is indicated by ROSCS.ROSCCLKACT = 1
          while((CLKCTL.ROSCS & 0x04)!= 0x04u);
      }
      asm("nop");


    /*********** Enable MAIN Oscillator *********************************/
      /* Prepare 20MHz MainOsc */
    if((CLKCTL.MOSCS&0x04u) != 0x4u)                                       /* Check if MainOsc needs to be started */
    {
     CLKCTL.MOSCC=0x05;                                                    /* Set MainOSC gain for 16MHz */
     CLKCTL.MOSCST=0x00003E80;     // 2msec
     protected_write_test(WPROTR.PROTCMD0,WPROTR.PROTS0,CLKCTL.MOSCE,0x01u);      /* Trigger Enable (protected write) */
     while ((CLKCTL.MOSCS&0x04u) != 0x04u);                                /* Wait for active MainOSC i.e , MOSCCLKACT = 1 */
    }

    /************ PLL1 : PLL without SSCG (PLL1) ********************/
    /* Prepare clock to PLL1 : CKSC_PLL1IS_CTL.PLLISCSID = 0x01 : MainOSC   --> default value of this register after reset : 0x01*/
    protected_write_test(WPROTR.PROTCMD1,WPROTR.PROTS1,CLKCTL.CKSC_PLL1IS_CTL,0x01u);      /* Enable clock to PLL */

    /* Prepare PLL1*/
    if((CLKCTL.PLL1S&0x04u) != 0x04u)                                       /* Check if PLL needs to be started */
    {
      /* Prepare PLL1*/
      CLKCTL.PLL1C=0x00010B2F;                                          /* 20 MHz MainOSC -> VCOOUT = 480MHz-> PLLOUT = 80MHz */
      protected_write_test(WPROTR.PROTCMD1,WPROTR.PROTS1,CLKCTL.PLL1E,0x01u);  /* Enable PLL */
      while((CLKCTL.PLL1S&0x04u) != 0x04u);                             /* Wait for active PLL : PLLCLKACT = 1*/
    }

    /* CPLLOUT = VCOOUT × 1/4 = 120 MHz (for Premium Device) */
    protected_write_test(WPROTR.PROTCMD1,WPROTR.PROTS1,CLKCTL.CKSC_CPUCLKD_CTL,0x11);
    while(CLKCTL.CKSC_CPUCLKD_ACT!=0x11);

    /* CPLLOUT -> CPU Clock */
    protected_write_test(WPROTR.PROTCMD1,WPROTR.PROTS1,CLKCTL.CKSC_CPUCLKS_CTL,0x03u);
    while(CLKCTL.CKSC_CPUCLKS_ACT!=0x03u);

    /* PPLLOUT -> PPLLCLK = 80MHz */
    protected_write_test(WPROTR.PROTCMD1,WPROTR.PROTS1,CLKCTL.CKSC_PPLLCLKS_CTL,0x3);
    while(CLKCTL.CKSC_PPLLCLKS_ACT!=0x3);

#endif
}
