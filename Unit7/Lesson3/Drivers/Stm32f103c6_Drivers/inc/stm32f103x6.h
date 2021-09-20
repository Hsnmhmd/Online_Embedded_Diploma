/*
 * stm32f103x6.h
 *
 *  Created on: Sep 18, 2021
 *      Author: hassan
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_
//-----------------------------
//Includes
#include<stdint.h>
#include<stdlib.h>
//====================================================================
//Base addresses for Memories
#define Flash_Memory_BASE 					0x08000000UL
#define System_Memory_BASE 					0x1FFFF000UL
#define SRAM_BASE 							0x20000000UL
#define Peripherals_BASE 					0x40000000UL
#define Cortex_M3_Internal_Peripherals_BASE 0xE0000000UL
//====================================================================
//Base addresses for BUS Peripherals
/*AHB Bus*/
#define RCC_BASE							0x40021000UL
/*APB2 Bus*/
/*GPIOA GPIOB FULLY INCLUDED IN LQFP48 PACKAGE*/
#define GPIOA_BASE							0x40010800UL
#define GPIOB_BASE							0x40010C00UL
/*GPIOC GPIOD PARTIALY INCLUDED*/
#define GPIOC_BASE							0x40011000UL
#define GPIOD_BASE							0x40011400UL
/*GPIOE NOT INCLUDED IN LQFP48 PACKAGE*/
#define GPIOE_BASE							0x40011800UL
//
#define AFIO_BASE							0x40010000UL
#define EXTI_BASE							0x40010400UL
/*APB1*/
//REST WILL BE ADDED INCREAMENTALLY
//-*-*-*-*-*-*-*-*-*-*-*-
//====================================================================
//Peripheral register USING STRUCTURES:
/*GPIO*/
typedef struct{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_t;
/*RCC*/
typedef struct{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSRT;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
}RCC_t;
/*AFIO*/
typedef struct{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	uint32_t RESERVED0;
	volatile uint32_t MAPR2;
}AFIO_t;
typedef struct{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXI_t;
//=============================================================
//Peripheral Instants:
/*GPIO*/
#define GPIOA 	((GPIO_t *)GPIOA_BASE)
#define GPIOB 	((GPIO_t *)GPIOB_BASE)
#define GPIOC 	((GPIO_t *)GPIOC_BASE)
#define GPIOD 	((GPIO_t *)GPIOD_BASE)
#define GPIOE 	((GPIO_t *)GPIOE_BASE)

#define RCC 	((RCC_t *)RCC_BASE)

#define EXTI 	((EXTI_t *)EXTI_BASE)

#define AFIO 	((AFIO_t *)AFIO_BASE)

//====================================================================
//clock enable Macros:
#define RCC_GPIOA_CLK_EN()	(RCC->APB2ENR |=1<<2)
#define RCC_GPIOB_CLK_EN()	(RCC->APB2ENR |=1<<3)
#define RCC_GPIOC_CLK_EN()	(RCC->APB2ENR |=1<<4)
#define RCC_GPIOD_CLK_EN()	(RCC->APB2ENR |=1<<5)
#define RCC_GPIOE_CLK_EN()	(RCC->APB2ENR |=1<<6)

#define RCC_AFIO_CLK_EN()	(RCC->APB2ENR |=1<<0)
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*


#endif /* INC_STM32F103X6_H_ */
