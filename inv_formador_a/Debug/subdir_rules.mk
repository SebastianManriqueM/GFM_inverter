################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
A_Main_GFinv.obj: ../A_Main_GFinv.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/include" -g --diag_warning=225 --preproc_with_compile --preproc_dependency="A_Main_GFinv.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_ADC_cal.obj: C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_ADC_cal.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/include" -g --diag_warning=225 --preproc_with_compile --preproc_dependency="DSP2833x_ADC_cal.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_Adc.obj: C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_Adc.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/include" -g --diag_warning=225 --preproc_with_compile --preproc_dependency="DSP2833x_Adc.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_CodeStartBranch.obj: C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_CodeStartBranch.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/include" -g --diag_warning=225 --preproc_with_compile --preproc_dependency="DSP2833x_CodeStartBranch.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_CpuTimers.obj: C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_CpuTimers.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/include" -g --diag_warning=225 --preproc_with_compile --preproc_dependency="DSP2833x_CpuTimers.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_DefaultIsr.obj: C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_DefaultIsr.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/include" -g --diag_warning=225 --preproc_with_compile --preproc_dependency="DSP2833x_DefaultIsr.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_ECan.obj: ../DSP2833x_ECan.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/include" -g --diag_warning=225 --preproc_with_compile --preproc_dependency="DSP2833x_ECan.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_EPwm.obj: C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_EPwm.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/include" -g --diag_warning=225 --preproc_with_compile --preproc_dependency="DSP2833x_EPwm.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_GlobalVariableDefs.obj: C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/source/DSP2833x_GlobalVariableDefs.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/include" -g --diag_warning=225 --preproc_with_compile --preproc_dependency="DSP2833x_GlobalVariableDefs.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_PieCtrl.obj: C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_PieCtrl.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/include" -g --diag_warning=225 --preproc_with_compile --preproc_dependency="DSP2833x_PieCtrl.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_PieVect.obj: C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_PieVect.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/include" -g --diag_warning=225 --preproc_with_compile --preproc_dependency="DSP2833x_PieVect.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_Sci.obj: ../DSP2833x_Sci.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/include" -g --diag_warning=225 --preproc_with_compile --preproc_dependency="DSP2833x_Sci.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_Spi.obj: C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_Spi.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/include" -g --diag_warning=225 --preproc_with_compile --preproc_dependency="DSP2833x_Spi.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_SysCtrl.obj: C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_SysCtrl.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/include" -g --diag_warning=225 --preproc_with_compile --preproc_dependency="DSP2833x_SysCtrl.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_usDelay.obj: C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/source/DSP2833x_usDelay.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.3.LTS/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_common/include" --include_path="C:/tidcs/c28/DSP2833x/v131/DSP2833x_headers/include" -g --diag_warning=225 --preproc_with_compile --preproc_dependency="DSP2833x_usDelay.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


