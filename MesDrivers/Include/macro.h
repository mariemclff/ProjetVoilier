#ifndef MACRO_H
#define MACRO_H
#include "stm32f10x.h"

#define TimerBordage TIM2
#define GPIOBordage GPIOA
#define PinIndex 8 //PA8
#define PinChannel1 0 //Channel1 PA6
#define PinChannel2 7 //Channel2 PA7

// VALEURS ANGLES

#define TimerCap TIM3
#define GPIOCap (GPIOA)
#define PinCapIn 6 //PA6 pour l'entr�e
#define PinCapOut1 9 //PC9 pour une des sorties
#define PinCapOut2 10 //PC10 pour l'autre



typedef struct
{
TIM_TypeDef * Timer ; // TIM1 � TIM4
unsigned short ARR ;
unsigned short PSC ;
} MyTimer_Struct_TypeDef ;


typedef struct{
	GPIO_TypeDef * GPIO ;
	char GPIO_Pin ; //numero de 0 a 15
	char GPIO_Conf ; // v o i r c i de s sou s
} MyGPIO_Struct_TypeDef ;


#endif


