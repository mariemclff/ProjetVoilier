int main () {

	int test = 0 ;
	
	//set up GPIOA et Pin sur lequel on prend I
	//set up structure Timer
	
	MyTimer_Base_Init ( Timer ) ;
	MyTimer_Set_CI ( Timer, ARR ) ;
	
	while (test == 0) {
		test = MyGPIO_Read ( GPIO , Pin ) ;
	}
	
	MyTimer_Base_Start ( Timer ) ;

}