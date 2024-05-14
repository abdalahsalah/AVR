################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/USART/subdir.mk
-include MCAL/TIMERS/subdir.mk
-include MCAL/SPI/subdir.mk
-include MCAL/PORT/subdir.mk
-include MCAL/I2C/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include Hall/SWITCH/subdir.mk
-include Hall/LED/subdir.mk
-include Hall/KAYPAD/subdir.mk
-include Hall/DAC/subdir.mk
-include Hall/CLCD/subdir.mk
-include Hall/7_SEGMENT/subdir.mk
-include APP/projects/calc/subdir.mk
-include APP/projects/PingPong/subdir.mk
-include APP/WEEK2/TASK2/subdir.mk
-include APP/WEEK2/TASK1/subdir.mk
-include APP/WEEK1/snake/subdir.mk
-include APP/WEEK1/led/subdir.mk
-include APP/WEEK1/TEST/subdir.mk
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
cots.lss \

FLASH_IMAGE += \
cots.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: cots.elf secondary-outputs

# Tool invocations
cots.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,cots.map -mmcu=atmega32 -o "cots.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

cots.lss: cots.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S cots.elf  >"cots.lss"
	@echo 'Finished building: $@'
	@echo ' '

cots.hex: cots.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex cots.elf  "cots.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: cots.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 cots.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) cots.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
