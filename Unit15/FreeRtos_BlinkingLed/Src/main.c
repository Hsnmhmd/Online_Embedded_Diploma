/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Hassan Abd Eltawab
 * @brief          : Blinking Led Using Free RTOS
 ******************************************************************************

 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
#include"Stm32_F103C6_gpio_driver.h"
#include"FreeRTOS.h"
#include"task.h"
TaskHandle_t xHandle = NULL;
void GpioPin_Init(){
	GPIO_PinConfig_t pinconfig;
	pinconfig.GPIO_Mode=GPIO_MODE_OUTPUT_OD_10M;
	pinconfig.GPIO_Pin_Number=GPIO_Pin_13;
	MCAL_GPIO_Init(GPIOC, &pinconfig);
}
void BlinkLed_Handler(void *parms);
int main(void)
{
	RCC_GPIOC_CLK_EN();
	GpioPin_Init();
    /* Create the task, storing the handle. */
     xTaskCreate(
    		BlinkLed_Handler,       /* Function that implements the task. */
                    "Blink Led GPIOC 13",          /* Text name for the task. */
                    128,      /* Stack size in words, not bytes. */
                    NULL,    /* Parameter passed into the task. */
                    1,/* Priority at which the task is created. */
                    &xHandle );
     vTaskStartScheduler();
    /* Loop forever */
	for(;;);
}
void BlinkLed_Handler(void *parms){


	while(1){
		MCAL_GPIO_TogglePin(GPIOC, GPIO_Pin_13);
		vTaskDelay(200);
	}
}
