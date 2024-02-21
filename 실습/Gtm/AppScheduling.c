/*
 * AppScheduling.c
 *
 *  Created on: 2024. 2. 20.
 *      Author: JJu0_0
 */
#include "AppScheduling.h"
#include "DRIVER_STM.h"
#include "IfxPort.h"
#include "stdio.h"
#include "ADC.h"
#include "MIDADC.h"
#include "AppNoTask.h"
#include "GtmTomPwm_.h"
#include "Configurationisr_.h"
#include "stdio.h"

#define LED         &MODULE_P10,2


typedef struct
{
        uint32 u32nuCnt1ms;
        uint32 u32nuCnt10ms;
        uint32 u32nuCnt100ms;
}TestCnt;

static void AppTask1ms(void);
static void AppTask10ms(void);
static void AppTask100ms(void);
uint32 ULSraw;
TestCnt stTestCnt;
uint32 seconds = 0;
float dutyx=0;

static void AppTask1ms(void)
{

    stTestCnt.u32nuCnt1ms++;
}
static void AppTask10ms(void)
{

//    stTestCnt.u32nuCnt10ms++;
//    seconds += 10;
//    if(seconds*0.001 < 5){
//        dutyx = 0;
//    }
//    else if(seconds*0.001 > 5 && seconds*0.001 < 10)
//    {
//        dutyx = 0.3;
//    }
//    else
//    {
//        dutyx = 0;
//    }
//    g_GtmTomPwmHl.tOn[0] = dutyx;
//    GtmTomPwmHl_run();
}

static void AppTask100ms(void)
{
    stTestCnt.u32nuCnt100ms++;
}
static void AppTask50ms(void)
{
    stTestCnt.u32nuCnt10ms++;
//    DrvAdc_GetAdcRawGroup0();
//    SensorAdcRaw* pstSensorAdcRaw = MidAdc_GetAdcGroup0senseRaw();
//    ULSraw = pstSensorAdcRaw->UlSSense1_Raw;
//    printf("%lld\n",ULSraw);
}
static void AppTask500ms(void)
{
    stTestCnt.u32nuCnt100ms++;
    //IfxPort_togglePin(LED);
}

void AppScheduling(void)
{
    AppNoTask();

    if(stSchedulingInfo.u8nuScheduling1msFlag == 1u)
    {
        stSchedulingInfo.u8nuScheduling1msFlag = 0u;
        AppTask1ms();

    if(stSchedulingInfo.u8nuScheduling10msFlag == 1u)
    {
        stSchedulingInfo.u8nuScheduling10msFlag = 0u;
        AppTask10ms();
     }
    if(stSchedulingInfo.u8nuScheduling100msFlag == 1u)
    {
        stSchedulingInfo.u8nuScheduling100msFlag = 0u;
        AppTask100ms();
    }
    if(stSchedulingInfo.u8nuScheduling50msFlag == 1u)
    {
        stSchedulingInfo.u8nuScheduling50msFlag = 0u;
        AppTask50ms();
    }
    if(stSchedulingInfo.u8nuScheduling500msFlag == 1u)
    {
        stSchedulingInfo.u8nuScheduling500msFlag = 0u;
        AppTask500ms();
    }
  }
}
