
void abre_chaves(void)
{
	EPwm1Regs.CMPA.half.CMPA = 3750;
 	EPwm1Regs.CMPB = 0;
 	EPwm2Regs.CMPA.half.CMPA = 3750;
 	EPwm2Regs.CMPB = 0;
 	EPwm3Regs.CMPA.half.CMPA = 3750;
 	EPwm3Regs.CMPB = 0;
}
