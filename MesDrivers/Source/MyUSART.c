#include "MyUSART.h"

static void (*HandlerUart1)(void);
static void (*HandlerUart2)(void);
static void (*HandlerUart3)(void);

//Initialisation de l'USART
void MyUSART_Init (MyUART_Struct_TypeDef * Uart) {
	if (Uart->Uart == USART1){
		//validation  horloge USART1
		RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
		//on fixe le baud rate
		Uart->Uart->BRR = 72000000/(Uart->Debit);}
	
	if (Uart->Uart == USART2){
		RCC -> APB1ENR |= RCC_APB1ENR_USART2EN;
		Uart->Uart->BRR = 36000000/(Uart->Debit);}
	
	if (Uart->Uart == USART3){
		RCC -> APB1ENR |= RCC_APB1ENR_USART3EN;
		Uart->Uart->BRR = 36000000/(Uart->Debit);}
	
	//activation de l'UART
	Uart->Uart ->CR1 |= USART_CR1_UE;
	//8 bits de données
	Uart->Uart->CR1 &= ~USART_CR1_M; 
	//1 bit de stop
	Uart->Uart->CR2 &= USART_CR2_STOP;
	
		//Réception des octets( Receiver enable)
	Uart->Uart -> CR1 |= USART_CR1_RE ;
		//Tansmettre des octets (Transmitter enable)
	Uart->Uart -> CR1 |= USART_CR1_TE ;
}

//Activation interupteur
void MyUSART_Active_IT (MyUART_Struct_TypeDef * MyUart, void(*IT_function) (void)) {
	MyUart->Uart->CR1 |= USART_CR1_RXNEIE;
	
	if (MyUart->Uart == USART1){
		HandlerUart1 = IT_function;
		NVIC->IP[USART1_IRQn] = MyUart->Prio <<4;
		NVIC->ISER[1] |= NVIC_ISER_SETENA_5;}
	
	if (MyUart->Uart == USART2){
		HandlerUart2 = IT_function;
		NVIC->IP[USART2_IRQn] = MyUart->Prio <<4;
		NVIC->ISER[1] |= NVIC_ISER_SETENA_6;}
	
	if (MyUart->Uart == USART3){
		HandlerUart3 = IT_function;
		NVIC->IP[USART3_IRQn] = MyUart->Prio <<4;
		NVIC->ISER[1] |= NVIC_ISER_SETENA_7;}
}

//Recevoir des bits (data du voilier)
char MyUSART_Receive_Byte(USART_TypeDef * Uart){
	return Uart->DR;}

void USART1_IRQHandler(void){
	 // On remet le flag à 0
	USART1->SR &= ~USART_SR_RXNE;
	//Message = USART1->DR;
	if (HandlerUart1 !=0){
	(*HandlerUart1) ();}
	}

void USART2_IRQHandler(void){
	// On remet le flag à 0
	USART2->SR &= ~USART_SR_RXNE; 
	//Message = USART2->DR;
	if (HandlerUart2 !=0){
	(*HandlerUart2) ();}
	}

void USART3_IRQHandler(void){
	 // On remet le flag à 0
	USART3->SR &= ~USART_SR_RXNE;
	//Message = USART3->DR;
	if (HandlerUart3 !=0){
	(*HandlerUart3) ();}
}

//Envoyer des bits (data au voilier (vitesse, etc..))
	void MyUSART_Send_Byte(USART_TypeDef * Uart, char Byte){
		Uart->DR =  Byte;
}

