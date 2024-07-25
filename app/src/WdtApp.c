#include "driver/inc/WdtDriver.h"
#include "driver/inc/UartDriver.h"
#include "app/inc/TC0App.h"

static uint8_t u8TxBuffer[60] = {0};

void WdtApp_CheckResetCause(void)
{
    switch (Cy_SysLib_GetResetReason())
    {
    case CY_SYSLIB_RESET_HWWDT:
        /* code */
        sprintf((char *)u8TxBuffer,"Reset Cause by 0x%04lX:HWWDT!\r\n",CY_SYSLIB_RESET_HWWDT);
        UartDriver_TxWriteString(u8TxBuffer);
        break;

    case CY_SYSLIB_PROT_FAULT:
        /* code */
        sprintf((char *)u8TxBuffer,"Reset Cause by 0x%04lX:FAULT!\r\n",CY_SYSLIB_PROT_FAULT);
        UartDriver_TxWriteString(u8TxBuffer);
        break;

    case CY_SYSLIB_RESET_SOFT:
        /* code */
        sprintf((char *)u8TxBuffer,"Reset Cause by 0x%04lX:SOFT!\r\n",CY_SYSLIB_RESET_SOFT);
        UartDriver_TxWriteString(u8TxBuffer);
        break;

    default:
        sprintf((char *)u8TxBuffer,"Reset Cause by 0x%04lX:UNKOWN!\r\n",Cy_SysLib_GetResetReason());
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
}

void WdtApp_Initial(void)
{
    Cy_WDT_ClearWatchdog();
    WdtDriver_Disable();
    (void)WdtDriver_Initial();
    (void)WdtDriver_SetMatchIfPeriodMode();
    (void)WdtDriver_Enable();
    WdtDriver_RegisterDSCallback();
}