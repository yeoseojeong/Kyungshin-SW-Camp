
/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "IfxPort.h" //포트 정의
#include "IfxPort_PinMap.h"
#include "Driver_Stm.h"

/*********************************************************************************************************************/
typedef struct
{
        Ifx_STM     *stmSfr;
        IfxStm_CompareConfig stmConfig;
}App_Stm;

App_Stm     g_Stm;
uint32      u32nuCounter1ms = 0;
SchedulingFlag  stSchedulingInfo;

void Driver_Stm_Init(void)  //stm 초기화
{
    boolean interruptState = IfxCpu_disableInterrupts();

    IfxStm_enableOcdsSuspend(&MODULE_STM0);

    g_Stm.stmSfr = &MODULE_STM0;
    IfxStm_initCompareConfig(&g_Stm.stmConfig);

    g_Stm.stmConfig.triggerPriority     = 100u;
    g_Stm.stmConfig.typeOfService       = IfxSrc_Tos_cpu0;
    g_Stm.stmConfig.ticks               = 100000u;

    IfxStm_initCompare(g_Stm.stmSfr, &g_Stm.stmConfig);

    IfxCpu_restoreInterrupts(interruptState);
}

IFX_INTERRUPT(STM_Int0Handler, 0, 100);
void STM_Int0Handler(void)
{
    IfxCpu_enableInterrupts();

    IfxStm_clearCompareFlag(g_Stm.stmSfr, g_Stm.stmConfig.comparator);
    IfxStm_increaseCompare(g_Stm.stmSfr, g_Stm.stmConfig.comparator, 100000u);

    u32nuCounter1ms++;

    if ((u32nuCounter1ms % 1) == 0u)
    {
        stSchedulingInfo.u8nuScheduling1msFlag = 1u;
    }

    if ((u32nuCounter1ms % 10) == 0u)
        {
            stSchedulingInfo.u8nuScheduling10msFlag = 1u;
        }

    if ((u32nuCounter1ms % 100) == 0u)
        {
            stSchedulingInfo.u8nuScheduling100msFlag = 1u;
        }

}

/*
IFX_INTERRUPT(STM_Int1Handler, 0, 100);


void STM_Int1Handler(void)
{
    IfxCpu_enableInterrupts();

    IfxStm_clearCompareFlag(g_Stm.stmSfr, g_Stm.stmConfig.comparator);
    IfxStm_increaseCompare(g_Stm.stmSfr, g_Stm.stmConfig.comparator, 100000u);

    u32nuCounter1ms++;

    if ((u32nuCounter1ms % 50) == 0u)  //50
            {
                stSchedulingInfo.u8nuScheduling50msFlag = 1u;
            }

    if ((u32nuCounter1ms % 500) == 0u)  //500
            {
                stSchedulingInfo.u8nuScheduling500msFlag = 1u;
            }
}
*/
