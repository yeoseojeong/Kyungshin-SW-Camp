//asw.c

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
TASK(TaskM)
{
	printState(Task1);
	printState(Task2);

	TerminateTask();
}

TASK(Task1){
	TaskType id;
   printfSerial("Task Begins...\n");
   printState(Task1);
   printState(Task2);
   mdelay(3000);
   ActivateTask(Task2);
   printState(Task1);
      printState(Task2);
   mdelay(3000);
   GetTaskID(&id);
   printfSerial("Task ID = %d...",id);
   printfSerial("Task1 Finishes...\n");
   ChainTask(TaskM);
}

TASK(Task2){
	TaskType id;
	printfSerial("Task2 Begins...\n");
	printState(Task1);
	   printState(Task2);
	mdelay(3000);
	GetTaskID(&id);
	   printfSerial("Task ID = %d...",id);
	printfSerial("Task2 Finishes...\n");
	 ChainTask(TaskM);
}

void printState(TaskType id){
	TaskStateType state;

	if(GetTaskState(id,&state)==E_OK){
		switch (state){
		case SUSPENDED:
			printfSerial("%d: suspended...",id);
			break;
		case READY:
			printfSerial("%d: ready...",id);
			break;
		case WAITING:
			printfSerial("%d: waiting...",id);
			break;
		case RUNNING:
			printfSerial("%d: running...",id);
			break;
		}
	}
}






