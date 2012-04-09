################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/GameMap.cpp \
../src/LocationMap.cpp \
../src/Settings.cpp \
../src/Sprite.cpp \
../src/Tile.cpp \
../src/capp.cpp \
../src/libwittek.cpp 

OBJS += \
./src/GameMap.o \
./src/LocationMap.o \
./src/Settings.o \
./src/Sprite.o \
./src/Tile.o \
./src/capp.o \
./src/libwittek.o 

CPP_DEPS += \
./src/GameMap.d \
./src/LocationMap.d \
./src/Settings.d \
./src/Sprite.d \
./src/Tile.d \
./src/capp.d \
./src/libwittek.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	/opt/local/bin/g++-mp-4.7 -D__GXX_EXPERIMENTAL_CXX0X__ -I/Users/max/Downloads/SDL-2.0.0-6302/include -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


