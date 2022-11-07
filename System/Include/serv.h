#ifndef SERV
#define SERV
#include "stm32f10x.h"


/*
*****************************************************************************************
* @brie f
* @param -> Paramè t r e sous forme d ’ une s t r u c t u r e ( son a d re s se ) con ten an t l e s
i n f o rm a ti o n s de base
* @Note -> Fonction à lancer systématiquement avant d’aller plus en détail dans les
conf plus fines (PWM, codeur inc . . . )
*************************************************************************************************
*/
void bordage_process ( int alpha ) ;

#endif
