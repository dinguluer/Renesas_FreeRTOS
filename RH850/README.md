# This sample project is porting for freeRTOS on RH850.

* RH850 : This folder contains the code
* Smart_configurator : This folder contains the smart configurator project for generating drivers for RH850/F1KM-S1, R7F701690, 64 pins. same drivers are used in folder RH850.

# Development enviroment used for porting freeRTOS on RH850.
* MCU : RH850/F1KM-S1
* Part Number : R7F701690, 64 pins
* Main Clock crystal : 8 MHZ
* IDE used = CS+ (GHS Multi)
* Compiler = CCRH (GHS compiler)
* OSTM0 = used as RTOS timer = 1 msec interval timer
* TAUJ0 = 1 msec interval timer (this timer do not have any thing to do with RTOS)
* freeRTOS = V10.4.1
