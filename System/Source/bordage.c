#include  "MyGPIO.h"
#include  "MyTimer.h"
#include  "macro.h"

int main () {

	int test = 0 ;
	
	//set up GPIOA et Pin sur lequel on prend I
	MyGPIO_Struct_TypeDef GPIOStruct ;
		GPIOStruct.GPIO = GPIOBordage ;
		GPIOStruct.GPIO_Pin = PinBordage ;
		GPIOStruct.GPIO_Conf = In_Floating ;
	
	//set up structure Timer
	MyTimer_Struct_TypeDef TimerStruct ;
		TimerStruct.ARR = TimerBordage ;
		TimerStruct.ARR = 360 ;
	
	MyTimer_Base_Init ( Timer ) ;
	MyTimer_Set_CI ( Timer, ARR ) ;
	
	while (test == 0) {
		test = MyGPIO_Read ( GPIO , Pin ) ;
	}
	
	MyTimer_Base_Start ( Timer ) ;

}