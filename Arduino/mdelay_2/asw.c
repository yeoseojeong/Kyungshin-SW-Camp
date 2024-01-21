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
   printfSerial("Timer on\n");
}



