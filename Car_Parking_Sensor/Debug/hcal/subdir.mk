################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hcal/buzzer.c \
../hcal/lcd.c \
../hcal/led.c \
../hcal/ultrasonic_sensor.c 

OBJS += \
./hcal/buzzer.o \
./hcal/lcd.o \
./hcal/led.o \
./hcal/ultrasonic_sensor.o 

C_DEPS += \
./hcal/buzzer.d \
./hcal/lcd.d \
./hcal/led.d \
./hcal/ultrasonic_sensor.d 


# Each subdirectory must supply rules for building sources it contributes
hcal/%.o: ../hcal/%.c hcal/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


