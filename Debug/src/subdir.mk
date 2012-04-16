################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/FontManager.cpp \
../src/GameMap.cpp \
../src/Label.cpp \
../src/LocationMap.cpp \
../src/Manager.cpp \
../src/Settings.cpp \
../src/Sprite.cpp \
../src/TextureManager.cpp \
../src/Tile.cpp \
../src/capp.cpp \
../src/libwittek.cpp 

OBJS += \
./src/FontManager.o \
./src/GameMap.o \
./src/Label.o \
./src/LocationMap.o \
./src/Manager.o \
./src/Settings.o \
./src/Sprite.o \
./src/TextureManager.o \
./src/Tile.o \
./src/capp.o \
./src/libwittek.o 

CPP_DEPS += \
./src/FontManager.d \
./src/GameMap.d \
./src/Label.d \
./src/LocationMap.d \
./src/Manager.d \
./src/Settings.d \
./src/Sprite.d \
./src/TextureManager.d \
./src/Tile.d \
./src/capp.d \
./src/libwittek.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	/opt/local/bin/g++-mp-4.7 -D__GXX_EXPERIMENTAL_CXX0X__ -I/usr/local/include/SDL2 -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


