
void Modelo_turbina(void)
{
	if(Vvento == 0){
		Vvento = 1;
	}
		if(Vvento >= 12.5){
			Vvento = 12.5;
		}
		EndVento = (Vvento-1)*10;
		lambda=Wm*Rt*TabVento[EndVento];
			if(lambda<=0){
				lambda=0.01;
			}

//-------------------------------- Turbina 1kW -----------------------------------------------------------
//	y = 1/(lambda-0.02*beta) - 0.003/(powf(beta,3) + 1);
/*	y = 1/(lambda) + 0.003;
	lambda_i = 1/y;
	Cp = 0.37*(141*y - 13.2)*expf(-19.5*y) + 0.003*lambda;
	Pm = 0.5*Cp*ro*pi*Rt*Rt*Vvento*Vvento*Vvento;
	Tm = 0.5*Cp*ro*pi*Rt*Rt*Rt*Vvento*Vvento/lambda;*/
//--------------------------------------------------------------------------------------------------------

////-------------------------------- Turbina 6kW -----------------------------------------------------------
//	y = 1/(lambda-0.02*beta) + 0.003/(powf(beta,3) + 1);
	y = 1/(lambda) + 0.0035;
	lambda_i = 1/y;
	Cp = 0.63*(125/lambda_i - 0.58*beta -0.02*powf(beta,2.14) - 13.2)*expf(-19/lambda_i) + 0.0025*lambda;
	Pm = 0.5*Cp*ro*pi*Rt*Rt*Vvento*Vvento*Vvento;
	Tm = 0.5*Cp*ro*pi*Rt*Rt*Rt*Vvento*Vvento/lambda;
////--------------------------------------------------------------------------------------------------------
}

void Modelo_acoplamento(void)
{
//--------------------------------------------------------------------------------------------------------
	 /*if (Vvento<=6)
	    Jtg_i=0.03;
	else
	    Jtg_i=0.0917;
	    */


    M = Jtg_i*(Tm-Te-B*Wm);//
	Wm = ((IntegradorNum*M)+(IntegradorNum*M_ant)-(IntegradorDen*Wm_ant));

	if (Wm<0) Wm=0;

	Wm_ant = Wm;
	M_ant = M;
//--------------------------------------------------------------------------------------------------------
	We = Wm*0.5*P;
	Teta_e = ((IntegradorNum*We)+(IntegradorNum*We_ant)-(IntegradorDen*Teta_e_ant));

// Saturador para o Teta_e
	if (Teta_e >= 2*pi){
		Teta_e = 0;
	}

	EndSeno_g=Teta_e*95.33381091;
	EndCosseno_g=EndSeno_g+150;
	if(EndCosseno_g>599){
		EndCosseno_g=EndCosseno_g-600;
	}

	Senoteta_e = Tab_Seno[EndSeno_g];
	Cossenoteta_e = Tab_Seno[EndCosseno_g];

	//	Senoteta_e = -sin(Teta_e);
	//	Cossenoalfa = -cos(Teta_e);
	We_ant = We;
	Teta_e_ant = Teta_e;

//--------------------------------------------------------------------------------------------------------
}

void Modelo_GSIP(void)
{


//--------------------------------------------------------------------------------------------------------
	Vgq_ref = fluxo*We - We*iLd*Ld - iLq*Rs - diLq*Lq;//diLq*Lq
//--------------------------------------------------------------------------------------------------------
	Vgd_ref = We*iLq*Lq - iLd*Rs - diLd*Ld;//diLd*Ld
//--------------------------------------------------------------------------------------------------------
	Pe = Vcfd*iLd + Vcfq*iLq;
	Te = 0.5*P*iLq*fluxo;
//--------------------------------------------------------------------------------------------------------



	//Modificado sampaio. Valores filtrados
/*
	//--------------------------------------------------------------------------------------------------------
	    Vgq_ref = fluxo*We - We*iLd_filtrado*Ld - iLq_filtrado*Rs - diLq*Lq;//diLq*Lq
	//--------------------------------------------------------------------------------------------------------
	    Vgd_ref = We*iLq_filtrado*Lq - iLd_filtrado*Rs - diLd*Ld;//diLd*Ld
	//--------------------------------------------------------------------------------------------------------
	    Pe = Vcfd_filtrado*iLd_filtrado + Vcfq_filtrado*iLq_filtrado;
	    Te = 0.5*P*iLq_filtrado*fluxo;
	//--------------------------------------------------------------------------------------------------------
	 *
	 */

/*
    //Modificado sampaio. Valores filtrados

        //--------------------------------------------------------------------------------------------------------
            Vgq_ref = fluxo*We - We*iLd_filtrado*Ld - iLq_filtrado*Rs - diLq*Lq;//diLq*Lq
        //--------------------------------------------------------------------------------------------------------
            Vgd_ref = We*iLq_filtrado*Lq - iLd_filtrado*Rs - diLd*Ld;//diLd*Ld
        //--------------------------------------------------------------------------------------------------------
            Pe = Vcfd*iLd_filtrado + Vcfq*iLq_filtrado;
            Te = 0.5*P*iLq_filtrado*fluxo;
        //--------------------------------------------------------------------------------------------------------
*/
}
