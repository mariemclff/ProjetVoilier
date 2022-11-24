#ifndef MACRO_H
#define MACRO_H
#include "stm32f10x.h"

#define TimerBordage TIM2
#define GPIOBordage GPIOA
#define PinIndex 8 //PA8
#define PinChannel1 6 //Channel1 PA6
#define PinChannel2 7 //Channel2 PA7

//dans la datasheet pages 29-30-31
#define TxPin_UART1 9 //transmission
#define RxPin_UART1 10 //réception
#define GPIO_UART1 GPIOA

#define TxPin_UART2 2
#define RxPin_UART2 3
#define GPIO_UART2 GPIOA

#define TxPin_UART3 10
#define RxPin_UART3 11
#define GPIO_UART3 GPIOB

// VALEURS ANGLES

#define TimerCap TIM3
#define GPIOCap (GPIOA)
#define PinCapIn 7 //PC8 pour l'entrée
#define PinCapOut1 9 //PC9 pour une des sorties
#define PinCapOut2 10 //PC10 pour l'autre

#define PWM_RAPPORT_CYCLIQUE 3600
#define PWM_ARR 100
#define PWM_PSC (PWM_RAPPORT_CYCLIQUE/PWM_ARR)

typedef struct
{
TIM_TypeDef * Timer ; // TIM1 à TIM4
unsigned short ARR ;
unsigned short PSC ;
} MyTimer_Struct_TypeDef ;


typedef struct{
	GPIO_TypeDef * GPIO ;
	char GPIO_Pin ; //numero de 0 a 15
	char GPIO_Conf ; // v o i r c i de s sou s
} MyGPIO_Struct_TypeDef ;


#endif


