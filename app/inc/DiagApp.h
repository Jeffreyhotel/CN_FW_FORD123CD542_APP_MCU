#ifndef DIAGAPP_H__
#define DIAGAPP_H__

#include "main.h"

#define DISP_STATUS_BYTE0   0x00U
#define DISP_STATUS_BYTE1   0x01U

#define DISP0_LATCHED_MASK  0xEFU
#define DISP0_TCERR_MASK    0x80U   /* [Latched] Touch Connection Error (FPC connection)(No use)*/
#define DISP0_TSCERR_MASK   0x40U   /* [Latched] Touch Screen Controller Error (No use)*/
#define DISP0_LLOSS_MASK    0x20U   /* [Latched] Loss of Lock*/
#define DISP0_RSTRQ_MASK    0x10U   /* Reset Request*/
#define DISP0_DCERR_MASK    0x08U   /* [Latched] Disconnect Error (FPC connection)*/
#define DISP0_TERR_MASK     0x04U   /* [Latched] Temperature Derating*/
#define DISP0_BLERR_MASK    0x02U   /* [Latched] LCD Backlight Error*/
#define DISP0_LCDERR_MASK   0x01U   /* [Latched] LCD Error*/

#define DISP1_LATCHED_MASK  0xB8U
#define DISP1_DISPERR_MASK  0x80U   /* [Latched] Display Error*/
#define DISP1_BLST_MASK     0x40U   /* Backlight Status*/
#define DISP1_LOWERR_MASK   0x20U   /* [Latched] Low Priority Error Status*/
#define DISP1_MEDERR_MASK   0x10U   /* [Latched] Medium Priority Error Status*/
#define DISP1_HIGHERR_MASK  0x08U   /* [Latched] High Priority Error Status*/
#define DISP1_INIT_MASK     0x04U   /* Display Initial*/
#define DISP1_TSCST_MASK    0x02U   /* Touch Controller Status (No use)*/
#define DISP1_DISPST_MASK   0x01U   /* I2C Client Status (Formerly Display Status)*/

#define IO_HIGH     1U
#define IO_LOW      0U

#define IO_STATUS_HIGH  0x01U
#define IO_STATUS_LOW   0x00U
#define IO_STATUS_SWIM  0x02U

typedef struct{
    uint8_t Status;
    const GPIO_PRT_Type *Port;
    uint32_t PortNumber;
    uint8_t Threshlod;
    uint8_t ConsecutiveHighCnt;
    uint8_t ConsecutiveLowCnt;
}DiagIO;

void DiagApp_DispStatusClear(uint8_t ByteNumber, uint8_t MaskValue);
void DiagApp_DispStatusSet(uint8_t ByteNumber, uint8_t MaskValue);
uint8_t DiagApp_ConsecutiveCheckIO(DiagIO ds);
void DiagApp_FaultCheckFlow(void);
void DiagApp_FpcCheckFlow(void);
void DiagApp_LockCheckFlow(void);
#endif
