#ifndef MYUSART_H
#define MYUSART_H
#include "stm32f10x.h"
#include "MyTimer.h"
#include "MyGPIO.h"
#include "macro.h"

//On utilise le type USART_TypeDef

//Initialisation de l'USART; procédure d'initialisation page 797  du manuel

void MyUSART_Init( USART_TypeDef * USART, int BaudRate) ;

//La fonction UART_Init doit avoir ete lancee au prealable

void MyUSART_Active (USART_TypeDef * USART, uint32_t Prio, void (*IT_function)(void)) ;

// Fonction pour envoi de données

void MyUSART_Send (USART_TypeDef * USART, char Data) ;

// Fonction pour envoi de String
void MyUSART_Send_Str (USART_TypeDef * USART, char* Data) ;

//Reception de données
char MyUSART_Receive (USART_TypeDef * USART) ;

#endif
