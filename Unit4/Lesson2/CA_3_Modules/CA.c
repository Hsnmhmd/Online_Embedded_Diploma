/*
 * CA.c
 *
 *  Created on: 23 Sep 2021
 *      Author: hassan
 */
#include<stdlib.h>
#include"CA.h"


//States
enum{
	CA_Waiting,
	CA_Driving
}CA_state_id;

int CA_Speed = 0;
int CA_Distance = 0;
int CA_Threshold = 50;

//State Pointer To Function
void (*CA_state )();
void US_Set_Distance(int Distance){
	CA_Distance = Distance;
	if(CA_Distance <= CA_Threshold)
		CA_state = STATE(CA_Waiting);
	else
		CA_state = STATE(CA_Driving);
	printf("US>>>>>>>>Distance = %d >>>>>>>>CA\n",CA_Distance);
}

STATE_define(CA_Waiting){
	CA_state_id = CA_Waiting;
	printf("CA_Waiting state : Distance = %d Speed = %d\n",CA_Distance,CA_Speed);
	CA_Speed = 0;
	DC_Set_Speed(CA_Speed);
}
STATE_define(CA_Driving){
	CA_state_id = CA_Driving;
	printf("CA_Driving state : Distance = %d Speed = %d \n",CA_Distance,CA_Speed);
	CA_Speed = 30;
	DC_Set_Speed(CA_Speed);
}

