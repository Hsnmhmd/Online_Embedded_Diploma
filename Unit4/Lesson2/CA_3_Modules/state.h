/*
 * state.h
 *
 *  Created on: 23 Sep 2021
 *      Author: hassan
 */

#ifndef STATE_H_
#define STATE_H_
//Automatic FN Generator
#define STATE_define(_stat_FN) void ST_##_stat_FN()
//For FN Assigning to PTR To Fn
#define STATE(_stat_FN) ST_##_stat_FN

//Connections
void US_Set_Distance(int Distance);
void DC_Set_Speed(int Speed);


#endif /* STATE_H_ */
