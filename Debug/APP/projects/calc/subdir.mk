################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/projects/calc/calc.c \
../APP/projects/calc/main.c 

OBJS += \
./APP/projects/calc/calc.o \
./APP/projects/calc/main.o 

C_DEPS += \
./APP/projects/calc/calc.d \
./APP/projects/calc/main.d 


# Each subdirectory must supply rules for building sources it contributes
APP/projects/calc/%.o: ../APP/projects/calc/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


