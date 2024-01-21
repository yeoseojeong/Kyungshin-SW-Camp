//asw.c

#include "bsw.h"

TASK (Task1)
{
	printfSerial("Hello World\n");
	TerminateTask();
}

ISR2(TimerISR)
{
	printfSerial("Interrupt !!");
}

