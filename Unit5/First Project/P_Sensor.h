#ifndef PS_H_
#define PS_H_
void PSensor_Read_Pval();
void PSensor_Send_Pval();
extern void (*PSensor_state)();
#endif