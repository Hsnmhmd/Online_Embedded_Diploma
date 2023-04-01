/*
 * Stm32_F103C6_gpio_driver.h
 *
 *  Created on: Sep 18, 2021
 *      Author: hassan
 */

#ifndef INC_STM32_F103C6_RCC_DRIVER_H_
#define INC_STM32_F103C6_RCC_DRIVER_H_

//Includes
#include<stm32f103x6.h>

#define HSE_CLK 		(uint32_t)4000000
#define HSI_RC_CLK 		(uint32_t)8000000
//-----------------------------
//CONFIG (structures)


/*
 * ===============================================
 * APIs Supported by "MCAL RCC DRIVER"
 * ===============================================*/
uint32_t MCAL_RCC_GetSYS_CLK(void);
uint32_t MCAL_RCC_GetHCLK(void);
uint32_t MCAL_RCC_GetPCLK1(void);
uint32_t MCAL_RCC_GetPCLK2(void);
//
//MACRO CONFIGRATION References
//


#endif /* INC_STM32_F103C6_GPIO_DRIVER_H_ */
