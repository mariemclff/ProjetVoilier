
#include "MyGPIO.h"

void MyGPIO_Init ( MyGPIO_Struct_TypeDef * GPIOStructPtr ){
	
RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4) ; 
	
	if ( GPIOStructPtr->GPIO_Pin < 8 ){
		GPIOStructPtr->GPIO -> CRL |= GPIOStructPtr->GPIO_Conf << GPIOStructPtr->GPIO_Pin*4 ;
	} else {
		GPIOStructPtr->GPIO -> CRH |= GPIOStructPtr->GPIO_Conf << (GPIOStructPtr->GPIO_Pin - 8)*4 ;
	}
}

int MyGPIO_Read ( GPIO_TypeDef * GPIO , char GPIO_Pin ){
	int rrdata = GPIO->IDR;
	rrdata = rrdata & (1<<GPIO_Pin);
	
	return rrdata >> GPIO_Pin;
	//return GPIO->IDR & (1<<GPIO_Pin) >> GPIO_Pin;
}
	
void MyGPIO_Set ( GPIO_TypeDef * GPIO , char GPIO_Pin ) {
	GPIO->BSRR = 1<<GPIO_Pin;}
	
void MyGPIO_Reset ( GPIO_TypeDef * GPIO , char GPIO_Pin ) {
	GPIO->BRR = 1<<GPIO_Pin;}
	
void MyGPIO_Toggle ( GPIO_TypeDef * GPIO , char GPIO_Pin ) {
	GPIO->IDR ^= 1 << GPIO_Pin;
}
	

