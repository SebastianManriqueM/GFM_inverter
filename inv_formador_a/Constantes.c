//Constantes globais - Frequência de Amostragem 60kHz
#define pi (float32) (3.14159265)

//Constantes do Integrador
#define IntegradorNum (float32) (0.0000125)// Ta = 40kHz
#define IntegradorDen (float32) (-1)


// PWM
#define TIMER_TBPRD  3750//4166       // Period register TIMER_TBPRD = SYSCLK / 2*FREQUENCIA DE CHAVEAMENTO  (EPWMCLK = SYSCLK)
#define TIMER_TBPRD_DIV2  1875  // Period register div 2 TIMER_TBPRD_DIV2 = TIMER_TBPRD / 2
#define TIMER_TBPHS  2500       // Defasagem do PWM 2*TIMER_TBPR/3
#define DB_VLR 400            // Valor atribuido ao tempo morto



// Limites do saturador para o PI de corrente
#define Limite_Sat_max (float32) (4166)//CUIDADO IGUAL TBPRD!!!
#define Limite_Sat_min (float32) (0)

// Ganhos P e PI da malha de controle do Inversor Trifásico
//#define numzv1 (float32) (0.217837733120141)// barramento de 311V
//#define numzv2 (float32) (-0.216432521091765)
//#define KPii (float32) (252.6166886208783)

//#define numzv1 (float32) (0.378137131515023)// Barramento 450 1kW
//#define numzv2 (float32) (-0.372975975301808)//
//#define KPii (float32) (98.179049830992966)

