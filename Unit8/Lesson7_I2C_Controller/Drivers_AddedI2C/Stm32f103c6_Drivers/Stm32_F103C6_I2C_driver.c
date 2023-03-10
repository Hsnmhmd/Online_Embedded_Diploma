/*
 * Stm32_F103C6_DRiver.c
 *
 *  Created on: 25 Feb 2023
 *      Author: admin
 */
#include<stm32f103x6.h>
//#include"Stm32_F103C6_gpio_driver.h"
#include"Stm32_F103C6_I2C_driver.h"
#include"Stm32_F103C6_RCC_driver.h"

I2C_Config_t  Global_I2C_Config [2] = {NULL,NULL};

/*
 * ========================================================
 * 				Generic macros
 * ========================================================
 */
#define I2C1_Index 		0
#define I2C2_Index		1
#define SR_TXE		(uint8_t)(1<<1)
#define SR_RXNE		(uint8_t)(1<<0)
/*
 * ========================================================
 * 				Generic Functions
 * ========================================================
 */

/*
 * ========================================================
 * 							APIS
 * ========================================================
 */
/**================================================================
 * @Fn               -MCAL_I2C_INIT
 * @brief            -Initialize I2C according to the specified parameters
 *param[in]         -I2Cx :where x can be 1,2 depending on device used
 *param[in]           -I2C_Config :all the I2C configuration
 * @retval           -none
 * Note              -support for SM only
 */
void MCAL_I2C_INIT(I2C_t * I2Cx , I2C_Config_t* I2C_Config)
{
	uint16_t tempreg = 0 , freqrange = 0 ;
	uint32_t pclk1 = 8000000 ;
	uint16_t result = 0 ;

	//Enable RCC Clock
	if (I2Cx == I2C1)
	{
		Global_I2C_Config[I2C1_INDEX] = *I2C_Config ;
		RCC_I2C1_CLK_EN();


	}else //I2C2
	{
		Global_I2C_Config[I2C2_INDEX] = *I2C_Config ;
		RCC_I2C2_CLK_EN();
	}

	if(I2C_Config->I2C_Mode == I2C_Mode_I2C)
	{
		/*------------------------------------------Init Timing---------------------------*/

		//1-I2C_CR2 :FREQ[5:0]:Peripheral clock frequency
		tempreg = I2Cx->CR2 ;
		/*clear the FREQ[5:0] bits  */
		tempreg &= ~(I2C_CR2_FREQ_Msk) ;
		/*get pclk1 frequency value if clock =50NHZ put 50 in FREQ[5:0]*/
		pclk1 = MCAL_RCC_GetPCLK1();
		freqrange = (uint16_t)(pclk1 /1000000);//8000000>>20=7
		tempreg |= freqrange;
		/* write to CR2*/
		I2Cx->CR2 = tempreg ;

		//2-Configure the clock control registers

		/*Disable the selected I2C Peripheral to configure Time Just to make sure */
		I2Cx->CR1 &= ~(I2C_CR1_PE);
		tempreg = 0;

		/*Configure speed in standard mode */
		if((I2C_Config->I2C_ClockSpeed == I2C_SCLK_SM_50K) || (I2C_Config->I2C_ClockSpeed == I2C_SCLK_SM_100K))
		{
			/*standard mode speed calculation*/
			//T_high = CCR*T_pclk1 & T_pclk1 = T_high + T_low
			//CRR = Tclk / (2*Tpclk1)
			//CRR = (F_pclk1) / (2* F_i2cclk)
			result =(uint16_t) (pclk1 / ( I2C_Config->I2C_ClockSpeed * 2 ));
			tempreg = I2Cx->CCR;
			tempreg |= result;
			/* write to CRR*/
			I2Cx->CCR = tempreg ;

			//3-I2C_TRISE Configuration
			/* frequency bits +1 */
			I2Cx->TRISE = freqrange +1 ;

		}
		else
		{
			//fast mode not Supported
		}

		/*------------------------------------------I2Cx CR1 Configuration ---------------------------*/
		/*get the I2Cx_CR1 Value */
		tempreg = I2Cx->CR1 ;
		tempreg |= (uint16_t)(I2C_Config->I2c_ACK_Control | I2C_Config->General_Call_Address_Detection | I2C_Config->I2C_Mode |I2C_Config->StretchMode);

		/* write to CR1*/
		I2Cx->CR1 =tempreg ;

		/*------------------------------------------I2Cx OAR1 & I2Cx OAR2 Configuration ---------------------------*/
		tempreg = 0;
		if(I2C_Config->I2C_Slave_Address.Enable_Dual_ADD == 1) // there is a secendry address
		{
			tempreg = I2C_OAR2_ENDUAL;
			tempreg |= I2C_Config->I2C_Slave_Address.Secondary_slave_add << I2C_OAR2_ADD2_Pos; //<<1
			I2Cx->OAR2 =tempreg ;
		}
		//Primary address
		tempreg = 0;
		tempreg |= I2C_Config->I2C_Slave_Address.Primary_slave_add << 1 ;
		tempreg |= I2C_Config->I2C_Slave_Address.I2C_Addressing_Slave_mode ;		//7bit add or 10
		I2Cx->OAR1 =tempreg ;


	}else
	{
		//SMBUS Not supported
	}

	//Interrupt Mode (Slave Mode)
	if(I2C_Config->P_Slave_Event_CallBack != NULL) //enable SLAVE IRQ states Mode
	{
		//Enable irq
		I2Cx->CR2 |= I2C_CR2_ITERREN ;
		I2Cx->CR2 |= I2C_CR2_ITEVTEN ;
		I2Cx->CR2 |= I2C_CR2_ITBUFEN ;
		if(I2Cx == I2C1)
		{
			NVIC_IRQ31_I2C1_EV_Enable;
			NVIC_IRQ32_I2C1_ER_Enable;
		}
		else if(I2Cx == I2C2)
		{
			NVIC_IRQ33_I2C2_EV_E+nable;
			NVIC_IRQ34_I2C2_ER_Enable;
		}

		I2Cx->SR1 = 0;
		I2Cx->SR2 = 0;

	}

	/*Enable the selected I2C Peripheral */
	I2Cx->CR1 |= (I2C_CR1_PE);

}

/**================================================================
 * @Fn               -MCAL_I2C_DeINIT
 * @brief            -DeInitialize I2C
 *param[in]         -I2Cx :where x can be 1,2 depending on device used
 * @retval           -none
 * Note              -Reset the model by RCC
 */
void MCAL_I2C_DeINIT(I2C_t * I2Cx )
{
	if(I2Cx == I2C1)
	{
		NVIC_IRQ31_I2C1_EV_Disable;
		NVIC_IRQ32_I2C1_ER_Disable;
		RCC_I2C1_Reset();
	}
	else if(I2Cx == I2C2)
	{
		NVIC_IRQ33_I2C2_EV_Disable;
		NVIC_IRQ34_I2C2_ER_Disable;
		RCC_I2C2_Reset();
	}



}
/**================================================================
 * @Fn               - MCAL_I2C_GPIO_Set_Pins
 * @brief            -set the Gpio pins (can know the Pins from GPIO Pins table from TRM)
 *param[in]         -I2Cx :where x can be 1,2,depending on device used
 * @retval           -none
 * Note              -should enable the corresponding ALT &GPIO in RCC CLOCK AND called after MCAL_I2C_INIT()
 */

void MCAL_I2C_GPIO_Set_Pins (I2C_TypeDef * I2Cx)
{
	GPIO_PinConfig_t Pincfg;

	if(I2Cx == I2C1)
	{
		//PB6 : I2C1_SCL
		//PB7 : I2C1_SDA
		Pincfg.GPIO_Pin_Number = GPIO_Pin_6 ;
		Pincfg.GPIO_Mode = GPIO_Mode_OUTPUT_AF_OD;
		Pincfg.GPIO_output_speed = GPIO_output_speed_10M;
		MCAL_GPIO_Init(GPIOB,&Pincfg);

		Pincfg.GPIO_Pin_Number = GPIO_Pin_7 ;
		Pincfg.GPIO_Mode = GPIO_Mode_OUTPUT_AF_OD;
		Pincfg.GPIO_output_speed = GPIO_output_speed_10M;
		MCAL_GPIO_Init(GPIOB, &Pincfg);
	}

	else if(I2Cx == I2C2)
	{
		//PB10 : I2C2_SCL
		//PB11 : I2C2_SDA
		Pincfg.GPIO_Pin_Number = GPIO_Pin_10 ;
		Pincfg.GPIO_Mode = GPIO_Mode_OUTPUT_AF_OD;
		Pincfg.GPIO_output_speed = GPIO_output_speed_10M;
		MCAL_GPIO_Init(GPIOB,&Pincfg);

		Pincfg.GPIO_Pin_Number = GPIO_Pin_11 ;
		Pincfg.GPIO_Mode = GPIO_Mode_OUTPUT_AF_OD;
		Pincfg.GPIO_output_speed = GPIO_output_speed_10M;
		MCAL_GPIO_Init(GPIOB, &Pincfg);
	}


}

/*=================================================================*/
/*=========================IRQ=====================================*/
/*=================================================================*/

void SPI1_IRQHandler(void)
{

	struct S_IRQ_SRC irq_src;
	irq_src.TXE = ((SPI1->SR)&(1<<1)>>1);
	irq_src.RXNE = ((SPI1->SR)&(1<<0)>>0);
	irq_src.ERRI = ((SPI1->SR)&(1<<4)>>4);
	Global_SPI_Config[SPI1_Index]->P_IRQ_CallBack(irq_src);
}
void SPI2_IRQHandler(void)
{
	struct S_IRQ_SRC irq_src;
	irq_src.TXE = ((SPI2->SR)&(1<<1)>>1);
	irq_src.RXNE = ((SPI2->SR)&(1<<0)>>0);
	irq_src.ERRI = ((SPI2->SR)&(1<<4)>>4);
	Global_SPI_Config[SPI2_Index]->P_IRQ_CallBack(irq_src);
}
