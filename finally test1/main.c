#include "DSP28x_Project.h"



void GPIO_Init(void);
void EPWM_Init(void);
void InitEPwm1Example(void);
void InitEPwm2Example(void);

int main(void)
{

     InitSysCtrl();

    EALLOW;
    SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;
    EDIS;


    InitEPwm1Gpio();
    InitEPwm2Gpio();

    EALLOW;
    SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;
    EDIS;


    DINT;
    InitPieCtrl();
    IER = 0x0000;
    IFR = 0x0000;
    InitPieVectTable();

    InitEPwm1Example();
    InitEPwm2Example();


    while(1)
    {

    }

}

void InitEPwm1Example(){
    EPwm1Regs.TBPRD = 3571; // Period = 1201 TBCLK counts
    EPwm1Regs.CMPA.half.CMPA = 1786; // Set 50% fixed duty for EPWM1A
    EPwm1Regs.CMPB = 1786; // Compare B = 200 TBCLK counts
    EPwm1Regs.TBPHS.half.TBPHS = 0; // Set Phase register to zero
    EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Asymmetrical mode
    EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE; // Master module
    EPwm1Regs.TBCTL.bit.PRDLD = TB_SHADOW;
    EPwm1Regs.TBCTL.bit.SYNCOSEL = TB_CTR_ZERO; // Sync down-stream module
    EPwm1Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm1Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm1Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO; // load on CTR=Zero
    EPwm1Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO; // load on CTR=Zero
    EPwm1Regs.AQCTLA.bit.ZRO = AQ_SET; // set actions for EPWM1A
    EPwm1Regs.AQCTLA.bit.CAU = AQ_CLEAR;
    EPwm1Regs.AQCTLB.bit.PRD = AQ_CLEAR;
    EPwm1Regs.AQCTLB.bit.CBU = AQ_SET;
    EPwm1Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE; // enable Dead-band module
    EPwm1Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC; // Active Hi complementary
    EPwm1Regs.DBFED = 214; // FED = 50 TBCLKs initially
    EPwm1Regs.DBRED = 214;
}


void InitEPwm2Example(){
    EPwm2Regs.TBPRD = 3571; // Period = 1201 TBCLK counts
    EPwm2Regs.CMPA.half.CMPA = 1786; // Set 50% fixed duty EPWM2A
    EPwm2Regs.CMPB = 1786; // Compare B = 200 TBCLK counts
    EPwm2Regs.TBPHS.half.TBPHS = 0; // Set Phase register to zero initially
    EPwm2Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Asymmetrical mode
    EPwm2Regs.TBCTL.bit.PHSEN = TB_ENABLE; // Slave module
    EPwm2Regs.TBCTL.bit.PRDLD = TB_SHADOW;
    EPwm2Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN; // sync flow-through
    EPwm2Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm2Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
    EPwm2Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO; // load on CTR=Zero
    EPwm2Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO; // load on CTR=Zero
    EPwm2Regs.AQCTLA.bit.ZRO = AQ_SET; // set actions for EPWM2A
    EPwm2Regs.AQCTLA.bit.CAU = AQ_CLEAR;
    EPwm2Regs.AQCTLB.bit.PRD = AQ_CLEAR;
    EPwm2Regs.AQCTLB.bit.CBU = AQ_SET;
    EPwm2Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE; // enable Dead-band module
    EPwm2Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC; // Active Hi complementary
    EPwm2Regs.DBFED = 214; // FED = 30 TBCLKs initially
    EPwm2Regs.DBRED = 214;

//    EPwm2Regs.TBPHS.half.TBPHS = 3571-426;
}




