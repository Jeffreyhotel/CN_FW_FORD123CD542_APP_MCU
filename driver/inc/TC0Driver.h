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

#ifndef TC0DRIVER_H
#define TC0DRIVER_H

#include "main.h"

/* Timer period in milliseconds */
#define TIMER_PERIOD_MSEC 1000U

/* ************************************************************************** */
/** Global Function Definition
 */
/* ************************************************************************** */

bool TC0Driver_TimerStart( void );
void TC0Driver_IntFlagClean(void);
bool TC0Driver_TimerCallbackRegister(cy_israddress userIsr);

#endif /* _EXAMPLE_FILE_NAME_H */
/* *****************************************************************************
 End of File
 */
