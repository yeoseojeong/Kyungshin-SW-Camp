#include "bsw.h"

TASK(Task1){
   printfSerial("Task1 Begins...\n");
   mdelay(5000);
   printfSerial("Task1 Finishes...\n");
}

TASK(Task2){
   EventMaskType mask;
   printfSerial("Task2 Begins...\n");
   printfSerial("Task2 Waits...\n");
   WaitEvent(Event1 | Event2);
   printfSerial("Task2 Wakes Up...\n");
   GetEvent(Task2, &mask);
   if(mask & Event1){
      printfSerial("[Event1]\n");
      ClearEvent(Event1);
   }
   if(mask & Event2){
      printfSerial("[Event2]\n");
      ClearEvent(Event2);
   }
   printfSerial("Task2 Finishes...\n");
   TerminateTask();
}

ISR2(TimerISR)
{
   static long c = -4;
   IncrementCounter(counter1);
   printfSerial("\n%4ld: ",c++);
}

ALARMCALLBACK(MyCallback1)
{
      DisableAllInterrupts();
      IncrementCounter(counter1);
      SetEvent(Task2,Event1);
}
ALARMCALLBACK(MyCallback2)
{
      DisableAllInterrupts();
      IncrementCounter(counter1);
      SetEvent(Task2,Event2);
}
