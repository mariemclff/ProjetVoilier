#include "stm32f10x.h"
#include "MyTimer.h"
#include "stdio.h"
#include "math.h"


void (*fonc) (void);
void MyTimer_Base_Init ( MyTimer_Struct_TypeDef * Timer ) {
	
	if (Timer-> Timer == TIM2){
			RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
		}else if (Timer-> Timer == TIM4 ) {
			RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
		} else if (Timer-> Timer == TIM3) {
			RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
		} else if ( Timer-> Timer == TIM1 ) {
				RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
		}
	Timer->Timer->PSC = Timer->PSC;
	Timer->Timer->ARR = Timer->ARR;
	}

void MyTimer_Base_Start( MyTimer_Struct_TypeDef * Timer ) {

	Timer->Timer ->CR1  |= 0x01;

}
void MyTimer_Base_Stop( MyTimer_Struct_TypeDef *  Timer ) {
	Timer->Timer->CR1 |= 0x01;
	Timer->Timer->CR1 ^= 0x01;
	
	Timer->Timer->DIER |= 0x01;
	Timer->Timer->DIER ^= 0x01;
}

void MyTimer_ActiveIT ( MyTimer_Struct_TypeDef * Timer , char Prio,void (* IT_function ) ( void ) ) {
	Timer ->Timer-> DIER |= 0x01;
	if (Timer-> Timer == TIM1){
		NVIC->ISER[0] = 0x01 << 25;
		NVIC_EnableIRQ((IRQn_Type )(25));
		NVIC->IP [25] = Prio << 4;
		TIM1->DIER |= 0x01;
		fonc =IT_function;
	}else if (Timer-> Timer == TIM2 ) {
		NVIC->ISER[0] = 0x01 << 28;
		NVIC_EnableIRQ((IRQn_Type )28);
		NVIC->IP [28] = Prio << 4;
		TIM2->DIER |= 0x01;
		fonc =IT_function;
	}else if (Timer-> Timer == TIM3) {
		NVIC->ISER[0] = 0x01 << 29;
		NVIC_EnableIRQ((IRQn_Type )29);
		NVIC->IP [29] = Prio << 4;
		TIM3->DIER |= 0x01;
	fonc =IT_function;
	} else if ( Timer-> Timer == TIM4 ) {
		NVIC->ISER[0] = 0x01 << 30;
		NVIC_EnableIRQ((IRQn_Type )30);
		NVIC->IP [30] = Prio << 4;
		TIM4->DIER |= 0x01;
		fonc =IT_function;
	}
}

void MyTimer_Set_CI ( MyTimer_Struct_TypeDef * Timer , int ARR ) {
	
	// CC1S = 01
	Timer->Timer->CCMR1 &= ~(0x3) ;
	Timer->Timer->CCMR1 |= 0x01 ;
	
	//CC2S = 01
	Timer->Timer->CCMR1 &= ~(0x3 << 8) ;
	Timer->Timer->CCMR1 |= 0x01 << 8 ;
	
	//CC1P = 0
	Timer->Timer->CCER &= ~(0x1) ;
	
	//CC2P = 0
	Timer->Timer->CCER &= ~(0x1 <<5) ;
	
	//IC1F = 0000
	Timer->Timer->CCMR1 &= ~(0xF << 4) ;
	
	//IC2F = 0000
	Timer->Timer->CCMR1 &= ~(0xF << 12) ;
	
	// SET EN SUIVANT LA DOC p392 : on met SMS à 011, permet de récupérer signaux A et B de la girouette
	Timer->Timer->SMCR &= ~(0x7) ;
	Timer->Timer->SMCR |= 0x3 ;
	
	Timer->ARR = ARR ;
	// On le fait déjà dans la fonction start : Timer->Timer->CR1 |= 0x01 ;
	
}


void MyTimer_Set_CNT ( MyTimer_Struct_TypeDef * Timer , int init) {
	
	Timer->Timer->CNT = init ;
	
}


int MyTimer_Get_CNT ( MyTimer_Struct_TypeDef * Timer ) {
	
	return Timer->Timer->CNT ;
	
}

void MyTimer_PWM( MyTimer_Struct_TypeDef * Timer , char Channel ){

	switch(Channel){
	case '1' :
		Timer ->Timer ->CCMR1 &= ~(0x110 << 4);
		Timer->Timer ->CCMR1 |= (0x110 <<4);
		Timer->Timer ->CCER &= ~0;
		Timer->Timer ->CCER |= 1;
		Timer ->Timer -> CCR1 = 0;
	break;
	case '2' :
		Timer->Timer ->CCMR1 &= ~(0x110 << 12);
		Timer->Timer ->CCMR1 |= (0x110 <<12);
		Timer->Timer ->CCER &= ~0;
		Timer->Timer ->CCER |= 1;
		Timer -> Timer ->CCR2 = 0;
	break;
	case '3' :
		Timer->Timer ->CCMR2 &= ~(0x110 << 4);
		Timer->Timer ->CCMR2 |= (0x110 <<4);
		Timer->Timer ->CCER &= ~0;
		Timer->Timer ->CCER |= 1;
		Timer ->Timer -> CCR3 = 0;
	break;					
	case '4' :
		Timer->Timer ->CCMR2 &=~(0x110 << 12);
		Timer->Timer ->CCMR2 |= (0x110 <<12);
		Timer->Timer ->CCER &= ~0;
		Timer->Timer ->CCER |= 1;
		Timer ->Timer -> CCR4 = 0;
	break;
	default:
	break;
}

}
