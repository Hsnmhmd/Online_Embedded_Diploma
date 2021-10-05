#include "driver.h"
#include "P_Controller.h"
int Pval;
void (*PController_state )();

void PController_Receive_Pval(int val){
	Pval=val;
	PController_state = PController_Process;
		
}
/*The Idle State*/
void PController_Idle(){
	PController_state=PController_Idle;
}
/*The Processing  State*/
void PController_Process(){

		if(Pval>=20){
			/*Sending Signal To Alarm Module*/
			Alarm_Signal(1);
			PController_state=PController_Idle;
		}else{
			PController_state=PController_Idle;
		}
}
