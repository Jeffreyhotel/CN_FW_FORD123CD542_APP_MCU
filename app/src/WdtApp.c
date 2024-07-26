#include "driver/inc/WdtDriver.h"
#include "driver/inc/UartDriver.h"
#include "driver/inc/PortDriver.h"
#include "app/inc/RegisterApp.h"
#include "app/inc/TC0App.h"

static uint8_t u8TxBuffer[60] = {0};

#if 0
volatile bool isr_flag = false;

static void WdtApp_ISR(void)
{
    /* Avoid continue interrupt*/
    Cy_WDT_MaskInterrupt();
    isr_flag = true;
}
#endif

void WdtApp_CheckResetCause(void)
{
    switch (Cy_SysLib_GetResetReason())
    {
    case CY_SYSLIB_RESET_HWWDT:
        /* code */
        sprintf((char *)u8TxBuffer,"Reset Cause by 0x%04lX:HWWDT!\r\n",CY_SYSLIB_RESET_HWWDT);
        UartDriver_TxWriteString(u8TxBuffer);
        RegisterApp_DHU_Setup(CMD_DTC,DTC_RESET_CAUSE,0x02);
        break;

    case CY_SYSLIB_PROT_FAULT:
        /* code */
        sprintf((char *)u8TxBuffer,"Reset Cause by 0x%04lX:FAULT!\r\n",CY_SYSLIB_PROT_FAULT);
        RegisterApp_DHU_Setup(CMD_DTC,DTC_RESET_CAUSE,0x04);
        UartDriver_TxWriteString(u8TxBuffer);
        break;

    case CY_SYSLIB_RESET_SOFT:
        /* code */
        sprintf((char *)u8TxBuffer,"Reset Cause by 0x%04lX:SOFT!\r\n",CY_SYSLIB_RESET_SOFT);
        RegisterApp_DHU_Setup(CMD_DTC,DTC_RESET_CAUSE,0x08);
        UartDriver_TxWriteString(u8TxBuffer);
        break;

    default:
        sprintf((char *)u8TxBuffer,"Reset Cause by 0x%04lX:UNKOWN!\r\n",Cy_SysLib_GetResetReason());
        RegisterApp_DHU_Setup(CMD_DTC,DTC_RESET_CAUSE,0x01);
        UartDriver_TxWriteString(u8TxBuffer);
        break;
    }
}

void WdtApp_InterruptCallback(void)
{
    UartDriver_TxWriteString((uint8_t *)"WDT Timeout!");
}

void WdtApp_CleanCounter(void)
{
    Cy_WDT_ClearInterrupt();
    Cy_WDT_ClearWatchdog();
    TC0App_TimerReset(TIMER_WDTCOUNT);
#if 0
    if (isr_flag == true)
    {
        Cy_WDT_UnmaskInterrupt();
        isr_flag = false;
        /* Update the match count */
        WdtDriver_UpdateMatchCount();
        
    }
#endif
    // PortDriver_PinToggle(P1V2_EN_PORT,P1V2_EN_PIN);
}

void WdtApp_Initial(void)
{
    Cy_WDT_ClearWatchdog();
    WdtDriver_Disable();
    (void)WdtDriver_Initial();
    (void)WdtDriver_SetMatchIfPeriodMode();
#if 0
    (void)WdtDriver_RegisterISR(WdtApp_ISR);
#endif
    (void)WdtDriver_Enable();
    WdtDriver_RegisterDSCallback();
}