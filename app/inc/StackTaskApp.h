#ifndef StackTaskApp_H__
#define StackTaskApp_H__

#include "main.h"

#define StackTaskMaxSize 200U
#define MissionUnderFlow 0xFFU

#define MISSION_NUM_ONE     1U
#define MISSION_NUM_TWO     2U
#define MISSION_NUM_THREE   3U

#define TASK_DEBUGINFO  0U

typedef struct{
    volatile uint8_t data[StackTaskMaxSize];
    volatile int top;
}Stack;

uint8_t StackTaskApp_TaskNumberReturn(void);

void StackTaskApp_Global_MissionInitial(void);

void StackTaskApp_MissionPush(uint8_t u8TaskNumber);

void StackTaskApp_MissionAction(void);

#endif

