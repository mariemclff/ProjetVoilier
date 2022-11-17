
#ifndef PWM_H
#define PWM_H
#include "stm32f10x.h"


int set_rap_cyc ( int angle_wind);
void init (void);
void rapport_pwm (TIM_TypeDef TimerStruct, int canal , int Cycle);

#endif
