void Saturadores_PI_V(void)
{
// Saturador para o PI de tensão da fase "a"
	aci_a_sat=aci_a;
	if (aci_a>Limite_Sat_max)
	{
		aci_a_sat=Limite_Sat_max;
	}
	if (aci_a<Limite_Sat_min)
	{
		aci_a_sat=Limite_Sat_min;
	}

// Saturador para o PI de tensão da fase "b"
	aci_b_sat=aci_b;
	if (aci_b>Limite_Sat_max)
	{
		aci_b_sat=Limite_Sat_max;
	}
	if (aci_b<Limite_Sat_min)
	{
		aci_b_sat=Limite_Sat_min;
	}

// Saturador para o PI de tensão da fase "c"
	aci_c_sat=aci_c;
	if (aci_c>Limite_Sat_max)
	{
		aci_c_sat=Limite_Sat_max;
	}
	if (aci_c<Limite_Sat_min)
	{
		aci_c_sat=Limite_Sat_min;
	}

}
// =========================================================================

