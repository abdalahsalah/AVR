################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/projects/PingPong/app.c \
../APP/projects/PingPong/main.c 

OBJS += \
./APP/projects/PingPong/app.o \
./APP/projects/PingPong/main.o 

C_DEPS += \
./APP/projects/PingPong/app.d \
./APP/projects/PingPong/main.d 


# Each subdirectory must supply rules for building sources it contributes
APP/projects/PingPong/%.o: ../APP/projects/PingPong/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


