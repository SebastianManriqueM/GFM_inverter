################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
../28335_RAM_lnk.cmd \
C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/cmd/DSP2833x_Headers_nonBIOS.cmd 

ASM_SRCS += \
C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_ADC_cal.asm \
C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_CodeStartBranch.asm \
C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_usDelay.asm 

C_SRCS += \
../A_Main_GFinv_b.c \
C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_Adc.c \
C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_CpuTimers.c \
C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_DefaultIsr.c \
../DSP2833x_ECan.c \
C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_EPwm.c \
C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/source/DSP2833x_GlobalVariableDefs.c \
C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_PieCtrl.c \
C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_PieVect.c \
../DSP2833x_Sci.c \
C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_Spi.c \
C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_SysCtrl.c 

C_DEPS += \
./A_Main_GFinv_b.d \
./DSP2833x_Adc.d \
./DSP2833x_CpuTimers.d \
./DSP2833x_DefaultIsr.d \
./DSP2833x_ECan.d \
./DSP2833x_EPwm.d \
./DSP2833x_GlobalVariableDefs.d \
./DSP2833x_PieCtrl.d \
./DSP2833x_PieVect.d \
./DSP2833x_Sci.d \
./DSP2833x_Spi.d \
./DSP2833x_SysCtrl.d 

OBJS += \
./A_Main_GFinv_b.obj \
./DSP2833x_ADC_cal.obj \
./DSP2833x_Adc.obj \
./DSP2833x_CodeStartBranch.obj \
./DSP2833x_CpuTimers.obj \
./DSP2833x_DefaultIsr.obj \
./DSP2833x_ECan.obj \
./DSP2833x_EPwm.obj \
./DSP2833x_GlobalVariableDefs.obj \
./DSP2833x_PieCtrl.obj \
./DSP2833x_PieVect.obj \
./DSP2833x_Sci.obj \
./DSP2833x_Spi.obj \
./DSP2833x_SysCtrl.obj \
./DSP2833x_usDelay.obj 

ASM_DEPS += \
./DSP2833x_ADC_cal.d \
./DSP2833x_CodeStartBranch.d \
./DSP2833x_usDelay.d 

OBJS__QUOTED += \
"A_Main_GFinv_b.obj" \
"DSP2833x_ADC_cal.obj" \
"DSP2833x_Adc.obj" \
"DSP2833x_CodeStartBranch.obj" \
"DSP2833x_CpuTimers.obj" \
"DSP2833x_DefaultIsr.obj" \
"DSP2833x_ECan.obj" \
"DSP2833x_EPwm.obj" \
"DSP2833x_GlobalVariableDefs.obj" \
"DSP2833x_PieCtrl.obj" \
"DSP2833x_PieVect.obj" \
"DSP2833x_Sci.obj" \
"DSP2833x_Spi.obj" \
"DSP2833x_SysCtrl.obj" \
"DSP2833x_usDelay.obj" 

C_DEPS__QUOTED += \
"A_Main_GFinv_b.d" \
"DSP2833x_Adc.d" \
"DSP2833x_CpuTimers.d" \
"DSP2833x_DefaultIsr.d" \
"DSP2833x_ECan.d" \
"DSP2833x_EPwm.d" \
"DSP2833x_GlobalVariableDefs.d" \
"DSP2833x_PieCtrl.d" \
"DSP2833x_PieVect.d" \
"DSP2833x_Sci.d" \
"DSP2833x_Spi.d" \
"DSP2833x_SysCtrl.d" 

ASM_DEPS__QUOTED += \
"DSP2833x_ADC_cal.d" \
"DSP2833x_CodeStartBranch.d" \
"DSP2833x_usDelay.d" 

C_SRCS__QUOTED += \
"../A_Main_GFinv_b.c" \
"C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_Adc.c" \
"C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_CpuTimers.c" \
"C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_DefaultIsr.c" \
"../DSP2833x_ECan.c" \
"C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_EPwm.c" \
"C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/source/DSP2833x_GlobalVariableDefs.c" \
"C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_PieCtrl.c" \
"C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_PieVect.c" \
"../DSP2833x_Sci.c" \
"C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_Spi.c" \
"C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_SysCtrl.c" 

ASM_SRCS__QUOTED += \
"C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_ADC_cal.asm" \
"C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_CodeStartBranch.asm" \
"C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_usDelay.asm" 


