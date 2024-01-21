#include "bsw.h"

TASK(Task1){

   printfSerial("Task Begins...\n");
   mdelay(3000);
   printfSerial("Task Finishes...");
   TerminateTask();
}

TASK(Task2){
	printfSerial("Task2 Begins...\n");
	mdelay(3000);
	printfSerial("Task2 Finishes...");
	TerminateTask();
}
ISR2(TimerISR)
{
	static long c=0;
	printfSerial("\n%4ld: ",c++);
}


