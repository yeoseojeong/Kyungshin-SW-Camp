#include "bsw.h"
ISR2(TimerISR)
{
	static long c=-4;
	if(c==0)
	{
		ActivateTask(Task1);
	}
		printfSerial("\n%4ld: ",c++);
}
TASK(Task1){

   printfSerial("Task Begins...\n");
   mdelay(3000);
   ActivateTask(Task2);
   printfSerial("Task Finishes...\n");
   TerminateTask();
}

TASK(Task2){
	printfSerial("Task2 Begins...\n");
	mdelay(3000);
	printfSerial("Task2 Finishes...\n");
	 ChainTask(Task3);

}
TASK(Task3){
	printfSerial("Task3 Begins...\n");
	mdelay(3000);
	printfSerial("Task3 Finishes...\n");
	TerminateTask();

}
