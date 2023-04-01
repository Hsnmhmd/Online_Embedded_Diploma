################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/I2C_Slave_eeprom.c \
../HAL/Servo_Motor.c \
../HAL/keypad.c \
../HAL/lcd.c 

OBJS += \
./HAL/I2C_Slave_eeprom.o \
./HAL/Servo_Motor.o \
./HAL/keypad.o \
./HAL/lcd.o 

C_DEPS += \
./HAL/I2C_Slave_eeprom.d \
./HAL/Servo_Motor.d \
./HAL/keypad.d \
./HAL/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/I2C_Slave_eeprom.o: ../HAL/I2C_Slave_eeprom.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit11_2nd_Term_Project/Smart_Parking/HAL/INC" -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit11_2nd_Term_Project/Smart_Parking/Stm32f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/I2C_Slave_eeprom.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/Servo_Motor.o: ../HAL/Servo_Motor.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit11_2nd_Term_Project/Smart_Parking/HAL/INC" -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit11_2nd_Term_Project/Smart_Parking/Stm32f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/Servo_Motor.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/keypad.o: ../HAL/keypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit11_2nd_Term_Project/Smart_Parking/HAL/INC" -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit11_2nd_Term_Project/Smart_Parking/Stm32f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/lcd.o: ../HAL/lcd.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit11_2nd_Term_Project/Smart_Parking/HAL/INC" -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit11_2nd_Term_Project/Smart_Parking/Stm32f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/lcd.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

