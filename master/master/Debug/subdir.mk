################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App.c \
../CLCD_progam.c \
../DC_Motor.c \
../HKEY_PAD_program.c \
../MADC_program.c \
../MDIO_program.c \
../MSPI_program.c \
../main.c 

OBJS += \
./App.o \
./CLCD_progam.o \
./DC_Motor.o \
./HKEY_PAD_program.o \
./MADC_program.o \
./MDIO_program.o \
./MSPI_program.o \
./main.o 

C_DEPS += \
./App.d \
./CLCD_progam.d \
./DC_Motor.d \
./HKEY_PAD_program.d \
./MADC_program.d \
./MDIO_program.d \
./MSPI_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


