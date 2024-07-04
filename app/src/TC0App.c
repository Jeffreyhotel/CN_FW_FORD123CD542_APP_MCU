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

#define CLOCK_48M_DELAY 7920U

static long int timercount_ms = 0;
static long int timercount_sec = 0;
static long int cpu_timer_ms=0;

static void TC0APP_TC0_Task_1000msec(void)
{
    StackTaskApp_MissionPush(TASK_DEBUGINFO);
}

static void TC0App_Callback_InterruptHandler(void)
{
    TC0Driver_IntFlagClean();
    timercount_ms = timercount_ms+1;
    cpu_timer_ms = cpu_timer_ms+1;

    if((timercount_ms % 1000) == 0)
    {
        TC0APP_TC0_Task_1000msec();
        timercount_sec = timercount_sec+1;
    }else{/*Do Nothing*/}
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

uint8_t TC0App_DelayMS(uint16_t delay)
{
    uint16_t count;
    uint16_t count2;
    for(count2= 0 ; count2< delay ; count2++)
    {
        for(count = 0 ; count < CLOCK_48M_DELAY ; count ++)
        {
            // __asm("nop");
            __NOP();
        }
    }
    return NOTHING;
}
