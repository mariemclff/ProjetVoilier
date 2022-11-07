#include "stm32f10x.h"
#include "MyGPIO.h"
#include "stdio.h"
#include "math.h"



int main ( void )
{
	float arr, psc;
	 MyTimer_Struct_TypeDef  timer;

	arr=0xFFFF;
	psc=(0.5*72.0e6)/(arr+1.0);
	arr=(float)(floor(0.5*72.0e6/(psc+1.0)));
	
	timer.Timer = TimerCap;
	timer.ARR = arr ;
	timer.PSC = psc;


}
