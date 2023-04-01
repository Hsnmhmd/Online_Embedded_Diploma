/*
 * LED_Controller.h
 *
 *  Created on: 1 Apr 2023
 *      Author: admin
 */

#ifndef LED_CONTROLLER_H_
#define LED_CONTROLLER_H_

#include "Stm32_F103C6_gpio_driver.h"
extern void (* LED_Status)();
void LEDs_Init(void);
void LED_Red_On(void);
void LED_Green_On(void);
void LED_Green_Off(void);
void LED_Red_Off(void);
void LED_Idle(void);





#endif /* LED_CONTROLLER_H_ */
