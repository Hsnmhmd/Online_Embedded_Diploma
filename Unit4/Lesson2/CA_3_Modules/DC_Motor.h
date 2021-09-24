/*
 * DC.h
 *
 *  Created on: 23 Sep 2021
 *      Author: hassan
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include<stdio.h>
#include"state.h"

//State Pointer To Function
extern void (*DC_state )();
//Prototypes
STATE_define(DC_Idle);
STATE_define(DC_Busy);
void DC_Motor_Init();

#endif /* DC_H_ */
