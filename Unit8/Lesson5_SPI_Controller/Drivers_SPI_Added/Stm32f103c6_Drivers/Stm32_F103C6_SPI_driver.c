/*
 * Stm32_F103C6_DRiver.c
 *
 *  Created on: 25 Feb 2023
 *      Author: admin
 */
#include<stm32f103x6.h>
#include"Stm32_F103C6_gpio_driver.h"
#include"Stm32_F103C6_SPI_driver.h"


SPI_Config_t * Global_SPI_Config [2] = {NULL,NULL};


/*
 * ========================================================
 * 				Generic macros
 * ========================================================
 */
#define SPI1_Index 		0
#define SPI2_Index		1
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
/**=======================================================
 * @Fn				-MCAL_SPI_Init
 * @brief			-Initializes SPI
 * @param [in]		-SPI_Instance
 * @param [in]		-SPI_Cfg
 * @retval			-Non
 * Note
 */
void MCAL_SPI_Init(SPI_t * SPIx , SPI_Config_t * Config)
{
	//safety for registers to avoid any unwanted behavior
	// will  put their values in registers at the end
	uint16_t tmpreg_CR1 = 0;
	uint16_t tmpreg_CR2 = 0;
	if(SPIx == SPI1)
	{
		Global_SPI_Config[SPI1_Index] = Config;
		RCC_SPI1_CLK_EN();
	}
	else
	{
		Global_SPI_Config[SPI2_Index] = Config;
		RCC_SPI2_CLK_EN();
	}
	//Enable SPI bit6 in CR1
	tmpreg_CR1 |= (1<<6);
	//Master or slave
	tmpreg_CR1 |= Config->Device_Mode;
	//SPI Communication mode 2line or 1line rx only ,tx only or both
	tmpreg_CR1 |=Config->Communication_Mode;
	tmpreg_CR1 |=Config->Frame_Format;
	tmpreg_CR1 |=Config->Pay_Load_Length;
	//SPI_Clock_Polarity
	tmpreg_CR1 |=Config->CLock_Polarity;
	//SPI_Clock_Phase
	tmpreg_CR1 |=Config->CLock_Phase;
	//================================NSS==============================

	if(Config->NSS == SPI_NSS_Hard_Master_SS_Output_Enable)
	{
		//		Single Master Mode
		//		NSS output enabled (SSM = 0, SSOE = 1)
		//		This configuration is used only when the device operates in master mode. The
		//		NSS signal is driven low when the master starts the communication and is kept
		//		low until the SPI is disabled.
		tmpreg_CR2 |= SPI_NSS_Hard_Master_SS_Output_Enable;
	}
	else if (Config->NSS == SPI_NSS_Hard_Master_SS_No_output)
	{
		tmpreg_CR2 |= SPI_NSS_Hard_Master_SS_No_output;
	}
	else
		tmpreg_CR1 |= Config->NSS;
	//==============================PreScaler=========================
	tmpreg_CR1 |= Config->SPI_Prescaler;

	if(Config->IRQ_Enable != SPI_IRQ_Enable_Non)
	{
		tmpreg_CR2 |= Config->IRQ_Enable;
		if(SPIx == SPI1)
		{
			NVIC_IRQ35_SPI1_Enable;
		}
		else
		{
			NVIC_IRQ36_SPI2_Enable;
		}
	}

	SPIx->CR1 = tmpreg_CR1;
	SPIx->CR2 = tmpreg_CR2;
}

/**=======================================================
 * @Fn				-MCAL_SPI_DeInit
 * @brief			-DeInitializes SPI
 * @param [in]		-SPIx: SPI to reset
 * @retval			-None
 * Note
 */
void MCAL_SPI_DeInit(SPI_t * SPIx)
{
	if(SPIx == SPI1)
	{
		NVIC_IRQ35_SPI1_Disable;
		RCC_SPI1_Reset();
	}
	else
	{
		NVIC_IRQ36_SPI2_Disable;
		RCC_SPI2_Reset();
	}
}

/**=======================================================
 * @Fn				-MCAL_SPI_SendData
 * @brief			-Sending Data through SPI
 * @param [in]		-SPIx:Specifies through which SPI you want to transmit your data
 * @param [in]		-pTXBuffer:Specifies Data you want to transmit
 * @param [in]		-Polling_mechism:Waiting or Not
 * @retval			-None
 * Note
 */
void MCAL_SPI_SendData(SPI_t * SPIX , uint16_t * pTXBuffer ,  enum SPI_PollingMechanism Polling_En)
{
	if(Polling_En == Enabled)
	{	//Waiting until tx buffer is empty to not over write any previous transmissions
		while((SPIX->SR)&(SR_TXE));
	}
	else
	{
		SPIX->DR = *pTXBuffer;
	}

}
// Multi Slave operation not included only point to point
void MCAL_SPI_GPIO_Set_Pins(SPI_t * SPIx)
{
	GPIO_PinConfig_t PConfig;
	uint8_t NSS;
	uint8_t SCK;
	uint8_t MISO;
	uint8_t MOSI;
	SPI_Config_t * Local_SPI_Config;
	GPIO_t *GPIOx;
	if(SPIx == SPI1)
	{
		NSS=GPIO_Pin_4;
		SCK=GPIO_Pin_5;
		MISO=GPIO_Pin_6;
		MOSI=GPIO_Pin_7;
		Local_SPI_Config=Global_SPI_Config[SPI1_Index];
		GPIOx=GPIOA;
	}else
	{
		NSS=GPIO_Pin_12;
		SCK=GPIO_Pin_13;
		MISO=GPIO_Pin_14;
		MOSI=GPIO_Pin_15;
		Local_SPI_Config=Global_SPI_Config[SPI2_Index];
		GPIOx=GPIOB;
	}
		if(Local_SPI_Config->Device_Mode == SPI_Mode_Master )
		{
			//NSS
			switch(Local_SPI_Config->NSS)
			{
			case SPI_NSS_Hard_Master_SS_Output_Enable :
			{

				PConfig.GPIO_Pin_Number = NSS;
				PConfig.GPIO_Mode = GPIO_MODE_OUTPUT_PP_10M;
				MCAL_GPIO_Init(GPIOx, &PConfig);
				break;
			}
			case SPI_NSS_Hard_Master_SS_No_output:
			{
				PConfig.GPIO_Pin_Number = NSS;
				PConfig.GPIO_Mode = GPIO_MODE_INPUT_F;
				MCAL_GPIO_Init(GPIOx,&PConfig);
				break;
			}
			}
			PConfig.GPIO_Pin_Number = SCK;
			PConfig.GPIO_Mode = GPIO_MODE_AF_PP_10M;
			MCAL_GPIO_Init(GPIOx, &PConfig);
			//MISO
			PConfig.GPIO_Pin_Number = MISO;
			PConfig.GPIO_Mode = GPIO_MODE_INPUT_F;
			MCAL_GPIO_Init(GPIOx,&PConfig);
			//MOSI
			PConfig.GPIO_Pin_Number = MOSI;
			PConfig.GPIO_Mode = GPIO_MODE_AF_PP_10M;
			MCAL_GPIO_Init(GPIOx,&PConfig);
		}
		else
		{
			if (Local_SPI_Config->NSS == SPI_NSS_Hard_Slave )
			{
				PConfig.GPIO_Pin_Number = NSS;
				PConfig.GPIO_Mode = GPIO_MODE_INPUT_F;
				MCAL_GPIO_Init(GPIOx, &PConfig);
			}
			//SCK
			PConfig.GPIO_Pin_Number = SCK;
			PConfig.GPIO_Mode = GPIO_MODE_INPUT_F;
			MCAL_GPIO_Init(GPIOx, &PConfig);
			//MISO Full duplex / slave (point to point) does not support multi slave
			PConfig.GPIO_Pin_Number = MISO;
			PConfig.GPIO_Mode = GPIO_MODE_AF_PP_10M;
			MCAL_GPIO_Init(GPIOx, &PConfig);
			// MOSI Full duplex / slave
			PConfig.GPIO_Pin_Number = GPIO_Pin_7;
			PConfig.GPIO_Mode = GPIO_MODE_INPUT_F;
			MCAL_GPIO_Init(GPIOx,&PConfig);
		}


}
/**=======================================================
 * @Fn				-MCAL_SPI_ReceiveData
 * @brief			-Receiving Data through SPI
 * @param [in]		-SPIx:Specifies through which SPI you want to receive your data
 * @param [in]		-pRx:Specifies Data you want to receive
 * @param [in]		-Polling_mechism:Waiting or Not
 * @retval			-None
 * Note
 */
void MCAL_SPI_ReceiveData(SPI_t * SPIX,uint16_t * pRXBuffer ,  enum SPI_PollingMechanism Polling_En)
{
	//Wait until the data is fully received if there is no data transmitted it will wait forever

	if(Polling_En == Enabled)
	{
		while(!(SPIX->SR & SR_RXNE));
	}
	*pRXBuffer =SPIX->DR;
}
/**=======================================================
 * @Fn				-MCAL_SPI_Tx_Rx
 * @brief			-Transmitting and Receiving Data through SPI
 * @param [in]		-SPIx:Specifies through which SPI you want to receive your data
 * @param [in]		-TX_RX_pBuffer:reg which you will transmit or receive data in
 * @param [in]		-Polling_mechism:Waiting or Not
 * @retval			-None
 * Note
 */
void MCAL_SPI_Tx_Rx(SPI_t * SPIX ,uint16_t * TX_RX_pBuffer , enum SPI_PollingMechanism Polling_En)
{

	if(Polling_En == Enabled)
	{
		while(!(SPIX->SR & SR_TXE));//Waiting until tx buffer is empty
	}
	SPIX->DR = *TX_RX_pBuffer;
	if(Polling_En == Enabled)
	{
		while(!(SPIX->SR & SR_RXNE));
	}
	*TX_RX_pBuffer =  SPIX->DR;
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
