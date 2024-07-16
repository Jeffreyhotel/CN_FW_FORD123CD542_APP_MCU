#include "driver/inc/WdtDriver.h"
#include "driver/inc/UartDriver.h"

static void WdtApp_ISR(void)
{
    /* Avoid continue interrupt*/
    Cy_WDT_MaskInterrupt();
    UartDriver_TxWriteString((uint8_t *)"WDT Timeout!");    
}

void WdtApp_CleanCounter(void)
{
    Cy_WDT_ClearWatchdog();
}

void WdtApp_Initial(void)
{
    Cy_WDT_ClearWatchdog();
    WdtDriver_Disable();
    (void)WdtDriver_Initial();
    (void)WdtDriver_SetMatchIfPeriodMode();
    (void)WdtDriver_RegisterISR(WdtApp_ISR);
    (void)WdtDriver_Enable();
    WdtDriver_RegisterDSCallback();
}