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

#ifndef I2C4MDriver_H
#define I2C4MDriver_H

/* ************************************************************************** */
/** Global Function Definition
 */
/* ************************************************************************** */
#include "main.h"

#define ERROR_NONE    0x00U
#define ERROR_PARA    0x01U
#define ERROR_BUSNG   0x02U
#define ERROR_TIMEOUT 0x03U
#define ERROR_NAK     0x04U
#define ERROR_FAIL    0xFAU

/* Re-Name Macro for project use*/
#define I2C4M_MCU_HW    SCB_I2C4M_HW
#define I2C4M_MCU_IRQ   SCB_I2C4M_IRQ
#define I2C4M_MCU_config  SCB_I2C4M_config

/* Combine master error statuses in single mask  */
#define MASTER_ERROR_MASK   (CY_SCB_I2C_MASTER_DATA_NAK | CY_SCB_I2C_MASTER_ADDR_NAK   | \
                            CY_SCB_I2C_MASTER_ARB_LOST | CY_SCB_I2C_MASTER_ABORT_START | \
                            CY_SCB_I2C_MASTER_BUS_ERR)

bool I2C4MDriver_Initialize(void);
uint8_t I2C4MDriver_Read(uint16_t address, uint8_t* rdData, uint32_t rdLength);
uint8_t I2C4MDriver_Write(uint16_t address, uint8_t* wrData, uint32_t wrLength);
uint8_t I2C4MDriver_WriteRead(uint16_t address, uint8_t* wrData, uint32_t wrLength, uint8_t* rdData, uint32_t rdLength);

#endif /* _EXAMPLE_FILE_NAME_H */
/* *****************************************************************************
 End of File
 */
