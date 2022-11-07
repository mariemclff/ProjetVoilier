#ifndef MACRO_H
#define MACRO_H
#include "stm32f10x.h"

#define TimerBordage TIM3
#define GPIOBordage GPIOA 
#define PinIndex 8 //PA8
#define PinChannel1 6 //Channel1 PA6
#define PinChannel2 7 //Channel2 PA7

#define TimerCap TIM2
#define GPIOCap GPIOC
#define PinCapIn 8 //PC8 pour l'entrée
#define PinCapOut1 9 //PC9 pour une des sorties
#define PinCapOut2 10 //PC10 pour l'autre

#define PWM_RAPPORT_CYCLIQUE 
#define PWM_ARR
#define PWM_PSC (PWM_RAPPORT_CYCLIQUE/PWM_ARR)

#endif


