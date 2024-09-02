#ifndef UPDATEAPP_H__
#define UPDATEAPP_H__

#include "main.h"

#define UNIT_KB             1024U
#define SIZE_256B           256U
#define SIZE_64KB           (64U * UNIT_KB)
#define SIZE_60KB           (60U * UNIT_KB)
#define SIZE_56KB           (56U * UNIT_KB)
#define SIZE_APP_BASE       SIZE_56KB           /* APP memory size */
#define LENGTH_ERASE        (uint32_t)(SIZE_APP_BASE/SIZE_256B)

#define SIZE_ERASE_256B     256U
#define ADDR_APPA_START     0x3000U
#define ADDR_APPB_START     0x11000U

#define SIZE_PACKUNIT_128B  128U

#define POS_SN_AB_SEPERATE  (SIZE_APP_BASE/SIZE_PACKUNIT_128B)

#define RESERVED_DATA_LEN   1U
#define RESERVED_DATA_SIZE  4U

#define UNIT_READ           64U

bool UpdateApp_EraseFlashMCU(void);
bool UpdateApp_TransferFlashMCU(void);
bool UpdateApp_ChecksumFlashMCU(void);
void UpdateApp_McuReset(void);

#endif