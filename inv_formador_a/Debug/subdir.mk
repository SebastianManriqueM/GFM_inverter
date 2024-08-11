################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../A_FAPP_FourLegs_AlfaBeta_PLL_TD.c \
C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_Adc.c \
C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_CpuTimers.c \
C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_DefaultIsr.c \
C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_EPwm.c \
C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/source/DSP2833x_GlobalVariableDefs.c \
C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_PieCtrl.c \
C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_PieVect.c \
C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_SysCtrl.c 

ASM_SRCS += \
C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_ADC_cal.asm \
C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_CodeStartBranch.asm \
C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_usDelay.asm 

CMD_SRCS += \
../28335_RAM_lnk.cmd \
C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/cmd/DSP2833x_Headers_nonBIOS.cmd 

ASM_DEPS += \
./DSP2833x_ADC_cal.pp \
./DSP2833x_CodeStartBranch.pp \
./DSP2833x_usDelay.pp 

OBJS += \
./A_FAPP_FourLegs_AlfaBeta_PLL_TD.obj \
./DSP2833x_ADC_cal.obj \
./DSP2833x_Adc.obj \
./DSP2833x_CodeStartBranch.obj \
./DSP2833x_CpuTimers.obj \
./DSP2833x_DefaultIsr.obj \
./DSP2833x_EPwm.obj \
./DSP2833x_GlobalVariableDefs.obj \
./DSP2833x_PieCtrl.obj \
./DSP2833x_PieVect.obj \
./DSP2833x_SysCtrl.obj \
./DSP2833x_usDelay.obj 

C_DEPS += \
./A_FAPP_FourLegs_AlfaBeta_PLL_TD.pp \
./DSP2833x_Adc.pp \
./DSP2833x_CpuTimers.pp \
./DSP2833x_DefaultIsr.pp \
./DSP2833x_EPwm.pp \
./DSP2833x_GlobalVariableDefs.pp \
./DSP2833x_PieCtrl.pp \
./DSP2833x_PieVect.pp \
./DSP2833x_SysCtrl.pp 

OBJS__QTD += \
".\A_FAPP_FourLegs_AlfaBeta_PLL_TD.obj" \
".\DSP2833x_ADC_cal.obj" \
".\DSP2833x_Adc.obj" \
".\DSP2833x_CodeStartBranch.obj" \
".\DSP2833x_CpuTimers.obj" \
".\DSP2833x_DefaultIsr.obj" \
".\DSP2833x_EPwm.obj" \
".\DSP2833x_GlobalVariableDefs.obj" \
".\DSP2833x_PieCtrl.obj" \
".\DSP2833x_PieVect.obj" \
".\DSP2833x_SysCtrl.obj" \
".\DSP2833x_usDelay.obj" 

ASM_DEPS__QTD += \
".\DSP2833x_ADC_cal.pp" \
".\DSP2833x_CodeStartBranch.pp" \
".\DSP2833x_usDelay.pp" 

C_DEPS__QTD += \
".\A_FAPP_FourLegs_AlfaBeta_PLL_TD.pp" \
".\DSP2833x_Adc.pp" \
".\DSP2833x_CpuTimers.pp" \
".\DSP2833x_DefaultIsr.pp" \
".\DSP2833x_EPwm.pp" \
".\DSP2833x_GlobalVariableDefs.pp" \
".\DSP2833x_PieCtrl.pp" \
".\DSP2833x_PieVect.pp" \
".\DSP2833x_SysCtrl.pp" 

C_SRCS_QUOTED += \
"../A_FAPP_FourLegs_AlfaBeta_PLL_TD.c" \
"C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_Adc.c" \
"C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_CpuTimers.c" \
"C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_DefaultIsr.c" \
"C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_EPwm.c" \
"C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/source/DSP2833x_GlobalVariableDefs.c" \
"C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_PieCtrl.c" \
"C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_PieVect.c" \
"C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_SysCtrl.c" 

ASM_SRCS_QUOTED += \
"C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_ADC_cal.asm" \
"C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_CodeStartBranch.asm" \
"C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_usDelay.asm" 


# Each subdirectory must supply rules for building sources it contributes
A_FAPP_FourLegs_AlfaBeta_PLL_TD.obj: ../A_FAPP_FourLegs_AlfaBeta_PLL_TD.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/include" --diag_warning=225 --large_memory_model --unified_memory --float_support=fpu32 --preproc_with_compile --preproc_dependency="A_FAPP_FourLegs_AlfaBeta_PLL_TD.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_ADC_cal.obj: C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_ADC_cal.asm $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/include" --diag_warning=225 --large_memory_model --unified_memory --float_support=fpu32 --preproc_with_compile --preproc_dependency="DSP2833x_ADC_cal.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_Adc.obj: C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_Adc.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/include" --diag_warning=225 --large_memory_model --unified_memory --float_support=fpu32 --preproc_with_compile --preproc_dependency="DSP2833x_Adc.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_CodeStartBranch.obj: C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_CodeStartBranch.asm $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/include" --diag_warning=225 --large_memory_model --unified_memory --float_support=fpu32 --preproc_with_compile --preproc_dependency="DSP2833x_CodeStartBranch.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_CpuTimers.obj: C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_CpuTimers.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/include" --diag_warning=225 --large_memory_model --unified_memory --float_support=fpu32 --preproc_with_compile --preproc_dependency="DSP2833x_CpuTimers.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_DefaultIsr.obj: C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_DefaultIsr.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/include" --diag_warning=225 --large_memory_model --unified_memory --float_support=fpu32 --preproc_with_compile --preproc_dependency="DSP2833x_DefaultIsr.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_EPwm.obj: C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_EPwm.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/include" --diag_warning=225 --large_memory_model --unified_memory --float_support=fpu32 --preproc_with_compile --preproc_dependency="DSP2833x_EPwm.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_GlobalVariableDefs.obj: C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/source/DSP2833x_GlobalVariableDefs.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/include" --diag_warning=225 --large_memory_model --unified_memory --float_support=fpu32 --preproc_with_compile --preproc_dependency="DSP2833x_GlobalVariableDefs.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_PieCtrl.obj: C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_PieCtrl.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/include" --diag_warning=225 --large_memory_model --unified_memory --float_support=fpu32 --preproc_with_compile --preproc_dependency="DSP2833x_PieCtrl.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_PieVect.obj: C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_PieVect.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/include" --diag_warning=225 --large_memory_model --unified_memory --float_support=fpu32 --preproc_with_compile --preproc_dependency="DSP2833x_PieVect.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_SysCtrl.obj: C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_SysCtrl.c $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/include" --diag_warning=225 --large_memory_model --unified_memory --float_support=fpu32 --preproc_with_compile --preproc_dependency="DSP2833x_SysCtrl.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_usDelay.obj: C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_usDelay.asm $(GEN_SRCS) $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/bin/cl2000" --silicon_version=28 -g --include_path="C:/Program Files/Texas Instruments/ccsv4/tools/compiler/c2000/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/include" --diag_warning=225 --large_memory_model --unified_memory --float_support=fpu32 --preproc_with_compile --preproc_dependency="DSP2833x_usDelay.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


