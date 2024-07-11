/* ************************************************************************** */

/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */
#include "app/inc/TC0App.h"
#include "app/inc/StackTaskApp.h"
#include "driver/inc/TC0Driver.h"

#define CLOCK_48M_DELAY_MS 7920U
#define CLOCK_48M_DELAY_US 8U

static long int timercount_ms = 0;
static long int timercount_sec = 0;
static long int cpu_timer_ms=0;
static long int derating_timer_sec =0;
static long int batteryprotect_timer_sec =0;
static long int intb_set_timer_ms=0;
static long int intb_hold_timer_ms=0;
uint8_t FLAG_DERATINGCNT_START = FALSE;
uint8_t FLAG_BATTERYPROT_START = FALSE;
uint8_t FLAG_STARTTOWORK_START = FALSE;
uint8_t FLAG_INTBSETTCNT_START = FALSE;
uint8_t FLAG_INTBHOLDCNT_START = FALSE;

static void TC0APP_TC0_Task_1000msec(void)
{
    StackTaskApp_MissionPush(TASK_DEBUGINFO);
    StackTaskApp_MissionPush(TASK_MONITOR);
}

static void TC0APP_TC0_Task_10msec(void)
{
    StackTaskApp_MissionPush(TASK_BATFLOW);
}

static void TC0APP_TC0_Task_15msec(void)
{
    StackTaskApp_MissionPush(TASK_BLTFLOW);
}

static void TC0APP_TC0_Task_20msec(void)
{
    StackTaskApp_MissionPush(TASK_DIMMING);
}

static void TC0App_Callback_InterruptHandler(void)
{
    TC0Driver_IntFlagClean();
    timercount_ms = timercount_ms+1;
    cpu_timer_ms = cpu_timer_ms+1;
    if(FLAG_INTBSETTCNT_START == TRUE)
    {
        intb_set_timer_ms = intb_set_timer_ms+1;
    }
    if(FLAG_INTBHOLDCNT_START == TRUE)
    {
        intb_hold_timer_ms = intb_hold_timer_ms+1;
    }

    if(FLAG_STARTTOWORK_START == TRUE)
    {
        if ((timercount_ms % 10) ==0)
        {
            TC0APP_TC0_Task_10msec();
        }else{/*Do Nothing*/}

        if ((timercount_ms % 15) ==0)
        {
            TC0APP_TC0_Task_15msec();
        }else{/*Do Nothing*/}

        if ((timercount_ms % 20) ==0)
        {
            TC0APP_TC0_Task_20msec();
        }else{/*Do Nothing*/}
    }

    if((timercount_ms % 1000) == 0)
    {
        TC0APP_TC0_Task_1000msec();
        timercount_sec = timercount_sec+1;
        if(FLAG_DERATINGCNT_START == TRUE)
        {
            derating_timer_sec = derating_timer_sec +1U;
        }else{/*Do Nothing*/}
        if(FLAG_BATTERYPROT_START == TRUE)
        {
            batteryprotect_timer_sec = batteryprotect_timer_sec +1U;
        }else{/*Do Nothing*/}
    }else{/*Do Nothing*/}
}

void TC0App_DerateCntStartSet(uint8_t SetValue)
{
    FLAG_DERATINGCNT_START = SetValue;
}

void TC0App_BatteryCntStartSet(uint8_t SetValue)
{
    FLAG_BATTERYPROT_START = SetValue;
}

void TC0App_NormalWorkStartSet(uint8_t SetValue)
{
    FLAG_STARTTOWORK_START = SetValue;
}

void TC0App_IntbSetCountStartSet(uint8_t SetValue)
{
    FLAG_INTBSETTCNT_START = SetValue;
}

void TC0App_IntbHoldCountStartSet(uint8_t SetValue)
{
    FLAG_INTBHOLDCNT_START = SetValue;
}

void TC0App_Initial(void)
{
    if(true == TC0Driver_TimerCallbackRegister(TC0App_Callback_InterruptHandler))
    {
        if(true == TC0Driver_TimerStart())
        {
            /*Do nothing*/
        }else{/*Do nothing*/}
    }else{
        /*Flag error information*/
    }
}

uint8_t TC0App_TimerReturn(uint8_t Request)
{
	uint8_t u8Return;
	
    switch (Request)
    {
    case TIMER_CPUCOUNT:
        /* code */
        u8Return = (uint8_t)(((uint32_t)cpu_timer_ms) & 0XFFU);
        break;

    case TIMER_INT_SET_COUNT:
        /* code */
        u8Return = intb_set_timer_ms;
        break;

    case TIMER_INT_HOLD_COUNT:
        /* code */
        u8Return = intb_hold_timer_ms;
        break;

    case TIMER_HANDSHAKECOUNT:
        /* code */
        u8Return = 0xFFU;
        break;

    case TIMER_DERATECOUNT:
        /* code */
        u8Return = derating_timer_sec;
        break;

    case TIMER_BATTERYCOUNT:
        /* code */
        u8Return = batteryprotect_timer_sec;
        break;

    default:
        u8Return = 0xFFU;
        break;
    }

    return u8Return;
}

void TC0App_TimerReset(uint8_t Request)
{
    switch (Request)
    {
    case TIMER_CPUCOUNT:
        /* code */
        cpu_timer_ms = 0U;
        break;

    case TIMER_INT_SET_COUNT:
        /* code */
        intb_set_timer_ms = 0U;
        break;

    case TIMER_INT_HOLD_COUNT:
        /* code */
        intb_hold_timer_ms = 0U;
        break;

    case TIMER_HANDSHAKECOUNT:
        /* code */
        
        break;

    case TIMER_DERATECOUNT:
        /* code */
        derating_timer_sec = 0U;
        break;

    case TIMER_BATTERYCOUNT:
        /* code */
        batteryprotect_timer_sec = 0U;
        break;

    default:
		/*DO NOTHING*/
        break;
    }
}

uint8_t TC0App_DelayMS(uint16_t delay)
{
    uint16_t count;
    uint16_t count2;
    for(count2= 0 ; count2< delay ; count2++)
    {
        for(count = 0 ; count < CLOCK_48M_DELAY_MS ; count ++)
        {
            // __asm("nop");
            __NOP();
        }
    }
    return NOTHING;
}

uint8_t TC0App_DelayUS(uint16_t delay)
{
    uint16_t count;
    uint16_t count2;
    for(count2= 0 ; count2< delay ; count2++)
    {
        for(count = 0 ; count < CLOCK_48M_DELAY_US ; count ++)
        {
            // __asm("nop");
            __NOP();
        }
    }
    return NOTHING;
}
