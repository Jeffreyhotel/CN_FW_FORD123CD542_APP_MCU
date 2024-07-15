#include "app/inc/UartApp.h"
#include "app/inc/StackTaskApp.h"
#include "driver/inc/UartDriver.h"

bool UartApp_CompareBuffer(char *StringSource, uint8_t rdBuffer[], uint8_t start_pos, uint8_t stop_pos)
{
    bool bresult = false;
    uint8_t u8buffer[255] = {0};
    if(start_pos >= stop_pos)
    {
        for (uint8_t index = 0U;index<(stop_pos-start_pos+1U);index++)
        {
            u8buffer[index] = rdBuffer[index+start_pos];
        }
        if (strcmp(StringSource,(char *)u8buffer) != 0x01U){
            bresult = false;
        }else{
            bresult = true;
        }
    }else{
        bresult = false;
    }
    return bresult;
}

void UartApp_ReadFlow()
{
    uint8_t rdBuffer[255] = {0};
    uint8_t result = UART_RX_EMPTY;
    result = UartDriver_Receive(&rdBuffer[0],sizeof(rdBuffer));
    if(result == UART_SUCCESS)
    {
        if(rdBuffer[0] != 0x00U){
            switch (rdBuffer[0])
            {
            case 0x31:
                /* code */
                StackTaskApp_MissionPush(TASK_MONITOR);
                break;
            
            default:
                break;
            }
        }
    }else{
        /* No data received*/
    }
    /* Clean all data buffer*/
    UartDriver_AbortReceive();
}
