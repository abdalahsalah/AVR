################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Hall/7_SEGMENT/_7SEGMENT_program.c 

OBJS += \
./Hall/7_SEGMENT/_7SEGMENT_program.o 

C_DEPS += \
./Hall/7_SEGMENT/_7SEGMENT_program.d 


# Each subdirectory must supply rules for building sources it contributes
Hall/7_SEGMENT/%.o: ../Hall/7_SEGMENT/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


