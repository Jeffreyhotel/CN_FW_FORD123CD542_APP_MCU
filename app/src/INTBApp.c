#include "app/inc/INTBApp.h"
#include "app/inc/TC0App.h"
#include "driver/inc/PortDriver.h"

static uint8_t u8IntbCurrentState = INTB_STATE_INIT;
static uint8_t FLAG_PULL_REQ = INTB_REQ_CLEAR;
static uint8_t SWITCH_INIT_STATE = INTB_INITIAL;
static uint8_t u8quene_error_num = 0U;

static uint8_t INTBApp_Init_Mode(void)
{
    return INTB_STATE_IDLE;
}

static uint8_t INTBApp_Idle_Mode(void)
{
    uint8_t u8return = INTB_STATE_IDLE;
    TC0App_IntbSetCountStartSet(TRUE);
    TC0App_IntbHoldCountStartSet(FALSE);
    TC0App_TimerReset(TIMER_INT_HOLD_COUNT);
    PortDriver_PinSet(DES_INTB_PORT,DES_INTB_PIN);
    if(SWITCH_INIT_STATE == INTB_DEINITIAL)
    {
        u8return = INTB_STATE_DEINIT;
    }else if(FLAG_PULL_REQ == INTB_REQ_SET && (u8quene_error_num != 0UL)){
        u8return = INTB_STATE_SET;
        /* Avoid Interrupt impact*/
        if(u8quene_error_num > 0)
        {
            u8quene_error_num --;
        }else{/* Do nothing*/}
    }else{
        u8return = INTB_STATE_IDLE;
    }
    return u8return;
}

static uint8_t INTBApp_Set_Mode(void)
{
    uint8_t u8return = INTB_STATE_SET;
    TC0App_IntbSetCountStartSet(TRUE);
    PortDriver_PinSet(DES_INTB_PORT,DES_INTB_PIN);
    if(TC0App_TimerReturn(TIMER_INT_SET_COUNT) > 2U)
    {
        u8return = INTB_STATE_HOLD;
    }else{
        u8return = INTB_STATE_SET;
    }
    return u8return;
}

static uint8_t INTBApp_Hold_Mode(void)
{
    uint8_t u8return = INTB_STATE_HOLD;
    TC0App_IntbSetCountStartSet(FALSE);
    TC0App_IntbHoldCountStartSet(TRUE);
    TC0App_TimerReset(TIMER_INT_SET_COUNT);
    PortDriver_PinClear(DES_INTB_PORT,DES_INTB_PIN);
    if(TC0App_TimerReturn(TIMER_INT_HOLD_COUNT) > 2U)
    {
        u8return = INTB_STATE_IDLE;
    }else{
        u8return = INTB_STATE_HOLD;
    }
    return u8return;
}

static uint8_t INTBApp_Deinit_Mode(void)
{
    uint8_t u8return = INTB_STATE_DEINIT;
    TC0App_IntbSetCountStartSet(FALSE);
    TC0App_IntbHoldCountStartSet(FALSE);
    TC0App_TimerReset(TIMER_INT_SET_COUNT);
    TC0App_TimerReset(TIMER_INT_HOLD_COUNT);
    if(SWITCH_INIT_STATE == INTB_DEINITIAL)
    {
        u8return = INTB_STATE_DEINIT;
    }else if(SWITCH_INIT_STATE == INTB_INITIAL){
        u8return = INTB_STATE_INIT;
    }else{
        u8return = INTB_STATE_DEINIT;
    }
    return u8return;
}

void INTBApp_PullReqSetOrClear(uint8_t u8SetValue)
{
    FLAG_PULL_REQ = u8SetValue;
    if(FLAG_PULL_REQ == INTB_REQ_SET)
    {
        u8quene_error_num = (u8quene_error_num == 0xFFU) ? u8quene_error_num : u8quene_error_num+1 ;
    }else{
        u8quene_error_num = 0U;
    }
}

void INTBApp_InitSwitch(uint8_t u8SetValue)
{
    SWITCH_INIT_STATE = u8SetValue;
}

/*  Function: INTBApp_Flow
**  Callfrom: INTBApp_Flow() at mainapp.c
**        Do: Do State Machine Case
**        Go: loop state machine
 */
void INTBApp_Flow(void)
{
    switch(u8IntbCurrentState)
    {
        case INTB_STATE_INIT:
            u8IntbCurrentState = INTBApp_Init_Mode();
        break;

        case INTB_STATE_IDLE:
            u8IntbCurrentState = INTBApp_Idle_Mode();
        break;

        case INTB_STATE_SET:
            u8IntbCurrentState = INTBApp_Set_Mode();
        break;

        case INTB_STATE_HOLD:
            u8IntbCurrentState = INTBApp_Hold_Mode();
        break;

        case INTB_STATE_DEINIT:
            u8IntbCurrentState = INTBApp_Deinit_Mode();
        break;

        default:
            u8IntbCurrentState = INTB_STATE_INIT;
        break;
    }
}