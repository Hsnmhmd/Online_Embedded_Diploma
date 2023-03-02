# Drivers #
This Section in Repo contains:
1. the previously implemented drivers and added to them the SPI driver for stm32f103c6.
2. A little source code to test the driver that could be compiled for a master or a slave after set the acting macro accordingly.
3. A Partial implementation of Reset and Clock Control
4. A simulation snippet that shows A master slave interaction

## Driver Description ## 
This driver delivers its functionality through a set of APIs:
1. MCAL_SPI_Init
  *Initialize a Specified SPI with its mode, payload length, CLOCK specs, Baudrate, Interrupt status and Master/Slave mode according the config struct.
2. MCAL_SPI_SetPins
  *set the Gpio pins of the specidied SPI instance to work with AFIO(SPI)
3. MCAL_SPI_Send
  *Send buffer on SPI
4. MCAL_SPI_Recieve
  *Receive buffer from SPI
4. MCAL_SPI_TX_RX