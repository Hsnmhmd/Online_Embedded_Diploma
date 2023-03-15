# Drivers #
This Section in Repo contains:
1. the previously implemented drivers and added to them the I2C driver for stm32f103c6.
2. A little source code to test the driver that Sends data to and receives from E2PROM.
4. A simulation snippets that shows I2C and E2PROM interaction

## Driver Description ## 
This driver delivers its functionality through a set of APIs:
1. MCAL_I2C_Init
  *Initialize a Specified I2C  according the to config struct.
2. MCAL_I2C_SetPins
  *set the Gpio pins of the specidied I2C instance to work with AFIO(I2C)(OD)
3. MCAL_I2C_Master_TX
  *I2C Master transmit according to the specified parameters
4. MCAL_I2C_Master_RX
  *I2C Master Receive according to the specified parameters
-- APIs to be used with slaves in interrupt mode