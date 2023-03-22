################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Free_RTOS/portable/MemMang/heap_4.c 

OBJS += \
./Free_RTOS/portable/MemMang/heap_4.o 

C_DEPS += \
./Free_RTOS/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
Free_RTOS/portable/MemMang/heap_4.o: ../Free_RTOS/portable/MemMang/heap_4.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit15/FreeRtos_BlinkingLed/Free_RTOS/include" -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit15/FreeRtos_BlinkingLed/Stm32f103c6_Drivers/inc" -I"D:/Online_Emb_Diploma/GitHub/Online_Embedded_Diploma/Unit15/FreeRtos_BlinkingLed/Free_RTOS/portable/GCC/ARM_CM3" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Free_RTOS/portable/MemMang/heap_4.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

