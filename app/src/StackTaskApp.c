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

#include "app/inc/StackTaskApp.h"
#include "app/inc/BacklightApp.h"
#include "app/inc/BatteryApp.h"
#include "app/inc/RegisterApp.h"
#include "app/inc/TC0App.h"
#include "app/inc/INTBApp.h"
#include "app/inc/DiagApp.h"
#include "app/inc/UartApp.h"
#include "app/inc/PowerApp.h"
#include "app/inc/UpdateApp.h"
#include "driver/inc/AdcDriver.h"
#include "driver/inc/UartDriver.h"
#include "driver/inc/I2C4MDriver.h"

#define FIFO true

static Stack stacktask;
static uint8_t TaskNumber = 0U;
static int32_t QueneNumber;

static uint8_t u8TxBuffer[60] = {0};

uint8_t StackTaskApp_TaskNumberReturn(void)
{
    return TaskNumber;
}

static void StackTaskApp_Initial(Stack* stack)
{
    stack->top = -1;
}

void StackTaskApp_Global_MissionInitial(void)
{
    StackTaskApp_Initial(&stacktask);
}

/*  Function: StackTaskApp_ReturnQueneNumber
**  Callfrom: MainApp.c / TcApp.c / 
**        Do: Return mission for stack Task (First in First out)
**        Go: No Return
 */
static int32_t StackTaskApp_ReturnQueneNumber(Stack* stack)
{
    return stack->top;
}

static int32_t StackTaskApp_MissionReturnQueneNumber(void)
{
    return StackTaskApp_ReturnQueneNumber(&stacktask);
}


/*  Function: StackTaskApp_MissionPush
**  Callfrom: MainApp.c / TcApp.c / 
**        Do: PUSH mission for stack Task (First in First out)
**        Go: No Return
 */
static uint8_t StackTaskApp_Push(Stack* stack, uint8_t u8TaskNumber)
{
    uint8_t ErrorFlag = 0U;
	
	// volatile var should not be used in complex expression. Store it to stack first.
	int top = stack->top;
    if ((top >= (int32_t)(StackTaskMaxSize - 1U)) || (top < -1))
    {
        /*Over Flow Error Flag*/
        ErrorFlag = 1U;
        //RegisterApp_DHU_Setup(CMDID_COMP,COMP_OFFSET_OVERFLOW,0xFF);
    }
    else
    {
        stack->top = stack->top + 1;
        stack->data[stack->top] = u8TaskNumber; 
        (void)(stack->data[stack->top]);
        ErrorFlag = 0U;
    }
    return ErrorFlag;
}

void StackTaskApp_MissionPush(uint8_t u8TaskNumber)
{
    (void)StackTaskApp_Push(&stacktask,u8TaskNumber);
}

/*  Function: StackTaskApp_MissionPop
**  Callfrom: MainApp.c / TcApp.c / 
**        Do: POP mission for stack Task (First in First out)
**        Go: Return data position
 */
static uint8_t StackTaskApp_Pop(Stack* stack)
{
	uint8_t u8Return;
    uint8_t ErrorFlag = 0U;
    uint8_t datatmp = 0U;
    // uint32_t u32Index = 0;
	int32_t s32StackTaskMaxSize = (int32_t)StackTaskMaxSize;
	
	int top = stack->top;
    if ((top <= -1))
    {
        /*Under Flow Error Flag*/
        ErrorFlag = 255U;
        u8Return = ErrorFlag;
    }
	else if(top >= s32StackTaskMaxSize)
	{
		/*Under Flow Error Flag*/
        ErrorFlag = 255U;
        u8Return = ErrorFlag;
	}
    else
    {
#if FIFO
        if (stack->top == 0)
        {
            datatmp = stack->data[0];
        }else
        {
            datatmp = stack->data[0];
			
            for(int32_t s32Index = 0; s32Index < (stack->top); s32Index = s32Index+1)
            {
                stack->data[s32Index] = stack->data[s32Index+1];
            }
        }
        stack->top = stack->top - 1;
#else   /*LIFO*/
        datatmp = stack->data[stack->top];
        stack->top = stack->top - 1;
#endif
        u8Return = datatmp;
    }

	(void)ErrorFlag;
	(void)datatmp;
    (void)(stack->data);
	
	return u8Return;
}

static uint8_t StackTaskApp_MissionPop(void)
{
    return StackTaskApp_Pop(&stacktask);
}

/*  Function: StackTaskApp_MissionAction
**  Callfrom: MainApp_Normal_Mode()
**        Do: Do single mission from StackTask pool (First in First out)
**            Case Task define at StackTaskApp.h
**        Go: No Return
 */
void StackTaskApp_MissionAction(void)
{
    TC0App_TimerReset(TIMER_CPUCOUNT);
    (void)QueneNumber;
    //TC0App_TimerTaskStopper(true);
    QueneNumber = StackTaskApp_MissionReturnQueneNumber();
    (void)QueneNumber;
    TaskNumber = StackTaskApp_MissionPop();
    //TC0App_TimerTaskStopper(false);
    switch(TaskNumber)
    {
        case TASK_DEBUGINFO:
            /*Do nothing*/
            UartApp_ReadFlow();
        break;

        case TASK_MONITOR:
            BacklightApp_TempMonitor();
            BatteryApp_PowerMonitor();
        break;

        case TASK_BLTFLOW:
            BacklightApp_DeratingFlow();
        break;

        case TASK_DIMMING:
            BacklightApp_DimmingControl();
        break;

        case TASK_BATFLOW:
            BatteryApp_Flow();
        break;

        case TASK_PWGFLOW: /* 100ms Task*/
            PowerApp_PowerGoodFlow();
            /* RTQ6749 only check i2c when hardware pin BIAS_FAULT pull low (DiagApp_BiasFaultCheckFlow())
            PowerApp_RTQ6749_FaultCheck();
            */
            DiagApp_BiasFaultCheckFlow();
        break;

        case TASK_LEDFLOW:
            DiagApp_LedFaultCheckFlow();
        break;

        case TASK_IOCHECK:
            DiagApp_LockCheckFlow();
            DiagApp_FpcCheckFlow();
        break;

        case TASK_LCDFLOW:
            DiagApp_LcdFaultCheckFlow();
        break;

        case TASK_UPDATE_ERASE:
            UpdateApp_EraseFlashMCU();
        break;

        case TASK_UPDATE_TRANS:
            UpdateApp_TransferFlashMCU();
        break;

        case TASK_UPDATE_CRCSM:
            UpdateApp_ChecksumFlashMCU();
        break;

        case TASK_UPDATE_RESET:
            UpdateApp_McuReset();
        break;

        default:
            /*Do nothing*/
        break;
    }
    /* Show the CPU information exclude Overflow*/
    //if (TaskNumber == 0xFFU || TaskNumber == TASK_BLTFLOW || TaskNumber == TASK_DIMMING || TaskNumber == TASK_BATFLOW || TaskNumber == TASK_PWGFLOW){
    if (TaskNumber == 0xFFU){
        /*DO NOTHING*/
    }else{
        if (TC0App_TimerReturn(TIMER_CPUCOUNT)>3U)
        {
            sprintf((char *)u8TxBuffer,"LOADING:%d QLINE> %ld TASK> %d\r\n",TC0App_TimerReturn(TIMER_CPUCOUNT),QueneNumber,TaskNumber);
            UartDriver_TxWriteString(u8TxBuffer);
        }
    }

    (void)QueneNumber;
}
