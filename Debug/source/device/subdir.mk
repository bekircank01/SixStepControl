################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/device/system_MKV42F16.c 

C_DEPS += \
./source/device/system_MKV42F16.d 

OBJS += \
./source/device/system_MKV42F16.o 


# Each subdirectory must supply rules for building sources it contributes
source/device/%.o: ../source/device/%.c source/device/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKV42F64VLF16 -DCPU_MKV42F64VLF16_cm4 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\NAIL\Documents\MCUXpressoIDE_11.6.0_8187\workspace\MKV42F16_Project_deneme_14_october\utilities" -I"C:\Users\NAIL\Documents\MCUXpressoIDE_11.6.0_8187\workspace\MKV42F16_Project_deneme_14_october\drivers" -I"C:\Users\NAIL\Documents\MCUXpressoIDE_11.6.0_8187\workspace\MKV42F16_Project_deneme_14_october\CMSIS" -I"C:\Users\NAIL\Documents\MCUXpressoIDE_11.6.0_8187\workspace\MKV42F16_Project_deneme_14_october\component\serial_manager" -I"C:\Users\NAIL\Documents\MCUXpressoIDE_11.6.0_8187\workspace\MKV42F16_Project_deneme_14_october\component\uart" -I"C:\Users\NAIL\Documents\MCUXpressoIDE_11.6.0_8187\workspace\MKV42F16_Project_deneme_14_october\component\lists" -I"C:\Users\NAIL\Documents\MCUXpressoIDE_11.6.0_8187\workspace\MKV42F16_Project_deneme_14_october\device" -I"C:\Users\NAIL\Documents\MCUXpressoIDE_11.6.0_8187\workspace\MKV42F16_Project_deneme_14_october\board" -I"C:\Users\NAIL\Documents\MCUXpressoIDE_11.6.0_8187\workspace\MKV42F16_Project_deneme_14_october\drivers" -I"C:\Users\NAIL\Documents\MCUXpressoIDE_11.6.0_8187\workspace\MKV42F16_Project_deneme_14_october\CMSIS" -I"C:\Users\NAIL\Documents\MCUXpressoIDE_11.6.0_8187\workspace\MKV42F16_Project_deneme_14_october\board" -I"C:\Users\NAIL\Documents\MCUXpressoIDE_11.6.0_8187\workspace\MKV42F16_Project_deneme_14_october\component\serial_manager" -I"C:\Users\NAIL\Documents\MCUXpressoIDE_11.6.0_8187\workspace\MKV42F16_Project_deneme_14_october\component\lists" -I"C:\Users\NAIL\Documents\MCUXpressoIDE_11.6.0_8187\workspace\MKV42F16_Project_deneme_14_october\component\uart" -I"C:\Users\NAIL\Documents\MCUXpressoIDE_11.6.0_8187\workspace\MKV42F16_Project_deneme_14_october\device" -I"C:\Users\NAIL\Documents\MCUXpressoIDE_11.6.0_8187\workspace\MKV42F16_Project_deneme_14_october\utilities" -I"C:\Users\NAIL\Documents\MCUXpressoIDE_11.6.0_8187\workspace\MKV42F16_Project_deneme_14_october\source" -I"C:\Users\NAIL\Documents\MCUXpressoIDE_11.6.0_8187\workspace\MKV42F16_Project_deneme_14_october" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source-2f-device

clean-source-2f-device:
	-$(RM) ./source/device/system_MKV42F16.d ./source/device/system_MKV42F16.o

.PHONY: clean-source-2f-device

