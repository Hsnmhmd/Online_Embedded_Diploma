# Drivers #
This Section in Repo contains:
1. the previously implemented drivers and added to them the uart driver for stm32f103c6.
2. A little source code to test the driver.
3. A Partial implementation of Reset and Clock Control Driver to aquire the clock freq as it's reqiured for the Baudrate Calculations

## Driver Description ## 
This driver delivers its functionality through a set of APIs:
1. MCAL_EXTI_Init
  *Initialize a Specified USART with its mode, frame specs, Baudrate, Interrupt status and hardware flowcontrol according the config struct.
2. MCAL_USART_SetPins
  *set the Gpio pins of the specidied uarts instance to work with AFIO(UART)
3. MCAL_UART_Send
  *Send buffer on UART 
4. MCAL_USART_Recieve
  *Receive buffer from UART
