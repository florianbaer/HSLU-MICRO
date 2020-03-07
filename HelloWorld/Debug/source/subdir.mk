################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/HelloWorld.c \
../source/semihost_hardfault.c 

OBJS += \
./source/HelloWorld.o \
./source/semihost_hardfault.o 

C_DEPS += \
./source/HelloWorld.d \
./source/semihost_hardfault.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=c11 -D__REDLIB__ -DCPU_MK22FN512VLL12 -DCPU_MK22FN512VLL12_cm4 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"/home/hslu/MCUXpresso_workspace/HelloWorld/board" -I"/home/hslu/MCUXpresso_workspace/HelloWorld/source" -I"/home/hslu/MCUXpresso_workspace/HelloWorld" -I"/home/hslu/MCUXpresso_workspace/HelloWorld/device" -I"/home/hslu/MCUXpresso_workspace/HelloWorld/CMSIS" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


