/* ************************************************************************** */
/** Descriptive File Name
  @Company
    AUO
  @File Name
    MainApp.c
  @Summary
    Start state machine with function - Main Management APP.
  @Description
    RUN Main APP with State .
 **/
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

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
#include "app/inc/PowerApp.h"
#include "app/inc/FlashApp.h"
#include "app/inc/DiagApp.h"
#include "app/inc/UartApp.h"
#include "driver/inc/UartDriver.h"
#include "driver/inc/AdcDriver.h"
#include "driver/inc/I2C4MDriver.h"
#include "driver/inc/PwmDriver.h"

#define CY_ASSERT_FAILED          (0u)
#define APP_START_ADDR          0x3000U

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
    uint32_t PC = (uint32_t)(&MainApp_Task);
    result = cybsp_init();
    // (void)Cy_GPIO_Pin_FastInit(GPIO_PRT0, 4U, CY_GPIO_DM_ANALOG, 0x00U, HSIOM_SEL_GPIO);
    // (void)Cy_GPIO_Pin_FastInit(GPIO_PRT0, 5U, CY_GPIO_DM_ANALOG, 0x00U, HSIOM_SEL_GPIO);
    Cy_SysClk_WcoBypass(false);
    /* Cypress WCO chip spec request 500ms for TS START (set as 500000UL)*/
    Cy_SysClk_WcoEnable(1000UL);

    /* Board init failed. Stop program execution */
    if (result != CY_RSLT_SUCCESS)
    {
        //CY_ASSERT(CY_ASSERT_FAILED);
        u8Return = STATE_BOOT;
    }
    else{
        u8Return = STATE_SLEEP;
    }
    WdtApp_CleanCounter();
    /* Configure and enable the UART peripheral */
    UartDriver_Initial();
    TC0App_Initial();
    if(I2C4MDriver_Initialize() == false)
    {
        UartDriver_TxWriteString((uint8_t *)"I2C M driver init fail\r\n");
    }
    RegisterApp_ALL_Initial();
    I2C2SlaveApp_Initial();
    StackTaskApp_Global_MissionInitial();
    BacklightApp_Initial();
    DeviceApp_Intial();
    TC0App_DHUTaskClean();
    /*ADC initial*/
    AdcDriver_Initial(ADC_SAR0_TYPE, ADC_SAR0_CONFIG);
    PowerApp_PowerGoodInitial();
    /* Enable global interrupts */
    __enable_irq();
    /* WDT Init*/
    WdtApp_CheckResetCause();
    WdtApp_Initial();
    /* Power On Init*/
    PowerApp_Sequence(POWER_ON);
    /* Due to Bus pull up with P3V3 vout, Init after Power on seq; HW would change PCBA (pull up with MCU_3V3)*/
    I2C4MDriver_Initialize();
    TC0App_NormalWorkStartSet(TRUE);
    DiagApp_CheckFlowInitial();
    sprintf((char *)u8TxBuffer,"BOOT FINISHED, PC:0x%lX, POS:%02X\r\n",PC,MCU_POSITION);
    RegisterApp_DHU_Setup(CMD_DTC,DTC_APP_POS,MCU_POSITION);
    UartDriver_TxWriteString(u8TxBuffer);
    /* Only for LED Driver test*/
    // PowerApp_LP8664_CurrentSet();
    /* Only for flash w/r test*/
    // uint8_t Flag[4] = {0x0F, 0x00, 0x00, 0x00};
    // FlashApp_WriteRowFlash(&Flag[0],0x0001F000,4U);
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
    WdtApp_CleanCounter();
    /*Do LCD Power On Sequence*/
    TC0App_TimerTaskStopper(true);
    PowerApp_Sequence(LCD_ON);
    TC0App_TimerTaskStopper(false);
    /* SWRA-01-06: Set DISP_STATUS 0x00 CMD Byte1 DISP_ST & BL_ST set as 1.*/
    DiagApp_DispStatusSet(DISP_STATUS_BYTE1,DISP1_DISPST_MASK);
    DiagApp_DispStatusSet(DISP_STATUS_BYTE1,DISP1_BLST_MASK);
    sprintf((char *)u8TxBuffer,"PRENORMAL FINISHED\r\n");
    UartDriver_TxWriteString(u8TxBuffer);
    StackTaskApp_MissionPush(TASK_LCDVERS);
    /* Need to put at the end of prenormal task*/
    (void) u8Nothing;
    return STATE_NORMAL;
}

/*  Function: MainApp_Normal_Mode
**  Callfrom: Main_Flow state machine
**        Do: Do most time function.
**        Go: Strightly go into NORMAL mode.
 */
static uint8_t MainApp_HandShake_Mode(uint8_t u8Nothing)
{
    uint8_t u8Return;
    WdtApp_CleanCounter();
    /* Check Disp En Cmd*/
    if(RegisterApp_DHU_Read(CMD_DISP_EN,CMD_DATA_POS) == 0x01U)
    {
        u8Return = STATE_NORMAL;
        sprintf((char *)u8TxBuffer,"HANDSHAKE FINISHED\r\n");
    }else{
        u8Return = STATE_HANDSHAKE;
        sprintf((char *)u8TxBuffer,"WAIT HANDSHAKE\r\n");
    }
    /* Do or Check Handshake function*/
    UartDriver_TxWriteString(u8TxBuffer);
    /* Test Disp En Cmd -- need to be deleted*/
    RegisterApp_DHU_Setup(CMD_DISP_EN,CMD_DATA_POS,0x01U);
    (void) u8Nothing;
    return u8Return;
}

/*  Function: MainApp_Normal_Mode
**  Callfrom: Main_Flow state machine
**        Do: Do most time function.
**        Go: Strightly go into NORMAL mode.
 */
static uint8_t MainApp_Normal_Mode(uint8_t u8Nothing)
{
    uint8_t u8Return;
    WdtApp_CleanCounter();
    /* Do task & INTB flow*/
    StackTaskApp_MissionAction();
    INTBApp_Flow();
    // sprintf((char *)u8TxBuffer,"NORMAL FINISHED 0x%02x\r\n",RegisterApp_DHU_Read(CMD_DISP_STATUS,0U));
    // UartDriver_TxWriteString(u8TxBuffer);
    if((RegisterApp_DHU_Read(CMD_DISP_SHUTD,1U) & 0x01U) == 0x00U)
    {
        if((RegisterApp_DHU_Read(CMD_DISP_EN,1U) & 0x01U) == 0x01U)
        {
            u8Return = STATE_NORMAL;
        }else{
            u8Return = STATE_PRESLEEP;
        }
    }else{
        INTBApp_InitSwitch(INTB_DEINITIAL);
        u8Return = STATE_SHUTDOWN;
    }
    /* Test WDT timeout - ~3.2sec reset (ILO has 40Kz +/- 50%, so it should consider as 2.5)*/
    // TC0App_DelayMS(3000U);
    // WdtApp_CleanCounter();
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
    WdtApp_CleanCounter();
    /* SWRA-01-05: Set DISP_STATUS 0x00 CMD Byte1 DISP_ST & BL_ST set as 0.*/
    DiagApp_DispStatusClear(DISP_STATUS_BYTE1,DISP1_DISPST_MASK);
    DiagApp_DispStatusClear(DISP_STATUS_BYTE1,DISP1_BLST_MASK);
    /* Do LCD Power Off Sequence*/
    TC0App_TimerTaskStopper(true);
    PowerApp_Sequence(LCD_OFF);
    TC0App_TimerTaskStopper(false);
    /* SWRA-01-05: Timer Lock Hold set as 1000ms, avoid rapid-off/on behavior*/
    TC0App_TimerReset(TIMER_HOLDCOUNT);
    sprintf((char *)u8TxBuffer,"PRESLEEP FINISHED\r\n");
    UartDriver_TxWriteString(u8TxBuffer);
    u8Return = STATE_SLEEP;
    (void) u8Nothing;
    return u8Return;
}

/*  Function: MainApp_Sleep_Mode (Stand-by Mode)
**  Callfrom: Main_Flow state machine
**        Do: Do task & INTB flow
**        Go: Check if SHTDWN bit0 set as 1, Go to Shutdwon state.
**            Otherwise, Check if DISP_EN bit0 set as 0, Go to Prenormal state.
**            Inversely, Keep in sleep mode.
 */
static uint8_t MainApp_Sleep_Mode(uint8_t u8Nothing)
{
    uint8_t u8Return;
    WdtApp_CleanCounter();
    /* Do task & INTB flow*/
    StackTaskApp_MissionAction();
    INTBApp_Flow();
    /* Do Power Off Sequence*/
    sprintf((char *)u8TxBuffer,"SLEEP FINISHED\r\n");
    //UartDriver_TxWriteString(u8TxBuffer);
    if((RegisterApp_DHU_Read(CMD_DISP_SHUTD,1U) & 0x01U) == 0x00U)
    {
        if((RegisterApp_DHU_Read(CMD_DISP_EN,1U) & 0x01U) == 0x01U)
        {
            /* SWRA-01-05: Timer Lock Hold set as 1000ms, avoid rapid-off/on behavior*/
            /* TIMER_HOLDCOUNT will return 0xFF if hold time > 1000ms*/
            if(TC0App_TimerReturn(TIMER_HOLDCOUNT) != 0x00U)
            {
                u8Return = STATE_PRENORMAL;
            }else{
                u8Return = STATE_SLEEP;
            }
        }else{
            u8Return = STATE_SLEEP;
        }
    }else{
        INTBApp_InitSwitch(INTB_DEINITIAL);
        u8Return = STATE_SHUTDOWN;
    }
    (void) u8Nothing;
    return u8Return;
}

/*  Function: MainApp_Shutdown_Mode
**  Callfrom: Main_Flow state machine
**        Do: Power off (Disable 3V3 / 1V2 / PDB ...), and wait for Power down (Shutdown MCU anyway).
**        Go: If SHTDWN set as 1, keep shutdown mode. Otherwise, go to SLEEP(TBD, No possible specification)
 */
static uint8_t MainApp_Shutdown_Mode(uint8_t u8Nothing)
{
    uint8_t u8Return;
    WdtApp_CleanCounter();
    /* SWRA-01-07: Set DISP_STATUS 0x00 CMD Byte1 DISP_ST & BL_ST set as 0.*/
    DiagApp_DispStatusClear(DISP_STATUS_BYTE1,DISP1_DISPST_MASK);
    DiagApp_DispStatusClear(DISP_STATUS_BYTE1,DISP1_BLST_MASK);
    TC0App_NormalWorkStartSet(FALSE);
    /* Do Power Off Sequence*/
    INTBApp_Flow();
    PwmDriver_Stop();
    PowerApp_Sequence(LCD_OFF);
    PowerApp_Sequence(POWER_OFF);
    TC0App_DelayMS(500U);
    UartApp_ReadFlow();
    sprintf((char *)u8TxBuffer,"ShutDown... wait for power down\r\n");
    UartDriver_TxWriteString(u8TxBuffer);
    u8Return = STATE_SHUTDOWN;
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
            u8CurrentState = MainApp_Sleep_Mode(NOTHING);
        break;

        case STATE_WAKE_HOST:
            u8CurrentState = STATE_BOOT;
        break;

        case STATE_SHUTDOWN:
            u8CurrentState = MainApp_Shutdown_Mode(NOTHING);
        break;

        default:
            u8CurrentState = STATE_BOOT;
        break;
    }
    if(u8State != 0x00U)
    {
        RegisterApp_DHU_Setup(CMD_DTC,DTC_MAIN_STATE,u8State);
    }else{
        /* Do nothing*/
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
