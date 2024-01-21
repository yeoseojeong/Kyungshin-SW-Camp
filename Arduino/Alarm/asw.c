#include "bsw.h"

ISR2(TimerISR)
{
	static long c=-4;
	IncrementCounter(counter1);
		printfSerial("\n%4ld: ",c++);
}
TASK(TaskM)
{
	printState(Task1);
	printState(Task2);

	TerminateTask();
}

TASK(Task1){

   printfSerial("Task1 Begins...\n");
   mdelay(3000);
   printfSerial("Task1 Finishes...\n");
   TerminateTask();
}

TASK(Task2){

   printfSerial("Task2 Begins...\n");
   mdelay(3000);
   printfSerial("Task2 Finishes...\n");
   TerminateTask();
}




