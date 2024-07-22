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

#ifndef __NVMDRIVER_H
#define __NVMDRIVER_H


/* ************************************************************************** */
/** Global Function Definition
 */
/* ************************************************************************** */

#include "main.h"

/*---------------------------- Define Constant -------------------------------*/

#if (CY_FLASH_SIZEOF_ROW == 64)
	#define FLASH_ROW_ADDRESS( addr ) (addr & 0xFFFFFFC0)
	#define FLASH_ROW_OFFSET(  addr ) (addr & 0x0000003F)
#elif (CY_FLASH_SIZEOF_ROW == 128)
	#define FLASH_ROW_ADDRESS( addr ) (addr & 0xFFFFFF80)
	#define FLASH_ROW_OFFSET(  addr ) (addr & 0x0000007F)
#elif (CY_FLASH_SIZEOF_ROW == 256)
	#define FLASH_ROW_ADDRESS( addr ) (addr & 0xFFFFFF00)
	#define FLASH_ROW_OFFSET(  addr ) (addr & 0x000000FF)
#elif (CY_FLASH_SIZEOF_ROW == 512)
	#define FLASH_ROW_ADDRESS( addr ) (addr & 0xFFFFFE00)
	#define FLASH_ROW_OFFSET(  addr ) (addr & 0x000001FF)
#else
	#error CY_FLASH_SIZEOF_ROW IS NOT DEFINED OR INVALID
#endif

#define	SIZE_ROW		CY_FLASH_SIZEOF_ROW

bool NVMDriver_Read( uint32_t *data, uint32_t length, const uint32_t address );
cy_en_flashdrv_status_t NVMDriver_PageWrite( uint8_t *u8data, const uint32_t u32address);
bool NVMDriver_RowErase(uint32_t address);
bool NVMDriver_IsBusy(void);

#endif /* _EXAMPLE_FILE_NAME_H */
/* *****************************************************************************
 End of File
 */