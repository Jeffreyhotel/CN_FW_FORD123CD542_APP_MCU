#ifndef FLASHAPP_H__
#define FLASHAPP_H__

#include "main.h"

#define ADDR_MCUFLASH_FABCTRL   0x0001F100U
#define ADDR_MCUFLASH_MAXIMUM   0x00020000U
#define ADDR_MCUFLASH_APPFLAG   0x0001F000U
#define ADDR_MCUFLASH_SNUMBER   0x0001F100U
#define ADDR_MCUFLASH_DIMMING   0x0001F200U

#if (MCU_POSITION == 0x02U)
	#define PRJ_INFO_SECTION ".prj.info.2"
#elif (MCU_POSITION == 0x0AU)
	#define PRJ_INFO_SECTION ".prj.info.A"
#elif (MCU_POSITION == 0x0BU)
	#define PRJ_INFO_SECTION ".prj.info.B"
#else
	#error MCU_POSITION IS NOT DEFINED OR INVALID
#endif

void FlashApp_WriteRowFlash(uint8_t data[], const uint32_t address, uint8_t length);

#endif