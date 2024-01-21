#include "bsw.h"

TASK(Task1){
   pinMode(13,OUTPUT);
   printfSerial("Hello world \n");
   digitalWrite(13,HIGH);
   mdelay(3000);
   printfSerial("Goodbye World\n");
   digitalWrite(13,LOW);
   TerminateTask();
}

ISR2(TimerISR){
   static long c=0;
   printfSerial("\n%4ld: ",c++);
}

