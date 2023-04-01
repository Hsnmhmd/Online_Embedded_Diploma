/*
 * Park_Controller.c
 *
 *  Created on: 1 Apr 2023
 *      Author: Hassan
 */
#include "Park_Controller.h"


void (* Park_Status)();

uint8_t pass[3] ={0};
uint8_t Available_Slots=3;
uint8_t Search_Done = 0;

void Park_Idle(){
	Park_Status=Park_Idle;
}
void Park_Process_EntryGate(){

		if(Available_Slots>0)
		{
			Search_Done=0;
			uint8_t i;
			for(i=0;i<3;i++){
				/*==================Correct Id====================*/
				if(RFID_CARD_Enter==pass[i]){
					LCD1_Status=LCD_Welcome;
					LED_Status=LED_Green_On;
					Gate_Status=Gate1_Letting;
					Available_Slots--;
					break;
				}else
					Search_Done++;
			}/*==================Wrong Id====================*/
			if(Search_Done==3){
				LCD1_Status=LCD_Rejected;
				LED_Status=LED_Red_On;
				Search_Done=0;
			}
		}
		/*======Parking is full so not allow enetr cars=======*/
		else
		{
			LCD1_Status=LCD_Full_Parking;
		}
	Park_Status=Park_Idle;
}
void Park_Process_ExitGate(void){

	//Search about ID in array of Pass
	if(Available_Slots<3){
	int i=0;
		Search_Done=0;
		for(i=0;i<3;i++){
			/*==================Correct Id====================*/
			if(RFID_CARD_EXIT==pass[i]){
				LCD1_Status=LCD_Farewell;
				LED_Status=LED_Green_On;
				Gate_Status=Gate2_Letting;
				Available_Slots++;
				break;
			}else
				Search_Done++;
		}/*==================Wrong Id====================*/
		if(Search_Done==3){
			LCD1_Status=LCD_Rejected;
			LED_Status=LED_Red_On;
			Search_Done=0;
		}
	}
	Park_Status=Park_Idle;

}


void Store_IDs_From_Admin(void)
{
	LCD_WRITE_COMMAND(LCD0_INDEX, LCD_DISP_ON);
	LCD_WRITE_COMMAND(LCD0_INDEX, LCD_CLEAR_SCREEN);
	LCD_GOTO_XY(LCD0_INDEX, 0, 0);
	LCD_WRITE_STRING(LCD0_INDEX,"Enter Car IDS");
	static uint8_t i=0;
	for(i=0;i<3;i++){
		do{
			pass[i]=Keypad_getkey();
		}
		while(pass[i]=='N');
		LCD_WRITE_COMMAND(LCD0_INDEX, LCD_DISP_ON);
		LCD_WRITE_COMMAND(LCD0_INDEX, LCD_CLEAR_SCREEN);
		LCD_GOTO_XY(LCD0_INDEX, 0, 0);
		LCD_WRITE_STRING(LCD0_INDEX,"ID ");
		LCD_GOTO_XY(LCD0_INDEX, 4, 0);
		LCD_WRITE_CHAR(LCD0_INDEX,i+48);
		LCD_GOTO_XY(LCD0_INDEX, 5, 0);
		LCD_WRITE_CHAR(LCD0_INDEX,'=');
		LCD_GOTO_XY(LCD0_INDEX, 6, 0);
		LCD_WRITE_CHAR(LCD0_INDEX,pass[i]);
		//		pass[i]=Keypad_getkey();
	}
	LCD_WRITE_COMMAND(LCD0_INDEX, LCD_DISP_ON);
	LCD_WRITE_COMMAND(LCD0_INDEX, LCD_CLEAR_SCREEN);
	LCD_GOTO_XY(LCD0_INDEX, 0, 0);
	LCD_WRITE_STRING(LCD0_INDEX,"Allowed IDS=");
	for(i=0;i<3;i++){
		LCD_GOTO_XY(LCD0_INDEX, i+12, 0);
		LCD_WRITE_CHAR(LCD0_INDEX,pass[i]);
	}
}

