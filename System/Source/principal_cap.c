#include "stm32f10x.h"
#include "MyGPIO.h"
#include "stdio.h"
#include "math.h"
#include  "macro.h"
#include  "MyTimer.h"
#include "PWM.h"




int maincap ( void ) {
	//float arr, psc;
	MyTimer_Struct_TypeDef  timer;
	int alpha = 999 ;
	int Cycle;
	
	/*arr=0xFFFF;
	psc=(0.5*72.0e6)/(arr+1.0);
	arr=(float)(floor(0.5*72.0e6/(psc+1.0)));
	*/
	timer.Timer = TimerCap;
	timer.ARR = PWM_ARR ;
	timer.PSC = PWM_PSC;
 		
	init();
	alpha = MyTimer_Get_CNT ( &timer ) >> 2 ;
  Cycle = set_rap_cyc( alpha);
	MyTimer_PWM(&timer,1);
	rapport_pwm(&timer,1,Cycle);
	
	
	
}
