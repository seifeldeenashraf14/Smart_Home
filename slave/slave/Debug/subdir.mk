################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MDIO_program.c \
../MGIE_program.c \
../MTIMER_program.c \
../SPI_program.c \
../STPM_prg.c \
../main.c 

OBJS += \
./MDIO_program.o \
./MGIE_program.o \
./MTIMER_program.o \
./SPI_program.o \
./STPM_prg.o \
./main.o 

C_DEPS += \
./MDIO_program.d \
./MGIE_program.d \
./MTIMER_program.d \
./SPI_program.d \
./STPM_prg.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


