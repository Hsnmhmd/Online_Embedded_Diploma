/*
 * main.c
 *
 *  Created on: 23 Sep 2021
 *      Author: hassan
 */
#include"CA.h"
#include"US.h"
#include"DC_Motor.h"
void setup(){
	US_Init();
	DC_Motor_Init();
	CA_state = STATE(CA_Waiting);
	US_state = STATE(US_Busy);
	DC_state = STATE(DC_Idle);
}
int main(){
	setup();
	while(1){
		US_state();
		CA_state();
		DC_state();
		/*Delay*/
		for(int d=0;d<50000;d++){}
	}
	return 0;
}
