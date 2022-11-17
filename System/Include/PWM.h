
#ifndef PWM_H
#define PWM_H
#include "stm32f10x.h"

#include  "macro.h"

int set_rap_cyc ( int angle_wind);

void rapport_pwm (MyTimer_Struct_TypeDef * TimerStruct, int canal , int Cycle);

#endif
