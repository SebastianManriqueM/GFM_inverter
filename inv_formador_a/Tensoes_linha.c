// Tensões de linha
void Tensoes_linha(void)
{
Vcfab = Vcfa - Vcfb;
Vcfbc = Vcfb - Vcfc;
Vcfca = Vcfc - Vcfa;

Vcfalfa_linha = 0.81649658*(Vcfab - 0.5*Vcfbc - 0.5*Vcfca);
Vcfbeta_linha = 0.70710678*(Vcfbc - Vcfca);
Vcfzero_linha = 0.57735026*(Vcfab + Vcfbc + Vcfca);
}
