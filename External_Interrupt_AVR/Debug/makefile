################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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
LSS += \
External_Int.lss \

FLASH_IMAGE += \
External_Int.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: External_Int.elf secondary-outputs

# Tool invocations
External_Int.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,External_Int.map -mmcu=atmega32 -o "External_Int.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

External_Int.lss: External_Int.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S External_Int.elf  >"External_Int.lss"
	@echo 'Finished building: $@'
	@echo ' '

External_Int.hex: External_Int.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex External_Int.elf  "External_Int.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: External_Int.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 External_Int.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) External_Int.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
