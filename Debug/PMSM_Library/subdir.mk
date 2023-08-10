################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../PMSM_Library/PMSM_motor_lib.c \
../PMSM_Library/PMSM_pid_lib.c \
../PMSM_Library/PMSM_uart_lib.c 

C_DEPS += \
./PMSM_Library/PMSM_motor_lib.d \
./PMSM_Library/PMSM_pid_lib.d \
./PMSM_Library/PMSM_uart_lib.d 

OBJS += \
./PMSM_Library/PMSM_motor_lib.o \
./PMSM_Library/PMSM_pid_lib.o \
./PMSM_Library/PMSM_uart_lib.o 


# Each subdirectory must supply rules for building sources it contributes
PMSM_Library/%.o: ../PMSM_Library/%.c PMSM_Library/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKV42F64VLF16 -DCPU_MKV42F64VLF16_cm4 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DSERIAL_PORT_TYPE_SWO=1 -I"C:\bitirme\yeni\MKV42F16_Project_23_May_Code\MKV42F16_Project_23_May_Code\component\lists" -I"C:\bitirme\yeni\MKV42F16_Project_23_May_Code\MKV42F16_Project_23_May_Code\drivers" -I"C:\bitirme\yeni\MKV42F16_Project_23_May_Code\MKV42F16_Project_23_May_Code\component\serial_manager" -I"C:\bitirme\yeni\MKV42F16_Project_23_May_Code\MKV42F16_Project_23_May_Code\utilities" -I"C:\bitirme\yeni\MKV42F16_Project_23_May_Code\MKV42F16_Project_23_May_Code\CMSIS" -I"C:\bitirme\yeni\MKV42F16_Project_23_May_Code\MKV42F16_Project_23_May_Code\device" -I"C:\bitirme\yeni\MKV42F16_Project_23_May_Code\MKV42F16_Project_23_May_Code\board" -I"C:\bitirme\yeni\MKV42F16_Project_23_May_Code\MKV42F16_Project_23_May_Code\component\uart" -I"C:\bitirme\yeni\MKV42F16_Project_23_May_Code\MKV42F16_Project_23_May_Code\component\lists" -I"C:\bitirme\yeni\MKV42F16_Project_23_May_Code\MKV42F16_Project_23_May_Code\drivers" -I"C:\bitirme\yeni\MKV42F16_Project_23_May_Code\MKV42F16_Project_23_May_Code\component\serial_manager" -I"C:\bitirme\yeni\MKV42F16_Project_23_May_Code\MKV42F16_Project_23_May_Code\utilities" -I"C:\bitirme\yeni\MKV42F16_Project_23_May_Code\MKV42F16_Project_23_May_Code\CMSIS" -I"C:\bitirme\yeni\MKV42F16_Project_23_May_Code\MKV42F16_Project_23_May_Code\device" -I"C:\bitirme\yeni\MKV42F16_Project_23_May_Code\MKV42F16_Project_23_May_Code\board" -I"C:\bitirme\yeni\MKV42F16_Project_23_May_Code\MKV42F16_Project_23_May_Code\component\uart" -I"C:\bitirme\yeni\MKV42F16_Project_23_May_Code\MKV42F16_Project_23_May_Code" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-PMSM_Library

clean-PMSM_Library:
	-$(RM) ./PMSM_Library/PMSM_motor_lib.d ./PMSM_Library/PMSM_motor_lib.o ./PMSM_Library/PMSM_pid_lib.d ./PMSM_Library/PMSM_pid_lib.o ./PMSM_Library/PMSM_uart_lib.d ./PMSM_Library/PMSM_uart_lib.o

.PHONY: clean-PMSM_Library

