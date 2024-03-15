################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/WEEK2/TASK1/main.c 

OBJS += \
./APP/WEEK2/TASK1/main.o 

C_DEPS += \
./APP/WEEK2/TASK1/main.d 


# Each subdirectory must supply rules for building sources it contributes
APP/WEEK2/TASK1/%.o: ../APP/WEEK2/TASK1/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


