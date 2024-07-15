/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef WDTDRIVER_H
#define WDTDRIVER_H

/* ************************************************************************** */
/** Global Function Definition
 */
/* ************************************************************************** */
#include "main.h"

bool WdtDriver_Initial(void);
bool WdtDriver_SetMatchIfPeriodMode(void);
bool WdtDriver_RegisterISR(cy_israddress user_isr);
bool WdtDriver_Enable(void);
void WdtDriver_RegisterDSCallback(void);

#endif /* _EXAMPLE_FILE_NAME_H */
/* *****************************************************************************
 End of File
 */