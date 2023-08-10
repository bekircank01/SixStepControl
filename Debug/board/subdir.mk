################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../board/board.c \
../board/clock_config.c \
../board/peripherals.c \
../board/pin_mux.c 

C_DEPS += \
./board/board.d \
./board/clock_config.d \
./board/peripherals.d \
./board/pin_mux.d 

OBJS += \
./board/board.o \
./board/clock_config.o \
./board/peripherals.o \
./board/pin_mux.o 


# Each subdirectory must supply rules for building sources it contributes
board/%.o: ../board/%.c board/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKV42F64VLF16 -DCPU_MKV42F64VLF16_cm4 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSERIAL_PORT_TYPE_SWO=1 -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03\component\lists" -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03\drivers" -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03\component\serial_manager" -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03\utilities" -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03\CMSIS" -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03\device" -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03\board" -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03\component\uart" -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03\component\lists" -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03\drivers" -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03\component\serial_manager" -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03\utilities" -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03\CMSIS" -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03\device" -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03\board" -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03\component\uart" -I"C:\Users\NAIL\Desktop\PMSM_motor_control\PMSM_SixStep_v03" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-board

clean-board:
	-$(RM) ./board/board.d ./board/board.o ./board/clock_config.d ./board/clock_config.o ./board/peripherals.d ./board/peripherals.o ./board/pin_mux.d ./board/pin_mux.o

.PHONY: clean-board

