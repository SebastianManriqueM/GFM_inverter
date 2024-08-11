// Filtro Passa-Baixa da corrente de carga no eixo d (iLd)
//void FPB_iLd(void)
//{
//	fpb_iLd_in=iLd;
//
//	fpb_iLd_out=(numzfpb1*fpb_iLd_in)+(numzfpb1*fpb_iLd_in_0)+(denzfpb2*fpb_iLd_out_0);
//
//	fpb_iLd_in_0=fpb_iLd_in;
//	fpb_iLd_out_0=fpb_iLd_out;
//	iLd_dc=fpb_iLd_out;
//}

// Filtro Passa-Baixa da tensão de saída Vcfd
void FPB_Vcfd(void)
{
	Vcfd_filtrado=(numzfpb1*Vcfd)+(numzfpb1*Vcfd_ant)+(denzfpb2*Vcfd_filtrado_ant);
	Vcfd_ant = Vcfd;
	Vcfd_filtrado_ant = Vcfd_filtrado;
}

// Filtro Passa-Baixa do Barramento de Tensão
void FPB_Vcc(void)
{
	fpb_dcin=Vcc;

	fpb_dcout=(FILTROdc_A*fpb_dcin)+(FILTROdc_A*fpb_dcin_ant)+(FILTROdc_B*fpb_dcout_ant);

	fpb_dcin_ant=fpb_dcin;
	fpb_dcout_ant=fpb_dcout;
	Vcc_Filtrado=fpb_dcout;
}

void FPB_iLd_samp(void)
{
    //fpboutVdc[i]=(FILTRO_Num0*fpbinVdc[i])+(FILTRO_Num1*fpbinVdc[0])-(FILTRO_Den1*fpboutVdc[0]);

    iLd_filtrado=(FILTRO_Num0*iLd)+(FILTRO_Num1*iLd_ant)-(FILTRO_Den1*iLd_filtrado_ant);
    diLd = (iLd_filtrado - iLd_filtrado_ant)*40000;


    iLd_ant=iLd;
    iLd_filtrado_ant=iLd_filtrado;
}

void FPB_iLq_samp(void)
{
    //fpboutVdc[i]=(FILTRO_Num0*fpbinVdc[i])+(FILTRO_Num1*fpbinVdc[0])-(FILTRO_Den1*fpboutVdc[0]);

    iLq_filtrado=(FILTRO_Num0*iLq)+(FILTRO_Num1*iLq_ant)-(FILTRO_Den1*iLq_filtrado_ant);
    diLq = (iLq_filtrado - iLq_filtrado_ant)*40000;


    iLq_ant=iLq;
    iLq_filtrado_ant=iLq_filtrado;
}

void FPB_Vgd_samp(void)
{
    Vgd_ref_filtrado=(FILTRO_Num0*Vgd_ref)+(FILTRO_Num1*Vgd_ref_ant)-(FILTRO_Den1*Vgd_ref_filtrado_ant);
    Vgd_ref_ant = Vgd_ref;
    Vgd_ref_filtrado_ant = Vgd_ref_filtrado;
}

void FPB_Vgq_samp(void)
{
    Vgq_ref_filtrado=(FILTRO_Num0*Vgq_ref)+(FILTRO_Num1*Vgq_ref_ant)-(FILTRO_Den1*Vgq_ref_filtrado_ant);
    Vgq_ref_ant = Vgq_ref;
    Vgq_ref_filtrado_ant = Vgq_ref_filtrado;
}

void FPB_Vcfd_samp(void)
{
    Vcfd_filtrado=(FILTRO_Num0*Vcfd)+(FILTRO_Num1*Vcfd_ant)-(FILTRO_Den1*Vcfd_filtrado_ant);
    Vcfd_ant = Vcfd;
    Vcfd_filtrado_ant = Vcfd_filtrado;
}

void FPB_Vcfq_samp(void)
{
    Vcfq_filtrado=(FILTRO_Num0*Vcfq)+(FILTRO_Num1*Vcfq_ant)-(FILTRO_Den1*Vcfq_filtrado_ant);
    Vcfq_ant = Vcfq;
    Vcfq_filtrado_ant = Vcfq_filtrado;
}



void F2PB_iLd(void)
{
	iLd_filtrado=F2PB1*iLd + F2PB2*iLd_ant + F2PB3*iLd_ant_2 - F2PBD2*iLd_filtrado_ant - F2PBD3*iLd_filtrado_ant_2;

	iLd_ant_2 = iLd_ant;
	iLd_ant = iLd;
	diLd = (iLd_filtrado - iLd_filtrado_ant)*40000;

	iLd_filtrado_ant_2 = iLd_filtrado_ant;
	iLd_filtrado_ant = iLd_filtrado;


}
void F2PB_iLq(void)
{
	iLq_filtrado=F2PB1*iLq + F2PB2*iLq_ant + F2PB3*iLq_ant_2 - F2PBD2*iLq_filtrado_ant - F2PBD3*iLq_filtrado_ant_2;
	iLq_ant_2 = iLq_ant;
	iLq_ant = iLq;
	diLq = (iLq_filtrado - iLq_filtrado_ant)*40000;
	iLq_filtrado_ant_2 = iLq_filtrado_ant;
	iLq_filtrado_ant = iLq_filtrado;


}
// Filtro Passa-Baixa da tensão de saída Vcfd
void FPB_Pe(void)
{
	Pe_filtrado=(numzfpb1*Pe)+(numzfpb1*Pe_ant)+(denzfpb2*Pe_filtrado_ant);
	Pe_ant = Pe;
	Pe_filtrado_ant = Pe_filtrado;
}
