/* ************************************************************************** */
/** Descriptive File Name
  @Company
    AUO
  @File Name
    MainApp.c
  @Summary
    Start state machine with function - Power Management APP.
  @Description
    RUN Main APP with State .
 **/
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

#include "main.h"
#include "app/inc/MainApp.h"
#include "app/inc/TC0App.h"
#include "app/inc/StackTaskApp.h"
#include "app/inc/RegisterApp.h"
#include "app/inc/BacklightApp.h"
#include "app/inc/I2C2SlaveApp.h"
#include "app/inc/INTBApp.h"
#include "app/inc/DeviceApp.h"
#include "app/inc/WdtApp.h"
#include "driver/inc/UartDriver.h"
#include "driver/inc/AdcDriver.h"
#include "driver/inc/I2C1MDriver.h"
#include "driver/inc/PwmDriver.h"

#define CY_ASSERT_FAILED          (0u)

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

static uint8_t u8MAIN_STATUS = STATE_BOOT;
static uint8_t u8TxBuffer[60] = {0};

/*  Function: MainApp_Boot_Mode
**  Callfrom: Main_Flow state machine
**        Do: Do basic initial like PORT/CLOCK and other mustbe function.
**        Go: Go back to SLEEP mode if WAKEUP PIN is LOW, otherwise go to PRENORMAL mode for fully initial.
 */
static uint8_t MainApp_Boot_Mode(uint8_t u8Nothing)
{
    uint8_t u8Return;
    uint32_t result = 0U;
    /* Initialize the device and board peripherals */
    result = cybsp_init();

    /* Board init failed. Stop program execution */
    if (result != CY_RSLT_SUCCESS)
    {
        CY_ASSERT(CY_ASSERT_FAILED);
        u8Return = STATE_PRESLEEP;
    }
    else{
        u8Return = STATE_PRENORMAL;
    }

    /* Configure and enable the UART peripheral */
    UartDriver_Initial();
    TC0App_Initial();
    if(I2C1MDriver_Initialize() == false)
    {
        UartDriver_TxWriteString((uint8_t *)"I2C M driver init fail\r\n");
    }
    RegisterApp_ALL_Initial();
    RegisterApp_DHU_Setup(CMD_DISP_STATUS,1U,0xF3);
    I2C2SlaveApp_Initial();
    StackTaskApp_Global_MissionInitial();
    BacklightApp_Initial();
    DeviceApp_Intial();
    /* Enable global interrupts */
    __enable_irq();
    
    WdtApp_Initial();
    sprintf((char *)u8TxBuffer,"BOOT FINISHED\r\n");
    UartDriver_TxWriteString(u8TxBuffer);
    (void) u8Nothing;
    return u8Return;
}

/*  Function: MainApp_PreNormal_Mode
**  Callfrom: Main_Flow state machine
**        Do: Do all initial like SERCOM/ADC/TC and other mustbe function.
**        Go: Strightly go into NORMAL mode.
 */
static uint8_t MainApp_PreNormal_Mode(uint8_t u8Nothing)
{
    /*ADC initial*/
    TC0App_NormalWorkStartSet(TRUE);
    AdcDriver_Initial(ADC_SAR0_TYPE, ADC_SAR0_CONFIG);
    /*Do LCD Power On Sequence*/
    sprintf((char *)u8TxBuffer,"PRENORMAL FINISHED\r\n");
    UartDriver_TxWriteString(u8TxBuffer);
    (void) u8Nothing;
    return STATE_HANDSHAKE;
}

/*  Function: MainApp_Normal_Mode
**  Callfrom: Main_Flow state machine
**        Do: Do most time function.
**        Go: Strightly go into NORMAL mode.
 */
static uint8_t MainApp_HandShake_Mode(uint8_t u8Nothing)
{
    
    /*Do or Check Handshake function*/
    sprintf((char *)u8TxBuffer,"HANDSHAKE FINISHED\r\n");
    UartDriver_TxWriteString(u8TxBuffer);
    (void) u8Nothing;
    return STATE_NORMAL;
}

/*  Function: MainApp_Normal_Mode
**  Callfrom: Main_Flow state machine
**        Do: Do most time function.
**        Go: Strightly go into NORMAL mode.
 */
static uint8_t MainApp_Normal_Mode(uint8_t u8Nothing)
{
    uint8_t u8Return;

    StackTaskApp_MissionAction();
    INTBApp_Flow();
    // sprintf((char *)u8TxBuffer,"NORMAL FINISHED 0x%02x\r\n",RegisterApp_DHU_Read(CMD_DISP_STATUS,0U));
    // UartDriver_TxWriteString(u8TxBuffer);
    if((RegisterApp_DHU_Read(CMD_DISP_SHUTD,1U) & 0x01U) == 0x00U)
    {
        u8Return = STATE_NORMAL;
    }else{
        u8Return = STATE_PRESLEEP;
    }
    WdtApp_Initial();
    /* Test WDT timeout*/
    //TC0App_DelayMS(5000U);
    (void) u8Nothing;
    return u8Return;
}

/*  Function: MainApp_PreSleep_Mode
**  Callfrom: Main_Flow state machine
**        Do: De-Init Driver & Power Off Seq
**        Go: Strightly go into SLEEP mode.
 */
static uint8_t MainApp_PreSleep_Mode(uint8_t u8Nothing)
{
    uint8_t u8Return;
    /* Do LCD Power Off Sequence*/
    INTBApp_InitSwitch(INTB_DEINITIAL);
    sprintf((char *)u8TxBuffer,"PRESLEEP FINISHED\r\n");
    UartDriver_TxWriteString(u8TxBuffer);
    u8Return = STATE_SLEEP;
    (void) u8Nothing;
    return u8Return;
}

/*  Function: MainApp_Sleep_Mode
**  Callfrom: Main_Flow state machine
**        Do: ShutDown MCU / EN_DET CHECK
**        Go: Keep Sleep Mode until EN_DET is High (Before Power is Down)
 */
static uint8_t MainApp_Sleep_Mode(uint8_t u8Nothing)
{
    uint8_t u8Return;
    INTBApp_Flow();
    /* Do Power Off Sequence*/
    sprintf((char *)u8TxBuffer,"SLEEP FINISHED\r\n");
    UartDriver_TxWriteString(u8TxBuffer);
    u8Return = STATE_SLEEP;
    (void) u8Nothing;
    return u8Return;
}

/*  Function: MainApp_Flow
**  Callfrom: MainApp_Task() at main.c
**        Do: Do State Machine Case
**        Go: loop state machine
 */
static uint8_t MainApp_Flow(uint8_t u8State)
{
    uint8_t u8CurrentState;
    
    switch(u8State)
    {
        case STATE_BOOT:
            u8CurrentState = MainApp_Boot_Mode(NOTHING);
        break;

        case STATE_PRENORMAL:
            u8CurrentState = MainApp_PreNormal_Mode(NOTHING);
        break;

        case STATE_HANDSHAKE:
            u8CurrentState = MainApp_HandShake_Mode(NOTHING);
        break;

        case STATE_NORMAL:
            u8CurrentState = MainApp_Normal_Mode(NOTHING);
        break;

        case STATE_PRESLEEP:
            u8CurrentState = MainApp_PreSleep_Mode(NOTHING);
        break;

        case STATE_SLEEP:
            u8CurrentState = MainApp_Sleep_Mode(NOTHING);;
        break;

        case STATE_WAKE_HOST:
            u8CurrentState = STATE_BOOT;
        break;

        default:
            u8CurrentState = STATE_BOOT;
        break;
    }

    return u8CurrentState;
}

uint8_t MainApp_Task(void)
{
    uint8_t u8Return = FALSE;
    uint8_t u8Status = u8MAIN_STATUS;
    u8Status = MainApp_Flow(u8Status);
    u8MAIN_STATUS = u8Status;
    
    if((u8Status != STATE_BOOT)
        && (u8Status != STATE_PRENORMAL)
        && (u8Status != STATE_NORMAL)
        && (u8Status != STATE_HANDSHAKE)
        && (u8Status != STATE_PRESLEEP)
        && (u8Status != STATE_SLEEP)
        && (u8Status != STATE_WAKE_HOST))
    {
        u8Return=FALSE;
    }
    else
    {
        u8Return=TRUE;
    }
    return u8Return;
}
/* *****************************************************************************
 End of File
 */
