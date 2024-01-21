#include "bsw.h"
#include "mutex.h"


MutexType s1;

TASK(TaskH){
   printfSerial("<TaskH Begins>");
   mdelay(1000);

   printfSerial("TaskH : Try Lock(s1). ");
   GetMutex(&s1);
   printfSerial("TaskH : Get Lock(s1). ");

   mdelay(3000);

   printfSerial("TaskH Release Lock(s1). ");
   ReleaseMutex(&s1);

   mdelay(1000);

   printfSerial("<TaskH end>");
   TerminateTask();
}

TASK(TaskL){
   printfSerial("<TaskL Begins>");
      mdelay(1000);

      printfSerial("TaskL : Try Lock(s1). ");
      GetMutex(&s1);
      printfSerial("TaskL : Get Lock(s1). ");

      mdelay(3000);

      printfSerial("TaskL Release Lock(s1). ");
      ReleaseMutex(&s1);

      mdelay(1000);

      printfSerial("<TaskL end>");
      TerminateTask();
}


ISR2(TimerISR)
{
   static long c =-5;
   printfSerial("\n%4ld: ",++c);
   if(c == -4){
      InitMutex(&s1,Event1);
   }
   else if(c==0){
      ActivateTask(TaskL);
   }
   else if(c ==5){
      ActivateTask(TaskH);
   }
}
