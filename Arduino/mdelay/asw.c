#include "bsw.h"

TASK (Task1)
{
	printfSerial("Hello World\n");
	mdelay(3000);
	printfSerial("Goodbye World\n");
	TerminateTask();
}

ISR2(TimerISR)
{
	;
}


//conf.oil
CPU mySystem {
    OS myOs {
		EE_OPT = "OS_EE_APPL_BUILD_DEBUG";
		EE_OPT = "OS_EE_BUILD_DEBUG";

        USERESSCHEDULER = TRUE;
        CPU_DATA = AVR8 {
            MULTI_STACK = FALSE;
        };
        MCU_DATA = MEGA {
            MODEL = MEGA_328p;
        };
        LIB = ARDUINO {
            SDK_BOARD = UNO;
            VARIANT = CC {
                VERSION = "1.8.5";
            };
            STAND_ALONE = TRUE;        // Generate arduino libraries
        };
        KERNEL_TYPE = OSEK {
            CLASS = ECC2;    // Default
        };
    };
    
    APPDATA myApp {
        APP_SRC = "bsw.cpp";
        APP_SRC = "asw.c";
    };
    
    TASK Task1{
       PRIORITY = 1;
       STACK = SHARED;
       SCHEDULE = FULL;
       AUTOSTART = TRUE;
       ACTIVATION = 1;
    };
    

     ISR TimerISR{
    	CATEGORY = 2;
    	SOURCE = "TIMER1_COMPA";
    };
};