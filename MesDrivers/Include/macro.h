#ifndef MACRO_H
#define MACRO_H
#include "stm32f10x.h"

#define TimerBordage TIM2
#define GPIOBordage GPIOA
#define PinIndex 8 //PA8 Signal I
#define PinChannel1 0 //Channel1 PA0 Signal B
#define PinChannel2 1 //Channel2 PA7 Signal A devient PA1

//dans la datasheet pages 29-30-31
//#define TxPin_UART1 9 //transmission
//#define RxPin_UART1 10 //réception
//#define GPIO_UART1 GPIOA

#define TxPin_UART3 9 // pin transmission
#define RxPin_UART3 10 //pin réception
#define GPIO_UART3 GPIOB

// VALEURS ANGLES

#define TimerCap TIM3
#define GPIOCap (GPIOA)
#define PinCapIn 6 //PA6 pour l'entrée PWM
#define PinCapOut1 9 //PA9 pour une des sorties 
#define PinCapOut2 10 //PA10 pour l'autre



typedef struct
{
TIM_TypeDef * Timer ; // TIM1 à TIM4
unsigned short ARR ;
unsigned short PSC ;
} MyTimer_Struct_TypeDef ;


typedef struct{
	GPIO_TypeDef * GPIO ;
	char GPIO_Pin ; //numero de 0 a 15
	char GPIO_Conf ; 
} MyGPIO_Struct_TypeDef ;


#endif


