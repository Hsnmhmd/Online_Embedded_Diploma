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

int US_Distance_Random(int l,int r,int count);
int CA_Speed = 0;
int CA_Distance = 0;
int CA_Threshold = 50;

//State Pointer To Function
void (*CA_state )();

STATE_define(CA_Waiting){
	CA_state_id = CA_Waiting;
	CA_Speed = 0;
	CA_Distance =US_Distance_Random(45, 55, 1);
	if(CA_Distance <= CA_Threshold)
		CA_state = STATE(CA_Waiting);
	else
		CA_state = STATE(CA_Driving);
	printf("CA_Waiting state : 	Distance = %d Speed = %d\n",CA_Distance,CA_Speed);

}
STATE_define(CA_Driving){
	CA_state_id = CA_Driving;
	CA_Speed = 30;
	CA_Distance =US_Distance_Random(45 , 55 ,1);
	if(CA_Distance > CA_Threshold)
		CA_state = STATE(CA_Driving);
	else
		CA_state = STATE(CA_Waiting);
	printf("CA_Driving state : 	Distance = %d Speed = %d \n",CA_Distance,CA_Speed);

}
int US_Distance_Random(int l, int r, int count){

	for(int i=0;i < count;i++)
	{
		int randn = (rand() % (r-l+ 1)) + l;
		return randn;
	}
}
