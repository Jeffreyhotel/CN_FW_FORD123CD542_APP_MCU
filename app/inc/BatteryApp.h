#ifndef BATTERYAPP_H__
#define BATTERYAPP_H__

#define BT_NORMAL       0x00U
#define BT_LOWHIGH      0x01U
#define BT_OVERPOWER    0x02U

void BatteryApp_PowerMonitor(void);
void BatteryApp_Flow(void);

#endif

