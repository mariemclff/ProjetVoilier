
/*ARR/CRX : rapport entre front montant et front descendant 
72MHz et 20 khz de la pwm a mettre en forme pour avoir la bonne relation 
PSC prescaler permet de ralentir la freq pour trouver un diviseur commun*/

#include "MyGPIO.h"
#include "MyTimer.h"
#include "macro.h"


int set_rap_cyc ( int angle_wind){
	int cycle ;
	
	MyGPIO_Struct_TypeDef GPIO ;
	GPIO.GPIO = GPIOA ;
	GPIO.GPIO_Pin = 5 ;
	GPIO.GPIO_Conf = Out_Ppull ;
	
	MyGPIO_Init (&GPIO) ;
	
	if (angle_wind <= 45) {
		cycle = 5;
		MyGPIO_Set (GPIO.GPIO, GPIO.GPIO_Pin) ;
	}
	else if (angle_wind > 45 && angle_wind< 68) {
		cycle = 6;
		MyGPIO_Reset ( GPIO.GPIO , GPIO.GPIO_Pin ) ;
	}
	else if (angle_wind >= 68 && angle_wind < 90) {
		cycle = 7;	
		MyGPIO_Set (GPIO.GPIO, GPIO.GPIO_Pin) ;
	}
	else if (angle_wind >=90 && angle_wind< 113) {
		cycle = 8;
		MyGPIO_Reset ( GPIO.GPIO , GPIO.GPIO_Pin ) ;
	}
	else if (angle_wind >=113 && angle_wind< 135) {
		cycle = 9;
		MyGPIO_Set (GPIO.GPIO, GPIO.GPIO_Pin) ;
	}
	else if (angle_wind >=135 && angle_wind< 225) {
		cycle = 10;
		MyGPIO_Reset ( GPIO.GPIO , GPIO.GPIO_Pin ) ;
	}
	else if (angle_wind >=225 && angle_wind< 248) {
		cycle = 9;
		MyGPIO_Set (GPIO.GPIO, GPIO.GPIO_Pin) ;
	}
	else if (angle_wind >=248 && angle_wind< 270) {
		cycle = 8;
		MyGPIO_Reset ( GPIO.GPIO , GPIO.GPIO_Pin ) ;
	}
	else if (angle_wind >=270 && angle_wind < 293) {
		cycle = 7;
		MyGPIO_Set (GPIO.GPIO, GPIO.GPIO_Pin) ;
	}
	else if (angle_wind > 293 && angle_wind< 315) {
		cycle = 6;
		MyGPIO_Reset ( GPIO.GPIO , GPIO.GPIO_Pin ) ;
	}
	else if (angle_wind >= 315) {
		cycle = 5;
		MyGPIO_Set (GPIO.GPIO, GPIO.GPIO_Pin) ;
	}
	return cycle;
}
		



void rapport_pwm (MyTimer_Struct_TypeDef * Timer, int canal, int Cycle){
		switch(canal){
			case '1' :
				Timer ->Timer ->CCR1  = PWM_ARR * Cycle / 100;
			break;
			case '2' :
				Timer ->Timer ->CCR2 =PWM_ARR * Cycle / 100;
				break;
			case '3' :
				Timer->Timer ->CCR3 = PWM_ARR * Cycle / 100;
				break;
			case '4' :
				Timer->Timer ->CCR4  = PWM_ARR * Cycle / 100;
		break;
	default:
	break;
	}
}

