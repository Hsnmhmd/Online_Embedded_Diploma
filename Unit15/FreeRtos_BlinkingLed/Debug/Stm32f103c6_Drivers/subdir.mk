################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Stm32f103c6_Drivers/Stm32_F103C6_EXTI_driver.c \
../Stm32f103c6_Drivers/Stm32_F103C6_I2C_driver.c \
../Stm32f103c6_Drivers/Stm32_F103C6_RCC_driver.c \
../Stm32f103c6_Drivers/Stm32_F103C6_SPI_driver.c \
../Stm32f103c6_Drivers/Stm32_F103C6_UART_driver.c \
../Stm32f103c6_Drivers/Stm32_F103C6_gpio_driver.c \
../Stm32f103c6_Drivers/Timer.c 

OBJS += \
./Stm32f103c6_Drivers/Stm32_F103C6_EXTI_driver.o \
./Stm32f103c6_Drivers/Stm32_F103C6_I2C_driver.o \
./Stm32f103c6_Drivers/Stm32_F103C6_RCC_driver.o \
./Stm32f103c6_Drivers/Stm32_F103C6_SPI_driver.o \
./Stm32f103c6_Drivers/Stm32_F103C6_UART_driver.o \
./Stm32f103c6_Drivers/Stm32_F103C6_gpio_driver.o \
./Stm32f103c6_Drivers/Timer.o 

C_DEPS += \
./Stm32f103c6_Drivers/Stm32_F103C6_EXTI_driver.d \
./Stm32f103c6_Drivers/Stm32_F103C6_I2C_driver.d \
./Stm32f103c6_Drivers/Stm32_F103C6_RCC_driver.d \
./Stm32f103c6_Drivers/Stm32_F103C6_SPI_driver.d \
./Stm32f103c6_Drivers/Stm32_F103C6_UART_driver.d \
./Stm32f103c6_Drivers/Stm32_F103C6_gpio_driver.d \
./Stm32f103c6_Drivers/Timer.d 


# Each subdirectory must supply rules for building sources it contributes
Stm32f103c6_Drivers/Stm32_F103C6_EXTI_driver.o: ../Stm32f103c6_Drivers/Stm32_F103C6_EXTI_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit15/FreeRtos_BlinkingLed/Free_RTOS/include" -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit15/FreeRtos_BlinkingLed/Stm32f103c6_Drivers/inc" -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit15/FreeRtos_BlinkingLed/Free_RTOS/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32f103c6_Drivers/Stm32_F103C6_EXTI_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32f103c6_Drivers/Stm32_F103C6_I2C_driver.o: ../Stm32f103c6_Drivers/Stm32_F103C6_I2C_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit15/FreeRtos_BlinkingLed/Free_RTOS/include" -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit15/FreeRtos_BlinkingLed/Stm32f103c6_Drivers/inc" -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit15/FreeRtos_BlinkingLed/Free_RTOS/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32f103c6_Drivers/Stm32_F103C6_I2C_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32f103c6_Drivers/Stm32_F103C6_RCC_driver.o: ../Stm32f103c6_Drivers/Stm32_F103C6_RCC_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit15/FreeRtos_BlinkingLed/Free_RTOS/include" -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit15/FreeRtos_BlinkingLed/Stm32f103c6_Drivers/inc" -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit15/FreeRtos_BlinkingLed/Free_RTOS/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32f103c6_Drivers/Stm32_F103C6_RCC_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32f103c6_Drivers/Stm32_F103C6_SPI_driver.o: ../Stm32f103c6_Drivers/Stm32_F103C6_SPI_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit15/FreeRtos_BlinkingLed/Free_RTOS/include" -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit15/FreeRtos_BlinkingLed/Stm32f103c6_Drivers/inc" -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit15/FreeRtos_BlinkingLed/Free_RTOS/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32f103c6_Drivers/Stm32_F103C6_SPI_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32f103c6_Drivers/Stm32_F103C6_UART_driver.o: ../Stm32f103c6_Drivers/Stm32_F103C6_UART_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit15/FreeRtos_BlinkingLed/Free_RTOS/include" -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit15/FreeRtos_BlinkingLed/Stm32f103c6_Drivers/inc" -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit15/FreeRtos_BlinkingLed/Free_RTOS/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32f103c6_Drivers/Stm32_F103C6_UART_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32f103c6_Drivers/Stm32_F103C6_gpio_driver.o: ../Stm32f103c6_Drivers/Stm32_F103C6_gpio_driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit15/FreeRtos_BlinkingLed/Free_RTOS/include" -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit15/FreeRtos_BlinkingLed/Stm32f103c6_Drivers/inc" -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit15/FreeRtos_BlinkingLed/Free_RTOS/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32f103c6_Drivers/Stm32_F103C6_gpio_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32f103c6_Drivers/Timer.o: ../Stm32f103c6_Drivers/Timer.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit15/FreeRtos_BlinkingLed/Free_RTOS/include" -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit15/FreeRtos_BlinkingLed/Stm32f103c6_Drivers/inc" -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit15/FreeRtos_BlinkingLed/Free_RTOS/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32f103c6_Drivers/Timer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

