/*
 * Stm32_F103C6_gpio_driver.c
 *
 *  Created on: Sep 18, 2021
 *      Author: hassan
 */

#include"Stm32f103x6.h"
#include"Stm32_F103C6_RCC_driver.h"
//-----------------------------
/*
 * ===============================================
 * Generic Variables by "MCAL RCC DRIVER"
 * ===============================================
 */
const uint8_t APBprescTable[8U]={0,0,0,0,1,2,3,4};
//There is no division by 32 so 5 is not included for AHB
const uint8_t AHBprescTable[16U]={0,0,0,0,0,0,0,0,1,2,3,4,6,7,8,9};
/*
 * ===============================================
 * Generic Macros by "MCAL RCC DRIVER"
 * ===============================================
 */

/*
 * ===============================================
 * Generic Functions by "MCAL RCC DRIVER"
 * ===============================================
 */

/*
 * ===============================================
 * APIs Supported by "MCAL RCC DRIVER"
 * ===============================================
 */
uint32_t MCAL_RCC_GetSYS_CLK(void){
	switch ( (RCC->CFGR >>2) &0b11 ){
	//HSI selected as system clock
	case 0:
		return HSI_RC_CLK;
		break;
	//HSE selected as system clock
	case 1:
		return HSE_CLK;
		break;
	//PLL selected as system clock
	case 2:
		switch ( (RCC->CFGR >>16) &0b1 ){
		//HSI oscillator clock / 2 selected as PLL input clock
		case 0:
			if (((RCC->CFGR >>18)& 0b1111) ==15   )
				return (HSI_RC_CLK>>1)*( ( (RCC->CFGR >>18)& 0b1111 )+1 );
			else
				return (HSI_RC_CLK>>1)*( ( (RCC->CFGR >>18)& 0b1111 )+2 );
			break;
		//HSE oscillator clock selected as PLL input clock
		case 1:
			//HSE clock divided by 2
			if((RCC->CFGR >>17) &0b1){
				if (((RCC->CFGR >>18)& 0b1111) ==15   )
					return (HSE_CLK>>1)*( ( (RCC->CFGR >>18)& 0b1111 )+1 );
				else
					return (HSE_CLK>>1)*( ( (RCC->CFGR >>18)& 0b1111 )+2 );
			}//HSE clock not divided
			else{
				if (((RCC->CFGR >>18)& 0b1111) ==15   )
					return (HSE_CLK)*( ( (RCC->CFGR >>18)& 0b1111 )+1 );
				else
					return (HSE_CLK)*( ( (RCC->CFGR >>18)& 0b1111 )+2 );
			}

			break;

		}break;

	}

}
/**================================================================
 * @Fns-			MCAL_RCC_GetCLK
 * @brief -			GET the freq of each bus by dividing the input clock by the scaler
 * 					Get the value of the scaler from the scaler array according to CFGR register
 *					for ABP PCLK1 and 2PCLK2
 *					0xx: HCLK not divided
					100: HCLK divided by 2
					101: HCLK divided by 4
					110: HCLK divided by 8
					111: HCLK divided by 16
					AND SAME CONCEPT FOR AHB CLK according to the specs
 * @param [in] -	none
 * @param [out] -	None
 * @retval -		Freq
 * Note-
 */
uint32_t MCAL_RCC_GetHCLK(void){
	uint32_t test=(MCAL_RCC_GetSYS_CLK() >> AHBprescTable[( (RCC->CFGR >>4) &0b1111 )]);
	return test;
}
// bits 8 :10 PPRE1 APB1 prescaler
uint32_t MCAL_RCC_GetPCLK1(void){
	return (MCAL_RCC_GetHCLK() >> APBprescTable[( (RCC->CFGR >>8) &0b111 )]);
}
// bits 11 :13 PPRE1 APB2 prescaler
uint32_t MCAL_RCC_GetPCLK2(void){
	return (MCAL_RCC_GetHCLK() >> APBprescTable[( (RCC->CFGR >>11) &0b111 )]);
}



