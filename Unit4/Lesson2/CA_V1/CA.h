/*
 * CA.h
 *
 *  Created on: 23 Sep 2021
 *      Author: hassan
 */

#ifndef CA_H_
#define CA_H_
#include<stdio.h>
#include"state.h"

//State Pointer To Function
extern void (*CA_state )();
//Prototypes
STATE_define(CA_Waiting);
STATE_define(CA_Driving);

#endif /* CA_H_ */
