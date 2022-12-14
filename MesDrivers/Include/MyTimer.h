 
#ifndef MYTIM
#define MYTIM
#include "stm32f10x.h"
#include  "macro.h"


/*
*****************************************************************************************
* @brie f
* @param -> Paramè t r e sous forme d ’ une s t r u c t u r e ( son a d re s se ) con ten an t l e s
i n f o rm a ti o n s de base
* @Note -> Fonction à lancer systématiquement avant d’aller plus en détail dans les
conf plus fines (PWM, codeur inc . . . )
*************************************************************************************************
*/
void MyTimer_Base_Init ( MyTimer_Struct_TypeDef * Timer ) ;
void MyTimer_Base_Start ( MyTimer_Struct_TypeDef * Timer );
void MyTimer_Base_Stop ( MyTimer_Struct_TypeDef * Timer ) ;
void MyTimer_ActiveIT ( MyTimer_Struct_TypeDef * Timer , char Prio,void (* IT_function ) ( void ) ) ;
void MyTimer_Set_CI ( MyTimer_Struct_TypeDef * Timer , int ARR ) ;
void MyTimer_Set_CNT ( MyTimer_Struct_TypeDef * Timer , int init) ;
int MyTimer_Get_CNT ( MyTimer_Struct_TypeDef * Timer ) ;
void MyTimer_PWM( MyTimer_Struct_TypeDef * Timer , int Channel ); 

#endif
