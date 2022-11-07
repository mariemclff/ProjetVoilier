
/*ARR/CRX : rapport entre front montant et front descendant 
72MHz et 20 khz de la pwm a mettre en forme pour avoir la bonne relation 
PSC prescaler permet de ralentir la freq pour trouver un diviseur commun*/

#include "MyGPIO.h"


int set_rap_cyc ( int angle_wind){
	int cycle ;
	
	if (angle_wind <= 45) {
		cycle = 5;
	}
	else if ((angle_wind > 45) && (angle_wind < 68)) {
		cycle = 6;
	}
	else if ((angle_wind >= 68) && (angle_wind < 90)) {
		cycle = 7;	}
	else if ((angle_wind >=90) && (angle_wind < 113)) {
		cycle = 8;
	}
	else if ((angle_wind >=113 ) && (angle_wind < 135)) {
		cycle = 9;
	}
	else if ((angle_wind >=135 ) && (angle_wind < 225)) {
		cycle = 10;
	}
	else if ((angle_wind >=225 ) && (angle_wind < 248)) {
		cycle = 9;
	}
	else if ((angle_wind >=248 ) && (angle_wind < 270)) {
		cycle = 8;
	}
	else if ((angle_wind >=270 ) && (angle_wind < 293)) {
		cycle = 7;
	}
	else if ((angle_wind > 293 ) && (angle_wind < 315)) {
		cycle = 6;
	}
	else if (angle_wind >= 315) {
		cycle = 5;
	}
	return cycle;
}
		


void init (void){
	MyGPIO_Init(GPIOCap ) ;
	MyTimer_Set_CI(TimerCap);
	PWM_Init_ff(TimerCap, 2000, 720);
}

void rapport_pwm (MyTimer_Struct_TypeDef TimerStruct, int canal)){
	unsigned short ARR =0xFFFF
	MyTimer_PWM (TimerCap, canal);
	int cycle = set_rap_cyc( 
		switch(Channel){
			case '1' :
				Timer -> CCR1 -> ARR * Cycle / 100
			case '2' :
				Timer -> CCR2 -> ARR * Cycle / 100
			case '3' :
				Timer -> CCR3 -> ARR * Cycle / 100
			case '4' :
				Timer -> CCR4 -> ARR * Cycle / 100