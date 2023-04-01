################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Gate_Controller.c \
../Src/LCD_Controller.c \
../Src/LED_COntroller.c \
../Src/Park_Controller.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/Gate_Controller.o \
./Src/LCD_Controller.o \
./Src/LED_COntroller.o \
./Src/Park_Controller.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/Gate_Controller.d \
./Src/LCD_Controller.d \
./Src/LED_COntroller.d \
./Src/Park_Controller.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Gate_Controller.o: ../Src/Gate_Controller.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit11_2nd_Term_Project/Smart_Parking/HAL/INC" -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit11_2nd_Term_Project/Smart_Parking/Stm32f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/Gate_Controller.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/LCD_Controller.o: ../Src/LCD_Controller.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit11_2nd_Term_Project/Smart_Parking/HAL/INC" -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit11_2nd_Term_Project/Smart_Parking/Stm32f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/LCD_Controller.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/LED_COntroller.o: ../Src/LED_COntroller.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit11_2nd_Term_Project/Smart_Parking/HAL/INC" -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit11_2nd_Term_Project/Smart_Parking/Stm32f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/LED_COntroller.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/Park_Controller.o: ../Src/Park_Controller.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit11_2nd_Term_Project/Smart_Parking/HAL/INC" -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit11_2nd_Term_Project/Smart_Parking/Stm32f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/Park_Controller.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/main.o: ../Src/main.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit11_2nd_Term_Project/Smart_Parking/HAL/INC" -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit11_2nd_Term_Project/Smart_Parking/Stm32f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/syscalls.o: ../Src/syscalls.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit11_2nd_Term_Project/Smart_Parking/HAL/INC" -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit11_2nd_Term_Project/Smart_Parking/Stm32f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/syscalls.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/sysmem.o: ../Src/sysmem.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit11_2nd_Term_Project/Smart_Parking/HAL/INC" -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit11_2nd_Term_Project/Smart_Parking/Stm32f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/sysmem.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

