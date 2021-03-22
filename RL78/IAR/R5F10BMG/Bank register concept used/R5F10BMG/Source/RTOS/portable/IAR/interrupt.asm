 ;
 ; FreeRTOS Kernel V10.4.1
 ; Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 ;
 ; Permission is hereby granted, free of charge, to any person obtaining a copy of
 ; this software and associated documentation files (the "Software"), to deal in
 ; the Software without restriction, including without limitation the rights to
 ; use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 ; the Software, and to permit persons to whom the Software is furnished to do so,
 ; subject to the following conditions:
 ;
 ; The above copyright notice and this permission notice shall be included in all
 ; copies or substantial portions of the Software.
 ;
 ; THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 ; IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 ; FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 ; COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 ; IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 ; CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 ;
 ; https://www.FreeRTOS.org
 ; https://github.com/FreeRTOS
 ;
 ; 1 tab == 4 spaces!
 ;

;
;MEMORY MODEL : Interpretation when omitted
;When the -cpu=S1 option is specified, __DATA_MODEL__ == __DATA_MODEL_NEAR__ is assumed
;When the -cpu=S2 or -cpu=S3 option is specified, __DATA_MODEL__ == __DATA_MODEL_FAR__ is assumed
;

    name a_filexx___
    
    EXTERN ___interrupt_tab_0x2C
    EXTERN ___interrupt_tab_0x7E

    PUBLIC ___interrupt_0x2C
    PUBLIC _r_tau0_channel0_interrupt  
    PUBLIC ___interrupt_0x7E
    PUBLIC _vPortYield

    PUBLIC  _vPortStart    

    ; Variables used by scheduler
    ;------------------------------------------------------------------------------
    EXTERN    _pxCurrentTCB
    EXTERN    _usCriticalNesting

    EXTERN    _vTaskSwitchContext
    EXTERN    _xTaskIncrementTick

;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
;   portRESTORE_CONTEXT MACRO
;   Restores the task Stack Pointer then use this to restore usCriticalNesting,
;   general purpose registers and the CS and ES (only in far memory mode)
;   of the selected task from the task stack
;------------------------------------------------------------------------------
portRESTORE_CONTEXT MACRO
        SEL		RB0
    MOVW      AX, _pxCurrentTCB	    ;  Restore the Stack pointer.
    MOVW      HL, AX
    MOVW      AX, [HL]
    MOVW      SP, AX
    POP	      AX	                ;  Restore usCriticalNesting value.
    MOVW      _usCriticalNesting, AX
    ;/* Restore the alternative register banks - only necessary in the GCC
    ;port.  Register bank 3 is dedicated for interrupts use so is not saved or
    ;restored. */
        SEL		RB2
    POP		HL
    POP		DE
    POP		BC
    POP		AX
        SEL		RB1
    POP		HL
    POP		DE
    POP		BC
    POP		AX
        SEL		RB0
    POP	      BC                    ;  Restore the necessary general purpose registers.
    POP	      DE
    #if __CODE_MODEL__  == __CODE_MODEL_FAR__
    POP       AX                    ;  Restore the ES register.
    MOV       ES, A
    XCH       A, X                  ;  Restore the CS register.
    MOV       CS, A
    #else
    POP       AX
    MOV       CS, A                 ;  Restore CS register.
    #endif
    POP       HL                    ;  Restore general purpose register HL.
    POP       AX                    ;  Restore AX.
    ENDM

;------------------------------------------------------------------------------
;   portSAVE_CONTEXT MACRO
;   Saves the context of the general purpose registers, CS and ES (only in far
;	memory mode) registers the usCriticalNesting Value and the Stack Pointer
;   of the active Task onto the task stack
;------------------------------------------------------------------------------
portSAVE_CONTEXT MACRO
        SEL		RB0
    PUSH      AX                    ;  Save AX Register to stack.
    PUSH      HL
    #if __CODE_MODEL__  == __CODE_MODEL_FAR__
    MOV       A, CS                 ;  Save CS register.
    XCH       A, X
    MOV       A, ES                 ;  Save ES register.
    PUSH      AX
    #else
    MOV       A, CS                 ;  Save CS register.
    PUSH      AX
    #endif
    ;/* Save the remaining general purpose registers from bank 0. */
    PUSH      DE                    ;  Save the remaining general purpose registers.
    PUSH      BC
    ;/* Save the other register banks  */
        SEL		RB1
    PUSH	AX
    PUSH	BC
    PUSH	DE
    PUSH	HL
        SEL		RB2
    PUSH	AX
    PUSH	BC
    PUSH	DE
    PUSH	HL
    ;/* Registers in bank 3 are for ISR use only so don't need saving. */
            SEL		RB0
    MOVW      AX, _usCriticalNesting ;  Save the usCriticalNesting value.
    PUSH      AX
    MOVW      AX, _pxCurrentTCB 	    ;  Save the Stack pointer.
    MOVW      HL, AX
    MOVW      AX, SP
    MOVW      [HL], AX
    ENDM

; FreeRTOS tick handler.  This is installed as the interval timer interrupt
; handler.
    SECTION `.text`:CODE:ROOT(0)
_r_tau0_channel0_interrupt:
___interrupt_0x2C:
    portSAVE_CONTEXT		       ;  Save the context of the current task.
    call    _xTaskIncrementTick     ;  Call the timer tick function.
    cmpw    ax, #0x00
    skz
    call    _vTaskSwitchContext     ;  Call the scheduler to select the next task.
    portRESTORE_CONTEXT		       ;  Restore the context of the next task to run.
    reti
    REQUIRE ___interrupt_tab_0x2C

; FreeRTOS yield handler.  This is installed as the BRK software interrupt
; handler.
    SECTION `.text`:CODE:ROOT(0)
_vPortYield:
___interrupt_0x7E
    portSAVE_CONTEXT		        ;  Save the context of the current task.
    call _vTaskSwitchContext    ;  Call the scheduler to select the next task.
    portRESTORE_CONTEXT		        ;  Restore the context of the next task to run.
    retb
    REQUIRE ___interrupt_tab_0x7E


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; asm function  ;;;;;;;;;;;;;;;;
; Starts the scheduler by restoring the context of the task that will execute
; first.
    RSEG CODE:CODE
_vPortStart:
    portRESTORE_CONTEXT	            ;  Restore the context of whichever task the ...
    reti			    ;  An interrupt stack frame is used so the task
                                    ;  is started using a RETI instruction.
    
    end