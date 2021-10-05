#include "P_Controller.h"
#include "P_Sensor.h"
#include "Alarm_Act.h"

#include "driver.h"
//#include<util/delay.h>
void Setup(){
	//Alarm & Sensor Initialization
	GPIO_INITIALIZATION();
	PSensor_state=PSensor_Read_Pval;
	PController_state=PController_Idle;
	Alarm_State=Alarm_Idle;
}

int main (){
	Setup();
	while (1)
	{
		PSensor_state();
		PController_state();
		Alarm_State();
		//Implement your Design 
	}
	return 0;
}
