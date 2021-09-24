/*
 * DC.c
 *
 *  Created on: 23 Sep 2021
 *      Author: hassan
 */
#include<stdlib.h>
#include"DC_Motor.h"


//States
enum{
	DC_Busy,
	DC_Idle
}DC_state_id;


int DC_Speed = 0;
void DC_Motor_Init(){
	printf("DC_Init.........\n");
}

//State Pointer To Function
void (*DC_state )();

void DC_Set_Speed(int Speed){
	DC_Speed = Speed;
	DC_state=STATE(DC_Busy);
	printf("CA>>>>>>>>Speed = %d >>>>>>>>DC\n",DC_Speed);

}
STATE_define(DC_Busy){
	DC_state_id = DC_Busy;

	printf("DC_Busy state : Speed = %d\n",DC_Speed);
	DC_state=STATE(DC_Idle);

}
STATE_define(DC_Idle){
	DC_state_id = DC_Idle;

	printf("DC_Idle state : Speed = %d \n",DC_Speed);
	DC_state=STATE(DC_Idle);
}

