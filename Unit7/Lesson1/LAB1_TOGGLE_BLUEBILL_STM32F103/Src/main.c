
/*
 * main.c
 *
 *  Created on: Sep 14, 2021
 *      Author: hassan
 */

typedef volatile unsigned int vuint32_t;
#include<stdio.h>

#define RCC_BASE		0x40021000
#define GPIOA_BASE		0x40010800
#define GPIOB_BASE		0x40010C00
#define RCC_APB2ENR		*(vuint32_t *)(RCC_BASE + 0x18)
#define GPIOA_CRH		*(vuint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_CRL		*(vuint32_t *)(GPIOA_BASE + 0x00)
#define GPIOA_ODR		*(vuint32_t *)(GPIOA_BASE + 0x0C)
#define GPIOA_IDR		*(vuint32_t *)(GPIOA_BASE + 0x08)
#define GPIOB_CRH		*(vuint32_t *)(GPIOB_BASE + 0x04)
#define GPIOB_CRL		*(vuint32_t *)(GPIOB_BASE + 0x00)
#define GPIOB_ODR		*(vuint32_t *)(GPIOB_BASE + 0x0C)
#define GPIOB_IDR		*(vuint32_t *)(GPIOB_BASE + 0x08)

void GPIO_init(void){
	/*pin 13 PA as FLOATING INPUT*/
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00800000;
	/*pin 1 PA as FLOATING INPUT*/
	GPIOA_CRL &= 0xFFFFFF0F;
	GPIOA_CRL |= 0x00000080;
	/*pin 13 PB as GENERAL OUTPUT PUSH PULL 10MHZ*/
	GPIOB_CRH &= 0xFF0FFFFF;
	GPIOB_CRH |= 0x00100000;
	/*pin 1 PA as GENERAL O/P PUSH PULL 10 MHZ*/
	GPIOB_CRL &= 0xFFFFFF0F;
	GPIOB_CRL |= 0x00000010;

}
void CLOCK_init(void){
	/*clock init for GPIOA */
	RCC_APB2ENR |=1<<2;
	/*clock init for GPIOB */
	RCC_APB2ENR |=1<<3;
}


int main(void)
{
	CLOCK_init();
	GPIO_init();

	/*  Loop forever */
	for(;;){
		/*Single Pressing for PA1*/
		if(!(GPIOA_IDR&(1<<1))){
			GPIOB_ODR ^=(1<<1);
			for(int i=0;i<200;i++){}
			while(!(GPIOA_IDR&(1<<1))){}
		}
		/*Multi PRessing*/
		/*Single Pressing for PA1*/
		if((GPIOA_IDR&(1<<13))){
			GPIOB_ODR ^=(1<<13);
			for(int i=0;i<200;i++){}
		}
	}
	return 0;
}





