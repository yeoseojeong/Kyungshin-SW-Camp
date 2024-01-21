#include "bsw.h"

TASK(Task1){
   printfSerial("Task1 Begins...");
   mdelay(3000);
   printfSerial("Task1 Finishes...");
   TerminateTask();
}

TASK(Task2){

   printfSerial("Task2 Begins...");
   mdelay(3000);
   printfSerial("Task2 Finishes...");
   TerminateTask();
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
ISR2(TimerISR)
{
   static long c = -4;
   TaskStateType s;
   if(c==5)
   {
	   GetTaskState(30,&s);
   }
   IncrementCounter(counter1);
   printfSerial("\n%4ld",c++);
}

void StartupHook(void)
{
	printfSerial("..StartupHook..\n");

}

void ShutdownHook(StatusType Error)
{
	printfSerial("..ShutdownHook..\n");
	printState(Task1);
	printState(Task2);
}

void PreTaskHook(void)
{
	TaskType id;
	GetTaskID(&id);
	printfSerial("[PreTaskHook(%d)]",id);
	printState(Task1);
	printState(Task2);
}

void PostTaskHook(void)
{
	TaskType id;
		GetTaskID(&id);
		printfSerial("[PostTaskHook(%d)]",id);
		printState(Task1);
		printState(Task2);
}

void ErrorHook(StatusType error)
{
	printfSerial("[ErrorHook: error = %d, service = %d, TaskID = %d]",error,OSErrorGetServiceId(),OSError_GetTaskState_TaskID());
}
