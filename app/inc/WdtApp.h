#ifndef WDTAPP_H__
#define WDTAPP_H__

#include "main.h"

void WdtApp_Initial(void);
void WdtApp_CleanCounter(void);
void WdtApp_InterruptCallback(void);
void WdtApp_CheckResetCause(void);

#define WDT_INT_TRIGER_MS    4000U

#endif
