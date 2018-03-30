################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/FileIO.cpp \
../src/Footer.cpp \
../src/Header.cpp \
../src/WAV_to_Bin.cpp 

OBJS += \
./src/FileIO.o \
./src/Footer.o \
./src/Header.o \
./src/WAV_to_Bin.o 

CPP_DEPS += \
./src/FileIO.d \
./src/Footer.d \
./src/Header.d \
./src/WAV_to_Bin.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


