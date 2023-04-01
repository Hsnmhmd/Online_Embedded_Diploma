/*
 * lcd.c
 *
 * Created: 4/22/2021 3:01:11 PM
 *  Author: hassan
 */

#include "lcd.h"
uint8_t data_size=0;
LCD_Config_t LCD_CONFIG[5];
void delay_ms(uint32_t time) {
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++);
}

void LCD_INIT(uint8_t LCD_INDEX,LCD_Config_t* LCD) {
	uint8_t i=0;
	if(LCD->LCD_MODE>>4 &0x1){
		data_size=8;
		LCD_CONFIG[LCD_INDEX]=*LCD;
	}else{
		data_size=4;
		LCD_CONFIG[LCD_INDEX]=*LCD;
	}
	PinCfg.GPIO_Pin_Number = LCD->RS_LCD_PIN.GPIO_PIN;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP_10M;

	MCAL_GPIO_Init(LCD->RS_LCD_PIN.GPIO_Port, &PinCfg);

	PinCfg.GPIO_Pin_Number = LCD->RW_LCD_PIN.GPIO_PIN;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP_10M;

	MCAL_GPIO_Init(LCD->RW_LCD_PIN.GPIO_Port, &PinCfg);

	PinCfg.GPIO_Pin_Number = LCD->EN_LCD_PIN.GPIO_PIN;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP_10M;

	MCAL_GPIO_Init(LCD->EN_LCD_PIN.GPIO_Port, &PinCfg);

	//============================
	// SET THE NEXT 8 PINS AS INPUT
	for(i=0;i<data_size;i++){
		PinCfg.GPIO_Pin_Number = LCD->D_LCD_PIN[i].GPIO_PIN;
		PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP_10M;

		MCAL_GPIO_Init(LCD->D_LCD_PIN[i].GPIO_Port, &PinCfg);

	}


	//	DataDir_LCD_CTRL |= (1 << EN_SWITCH | 1 << RS_SWITCH | 1 << RW_SWITCH);
	MCAL_GPIO_WritePin(LCD->RS_LCD_PIN.GPIO_Port, LCD->RS_LCD_PIN.GPIO_PIN, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD->RW_LCD_PIN.GPIO_Port, LCD->RW_LCD_PIN.GPIO_PIN, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD->EN_LCD_PIN.GPIO_Port, LCD->EN_LCD_PIN.GPIO_PIN, GPIO_PIN_RESET);
	delay_ms(15);

	LCD_clear_screen(LCD_INDEX);
	LCD_WRITE_COMMAND(LCD_INDEX,LCD_RETURN_HOME);
	LCD_WRITE_COMMAND(LCD_INDEX,LCD->LCD_MODE);
	LCD_WRITE_COMMAND(LCD_INDEX,LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_INDEX,LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_INDEX,LCD_DISP_ON_CURSOR_BLINK);

}

void LCD_clear_screen(uint8_t LCD_INDEX) {
	LCD_WRITE_COMMAND(LCD_INDEX,LCD_CLEAR_SCREEN);
}

void LCD_lcd_kick(uint8_t LCD_INDEX) {
	MCAL_GPIO_WritePin(LCD_CONFIG[LCD_INDEX].EN_LCD_PIN.GPIO_Port, LCD_CONFIG[LCD_INDEX].EN_LCD_PIN.GPIO_PIN, GPIO_PIN_RESET);
	delay_ms(50);
	MCAL_GPIO_WritePin(LCD_CONFIG[LCD_INDEX].EN_LCD_PIN.GPIO_Port, LCD_CONFIG[LCD_INDEX].EN_LCD_PIN.GPIO_PIN, GPIO_PIN_SET);
}

void LCD_GOTO_XY(uint8_t LCD_INDEX,unsigned char line, unsigned char position) {
	if (line == 1) {
		if (position < 16 && position >= 0) {
			LCD_WRITE_COMMAND(LCD_INDEX,LCD_BEGIN_AT_FIRST_ROW + position);
		}
	}
	if (line == 2) {
		if (position < 16 && position >= 0) {
			LCD_WRITE_COMMAND(LCD_INDEX,LCD_BEGIN_AT_SECOND_ROW + position);
		}
	}
}



void LCD_check_lcd_isbusy(uint8_t LCD_INDEX) {
//	DataDir_LCD_PORT &= ~(0xFF << DATA_shift);
	uint8_t i;
	for(i=0;i<data_size;i++){
		PinCfg.GPIO_Pin_Number = LCD_CONFIG[LCD_INDEX].D_LCD_PIN[i].GPIO_PIN;
		PinCfg.GPIO_Mode = GPIO_MODE_INPUT_F;

		MCAL_GPIO_Init(LCD_CONFIG[LCD_INDEX].D_LCD_PIN[i].GPIO_Port, &PinCfg);

	}

	MCAL_GPIO_WritePin(LCD_CONFIG[LCD_INDEX].RW_LCD_PIN.GPIO_Port, LCD_CONFIG[LCD_INDEX].RW_LCD_PIN.GPIO_PIN, GPIO_PIN_SET);
	MCAL_GPIO_WritePin(LCD_CONFIG[LCD_INDEX].RS_LCD_PIN.GPIO_Port, LCD_CONFIG[LCD_INDEX].RS_LCD_PIN.GPIO_PIN, GPIO_PIN_RESET);
//	LCD_CTRL |= (1 << RW_SWITCH);
//	LCD_CTRL &= ~(1 << RS_SWITCH);
	LCD_lcd_kick(LCD_INDEX);
//	DataDir_LCD_PORT |= (0xFF << DATA_shift);
	MCAL_GPIO_WritePin(LCD_CONFIG[LCD_INDEX].RW_LCD_PIN.GPIO_Port, LCD_CONFIG[LCD_INDEX].RW_LCD_PIN.GPIO_PIN, GPIO_PIN_RESET);
//	LCD_CTRL &= ~(1 << RW_SWITCH);

}

void LCD_WRITE_COMMAND(uint8_t LCD_INDEX,unsigned char command) {
//	LCD_check_lcd_isbusy(LCD_INDEX);
	uint8_t i;
//	MCAL_GPIO_WritePort(LCD_CONFIG[LCD_INDEX].D_LCD_PIN[i].GPIO_Port, command);
	if (data_size==8){
		for(i=0;i<data_size;i++){
			MCAL_GPIO_WritePin(LCD_CONFIG[LCD_INDEX].D_LCD_PIN[i].GPIO_Port, LCD_CONFIG[LCD_INDEX].D_LCD_PIN[i].GPIO_PIN, command>>i & 0x1);
		}
		MCAL_GPIO_WritePin(LCD_CONFIG[LCD_INDEX].RW_LCD_PIN.GPIO_Port, LCD_CONFIG[LCD_INDEX].RW_LCD_PIN.GPIO_PIN, GPIO_PIN_RESET);
		MCAL_GPIO_WritePin(LCD_CONFIG[LCD_INDEX].RS_LCD_PIN.GPIO_Port, LCD_CONFIG[LCD_INDEX].RS_LCD_PIN.GPIO_PIN, GPIO_PIN_RESET);
		delay_ms(1);
		LCD_lcd_kick(LCD_INDEX);
	//4bit mode
	}else {
		for(i=0;i<data_size;i++){
			//most significant nibble first
			MCAL_GPIO_WritePin(LCD_CONFIG[LCD_INDEX].D_LCD_PIN[i].GPIO_Port, LCD_CONFIG[LCD_INDEX].D_LCD_PIN[i].GPIO_PIN, command>>(i+4)& 0x1);	}

			MCAL_GPIO_WritePin(LCD_CONFIG[LCD_INDEX].RW_LCD_PIN.GPIO_Port, LCD_CONFIG[LCD_INDEX].RW_LCD_PIN.GPIO_PIN, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(LCD_CONFIG[LCD_INDEX].RS_LCD_PIN.GPIO_Port, LCD_CONFIG[LCD_INDEX].RS_LCD_PIN.GPIO_PIN, GPIO_PIN_RESET);
			delay_ms(1);
			LCD_lcd_kick(LCD_INDEX);
			for(i=0;i<data_size;i++){
				MCAL_GPIO_WritePin(LCD_CONFIG[LCD_INDEX].D_LCD_PIN[i].GPIO_Port, LCD_CONFIG[LCD_INDEX].D_LCD_PIN[i].GPIO_PIN, command>>i & 0x1);
			}

			MCAL_GPIO_WritePin(LCD_CONFIG[LCD_INDEX].RW_LCD_PIN.GPIO_Port, LCD_CONFIG[LCD_INDEX].RW_LCD_PIN.GPIO_PIN, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(LCD_CONFIG[LCD_INDEX].RS_LCD_PIN.GPIO_Port, LCD_CONFIG[LCD_INDEX].RS_LCD_PIN.GPIO_PIN, GPIO_PIN_RESET);
			delay_ms(1);
			LCD_lcd_kick(LCD_INDEX);


	}
}

void LCD_WRITE_CHAR(uint8_t LCD_INDEX,unsigned char character) {
//	LCD_check_lcd_isbusy(LCD_INDEX);
	uint8_t i;
	if (data_size==8){
		for(i=0;i<data_size;i++){
			MCAL_GPIO_WritePin(LCD_CONFIG[LCD_INDEX].D_LCD_PIN[i].GPIO_Port, LCD_CONFIG[LCD_INDEX].D_LCD_PIN[i].GPIO_PIN, character>>i & 0x1);
		}
		MCAL_GPIO_WritePin(LCD_CONFIG[LCD_INDEX].RW_LCD_PIN.GPIO_Port, LCD_CONFIG[LCD_INDEX].RW_LCD_PIN.GPIO_PIN, GPIO_PIN_RESET);
		MCAL_GPIO_WritePin(LCD_CONFIG[LCD_INDEX].RS_LCD_PIN.GPIO_Port, LCD_CONFIG[LCD_INDEX].RS_LCD_PIN.GPIO_PIN, GPIO_PIN_SET);
		delay_ms(1);
		LCD_lcd_kick(LCD_INDEX);
	//4bit mode
	}else {
		for(i=0;i<data_size;i++){
			//most significant nibble first
			MCAL_GPIO_WritePin(LCD_CONFIG[LCD_INDEX].D_LCD_PIN[i].GPIO_Port, LCD_CONFIG[LCD_INDEX].D_LCD_PIN[i].GPIO_PIN, character>>(i+4)& 0x1);	}
			MCAL_GPIO_WritePin(LCD_CONFIG[LCD_INDEX].RW_LCD_PIN.GPIO_Port, LCD_CONFIG[LCD_INDEX].RW_LCD_PIN.GPIO_PIN, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(LCD_CONFIG[LCD_INDEX].RS_LCD_PIN.GPIO_Port, LCD_CONFIG[LCD_INDEX].RS_LCD_PIN.GPIO_PIN, GPIO_PIN_SET);
			delay_ms(1);
			LCD_lcd_kick(LCD_INDEX);
			for(i=0;i<data_size;i++){
				MCAL_GPIO_WritePin(LCD_CONFIG[LCD_INDEX].D_LCD_PIN[i].GPIO_Port, LCD_CONFIG[LCD_INDEX].D_LCD_PIN[i].GPIO_PIN, character>>i & 0x1);
			}

			MCAL_GPIO_WritePin(LCD_CONFIG[LCD_INDEX].RW_LCD_PIN.GPIO_Port, LCD_CONFIG[LCD_INDEX].RW_LCD_PIN.GPIO_PIN, GPIO_PIN_RESET);
			MCAL_GPIO_WritePin(LCD_CONFIG[LCD_INDEX].RS_LCD_PIN.GPIO_Port, LCD_CONFIG[LCD_INDEX].RS_LCD_PIN.GPIO_PIN, GPIO_PIN_SET);
			delay_ms(1);
			LCD_lcd_kick(LCD_INDEX);


	}

}

void LCD_WRITE_STRING(uint8_t LCD_INDEX,char *string) {
	int count = 0;
	while (*string > 0) {
		count++;
		LCD_WRITE_CHAR(LCD_INDEX,*string++);
		if (count == 16) {
			LCD_GOTO_XY(LCD_INDEX,2, 0);
		} else if (count == 32) {
			LCD_clear_screen(LCD_INDEX);
			LCD_GOTO_XY(LCD_INDEX,1, 0);
			count = 0;
		}
	}
}

//void LCD_INIT() {
//
//	delay_ms(20);
//	// SET THE FIRST 3 PINS AS OUPUT
//	LCD_GPIO_init();
////	LCD_CTRL &= ~(1 << EN_SWITCH | 1 << RS_SWITCH | 1 << RW_SWITCH);
////	DataDir_LCD_PORT = 0xFF;
//	delay_ms(15);
//
//	LCD_clear_screen();
//	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
//	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
//	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
//	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
//}
