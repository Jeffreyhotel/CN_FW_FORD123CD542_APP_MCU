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

#ifndef I2C0SDRIVER_H
#define I2C0SDRIVER_H

/* ************************************************************************** */
/** Global Function Definition
 */
/* ************************************************************************** */
#include "main.h"

#define SL_RD_BUFFER_SIZE 80U
#define SL_WR_BUFFER_SIZE 2048U

bool I2C2SDriver_Initial(void);
uint32_t I2C2SDriver_GetTxCount(void);
void I2C2SDriver_ConfigRxBuff(uint8_t ReadBuffer[]);
void I2C2SDriver_ConfigTxBuff(uint8_t WriteBuffer[]);
void I2C2SDriver_RegisterCallback(cy_cb_scb_i2c_handle_events_t callback);
void I2C2SDriver_Enable(void);

#endif /* _EXAMPLE_FILE_NAME_H */
/* *****************************************************************************
 End of File
 */