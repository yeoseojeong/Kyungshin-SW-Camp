/**********************************************************************************************************************
 * \file Driver_Stm.c
 * \copyright Copyright (C) Infineon Technologies AG 2019
 * 
 * Use of this file is subject to the terms of use agreed between (i) you or the company in which ordinary course of 
 * business you are acting and (ii) Infineon Technologies AG or its licensees. If and as long as no such terms of use
 * are agreed, use of this file is subject to following:
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization obtaining a copy of the software and 
 * accompanying documentation covered by this license (the "Software") to use, reproduce, display, distribute, execute,
 * and transmit the Software, and to prepare derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including the above license grant, this restriction
 * and the following disclaimer, must be included in all copies of the Software, in whole or in part, and all 
 * derivative works of the Software, unless such copies or derivative works are solely in the form of 
 * machine-executable object code generated by a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE 
 * COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN 
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
 * IN THE SOFTWARE.
 *********************************************************************************************************************/

#include "Driver_Stm.h"
#include "IfxPort.h"
#include "IfxPort_PinMap.h"

typedef struct{
        Ifx_STM    *stmSfr;
        IfxStm_CompareConfig stmConfig;
}App_Stm;


App_Stm g_Stm;
uint32 u32nuCounter1ms=0;
SchedulingFlag stSchedulingInfo;




void Driver_Stm_Init(void)
{
    boolean interruptState = IfxCpu_disableInterrupts();

    IfxStm_enableOcdsSuspend(&MODULE_STM0);

    g_Stm.stmSfr=&MODULE_STM0;
    IfxStm_initCompareConfig(&g_Stm.stmConfig);

    g_Stm.stmConfig.triggerPriority=100u;
    g_Stm.stmConfig.typeOfService=IfxSrc_Tos_cpu0;
    g_Stm.stmConfig.ticks    =100000u;


    IfxStm_initCompare(g_Stm.stmSfr,&g_Stm.stmConfig);

    IfxCpu_restoreInterrupts(interruptState);

}


IFX_INTERRUPT(STM_IntoHandler,0,100);
void STM_IntoHandler(void)
{
    IfxCpu_enableInterrupts();
    IfxStm_clearCompareFlag(g_Stm.stmSfr,g_Stm.stmConfig.comparator);
    IfxStm_increaseCompare(g_Stm.stmSfr,g_Stm.stmConfig.comparator,100000u);


    u32nuCounter1ms++;


    if((u32nuCounter1ms%50)==0u)
      {
            stSchedulingInfo.u8nuScheduling50msFlag=1u;
      }
    if((u32nuCounter1ms%500)==0u)
       {
              stSchedulingInfo.u8nuScheduling500msFlag=1u;
       }
}






/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*-------------------------------------------------Data Structures---------------------------------------------------*/
/*********************************************************************************************************************/
 
/*********************************************************************************************************************/
/*--------------------------------------------Private Variables/Constants--------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/


