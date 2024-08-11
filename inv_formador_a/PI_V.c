// === Equacao a diferen�a do controlador PI Discretizado atrav�s do M�todo de Tustin ===
void PI_V_d(void)
{
	uV_d = (((numzv1*erroV_d)+(numzv2*erroV_d_ant))+uV_d_ant);
	erroV_d_ant = erroV_d;	// Salva erro anterior
	uV_d_ant = uV_d;   		// Salva a��o de controle anterior
}

void PI_V_q(void)
{
	uV_q = (((numzv1*erroV_q)+(numzv2*erroV_q_ant))+uV_q_ant);
	erroV_q_ant = erroV_q;	// Salva erro anterior
	uV_q_ant = uV_q;   		// Salva a��o de controle anterior
}


