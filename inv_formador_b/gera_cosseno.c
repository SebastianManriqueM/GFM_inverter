void gera_cosseno (void)
{

	Wteste = freq_teste*2*pi;

	Teta = ((IntegradorNum*Wteste)+(IntegradorNum*Wteste_ant)-(IntegradorDen*Teta_ant));

	// Saturador para o Teta_e
	if (Teta >= 2*pi){
		Teta = 0;
	}

	EndSeno=Teta*95.33381091;
	EndCosseno=EndSeno+150;
	if(EndCosseno>599){
		EndCosseno=EndCosseno-600;
	}
	Seno_a = Tab_Seno[EndSeno];
	Cosseno_a = Tab_Seno[EndCosseno];

	EndCosseno_b = EndCosseno+400;
	if(EndCosseno_b>599){
		EndCosseno_b=EndCosseno_b-600;
	}
	Cosseno_b = Tab_Seno[EndCosseno_b];

	EndCosseno_c = EndCosseno+200;
	if(EndCosseno_c>599){
		EndCosseno_c=EndCosseno_c-600;
	}
	Cosseno_c = Tab_Seno[EndCosseno_c];

//	Cossenoteta = -cos(Teta);

	Wteste_ant = Wteste;
	Teta_ant = Teta;
//	freq_teste1 = freq_teste*4096*0.008333333;
}    
