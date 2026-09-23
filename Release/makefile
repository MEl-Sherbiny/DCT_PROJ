################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/MTIMER2/subdir.mk
-include MCAL/MTIMER0/subdir.mk
-include MCAL/MEXTI/subdir.mk
-include MCAL/MDIO/subdir.mk
-include MCAL/MADC/subdir.mk
-include MCAL/EEPROM/subdir.mk
-include HAL/HLM35/subdir.mk
-include HAL/HLED/subdir.mk
-include APP/subdir.mk
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
DCT_PROJ.lss \

FLASH_IMAGE += \
DCT_PROJ.hex \

EEPROM_IMAGE += \
DCT_PROJ.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: DCT_PROJ.elf secondary-outputs

# Tool invocations
DCT_PROJ.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,DCT_PROJ.map -mmcu=atmega32 -o "DCT_PROJ.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

DCT_PROJ.lss: DCT_PROJ.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S DCT_PROJ.elf  >"DCT_PROJ.lss"
	@echo 'Finished building: $@'
	@echo ' '

DCT_PROJ.hex: DCT_PROJ.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex DCT_PROJ.elf  "DCT_PROJ.hex"
	@echo 'Finished building: $@'
	@echo ' '

DCT_PROJ.eep: DCT_PROJ.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex DCT_PROJ.elf  "DCT_PROJ.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: DCT_PROJ.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 DCT_PROJ.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) DCT_PROJ.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
