/*
 * main.c
 *
 *  Created on: 7 Sep 2021
 *      Author: hassan
 */
#include<util/delay.h>
#include<avr/interrupt.h>
/*
#define SREG   *(volatile unsigned char*)(0x3F)
#define GICR   *(volatile unsigned char*)(0x3B)
#define MCUCSR *(volatile unsigned char*)(0x34)
#define MCUCR  *(volatile unsigned char*)(0x35)
#define PORTD  *(volatile unsigned char*)(0x12)
#define DDRD   *(volatile unsigned char*)(0x11)
#define PIND   *(volatile unsigned char*)(0x10)*/
void PORTD_init(){
	/*PORTD5 as O/P*/
	DDRD |=(1<<5);
	/*PORTD2 as I/P*/
	DDRD &=~(1<<2);

}
void EXTI0_init(){
	/*Enabling Global INT*/
	SREG |=(1<<7);
	/*ENABLING INT0*/
	GICR |=(1<<6);
	/*CONFIG INT0 ANY LOGIC CHANGE*/
	MCUCR |=1;
}
ISR(INT0_vect){
	PORTD |=(1<<5);
	_delay_ms(100);
	PORTD ^=(1<<5);
}
int main(){
	PORTD_init();
	EXTI0_init();
	while(1){}

	return 0;
}
