#include <Ifx_Types.h>
#include <IfxPort.h>
#include <IfxCpu.h>


uint32 encoder_count = 0;
int flag = 0;
int o_state = 0;
int c_state = 0;
#define enca &MODULE_P02,1
#define encb &MODULE_P02,0


void AppNoTask(void){
    IfxPort_setPinModeInput(enca, IfxPort_Mode_inputPullDown); // A = 3번 포트
    IfxPort_setPinModeInput(encb, IfxPort_Mode_inputPullDown); // B = 2번 포트

    boolean ENCA = IfxPort_getPinState(enca);
    boolean ENCB = IfxPort_getPinState(encb);

    if(flag == 0){
        o_state = c_state;
        flag = 1;
    }
    if(ENCA == FALSE && ENCB == FALSE){
        c_state = 0;

    }
    else if(ENCA == TRUE && ENCB == FALSE){
        c_state = 1;

    }
    else if(ENCA == FALSE && ENCB == TRUE){
        c_state = 2;

    }
    else{
        c_state = 3;
    }
    if(o_state != c_state){
        encoder_count++;
    }
    o_state = c_state;
}

void makeVel(void){
encoder_count


}


