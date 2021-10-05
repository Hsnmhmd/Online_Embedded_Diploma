#ifndef AA_H_
#define AA_H_
//Prototypes
void Alarm_Idle();
void Alarm_Fire();
//State Pointer To Function
extern void (*Alarm_State)();
#endif