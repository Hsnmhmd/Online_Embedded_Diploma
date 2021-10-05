#include "driver.h"
#include "P_Controller.h"
#include "P_Sensor.h"
int Pval;
/*void PSensor_Init(){

}*/
void (*PSensor_state)();
void PSensor_Read_Pval(){
	Pval=getPressureVal();
	PSensor_state=PSensor_Send_Pval;
}
void PSensor_Send_Pval(){
	PController_Receive_Pval(Pval);
	PSensor_state=PSensor_Read_Pval;
}

