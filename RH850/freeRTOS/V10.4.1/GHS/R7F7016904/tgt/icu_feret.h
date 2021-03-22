/*===========================================================================*/
/* Module      = icu_feret.h                                                 */
/* Version     = V3.05                                                       */
/* History:                                                                  */
/*               V3.00 initial Version                                       */
/*               V3.01 changed register usage                                */
/*                     save FEIC and FEPSW                                   */
/*               V3.02 added support for no CALLT register save              */
/*               V3.03 added support for no RH850G3K without H/W FPU         */
/*               V3.04 fit to use along with cpu.h                           */
/*               V3.05 no access to r4,r5, no double save of r31 (lp)        */
/*===========================================================================*/
/*                                  COPYRIGHT                                */
/*===========================================================================*/
/* Copyright (c) 2011 by Renesas Electronics Europe GmbH,                    */
/*               a company of the Renesas Electronics Corporation            */
/*===========================================================================*/
/* Purpose:      Definition of Fatal Exception Handler                       */
/*                                                                           */
/*===========================================================================*/
/*                                                                           */
/* Warranty Disclaimer                                                       */
/*                                                                           */
/* Because the Product(s) is licensed free of charge, there is no warranty   */
/* of any kind whatsoever and expressly disclaimed and excluded by Renesas,  */
/* either expressed or implied, including but not limited to those for       */
/* non-infringement of intellectual property, merchantability and/or         */
/* fitness for the particular purpose.                                       */
/* Renesas shall not have any obligation to maintain, service or provide bug */
/* fixes for the supplied Product(s) and/or the Application.                 */
/*                                                                           */
/* Each User is solely responsible for determining the appropriateness of    */
/* using the Product(s) and assumes all risks associated with its exercise   */
/* of rights under this Agreement, including, but not limited to the risks   */
/* and costs of program errors, compliance with applicable laws, damage to   */
/* or loss of data, programs or equipment, and unavailability or             */
/* interruption of operations.                                               */
/*                                                                           */
/* Limitation of Liability                                                   */
/*                                                                           */
/* In no event shall Renesas be liable to the User for any incidental,       */
/* consequential, indirect, or punitive damage (including but not limited    */
/* to lost profits) regardless of whether such liability is based on breach  */
/* of contract, tort, strict liability, breach of warranties, failure of     */
/* essential purpose or otherwise and even if advised of the possibility of  */
/* such damages. Renesas shall not be liable for any services or products    */
/* provided by third party vendors, developers or consultants identified or  */
/* referred to the User by Renesas in connection with the Product(s) and/or  */
/* the Application.                                                          */
/*                                                                           */
/*===========================================================================*/
/* Environment:                                                              */
/*              Device:         RH850G3M cores devices (with FPU)            */
/*                              RH850G3K cores (__HAS_FPU__ is undefined)    */
/*              IDE:            GHS Multi for V800                           */
/*===========================================================================*/

#ifndef __ICU_FERET_H__
 #define __ICU_FERET_H__

#define __HAS_FPU__
// #undef __HAS_FPU__

asm void FETRAP_ENTRY( void)
{
    pushsp  lp-lp
    pushsp  r1-r2
#if (__V800_registermode==32)
    pushsp  r6-r30
#endif
#if (__V800_registermode==26)
    pushsp  r6-r16              -- r17 to r22 are reserved for user
    pushsp  r23-r30
#endif
#if (__V800_registermode==22)
    pushsp  r6-r14              -- r15 to r24 are reserved for user
    pushsp  r25-r30
#endif
    pushsp  ep-ep
    stsr    14, r6,  0          -- FEIC
    stsr     3, r7,  0          -- FEPSW
    stsr     2, r8,  0          -- FEPC
#ifndef __V800_ignore_callt_state_in_interrupts__
    stsr    17, r9,  0          -- CTPSW
    stsr    16, r10, 0          -- CTPC
 #ifdef __HAS_FPU__
    stsr     6, r11, 0          -- FPSR
    stsr     7, r12, 0          -- FPEPC
    pushsp  r6-r12              -- FPU and CALLT to save
 #else
    pushsp  r6-r10             -- CALLT to save
 #endif /* __HAS_FPU__ */

#else   /* do not save callt control registers */
 #ifdef __HAS_FPU__
    stsr     6,  r9, 0          -- FPSR
    stsr     7, r10, 0          -- FPEPC
    pushsp  r6-r10              -- FPU reg to save
 #else
    pushsp  r6-r8               -- no FPU and no CALLT
 #endif /* __HAS_FPU__ */
#endif

}

asm void FETRAP_LEAVE( void)
{ 
#ifndef __V800_ignore_callt_state_in_interrupts__
 #ifdef __HAS_FPU__
    popsp   r6-r12
    ldsr    r12,  7, 0          -- FPEPC
    ldsr    r11,  6, 0          -- FPSR
    ldsr    r10, 16, 0          -- CTPC
    ldsr    r9,  17, 0          -- CTPSW
 #else                        
    popsp   r6-r10            
    ldsr    r10, 16, 0          -- CTPC
    ldsr    r9,  17, 0          -- CTPSW
 #endif /* __HAS_FPU__ */

#else   /* do not restore callt control registers */
 #ifdef __HAS_FPU__
    popsp   r6-r10
    ldsr    r10, 7, 0           -- FPEPC
    ldsr    r9,  6, 0           -- FPSR
 #else                        
    popsp   r6-r8             
 #endif /* __HAS_FPU__ */     
#endif                        
    ldsr    r8,  2, 0           -- FEPC
    ldsr    r7,  3, 0           -- FEPSW
    ldsr    r6, 14, 0           -- FEIC
    popsp   ep-ep
#if (__V800_registermode==32)
    popsp   r6-r30
#endif
#if (__V800_registermode==26)
    popsp   r23-r30            -- r17 to r22 are reserved for user
    popsp   r6-r16
#endif
#if (__V800_registermode==22)
    popsp   r25-r30            -- r15 to r24 are reserved for user
    popsp   r6-r14
#endif
    popsp   r1-r2
    popsp   lp-lp
    feret  
}

 
 #define PRAGMA(x) _Pragma(#x)

 #define FETRAP_EXCEPTION( name, isr) \
   __attribute__((noinline)) void isr( void); \
   PRAGMA( ghs noprologue)            \
   void name( void) {                 \
     FETRAP_ENTRY();                  \
     isr();                           \
     FETRAP_LEAVE();                  \
   } 


 #endif  // __ICU_FERET_H__
