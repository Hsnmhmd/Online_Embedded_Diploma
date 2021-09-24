/*
 * US.c
 *
 *  Created on: 23 Sep 2021
 *      Author: hassan
 */
#include<stdlib.h>
#include"US.h"


//States
enum{
	US_Busy,
}US_state_id;

int US_Distance_Random(int l,int r,int count);

int US_Distance = 0;
void US_Init(){
	printf("US_Init.....\n");
}

//State Pointer To Function
void (*US_state )();

STATE_define(US_Busy){
	US_state_id = US_Busy;

	US_Distance =US_Distance_Random(45, 55, 1);
	printf("US_Busy state : Distance = %d \n",US_Distance);
	US_Set_Distance(US_Distance);
	US_state=STATE(US_Busy);
}

int US_Distance_Random(int l, int r, int count){

	for(int i=0;i < count;i++)
	{
		int randn = (rand() % (r-l+ 1)) + l;
		return randn;
	}
}
