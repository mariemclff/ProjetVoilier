#ifndef MYUSART_H
#define MYUSART_H
#include "stm32f10x.h"
#include "MyTimer.h"
#include "MyGPIO.h"
#include "macro.h"

typedef struct {
	USART_TypeDef * Uart ; // USART1 à USART3
	int Debit;
	int Prio;
} MyUART_Struct_TypeDef ;

//Initialisation de l'USART
void MyUSART_Init( MyUART_Struct_TypeDef * Uart);

//Réception des octets 
#define MyUSART_Reception() ( USART1 -> CR1 |= USART_CR1_RE )

//Envoyer(transmettre) des octets
#define MyUSART_Transmission() ( USART1 -> CR1 |= USART_CR1_TE )

//Attendre pour recevoir les bits 
#define MyUSART_WaitOnSend(muart) ((muart.Uart->SR & USART_SR_TXE) == 0)
char MyUSART_Receive_Byte(USART_TypeDef * Uart);

//Envoyer des bits
void MyUSART_Send_Byte(USART_TypeDef * Uart, char Byte);

//Activer Interruption
void MyUSART_Active_IT (MyUART_Struct_TypeDef * Uart, void(*IT_function) (void));

#endif
