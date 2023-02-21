/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body

 */
#include"Stm32_F103C6_gpio_driver.h"
typedef volatile unsigned int vuint32_t;
#include<stdio.h>

GPIO_PinConfig_t GPIOA13={GPIO_MODE_INPUT_F,13};
GPIO_PinConfig_t GPIOA1={GPIO_MODE_INPUT_F,1};
GPIO_PinConfig_t GPIOB13={GPIO_MODE_OUTPUT_PP_10M,13};
GPIO_PinConfig_t GPIOB1={GPIO_MODE_OUTPUT_PP_10M,1};
void GPIO_init(void){
	/*pin 13 PA as FLOATING INPUT*/
	MCAL_GPIO_Init(GPIOA, &GPIOA13);

	/*pin 1 PA as FLOATING INPUT*/
	MCAL_GPIO_Init(GPIOA, &GPIOA1);
	/*pin 13 PB as GENERAL OUTPUT PUSH PULL 10MHZ*/
	MCAL_GPIO_Init(GPIOB, &GPIOB13);
	/*pin 1 PA as GENERAL O/P PUSH PULL 10 MHZ*/
	MCAL_GPIO_Init(GPIOB, &GPIOB1);

}
void CLOCK_init(void){
	/*clock init for GPIOA */
	RCC_GPIOA_CLK_EN();
	/*clock init for GPIOB */
	RCC_GPIOB_CLK_EN();
}


int main(void)
{
	CLOCK_init();
	GPIO_init();

	/*  Loop forever */
	for(;;){
		/*Single Pressing for PA1*/
		if(!MCAL_GPIO_ReadPIN(GPIOA, 1)){
			MCAL_GPIO_TogglePin(GPIOB, 1);
			for(int i=0;i<200;i++){}
			while(!MCAL_GPIO_ReadPIN(GPIOA, 1)){}
		}
		/*Multi PRessing*/
		/*Single Pressing for PA1*/
		if(MCAL_GPIO_ReadPIN(GPIOA, 13)){
			MCAL_GPIO_TogglePin(GPIOB, 13);
			for(int i=0;i<200;i++){}
		}
	}
	return 0;
}