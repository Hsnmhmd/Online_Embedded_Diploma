#ifndef PC_H_
#define PC_H_
void PController_Idle();
void PController_Process();
void PController_Receive_Pval(int val);
extern void (*PController_state)();
#endif