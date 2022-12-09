#include "MyUSART.h"
#include "MyGPIO.h"

void (*		IT_function_UART1)(void);
void (*		IT_function_UART2)(void);
void (*		IT_function_UART3)(void);

MyGPIO_Struct_TypeDef GPIO_Tx = { GPIO_UART3, TxPin_UART3, AltOut_Ppull}; //Envoi

MyGPIO_Struct_TypeDef GPIO_Rx = { GPIO_UART3, RxPin_UART3, In_Floating}; //Reception

void MyUSART_Init (USART_TypeDef * USART, int BaudRate){
	
	//Baud Rate and Clock Activation
	if (USART == USART1){
		RCC ->APB2ENR |= RCC_APB2ENR_USART1EN;
		USART->BRR = (int) (72000000/(BaudRate));
		MyGPIO_Init(&GPIO_Tx);
		MyGPIO_Init(&GPIO_Rx);
		//USART->BRR = BaudRate ;
	}
	else if (USART == USART2){
		RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
		USART->BRR |= (int) (36000000/(BaudRate));
	}
	else if (USART == USART3){
		RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
		USART->BRR |= (int) (36000000/(BaudRate));
	}
	
		//Enable USART
	USART->CR1 |= USART_CR1_UE;
	
	//Word Length : 0: 1 Start bit, 8 Data bits, n Stop bit
	USART->CR1 &= ~(USART_CR1_M);
	
	//STOP bits : 1 stop bit
	USART->CR2 &= ~(USART_CR2_STOP);
	
	//Transmitter Enable
	USART->CR1 |= USART_CR1_TE;
	
	//Receiver Enable
	USART->CR1 |= USART_CR1_RE;
	
}

void MyUSART_Send (USART_TypeDef * USART, char Data){

		while (!(USART->SR & USART_SR_TXE));
		USART->DR = Data;
}


void MyUSART_Send_Str (USART_TypeDef * USART, char* Data){
	while (*Data != '\0'){
		MyUSART_Send(USART, *Data);
		Data++;
	}
}


char MyUSART_Receive (USART_TypeDef * USART){
	return (signed char) USART->DR ;
}

void MyUSART_ActiveIT (USART_TypeDef * USART, uint32_t Prio, void (*IT_function)(void)){
	
	USART->CR1 |= USART_CR1_RXNEIE;
	
	if (USART == USART1){
		NVIC_EnableIRQ(USART1_IRQn);
		NVIC_SetPriority(USART1_IRQn, Prio);
		IT_function_UART1=IT_function;
		
	}
	else if(USART == USART2){
		NVIC_EnableIRQ(USART2_IRQn);
		NVIC_SetPriority(USART2_IRQn, Prio);
		IT_function_UART2=IT_function;
	}
	else if(USART == USART3){
		NVIC_EnableIRQ(USART3_IRQn);
		NVIC_SetPriority(USART3_IRQn, Prio);
		IT_function_UART3=IT_function;
	}
	
}