//FUNÇÕES PASSANDO POR REFERÊNCIA E USANDO ESTRUTURAS

void f_abc_AlfaBeta_X( struct alf_bet_x *output, struct abc_x *input )//invariante em potência
{
    output->alf = 0.81649658 * ( input->a - 0.5*input->b - 0.5*input->c );
    output->bet = 0.70710678 * ( input->b - input->c );
    //Vcfzero = 0.57735026 * ( Vcfa + Vcfb + Vcfc );
}

void f_AlfaBeta_dq_X( struct dq_x *output , struct alf_bet_x *input )
{
    output->d =  input->alf * cos_teta  +  input->bet * sen_teta;
    output->q = -input->alf * sen_teta  +  input->bet * cos_teta;
}

void f_dq_AlfaBeta_X( struct alf_bet_x *output , struct dq_x *input )
{
    output->alf = input->d * cos_teta - input->q * sen_teta;
    output->bet = input->d * sen_teta + input->q * cos_teta;
}

void f_AlfaBeta_abc_X( struct abc_x *output, struct alf_bet_x *input )
{
    output->a = 0.81649658 * ( input->alf );
    output->b = 0.81649658 * ( (-0.5 * input->alf) + ( 0.866025403 * input->bet) );
    output->c = 0.81649658 * ( (-0.5 * input->alf) + (-0.866025403 * input->bet) );
}




//FUNÇÕES COM VARIÁVEIS GLOBAIS
/*void abc_AlfaBeta_Vcf(void) // Vcf (Inversor Trifásico)
{
	Vcfalfa = 0.81649658*(Vcfa - 0.5*Vcfb - 0.5*Vcfc);
    Vcfbeta = 0.70710678*(Vcfb - Vcfc);
    Vcfzero = 0.57735026*(Vcfa + Vcfb + Vcfc);
}

void AlfaBeta_dq_Vcf(void) // Vcf (Inversor Trifásico)
{
//  Vcfd = Vcfalfa*Senoteta_e + Vcfbeta*Cossenoteta_e;
//  Vcfq = -Vcfalfa*Cossenoteta_e + Vcfbeta*Senoteta_e;
    Vcfd = Vcfalfa*Cossenoteta_e + Vcfbeta*Senoteta_e;
    Vcfq = -Vcfalfa*Senoteta_e + Vcfbeta*Cossenoteta_e;

}

void abc_AlfaBeta_iLf(void) // iLf (Inversor Trifásico)
{
	iLfalfa = 0.81649658*(iLfa - 0.5*iLfb - 0.5*iLfc);
	iLfbeta = 0.70710678*(iLfb - iLfc);
}

void AlfaBeta_dq_iLf(void) // iLf (Inversor Trifásico)
{
//	iLfd = iLfalfa*Senoteta_e + iLfbeta*Cossenoteta_e;
//	iLfq = -iLfalfa*Cossenoteta_e + iLfbeta*Senoteta_e;
	iLfd = iLfalfa*Cossenoteta_e + iLfbeta*Senoteta_e;
	iLfq = -iLfalfa*Senoteta_e + iLfbeta*Cossenoteta_e;
}

void dq_AlfaBeta_aci(void)	// Ação de controle (Inversor Trifásico)
{
//	aci_alfa = aci_d*Senoteta_e - aci_q*Cossenoteta_e;
//	aci_beta = aci_d*Cossenoteta_e + aci_q*Senoteta_e;
	aci_alfa = aci_d*Cossenoteta_e - aci_q*Senoteta_e;
	aci_beta = aci_d*Senoteta_e + aci_q*Cossenoteta_e;
}

void AlfaBeta_abc_aci(void) // Ação de controle (Inversor Trifásico)
{
	aci_a = 1875 + (0.81649658*(aci_alfa));
	aci_b = 1875 + (0.81649658*((-0.5*aci_alfa)+(0.8660254*aci_beta)));
	aci_c = 1875 + (0.81649658*((-0.5*aci_alfa)+(-0.8660254*aci_beta)));
}

void abc_AlfaBeta_iL(void) // iL (Corrente da Carga)
{
	iLalfa = 0.81649658*(iLa - 0.5*iLb - 0.5*iLc);
	iLbeta = 0.70710678*(iLb - iLc);
}

void AlfaBeta_dq_iL(void) // iL (Corrente da Carga)
{
//	iLd = iLalfa*Senoteta_e + iLbeta*Cossenoteta_e;
//	iLq = -iLalfa*Cossenoteta_e + iLbeta*Senoteta_e;
	iLd = iLalfa*Cossenoteta_e + iLbeta*Senoteta_e;
	iLq = -iLalfa*Senoteta_e + iLbeta*Cossenoteta_e;
}
*/
