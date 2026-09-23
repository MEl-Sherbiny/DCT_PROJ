################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/MTIMER0/TIMER0.c 

OBJS += \
./MCAL/MTIMER0/TIMER0.o 

C_DEPS += \
./MCAL/MTIMER0/TIMER0.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/MTIMER0/%.o: ../MCAL/MTIMER0/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


