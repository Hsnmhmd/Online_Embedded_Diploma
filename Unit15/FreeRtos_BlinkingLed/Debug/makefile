################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Stm32f103c6_Drivers/subdir.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include Free_RTOS/portable/MemMang/subdir.mk
-include Free_RTOS/portable/GCC/ARM_CM3/subdir.mk
-include Free_RTOS/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
FreeRtos_BlinkingLed.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
FreeRtos_BlinkingLed.list \

OBJCOPY_BIN += \
FreeRtos_BlinkingLed.bin \


# All Target
all: FreeRtos_BlinkingLed.elf secondary-outputs

# Tool invocations
FreeRtos_BlinkingLed.elf: $(OBJS) $(USER_OBJS) D:\Online_Emb_Diploma\GitHub\Online_Embedded_Diploma\Unit15\FreeRtos_BlinkingLed\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "FreeRtos_BlinkingLed.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\Online_Emb_Diploma\GitHub\Online_Embedded_Diploma\Unit15\FreeRtos_BlinkingLed\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="FreeRtos_BlinkingLed.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

FreeRtos_BlinkingLed.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "FreeRtos_BlinkingLed.list"
	@echo 'Finished building: $@'
	@echo ' '

FreeRtos_BlinkingLed.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "FreeRtos_BlinkingLed.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
