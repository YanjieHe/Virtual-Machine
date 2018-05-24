################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/byte_code.c \
../src/executable.c \
../src/main.c \
../src/structs.c \
../src/vm.c 

OBJS += \
./src/byte_code.o \
./src/executable.o \
./src/main.o \
./src/structs.o \
./src/vm.o 

C_DEPS += \
./src/byte_code.d \
./src/executable.d \
./src/main.d \
./src/structs.d \
./src/vm.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


