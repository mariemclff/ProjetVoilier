#include "stm32f10x.h"
#include "MyGPIO.h"
#include "stdio.h"
#include "math.h"
#include  "macro.h"
#include  "MyTimer.h"
#include "PWM.h"
#include <math.h>
#include <stdlib.h>
#include "bordage.h"

int set (){
		//float arr, psc;
	MyTimer_Struct_TypeDef  * timer;
	MyGPIO_Struct_TypeDef * gpio;
	int alpha = 999 ;

	gpio = malloc(sizeof(MyGPIO_Struct_TypeDef));
	timer = malloc(sizeof(MyTimer_Struct_TypeDef));

	/*arr=0xFFFF;
	psc=(0.5*72.0e6)/(arr+1.0);
	arr=(float)(floor(0.5*72.0e6/(psc+1.0)));
	*/
	
	gpio->GPIO = GPIOA;
 	gpio->GPIO_Pin = 6;
	gpio->GPIO_Conf = AltOut_Ppull;
	MyGPIO_Init(gpio);
		//RCC->APB1ENR |= RCC_APB1ENR_TIM3EN ;
	timer ->Timer  = TimerCap;

	
	MyTimer_Base_Init(timer);
	MyTimer_Base_Start (timer ) ;

	
	
	//alpha = MyTimer_Get_CNT ( timer ) >> 2 ;
	//alpha = 70;
	//Cycle = set_rap_cyc ( alpha ) ;
	
	
}

int maincap ( int Cycle ) {


	
	while(1);
}
