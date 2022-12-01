#include  "MyGPIO.h"
#include  "MyTimer.h"
#include  "PWM.h"
#include  "macro.h"
#include "principal_cap.h"
#include <math.h>
#include <stdlib.h>

void mainbordage () {

	int test = 0 ;
	int alpha = 999 ;
	int cycle;
	
	//bordage : 
	MyTimer_Struct_TypeDef TimerStruct ;
	MyGPIO_Struct_TypeDef GPIOIndex , GPIOCH1 , GPIOCH2 ;
	
	//PWM
	MyTimer_Struct_TypeDef  * timer;
	MyGPIO_Struct_TypeDef * gpio;

	gpio = malloc(sizeof(MyGPIO_Struct_TypeDef));
	timer = malloc(sizeof(MyTimer_Struct_TypeDef));
	
	timer ->Timer  = TimerCap;
	gpio->GPIO = GPIOCap;
 	gpio->GPIO_Pin = PinCapIn;
	gpio->GPIO_Conf = AltOut_Ppull;
	
	
	//bordage :
	//set up GPIOA et Pin sur lequel on prend I
	//MyGPIO_Struct_TypeDef * GPIOStruct = {GPIOBordage, 5, In_Floating};
	GPIOIndex.GPIO = GPIOBordage ;
	GPIOIndex.GPIO_Pin = PinIndex ;
	GPIOIndex.GPIO_Conf = In_Floating ;

	GPIOCH1.GPIO = GPIOBordage ;
	GPIOCH1.GPIO_Pin = PinChannel1 ;
	GPIOCH1.GPIO_Conf = In_Floating ;

	GPIOCH2.GPIO = GPIOBordage ;
	GPIOCH2.GPIO_Pin = PinChannel2 ;
	GPIOCH2.GPIO_Conf = In_Floating ;
	
	//set up structure Timer

	TimerStruct.Timer = TimerBordage  ;
	TimerStruct.ARR = 1439 ;
	
	 
	MyGPIO_Init (&GPIOIndex) ;
	MyGPIO_Init (&GPIOCH1) ;
	MyGPIO_Init (&GPIOCH2) ;
	MyTimer_Base_Init ( &TimerStruct ) ;
	MyTimer_Set_CI ( &TimerStruct , TimerStruct.ARR ) ;
	MyTimer_Base_Start ( &TimerStruct ) ;
	
	//PWM : 
	MyGPIO_Init(gpio);
	MyTimer_Base_Init(timer);
	MyTimer_Base_Start (timer ) ;

	
	
	while (test == 0) {
		test = MyGPIO_Read ( GPIOIndex.GPIO , GPIOIndex.GPIO_Pin ) ;
	}
	
	MyTimer_Set_CNT ( &TimerStruct , 0 ) ;
	
	while(1){
		
		//on divise par 4 le chiffre r&cupéré sur le compteur pour retrouver l'angle car l'ARR impose une précision au quart de degré
		alpha = MyTimer_Get_CNT ( &TimerStruct ) >> 2 ;
		
		cycle = set_rap_cyc ( alpha ) ;
		
		rapport_pwm(timer,1,10);
		//fonction servo (alpha) qui bouge servo selon les critères demandés
	}
}
	

