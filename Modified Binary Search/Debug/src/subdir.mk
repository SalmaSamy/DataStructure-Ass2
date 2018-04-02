################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Modified\ Binary\ Search.cpp 

OBJS += \
./src/Modified\ Binary\ Search.o 

CPP_DEPS += \
./src/Modified\ Binary\ Search.d 


# Each subdirectory must supply rules for building sources it contributes
src/Modified\ Binary\ Search.o: ../src/Modified\ Binary\ Search.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Modified Binary Search.d" -MT"src/Modified\ Binary\ Search.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


