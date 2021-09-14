################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
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
LAB1_TOGGLE_BLUEBILL_STM32F103.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
LAB1_TOGGLE_BLUEBILL_STM32F103.list \

OBJCOPY_BIN += \
LAB1_TOGGLE_BLUEBILL_STM32F103.bin \


# All Target
all: LAB1_TOGGLE_BLUEBILL_STM32F103.elf secondary-outputs

# Tool invocations
LAB1_TOGGLE_BLUEBILL_STM32F103.elf: $(OBJS) $(USER_OBJS) D:\Online_Emb_Diploma\GitHub\Online_Embedded_Diploma\Unit7\Lesson1\LAB1_TOGGLE_BLUEBILL_STM32F103\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -gdwarf-2 -o "LAB1_TOGGLE_BLUEBILL_STM32F103.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\Online_Emb_Diploma\GitHub\Online_Embedded_Diploma\Unit7\Lesson1\LAB1_TOGGLE_BLUEBILL_STM32F103\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="LAB1_TOGGLE_BLUEBILL_STM32F103.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

LAB1_TOGGLE_BLUEBILL_STM32F103.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "LAB1_TOGGLE_BLUEBILL_STM32F103.list"
	@echo 'Finished building: $@'
	@echo ' '

LAB1_TOGGLE_BLUEBILL_STM32F103.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "LAB1_TOGGLE_BLUEBILL_STM32F103.bin"
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
