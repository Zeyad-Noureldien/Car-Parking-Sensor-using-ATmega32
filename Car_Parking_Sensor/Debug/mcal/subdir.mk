################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../mcal/gpio.c \
../mcal/icu.c 

OBJS += \
./mcal/gpio.o \
./mcal/icu.o 

C_DEPS += \
./mcal/gpio.d \
./mcal/icu.d 


# Each subdirectory must supply rules for building sources it contributes
mcal/%.o: ../mcal/%.c mcal/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


