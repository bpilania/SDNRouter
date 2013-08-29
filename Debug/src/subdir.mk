################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/flowtable.c \
../src/main_program.c \
../src/simplequeue.c 

OBJS += \
./src/flowtable.o \
./src/main_program.o \
./src/simplequeue.o 

C_DEPS += \
./src/flowtable.d \
./src/main_program.d \
./src/simplequeue.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -pthread -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


