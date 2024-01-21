#include "bsw.h"

TASK(Task1){
   printfSerial("Task1 Begins...\n");
   mdelay(3000);
   mdelay(3000);
   printfSerial("Task1 Finishes...\n");
}

TASK(Task2){
   printfSerial("Task2 Begins...\n");
   mdelay(3000);
   printfSerial("Task2 Finishes...\n");
}

ISR2(TimerISR)
{
   static long c = -4;
   IncrementCounter(counter1);
   printfSerial("\n%4ld: ",c++);
}

ALARMCALLBACK(MyCallback)
{
   printfSerial("MyCallback Begins...");
   printfSerial("MyCallback Finishes...");
}
