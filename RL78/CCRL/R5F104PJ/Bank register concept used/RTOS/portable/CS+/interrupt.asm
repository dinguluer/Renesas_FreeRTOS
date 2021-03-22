;
;MEMORY MODEL : Interpretation when omitted
;When the -cpu=S1 option is specified, small is assumed.
;When the -cpu=S2 or -cpu=S3 option is specified, medium is assumed
;
; define this macro if you are using MEDIUM model otherwise comment it
$IFNDEF __RL78_MEDIUM__
    __RL78_MEDIUM__	.EQU	0x01
$ENDIF

;.EXTERN _portSAVE_CONTEXT
.EXTERN    _pxCurrentTCB
.EXTERN    _usCriticalNesting

portRESTORE_CONTEXT .MACRO
        SEL		RB0
    MOVW      AX, !_pxCurrentTCB	    ;  Restore the Stack pointer.
    MOVW      HL, AX
    MOVW      AX, [HL]
    MOVW      SP, AX
    POP	      AX	                ;  Restore usCriticalNesting value.
    MOVW      !_usCriticalNesting, AX
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
    $ifdef __RL78_MEDIUM__
    POP       AX                    ;  Restore the ES register.
    MOV       ES, A
    XCH       A, X                  ;  Restore the CS register.
    MOV       CS, A
    $ELSE
    POP       AX
    MOV       CS, A                 ;  Restore CS register.
    $ENDIF
    POP       HL                    ;  Restore general purpose register HL.
    POP       AX                    ;  Restore AX.
    .ENDM

portSAVE_CONTEXT .MACRO
        SEL		RB0
    PUSH      AX                    ;  Save AX Register to stack.
    PUSH      HL
    $ifdef __RL78_MEDIUM__
    MOV       A, CS                 ;  Save CS register.
    XCH       A, X
    MOV       A, ES                 ;  Save ES register.
    PUSH      AX
    $ELSE
    MOV       A, CS                 ;  Save CS register.
    PUSH      AX
    $ENDIF
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
    MOVW      AX, !_usCriticalNesting ;  Save the usCriticalNesting value.
    PUSH      AX
    MOVW      AX, !_pxCurrentTCB 	    ;  Save the Stack pointer.
    MOVW      HL, AX
    MOVW      AX, SP
    MOVW      [HL], AX
    .ENDM


_r_tau0_channel0_interrupt  .vector 0x002C          ;INTTM00
.section    .text, TEXT ;Assumed to be the __near specification
                        ;because the vector table is specified
_r_tau0_channel0_interrupt:
    portSAVE_CONTEXT		       ;  Save the context of the current task.
    call    !!_xTaskIncrementTick     ;  Call the timer tick function.
    cmpw    ax, #0x00
    skz
    call    !!_vTaskSwitchContext     ;  Call the scheduler to select the next task.
    portRESTORE_CONTEXT		       ;  Restore the context of the next task to run.
    reti

_vPortYield  .vector 0x007E          ;BRK
.SECTION    .text, TEXT
_vPortYield:
        portSAVE_CONTEXT		        ;  Save the context of the current task.
        call !!_vTaskSwitchContext    ;  Call the scheduler to select the next task.
        portRESTORE_CONTEXT		        ;  Restore the context of the next task to run.
        retb

.PUBLIC	_vPortStart
.SECTION    .text, TEXT
_vPortStart:
    portRESTORE_CONTEXT	            ;  Restore the context of whichever task the ...
    reti			    ;  An interrupt stack frame is used so the task
                                    ;  is started using a RETI instruction.
