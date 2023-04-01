#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


/*===============Learn in depth================*/
/*===Second term project Smart Car Barking=====*/
/* Hassan Abd Eltawab */

#include "LCD_Controller.h"
#include "LED_Controller.h"
#include "Gate_Controller.h"
#include "Park_Controller.h"

#include "Stm32_F103C6_UART_driver.h"
#include "Stm32_F103C6_gpio_driver.h"
#include "stm32f103x6.h"
#include "Servo_Motor.h"
#include "keypad.h"


/*=================Global Variables===============*/
void Clock_Init(void){
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
}
void HW_Init(void){
	Keypad_init();

	LCDS_init();


	LEDs_Init();

	//Gates Init
	Timer2_init();
	Servo1_Entry_Gate_Init();
	Servo2_Exit_Gate_Init();
	RFIDs_Init();
	PIRs_Iint();

	Park_Status=Park_Idle;
	LCD1_Status=LCD_Idle;
	LED_Status=LED_Idle;
	Gate_Status=Gates_Idle;
}

int main(void)
{
	Clock_Init();
	HW_Init();


	/*==========Enter IDs To Store In Array Pass==========*/
	Store_IDs_From_Admin();
	LCD_Welcome();
	LCD_Display_Empty_Slots();

	while(1)
	{
		/*=====================Enter gate=====================*/
		Park_Status();
		LCD1_Status();
		LED_Status();
		LED_Status();
		Gate_Status();
		LED_Status();
		LCD1_Status();

	}

	return 0;
}



