#ifndef DEVICEAPP_H__
#define DEVICEAPP_H__

#include "main.h"

/* TEST VERSION = MAIN VER + 0x80U*/
#define IS_TEST_VERSION     (true)
#define SUBREVISION_SW_VER  (0x03U + (IS_TEST_VERSION << 7))

#define CommType_WRITE      0x01U
#define CommType_READ       0x02U
#define CommType_INIT       0x03U
#define CommType_STOP       0x04U
#define CommType_ADCRTN     0x05U
#define CommType_UARTENABLE     0x06U
#define CommType_UARTDISABLE    0x07U
#define CommType_PortRead   0x08U
#define CommType_PortSet    0x09U
#define CommType_PortClean  0x0AU
#define CommType_FLASHWRITE 0xF1U
#define CommType_FLASHREAD  0xF2U

void DeviceApp_Intial(void);
void DeviceApp_0xF1FabCommCtrl(void);

#endif
