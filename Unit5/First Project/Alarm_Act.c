#include "Alarm_Act.h"
#include "driver.h"
int signal;
void (*Alarm_State)();
void Alarm_Init(){

}
void Alarm_Idle(){
	Alarm_State=Alarm_Idle;
}
void Alarm_Fire(){
		Set_Alarm_actuator(0);
		//_delay_ms(60000);
		Delay(1000000);
		Set_Alarm_actuator(1);
		Alarm_State=Alarm_Idle;	
}
void Alarm_Signal(int signal){
	if (signal){
		Alarm_State=Alarm_Fire;
	}
}
