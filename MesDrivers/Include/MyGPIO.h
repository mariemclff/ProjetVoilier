 
#ifndef MYGPIO_H
#define MYGPIO_H
#include "stm32f10x.h"
#include  "macro.h"



//modifier valeurs pour qu'elles soient pas en héxa + 
#define In_Floating 4
#define In_PullDown 8  
#define In_PullUp 8 
#define In_Analog 0 
#define Out_Ppull 1
#define Out_OD 5 
#define AltOut_Ppull 9
#define AltOut_OD 13

void MyGPIO_Init ( MyGPIO_Struct_TypeDef * GPIOStructPtr ) ;
int MyGPIO_Read ( GPIO_TypeDef * GPIO , char GPIO_Pin ) ; // re nv oie 0 ou a u t re chose d i f f e r e n t de 0
void MyGPIO_Set ( GPIO_TypeDef * GPIO , char GPIO_Pin ) ;
void MyGPIO_Reset ( GPIO_TypeDef * GPIO , char GPIO_Pin ) ;
void MyGPIO_Toggle ( GPIO_TypeDef * GPIO , char GPIO_Pin ) ;

#endif
