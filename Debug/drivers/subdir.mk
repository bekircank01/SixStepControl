################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/fsl_cadc.c \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
../drivers/fsl_enc.c \
../drivers/fsl_ftm.c \
../drivers/fsl_gpio.c \
../drivers/fsl_smc.c \
../drivers/fsl_uart.c \
../drivers/fsl_xbara.c 

C_DEPS += \
./drivers/fsl_cadc.d \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_enc.d \
./drivers/fsl_ftm.d \
./drivers/fsl_gpio.d \
./drivers/fsl_smc.d \
./drivers/fsl_uart.d \
./drivers/fsl_xbara.d 

OBJS += \
./drivers/fsl_cadc.o \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_enc.o \
./drivers/fsl_ftm.o \
./drivers/fsl_gpio.o \
./drivers/fsl_smc.o \
./drivers/fsl_uart.o \
./drivers/fsl_xbara.o 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c drivers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKV42F64VLF16 -DCPU_MKV42F64VLF16_cm4 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSERIAL_PORT_TYPE_SWO=1 -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03\component\lists" -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03\drivers" -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03\component\serial_manager" -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03\utilities" -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03\CMSIS" -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03\device" -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03\board" -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03\component\uart" -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03\component\lists" -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03\drivers" -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03\component\serial_manager" -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03\utilities" -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03\CMSIS" -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03\device" -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03\board" -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03\component\uart" -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-drivers

clean-drivers:
	-$(RM) ./drivers/fsl_cadc.d ./drivers/fsl_cadc.o ./drivers/fsl_clock.d ./drivers/fsl_clock.o ./drivers/fsl_common.d ./drivers/fsl_common.o ./drivers/fsl_enc.d ./drivers/fsl_enc.o ./drivers/fsl_ftm.d ./drivers/fsl_ftm.o ./drivers/fsl_gpio.d ./drivers/fsl_gpio.o ./drivers/fsl_smc.d ./drivers/fsl_smc.o ./drivers/fsl_uart.d ./drivers/fsl_uart.o ./drivers/fsl_xbara.d ./drivers/fsl_xbara.o

.PHONY: clean-drivers

