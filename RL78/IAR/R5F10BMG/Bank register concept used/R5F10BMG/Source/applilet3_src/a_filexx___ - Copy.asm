    name a_filexx___
    
    EXTERN ___interrupt_tab_0x2C

    PUBLIC ___interrupt_0x2C
    PUBLIC _r_tau0_channel0_interrupt       
    PUBLIC _vtest_function

    SECTION `.text`:CODE:ROOT(0)
_r_tau0_channel0_interrupt:
___interrupt_0x2C:
    reti
    REQUIRE ___interrupt_tab_0x2C

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; asm function  ;;;;;;;;;;;;;;;;
    RSEG CODE:CODE
_vtest_function:
    ret
    
    end
