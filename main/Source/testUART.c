#include "stm32f10x.h"
#include "MyGPIO.h"
#include "MyTimer.h"
#include "MyUSART.h"
#include "macro.h"


char * data = "hello";
int cmpt = 0;
char i_uart = 0;

int maintest ( void )
{
	
	
	RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4);
	
	
	MyUSART_Init(USART1,9600);
	
	    MyUSART_Send(USART1, *data);
	    
	while (1){
		MyUSART_Send(USART1, *data);
		
		i_uart = MyUSART_Receive(USART1);
		
		MyUSART_Send_Str(USART1, "test");
		i_uart = MyUSART_Receive(USART1);
	}
	return 0;
}

//connexion telecommande