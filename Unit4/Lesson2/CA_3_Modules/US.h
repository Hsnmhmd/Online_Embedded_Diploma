/*
 * DC.h
 *
 *  Created on: 23 Sep 2021
 *      Author: hassan
 */

#ifndef US_H_
#define US_H_
#include<stdio.h>
#include"state.h"

//State Pointer To Function
extern void (*US_state )();
//Prototypes
STATE_define(US_Busy);
void US_Init();
#endif /* DC_H_ */
