/*
 * main.c
 *
 *  Created on: 14 Sep 2021
 *      Author: hassan
 */

/*
 * main.c
 *
 *  Created on: 7 Sep 2021
 *      Author: hassan
 */
#include<util/delay.h>
//#include<avr/io.h>

#define SREG   *(volatile unsigned char*)(0x5F)
#define GICR   *(volatile unsigned char*)(0x5B)
#define MCUCSR *(volatile unsigned char*)(0x54)
#define MCUCR  *(volatile unsigned char*)(0x55)
#define PORTD  *(volatile unsigned char*)(0x32)
#define DDRD   *(volatile unsigned char*)(0x31)
#define PIND   *(volatile unsigned char*)(0x30)
void PORTD_init(){
	/*PORTD 4,5,6,7 as O/P*/
	DDRD |=(0xF<<4);
}

int main(){
	PORTD_init();
	while(1){
		PORTD |=(1<<5);
		_delay_ms(3000);
		PORTD ^=(1<<5);
		PORTD |=(1<<6);
		_delay_ms(3000);
		PORTD ^=(1<<6);
		PORTD |=(1<<7);
		_delay_ms(3000);
		PORTD ^=(1<<7);
		PORTD |=(1<<4);
		_delay_ms(3000);
		PORTD ^=(1<<4);
	}

	return 0;
}

