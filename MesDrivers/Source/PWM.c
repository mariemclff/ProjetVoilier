
/*ARR/CRX : rapport entre front montant et front descendant 
72MHz et 20 khz de la pwm a mettre en forme pour avoir la bonne relation 
PSC prescaler permet de ralentir la freq pour trouver un diviseur commun*/
#include "MyGPIO.h"

void callback ( void){
	MyGPIO_Toggle(GPIOC,PC8);
}
