/* ************************************************************************** */
#ifndef MAINAPP_H    /* Guard against multiple inclusion */
#define MAINAPP_H
/* ************************************************************************** */
#define STATE_BOOT          0x00U
#define STATE_PRENORMAL     0x01U
#define STATE_HANDSHAKE     0x02U
#define STATE_NORMAL        0x03U
#define STATE_PRESLEEP      0x04U
#define STATE_SLEEP         0x05U
#define STATE_WAKE_HOST     0x06U  

uint8_t MainApp_Task(void);

#endif
/* *****************************************************************************
 End of File
 */