/*
 * LED_COntroller.c
 *
 *  Created on: 1 Apr 2023
 *      Author: Hassan
 */


#include "LED_Controller.h"
void (* LED_Status)();
void LED_Red_On(){
	MCAL_GPIO_WritePin(GPIOA, GPIO_Pin_0,GPIO_PIN_RESET);
	delay_mss(2000);
	LED_Red_Off();
	LED_Status=LED_Idle;
}
void LED_Green_On(){
	MCAL_GPIO_WritePin(GPIOA, GPIO_Pin_11,GPIO_PIN_RESET);


}
void LED_Green_Off(){
	MCAL_GPIO_WritePin(GPIOA, GPIO_Pin_11,GPIO_PIN_SET);
	LED_Status=LED_Idle;
}
void LED_Red_Off(){
	MCAL_GPIO_WritePin(GPIOA, GPIO_Pin_0,GPIO_PIN_SET);
	LED_Status=LED_Idle;

}
void LED_Idle(){
	LED_Status=LED_Idle;
}
void LEDs_Init(void)
{
	//RED LED A0
	GPIO_PinConfig_t PinCinfg;
	PinCinfg.GPIO_Pin_Number=GPIO_Pin_0;
	PinCinfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP_10M;
	MCAL_GPIO_Init(GPIOA, &PinCinfg);

	//GREEN LED A11
	PinCinfg.GPIO_Pin_Number=GPIO_Pin_11;
	PinCinfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP_10M;
	MCAL_GPIO_Init(GPIOA, &PinCinfg);
}
