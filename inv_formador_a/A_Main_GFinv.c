//###################################################################################################
//
// FILE:
// 
// TITLE: PROGRAMA DE TESTE, FILTROS, DROOP E CONTROLE PI
//	
// DATA DE ATUALIZAÇÃO: 19/06/2020
//
//	Taxa de amostragem = 40kHz.
//	Frequência de clock = 150MHz.
//
//
//###################################################################################################

#include "DSP28x_Project.h" 
#include "math.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

//================================ Declaração de variáveis ========================================//

//  Declaração de variáveis globais
Uint16 FlagSpiTx=0, sw_spi_signal = 0, ramp_enable = 0, partida = 0, cont_omeg = 0, sync_adc_pwm = 1;
Uint16 ciclos_dyn_test = 48, Ncont_samp = 40, index_dyn_test = 0, cont_samp_dyn_test = 0, flag_dyn_test = 0, flag_dyn_test2 = 0, N_delay_degrau = 66;//4 ciclos a 1kHz
int pos_dyn_test_v = 800, tipo_teste_dyn = 0, tipo_teste_dyn_ant = 0;
float E_dyn_test_v[800], w_dyn_test_v[800], P_dyn_test_v[800], Q_dyn_test_v[800];
float Ts_dsp = 2.5E-5, offset_adc = 2047.5, Ts_omeg = 2.5E-5, max_i=0;
//GERADOR DE REFERÊNCIAS
float teta_inv = 0, cos_teta = 0, sen_teta = 0;
float Cf = 50E-6, Lf = 1.5E-3, omeg_nom = 377, Vcc_nom = 550, I_Vcc_nom = 1.8182E-3;//inverso tensão nominal tensão de barramento
//float Rv = 1.15442910989394, Lv = 0.0122488732859199; //ZnZv0.25 - XvRv4
//float Rv = 0.577214554946972, Lv = 0.00612443664295993; //ZnZv0.5 - XvRv4
//float Rv = 0.288607277473486, Lv = 0.00306221832147997; //ZnZv1 - XvRv4
float Rv = 0.143931189154707, Lv = 0.00152715734793774; //ZnZv2 - XvRv4
//float Rv = 0.0719655945773533, Lv = 0.000763578673968872; //ZnZv4 - XvRv4
//float Rv = 0.0360759096841857, Lv = 0.000382777290184996; //ZnZv8 - XvRv4

//float Rv = 2.12866210029205, Lv = 0.0112929031811285; //ZnZv0.25 - XvRv2
//float Rv = 1.06433105014603, Lv = 0.00564645159056427; //ZnZv0.5 - XvRv2
//float Rv = 0.532165525073014, Lv = 0.00282322579528214; //ZnZv1 - XvRv2
//float Rv = 0.26539599944057, Lv = 0.00140796950625935; //ZnZv2 - XvRv2
//float Rv = 0.132697999720285, Lv = 0.000703984753129677; //ZnZv4 - XvRv2
//float Rv = 0.0665206906341267, Lv = 0.000352903224410267; //ZnZv8 - XvRv2

//Uint16 St_precarga = 0;
//float32 Port=0;
float kff  = 0.5;      //feedforward para cálculo da referência de corrente
Uint16 Counter_Timer =0, Controle_ON =0, Protecao =0, FlagDeConversao=0;//fa=40000
Uint16 Segundos = 0;
Uint16 AdcaResult0=0, AdcaResult1=0, AdcaResult2=0, AdcaResult3=0, AdcaResult4=0, AdcaResult5=0, AdcaResult6=0;
Uint16 AdcbResult2=0, AdcbResult3=0, AdcbResult4=0;

float32 teste =0;
Uint16 K1=0, K2=0, flag_pwm=1, Desliga_sistema = 0;


// Tensão do barramento
float32 Vcc=0, Vcc_teste=0;

// Variáveis para cálculo de seno e cosseno
//Uint16 EndSeno, EndCosseno, EndCosseno_b, EndCosseno_c,EndSeno_g,EndCosseno_g;
//float32 Tab_Seno[600]={0,0.010471775,0.020942402,0.031410731,0.041875616,0.052335909,0.062790463,0.073238131,0.083677768,0.094108228,0.104528369,0.114937047,0.12533312,0.13571545,0.146082897,0.156434324,0.166768597,0.177084581,0.187381146,0.197657163,0.207911505,0.218143046,0.228350666,0.238533245,0.248689666,0.258818815,0.268919582,0.278990859,0.289031542,0.299040529,0.309016723,0.31895903,0.328866359,0.338737625,0.348571744,0.358367639,0.368124234,0.377840461,0.387515253,0.39714755,0.406736295,0.416280438,0.42577893,0.435230731,0.444634804,0.453990118,0.463295647,0.472550371,0.481753274,0.490903348,0.499999588,0.509040998,0.518026586,0.526955367,0.535826361,0.544638596,0.553391106,0.562082929,0.570713115,0.579280715,0.587784791,0.596224409,0.604598645,0.61290658,0.621147303,0.629319911,0.637423506,0.645457201,0.653420114,0.661311373,0.669130112,0.676875473,0.684546607,0.692142673,0.699662838,0.707106277,0.714472174,0.721759721,0.72896812,0.736096578,0.743144316,0.75011056,0.756994546,0.763795519,0.770512733,0.777145453,0.783692949,0.790154505,0.796529412,0.80281697,0.809016491,0.815127294,0.82114871,0.827080077,0.832920746,0.838670076,0.844327436,0.849892207,0.855363777,0.860741548,0.866024928,0.87121334,0.876306213,0.881302989,0.886203121,0.891006071,0.895711312,0.900318328,0.904826615,0.909235677,0.913545032,0.917754206,0.921862739,0.925870179,0.929776087,0.933580034,0.937281605,0.940880392,0.944376001,0.947768049,0.951056164,0.954239984,0.957319162,0.960293359,0.96316225,0.965925519,0.968582863,0.971133992,0.973578625,0.975916494,0.978147344,0.980270928,0.982287015,0.984195384,0.985995825,0.98768814,0.989272144,0.990747664,0.992114537,0.993372614,0.994521756,0.995561838,0.996492746,0.997314378,0.998026642,0.998629463,0.999122772,0.999506516,0.999780654,0.999945155,1,0.999945184,0.999780714,0.999506606,0.999122891,0.998629612,0.998026822,0.997314587,0.996492985,0.995562107,0.994522054,0.993372942,0.992114894,0.990748051,0.989272561,0.987688586,0.9859963,0.984195889,0.98228755,0.980271492,0.978147937,0.975917117,0.973579276,0.971134672,0.968583573,0.965926257,0.963163017,0.960294155,0.957319987,0.954240838,0.951057045,0.947768959,0.94437694,0.940881359,0.9372826,0.933581057,0.929777137,0.925871257,0.921863845,0.91775534,0.913546193,0.909236865,0.90482783,0.90031957,0.895712581,0.891007366,0.886204443,0.881304338,0.876307587,0.87121474,0.866026355,0.860743,0.855365256,0.84989371,0.844328965,0.83867163,0.832922325,0.827081681,0.821150338,0.815128947,0.809018168,0.802818672,0.796531137,0.790156254,0.783694722,0.777147248,0.770514552,0.763797361,0.756996411,0.750112447,0.743146226,0.73609851,0.728970073,0.721761696,0.71447417,0.707108295,0.699664876,0.692144732,0.684548687,0.676877573,0.669132232,0.661313514,0.653422275,0.645459381,0.637425705,0.629322128,0.62114954,0.612908835,0.604600918,0.5962267,0.587787099,0.579283041,0.570715458,0.56208529,0.553393482,0.544640989,0.535828771,0.526957792,0.518029027,0.509043454,0.500002059,0.490905834,0.481755775,0.472552886,0.463298176,0.453992661,0.44463736,0.4352333,0.425781512,0.416283032,0.406738902,0.397150169,0.387517884,0.377843103,0.368126888,0.358370303,0.348574419,0.33874031,0.328869054,0.318961734,0.309019437,0.299043252,0.289034274,0.2789936,0.268922331,0.258821572,0.24869243,0.238536016,0.228353445,0.218145831,0.207914296,0.197659961,0.187383949,0.17708739,0.16677141,0.156437143,0.14608572,0.135718277,0.125335951,0.114939881,0.104531207,0.094111069,0.083680611,0.073240977,0.062793311,0.052338758,0.041878467,0.031413583,0.020945254,0.010474628,0,-0.010468921,-0.020939548,-0.031407878,-0.041872765,-0.052333059,-0.062787615,-0.073235285,-0.083674924,-0.094105387,-0.104525531,-0.114934212,-0.125330289,-0.135712623,-0.146080074,-0.156431506,-0.166765783,-0.177081773,-0.187378343,-0.197654366,-0.207908714,-0.218140262,-0.228347888,-0.238530474,-0.248686902,-0.258816059,-0.268916834,-0.278988119,-0.28902881,-0.299037806,-0.309014009,-0.318956325,-0.328863664,-0.33873494,-0.34856907,-0.358364975,-0.368121581,-0.377837819,-0.387512623,-0.397144931,-0.406733689,-0.416277843,-0.425776348,-0.435228162,-0.444632248,-0.453987576,-0.463293118,-0.472547856,-0.481750773,-0.490900861,-0.499997117,-0.509038542,-0.518024145,-0.526952942,-0.535823952,-0.544636203,-0.553388729,-0.562080569,-0.570710771,-0.579278389,-0.587782482,-0.596222118,-0.604596372,-0.612904325,-0.621145067,-0.629317693,-0.637421307,-0.645455021,-0.653417954,-0.661309232,-0.669127991,-0.676873372,-0.684544527,-0.692140613,-0.699660799,-0.707104259,-0.714470177,-0.721757746,-0.728966166,-0.736094647,-0.743142407,-0.750108673,-0.756992681,-0.763793677,-0.770510915,-0.777143657,-0.783691177,-0.790152756,-0.796527687,-0.802815269,-0.809014814,-0.815125641,-0.821147081,-0.827078473,-0.832919167,-0.838668522,-0.844325907,-0.849890703,-0.855362299,-0.860740095,-0.866023501,-0.871211939,-0.876304838,-0.881301641,-0.886201799,-0.891004775,-0.895710043,-0.900317086,-0.9048254,-0.90923449,-0.913543871,-0.917753073,-0.921861633,-0.9258691,-0.929775036,-0.933579012,-0.93728061,-0.940879425,-0.944375063,-0.947767139,-0.951055282,-0.954239131,-0.957318337,-0.960292563,-0.963161482,-0.96592478,-0.968582153,-0.971133311,-0.973577973,-0.975915872,-0.97814675,-0.980270364,-0.982286481,-0.984194879,-0.985995349,-0.987687693,-0.989271727,-0.990747276,-0.992114179,-0.993372286,-0.994521458,-0.99556157,-0.996492507,-0.997314169,-0.998026463,-0.998629313,-0.999122652,-0.999506427,-0.999780594,-0.999945125,-1,-0.999945214,-0.999780774,-0.999506696,-0.999123011,-0.998629761,-0.998027001,-0.997314796,-0.996493224,-0.995562375,-0.994522353,-0.99337327,-0.992115252,-0.990748438,-0.989272978,-0.987689033,-0.985996776,-0.984196395,-0.982288085,-0.980272056,-0.97814853,-0.975917739,-0.973579928,-0.971135353,-0.968584282,-0.965926996,-0.963163784,-0.960294952,-0.957320812,-0.954241691,-0.951057927,-0.947769869,-0.944377878,-0.940882325,-0.937283594,-0.93358208,-0.929778188,-0.925872335,-0.92186495,-0.917756473,-0.913547353,-0.909238053,-0.904829045,-0.900320812,-0.89571385,-0.891008662,-0.886205765,-0.881305686,-0.876308962,-0.871216141,-0.866027782,-0.860744453,-0.855366734,-0.849895214,-0.844330494,-0.838673184,-0.832923904,-0.827083285,-0.821151967,-0.8151306,-0.809019846,-0.802820373,-0.796532862,-0.790158003,-0.783696494,-0.777149044,-0.770516371,-0.763799203,-0.756998275,-0.750114334,-0.743148135,-0.736100442,-0.728972026,-0.721763671,-0.714476167,-0.707110312,-0.699666915,-0.692146792,-0.684550767,-0.676879674,-0.669134353,-0.661315654,-0.653424435,-0.64546156,-0.637427903,-0.629324346,-0.621151776,-0.61291109,-0.604603191,-0.596228991,-0.587789408,-0.579285367,-0.570717801,-0.56208765,-0.553395859,-0.544643383,-0.53583118,-0.526960218,-0.518031468,-0.509045911,-0.500004531,-0.49090832,-0.481758275,-0.472555401,-0.463300705,-0.453995203,-0.444639916,-0.435235869,-0.425784094,-0.416285627,-0.406741509,-0.397152788,-0.387520514,-0.377845745,-0.368129541,-0.358372967,-0.348577093,-0.338742995,-0.328871749,-0.318964439,-0.309022151,-0.299045975,-0.289037006,-0.27899634,-0.268925079,-0.258824328,-0.248695194,-0.238538788,-0.228356223,-0.218148616,-0.207917087,-0.197662758,-0.187386752,-0.177090198,-0.166774224,-0.156439961,-0.146088543,-0.135721104,-0.125338782,-0.114942716,-0.104534045,-0.09411391,-0.083683455,-0.073243823,-0.062796158,-0.052341608,-0.041881318,-0.031416435,-0.020948107,-0.010477481};
//float32 Teta=0, Teta_ant=0, freq_teste = 60, Wteste=0, Wteste_ant=0, Seno_a=0, Cosseno_a=0, Cosseno_b=0, Cosseno_c=0;

// Variáveis da transformada alfabeta/dq do Modelo do GSIP
//float32 Senoteta_e=0, Cossenoteta_e=0, Senoteta_e_ant=0, Cossenoteta_e_ant=0, We=0, Teta_e=0, We_ant = 0, Teta_e_ant=0;

//  -> Variáveis do PWM (Inversor Trifásico)
int WctrlA = 0, WctrlB = 0, WctrlC = 0;

struct abc_x
{   float a;
    float b;
    float c;        };

struct dq_x
{   float d;
    float q;        };

struct alf_bet_x
{   float alf;
    float bet;      };

struct droop
{   float k;
    float y_nom;
    float y;        };

struct pi_be
{   float kp;
    float ki;
    float y_integral;
    float y_pi;     };

struct pi_tust
{   float b0;
    float b1;
    float s_ant;
    float y_pi;     };

struct mav_eight
{   float buffer[8];
    float y_filt;
    int   i;        };

struct mav_five
{   float buffer[5];
    float y_filt;
    int   i;        };

struct mav_four
{   float buffer[4];
    float y_filt;
    int   i;        };

struct mav_two
{   float buffer[2];
    float y_filt;
    int   i;        };

struct lpf_fo
{   float b01;
    float a1;
    float s_ant;
    float y_lpf;    };

struct saturador
{   float upper_limit;
    float lower_limit;
    float y_sat;    };

Uint16 flag_cal = 0;
float contador_calibra_offset = 0, N_cal_offset=100000, inv_N_cal_offset=0.00001, upper_lim_offset = 2348, lower_lim_offset = 1747;
struct abc_x Vo_offset;
struct abc_x Ilf_offset;
struct abc_x Io_inv_offset;
struct abc_x Vo_gain;
struct abc_x Ilf_gain;
struct abc_x Io_inv_gain;
//Inicialização para ACESSO POR XDS (GLOBAL)
struct abc_x Vo_inv_abc;
struct abc_x Ilf_abc;
struct abc_x Io_inv_abc;
struct abc_x aci_abc;
struct dq_x Io_inv_dq;
struct mav_two Io_inv_d_filt;
struct mav_two Io_inv_q_filt;
struct mav_two omega_filt;
struct dq_x Vo_inv_dq;
struct dq_x Vo_inv_ref_dq;
struct dq_x Vo_err_dq;
struct dq_x Ilf_err_dq;
struct dq_x aci_dq;
struct dq_x Ilf_dq;
struct lpf_fo lpf_Vcc;       //Struct LPF Vcc
struct lpf_fo lpf_fo_Pav;       //Struct LPF Active Power
struct droop droop_P_Omeg;      //Droop P-f
struct lpf_fo lpf_fo_Qav;       //Struct LPF Reactive Power
struct droop droop_Q_E;         //droop Q-E


// Prototype statements for functions found within this file.
interrupt void sciaRxFifoIsr(void);
interrupt void adc_isr( void );
interrupt void epwm1_isr( void );
interrupt void epwm6_isr( void );
void ConfigEpwm( void );
void InitEPwmSyncGpio_user(void);
void Gpio_select( void );
void scia_fifo_init(void);
void f_initial_cond_kx( int *tipo_teste_dyn );
void f_enable_kx_dyn_test( int *tipo_teste_dyn );

#include "init_blocks.c"
#include "f_blocks.c"
#include "Constantes.c"
#include "Abre_chaves.c"

//#include "gera_cosseno.c"

//#include "PI_V.c"
//#include "Saturadores.c"

//#include "Filtro.c"

#include "Transformadas.c"
//#include "Tensoes_linha.c"
//#include "Modelo_EmEE.c"


void main(void)

{
	//###############################################################################################
	//================================== Função Principal do Programa ===============================
	//###############################################################################################
	
	// Initialize System Control:
	// PLL, WatchDog, enable Peripheral Clocks
	// This example function is found in the DSP2833x_SysCtrl.c file.

    EALLOW;
   	#if (CPU_FRQ_150MHZ)     // Default - 150 MHz SYSCLKOUT
    	#define ADC_MODCLK 0x3 // HSPCLK = SYSCLKOUT/2*ADC_MODCLK2 = 150/(2*3)   = 25.0 MHz
   	#endif
   	#if (CPU_FRQ_100MHZ)
    	#define ADC_MODCLK 0x2 // HSPCLK = SYSCLKOUT/2*ADC_MODCLK2 = 100/(2*2)   = 25.0 MHz
   	#endif
   	EDIS;

   	//Inicializações

   	Gpio_select();

    InitSysCtrl();// Inicializa controles do sistema e desabilita watchdog

	InitEPwm1Gpio();//Iniciaçiza pinos do GPIO para o ePWM1
	InitEPwm2Gpio();//Iniciaçiza pinos do GPIO para o ePWM2
	InitEPwm3Gpio();//Iniciaçiza pinos do GPIO para o ePWM3
	if ( sync_adc_pwm == 1 )
	{   InitEPwmSyncGpio_user();}//GPIO INIT PARA SINCRONIZAÇÃO DE TRIANGULARES ENTRE INVERSORES! (Pino 32-SYNCI e 33-SYNCO)

	InitSciGpio();  //Inicializa GPIO28 e 29 para SCI, pull-ups e pino RX assincrono

   	DINT;// Desabilita todas as interrupções

	// Initialize the PIE control registers to their default state.
	// The default state is all PIE interrupts disabled and flags
	// are cleared.  
	// This function is found in the DSP2833x_PieCtrl.c file.
   	InitPieCtrl();//Inicializa registratores de controle do PIE para o estado default
   
	// Disable CPU interrupts and clear all CPU interrupt flags:
   	IER = 0x0000;
   	IFR = 0x0000;

	// Initialize the PIE vector table with pointers to the shell Interrupt 
	// Service Routines (ISR).  
	// This will populate the entire table, even if the interrupt
	// is not used in this example.  This is useful for debug purposes.
	// The shell ISR routines are found in DSP2833x_DefaultIsr.c.
	// This function is found in DSP2833x_PieVect.c.
	InitPieVectTable();

	// Interrupts that are used in this example are re-mapped to
	// ISR functions found within this file.  
	EALLOW;  // This is needed to write to EALLOW protected registers
	PieVectTable.SCIRXINTA = &sciaRxFifoIsr;
	PieVectTable.EPWM1_INT = &epwm1_isr;
	if ( sync_adc_pwm == 1 )
	{   PieVectTable.EPWM6_INT = &epwm6_isr;}
	PieVectTable.ADCINT    = &adc_isr;
	EDIS;    // This is needed to disable write to EALLOW protected registers

	scia_fifo_init();  // Init SCI-A
	InitSpiGpio();      //init SPI - inclui gpio e registradores de configuração



	// This function is found in DSP2833x_InitPeripherals.c
	InitAdc();  // Inicializa o ADC

	//--------- INTERRUPÇÕES ---------
    PieCtrlRegs.PIEIER1.bit.INTx6 = 1;// Enable ADCINT in PIE - p150 - Table 1-112. PIE Vector Table
	IER |= M_INT1; // Enable CPU Interrupt 1 -- PIE -- ADC

	if ( sync_adc_pwm == 1 )
	{   PieCtrlRegs.PIEIER3.bit.INTx6 = 1;// Enable PWMINT in PIE - p150 - Table 1-112. PIE Vector Table
	    IER |= M_INT3; }// Enable CPU Interrupt 3 -- PIE -- ADC

	//    PieCtrlRegs.PIEIER6.bit.INTx1 = 1;// Enable SPIRXINTA in PIE
	//    IER |= M_INT6; // Enable CPU Interrupt 6  -- PIE -- SPI

	PieCtrlRegs.PIEIER9.bit.INTx1=1;// Enable SCIRXINTA in PIE - p152 - Table 1-112. PIE Vector Table
	IER |= M_INT9; // Enable CPU Interrupt 9 -- PIE-- SCI AND CAN


	// ================================= Configura o ADC ============================================
	//P478. Table7-10
	AdcRegs.ADCTRL1.bit.ACQ_PS = 4;          // Acquisition window size. Determines the width of SOC pulse=time duration the sampling switch is closed
	AdcRegs.ADCTRL1.bit.CPS = 1;             // Core clock pre-scaler - 1h = ADCCLK = Fclk/2;  0h = ADCCLK = Fclk/1
	AdcRegs.ADCTRL1.bit.CONT_RUN = 0;        // 0:Start-Stop or continuous sequencer mode

	//P491. Table7-22
	// HSPCLK, is divided by 2*ADCCLKPS[3-0], except when ADCCLKPS[3-0] is 0000, in which case HSPCLK is directly passed on.
	//The divided clock is further divided by ADCTRL1[7]+1 to generate the core clock,
	AdcRegs.ADCTRL3.bit.ADCCLKPS = 3;        // Core clock divider -
	AdcRegs.ADCTRL3.bit.ADCBGRFDN = 0x3;     // Bandgap and reference powered up 00b = The bandgap and reference circuitry is powered down. 11b = The bandgap and RC is powered up.
	AdcRegs.ADCTRL3.bit.SMODE_SEL = 0;       // 1:Simultaneous, 0:Sequential sampling

	//P483. Table7-12
	AdcRegs.ADCREFSEL.bit.REF_SEL = 0 ;      // Set Reference Voltage
	AdcRegs.ADCOFFTRIM.bit.OFFSET_TRIM = 0;  // Set Offset Error Correction Value
    //P478. Table7-10
	AdcRegs.ADCTRL1.bit.SEQ_CASC = 1;        // 0=Dual-seq mode; 1=Cascaded mode. SEQ1 e 2 operate as a single 16 state sequencer

	//P483. Table7-12 (10=11 conversões)
   	 AdcRegs.ADCMAXCONV.all = 10;           //defines the maximum number of conversions executed in an autoconversion session for sequencer 1 (SEQ1

   	AdcRegs.ADCCHSELSEQ1.bit.CONV00 = 0x0; // Setup ADCINA0 Vo_inv_abc.a
   	AdcRegs.ADCCHSELSEQ1.bit.CONV01 = 0x1; // Setup ADCINA1 Vo_inv_abc.b
   	AdcRegs.ADCCHSELSEQ1.bit.CONV02 = 0x2; // Setup ADCINA2 Vo_inv_abc.c

   	AdcRegs.ADCCHSELSEQ1.bit.CONV03 = 0x3; // Setup ADCINA3 Io_inv_abc.a
   	AdcRegs.ADCCHSELSEQ2.bit.CONV04 = 0x4; // Setup ADCINA4 Io_inv_abc.b
   	AdcRegs.ADCCHSELSEQ2.bit.CONV05 = 0x5; // Setup ADCINA5 Io_inv_abc.c

   	AdcRegs.ADCCHSELSEQ3.bit.CONV08 = 0xA; // Setup ADCINB2 Ilf_abc.a
   	AdcRegs.ADCCHSELSEQ3.bit.CONV09 = 0xB; // Setup ADCINB3 Ilf_abc.b
   	AdcRegs.ADCCHSELSEQ3.bit.CONV10 = 0xC; // Setup ADCINB4 Ilf_abc.c


   	AdcRegs.ADCCHSELSEQ2.bit.CONV06 = 0x6; // Setup ADCINA6 Vcc

   	//P481. Table7-11
    AdcRegs.ADCTRL2.bit.EPWM_SOCA_SEQ1 = 1;  // Enable SOCA from ePWM to start SEQ1
//    AdcRegs.ADCTRL2.bit.EPWM_SOCB_SEQ2 = 1;
    AdcRegs.ADCTRL2.bit.INT_ENA_SEQ1 = 1;    // Enable SEQ1 interrupt (every EOS)
//    AdcRegs.ADCTRL2.bit.INT_ENA_SEQ2 = 1;

	// Assumes ePWM1 clock is already enabled in InitSysCtrl();
    //PWM6 É UTILIZADO ARTIFICIALMENTE PARA GERAR A TAXA DE AMOSTRAGEM
    EALLOW;
    SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;
    EDIS;

    EPwm6Regs.TBPHS.half.TBPHS = 0x0000;           // Phase is 0   defasagem = 0
    EPwm6Regs.TBCTR = 0x0000;                      // Clear counter limpa contador
    EPwm6Regs.TBCTL.bit.PHSEN     = TB_DISABLE;     // Disable phase loading
    EPwm6Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;        // Clock ratio to SYSCLKOUT. Determine part of the time-base clock prescale value. TBCLK = SYSCLKOUT / (HSPCLKDIV × CLKDIV)
    EPwm6Regs.TBCTL.bit.CLKDIV    = TB_DIV1;        // Determine part of the time-base clock prescale value. TBCLK = SYSCLKOUT / (HSPCLKDIV × CLKDIV)

    //P320. Table3-44   ---- Foi configurado desta forma para sincronizar amostra nos picos do contador (0 e TBPRD)-menor ruido
    EPwm6Regs.ETSEL.bit.SOCAEN  = 1;       // Enable SOC on A group
    EPwm6Regs.ETSEL.bit.SOCASEL = 2;       // Select SOC from PRD -  1-TBCTR=0x0000; 2-TBCTR=TBPRD; determine when a EPWMxSOCA pulse will be generated.

    if ( sync_adc_pwm == 1 )
    {
        EPwm6Regs.ETSEL.bit.INTEN   = 1;        //Habilita interrupção PWM
        EPwm6Regs.ETSEL.bit.INTSEL  = 2;        //OPÇÃO int PWM: 0=reserved; 1=TBCTR=0;  2TBCTR=TBPRD
        //P322. Table3-45   ---- EVENT TRIGGER PRESCALE REGISTER
        EPwm6Regs.ETPS.bit.INTPRD   = 1;    //Interrupção a cada periodo
        EPwm6Regs.ETCLR.bit.INT     = 1;
        EPwm6Regs.ETPS.bit.INTPRD   = 1;
    }

    EPwm6Regs.ETPS.bit.SOCAPRD  = 1;       // Generate pulse on 1st event
    EPwm6Regs.TBPRD             = TIMER_TBPRD_DIV2;//40ks=1875, 2083=36k          // Set period for ePWM6 TBPRD = (FCLK/2*TAXA AMOSTRAGEM)
    EPwm6Regs.TBCTL.bit.CTRMODE = 2;		  // count up and start
    //Como CTRMODE é dente de serra não TBPRD deveria ser 3750 para somente duplicar taxa, Ou por triangular CTRMODE=2, E SOCASEL=1TBCTR=0x0000
    //Funcionava porque no reset HSPCLKDIV=/2 então divide por dois o clock mas não garante sincronismo dos pwm's
// ====================================================================================================



   	ConfigEpwm();		// Inicializa Epwm1 ao Epwm4

  	// Desliga todos os IGBTs
   	abre_chaves();
   
    EALLOW;
    SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;// Habilita sincronismo dos ePWM
    EDIS;

    //--------- INTERRUPÇÕES ---------
    IER |= M_INT3;// Enable CPU INT3 which is connected to EPWM1-3 INT:
    PieCtrlRegs.PIEIER3.bit.INTx1 = 1;// Enable EPWM INTn in the PIE: Group 3 interrupt 1-3 -p151-Table 1-112. PIE Vector Table

    EINT;   // Enable Global interrupt INTM
    ERTM;   // Enable Global realtime interrupt DBGM

	//===================== Inicializa as Variáveis do Programa Principal ===============================

	
	//GpioDataRegs.GPCCLEAR.bit.GPIO86=1;// Abre K1
    GpioDataRegs.GPCSET.bit.GPIO86=1;// fecha K1
    GpioDataRegs.GPCSET.bit.GPIO84=1;// fecha K2
	DELAY_US(1000000);
//	DELAY_US(1000000);



//____________________________________________________________________________________________________________
	Uint16 flag_sci = 0, address_sci[4]={48,49,50,51};
	Uint16 n_var_tx_sci = 4, count_tx_sci1 = 0, count_tx_sci2 = 0;
	float buffer_tx_sci[4] = {0,0,0,0};

	float p_inst = 0, q_inst = 0;

	//+++++ VARIÁVEIS ABC +++++
    Vo_inv_abc.a = 0;
    Vo_inv_abc.b = 0;
    Vo_inv_abc.c = 0;

    Ilf_abc.a = 0;
    Ilf_abc.b = 0;
    Ilf_abc.c = 0;

    Io_inv_abc.a = 0;
    Io_inv_abc.b = 0;
    Io_inv_abc.c = 0;

    aci_abc.a = 0;
    aci_abc.b = 0;
    aci_abc.c = 0;

    //+++++ VARIÁVEIS Alfa Beta +++++
    struct alf_bet_x Vo_inv_alfbet;
    Vo_inv_alfbet.alf = 0;
    Vo_inv_alfbet.bet = 0;

    struct alf_bet_x Ilf_alfbet;
    Ilf_alfbet.alf = 0;
    Ilf_alfbet.bet = 0;

    struct alf_bet_x Io_inv_alfbet;
    Io_inv_alfbet.alf = 0;
    Io_inv_alfbet.bet = 0;

    struct alf_bet_x aci_alfbet;
    aci_alfbet.alf = 0;
    aci_alfbet.bet = 0;

    //+++++ VARIÁVEIS DQ +++++ (GLOBAIS)
	Vo_inv_dq.d     = 0;
	Vo_inv_dq.q     = 0;

	Vo_inv_ref_dq.d = 0;
	Vo_inv_ref_dq.q = 0;

	Ilf_dq.d        = 0;
	Ilf_dq.q        = 0;

	Io_inv_dq.d     = 0;
	Io_inv_dq.q     = 0;

	Vo_err_dq.d     = 0;
	Vo_err_dq.q     = 0;
	Ilf_err_dq.d    = 0;
	Ilf_err_dq.q    = 0;

	aci_dq.d = 0;
	aci_dq.q = 0;

	//INICIALIZAÇÃO FILTRO VCC
	 f_init_lpf_fo_filt_vbles( &lpf_Vcc, 226 );

	//INICIALIZAÇÃO FILTROS POWER CALC
	f_init_lpf_fo_filt_vbles( &lpf_fo_Pav, 30 );
	f_init_lpf_fo_filt_vbles( &lpf_fo_Qav, 30 );

	// INIT DROOP
	f_init_droop( &droop_P_Omeg, 4E-4, omeg_nom );
	f_init_droop( &droop_Q_E   , 7.5E-3, 0 );     //Declarada global para ter acesso

	//INICIALIZAR CONTROL PI
	//struct pi_be pi_Vd;
	//f_init_pi_controllers_be( &pi_Vd, 10, 3, 0, 0 );//( struct pi_be *pi_ctrl, float kp, float ki, float y_pi, float y_integral )
	/*struct pi_tust pi_Vd;
	struct pi_tust pi_Vq;
	f_init_pi_controllers_tust( &pi_Vd, 0.04, 250, 0, 0 );//( struct pi_tust *pi_ctrl, float kp, float ki, float y_pi, float s_ant )
	f_init_pi_controllers_tust( &pi_Vq, 0.04, 250, 0, 0 );//( struct pi_tust *pi_ctrl, float kp, float ki, float y_pi, float s_ant )
	float kff  = 0.75;     //feedforward para cálculo da referência de corrente

	struct pi_tust pi_Id;
	struct pi_tust pi_Iq;
	f_init_pi_controllers_tust( &pi_Id, 0.03, 40.0, 0, 0 );//( struct pi_tust *pi_ctrl, float kp, float ki, float y_pi, float s_ant )
	f_init_pi_controllers_tust( &pi_Iq, 0.03, 40.0, 0, 0 );//( struct pi_tust *pi_ctrl, float kp, float ki, float y_pi, float s_ant )
*/


	struct pi_be pi_Vd;
	struct pi_be pi_Vq;
	f_init_pi_controllers_be( &pi_Vd, 0.23, 150, 0, 0 );//( struct pi_be *pi_ctrl, float kp, float ki, float y_pi, float y_integral )
	f_init_pi_controllers_be( &pi_Vq, 0.23, 150, 0, 0 );//( struct pi_be *pi_ctrl, float kp, float ki, float y_pi, float y_integral )
    //float kff  = 0.5;      //feedforward para cálculo da referência de corrente

	f_init_mav_two_vbles( &Io_inv_d_filt);//FILTROS IO - PARA FEED FORWARD
	f_init_mav_two_vbles( &Io_inv_q_filt);
	f_init_mav_two_vbles( &omega_filt);

    struct pi_be pi_Id;
    struct pi_be pi_Iq;
    //f_init_pi_controllers_be( &pi_Id, 0.06, 63.0, 0, 0 );//( struct pi_be *pi_ctrl, float kp, float ki, float y_pi, float y_integral )
    //f_init_pi_controllers_be( &pi_Iq, 0.06, 63.0, 0, 0 );//( struct pi_be *pi_ctrl, float kp, float ki, float y_pi, float y_integral )
    f_init_pi_controllers_be( &pi_Id, 0.074, 11.3, 0, 0 );//( struct pi_be *pi_ctrl, float kp, float ki, float y_pi, float y_integral )
    f_init_pi_controllers_be( &pi_Iq, 0.074, 11.3, 0, 0 );//( struct pi_be *pi_ctrl, float kp, float ki, float y_pi, float y_integral )
    //f_init_pi_controllers_be( &pi_Id, 0.065, 62.0, 0, 0 );//( struct pi_be *pi_ctrl, float kp, float ki, float y_pi, float y_integral )
    //f_init_pi_controllers_be( &pi_Iq, 0.065, 62.0, 0, 0 );//( struct pi_be *pi_ctrl, float kp, float ki, float y_pi, float y_integral )

    f_init_v_teste_dyn( E_dyn_test_v, pos_dyn_test_v );
    f_init_v_teste_dyn( w_dyn_test_v, pos_dyn_test_v );
    f_init_v_teste_dyn( P_dyn_test_v, pos_dyn_test_v );
    f_init_v_teste_dyn( Q_dyn_test_v, pos_dyn_test_v );


    GpioDataRegs.GPBCLEAR.bit.GPIO62=1;

    // ==============================================================================================
    //###############################################################################################
    // ================================= ROTINA CALIBRAÇÃO ==========================================
    while( flag_cal == 0 )
    {
        if ( FlagDeConversao == 1 )
        {
            if ( contador_calibra_offset == 0 )
            {
                f_reset_offset_vbles( &Vo_offset );   //void f_reset_offset_vbles( struct abc_x *input ) -ZERA OFFSET PARA COMEÇAR CALIBRAÇÃO
                f_reset_offset_vbles( &Ilf_offset );  //void f_reset_offset_vbles( struct abc_x *input ) -ZERA OFFSET PARA COMEÇAR CALIBRAÇÃO
                f_reset_offset_vbles( &Io_inv_offset );//void f_reset_offset_vbles( struct abc_x *input ) -ZERA OFFSET PARA COMEÇAR CALIBRAÇÃO
                contador_calibra_offset = contador_calibra_offset + 1;
            }
            if ( contador_calibra_offset <= N_cal_offset && contador_calibra_offset > 0 )
            {//Aqui se calcula a média: "input->a = input->a + ( inv_N_cal_offset * Adc_res_1 );"
                f_calc_avg_offset( &Vo_offset    , AdcaResult0, AdcaResult1, AdcaResult2 );//void f_calc_avg_offset( struct abc_x *input, float Adc_res_1, float Adc_res_2, float Adc_res_3 )
                f_calc_avg_offset( &Ilf_offset   , AdcbResult2, AdcbResult3, AdcbResult4 );//void f_calc_avg_offset( struct abc_x *input, float Adc_res_1, float Adc_res_2, float Adc_res_3 )
                f_calc_avg_offset( &Io_inv_offset, AdcaResult3, AdcaResult4, AdcaResult5 );//void f_calc_avg_offset( struct abc_x *input, float Adc_res_1, float Adc_res_2, float Adc_res_3 )

                contador_calibra_offset = contador_calibra_offset + 1;
            }

            if ( contador_calibra_offset == N_cal_offset+1 )
            {
                if( Vo_offset.a>upper_lim_offset || Vo_offset.b>upper_lim_offset || Vo_offset.c>upper_lim_offset || Ilf_offset.a>upper_lim_offset || Ilf_offset.b>upper_lim_offset || Ilf_offset.c>upper_lim_offset || Io_inv_offset.a>upper_lim_offset || Io_inv_offset.b>upper_lim_offset || Io_inv_offset.c>upper_lim_offset ||         Vo_offset.a<lower_lim_offset || Vo_offset.b<lower_lim_offset || Vo_offset.c<lower_lim_offset || Ilf_offset.a<lower_lim_offset || Ilf_offset.b<lower_lim_offset || Ilf_offset.c<lower_lim_offset || Io_inv_offset.a<lower_lim_offset || Io_inv_offset.b<lower_lim_offset || Io_inv_offset.c<lower_lim_offset )
                {
                    contador_calibra_offset = 0;
                }
                else
                {
                    flag_cal = 1;
                }
            }
            FlagDeConversao = 0;
        }
    }

    //INICIALIZAR OS GANHOS PLACA
    Vo_gain.a     = 0.1504787962;
    Vo_gain.b     = 0.1498637602;
    Vo_gain.c     = 0.1480484522;
    Ilf_gain.a    = 0.00923157297;//0.0062727849;//0.01109879963;
    Ilf_gain.b    = 0.00940085109;//0.00634543924;//0.0113610586;
    Ilf_gain.c    = 0.00945167337;//0.00622215401;//0.01103764922;
    Io_inv_gain.a = 0.00939667318;//0.01118139535;
    Io_inv_gain.b = 0.00942514371;//0.01127579737;
    Io_inv_gain.c = 0.00936958846;//0.01119402985;

    GpioDataRegs.GPBCLEAR.bit.GPIO58=1;

	// ==============================================================================================
	//###############################################################################################
	// =================================== Loop infinito ============================================

    //GpioDataRegs.GPCCLEAR.bit.GPIO84=1;//ABRE K2
	while(1)
	{
	    if (FlagDeConversao==1 && Protecao == 0){    // Executa o código dentro do if a cada período de amostragem

	                GpioDataRegs.GPBSET.bit.GPIO60=1;

	                // =================================== Salva Aquisições =================================
	                Vo_inv_abc.a =  ( float )AdcaResult0;
	                Vo_inv_abc.a = -( Vo_inv_abc.a - Vo_offset.a ) * Vo_gain.a;//0.1476068812;//2054
	                Vo_inv_abc.b =  ( float )AdcaResult1;//
	                Vo_inv_abc.b = -( Vo_inv_abc.b - Vo_offset.b ) * Vo_gain.b;//0.14888768318;//2052
	                Vo_inv_abc.c =  ( float )AdcaResult2;//
	                Vo_inv_abc.c = -( Vo_inv_abc.c - Vo_offset.c ) * Vo_gain.c;//0.14595017724;//2057

	                Ilf_abc.a    = ( float )AdcbResult2;//
	                Ilf_abc.a    = ( Ilf_abc.a - Ilf_offset.a ) * Ilf_gain.a;//0.01130350195;//2050
	                Ilf_abc.b    = ( float )AdcbResult3;//
	                Ilf_abc.b    = ( Ilf_abc.b - Ilf_offset.b ) * Ilf_gain.b;//0.01145299145;//2065
	                Ilf_abc.c    = ( float )AdcbResult4;//
	                Ilf_abc.c    = ( Ilf_abc.c - Ilf_offset.c ) * Ilf_gain.c;//0.01106849315;//2037

	                Vcc  = ( float )AdcaResult6;//
	                Vcc  = ( Vcc ) * 0.1446955873;

	                Io_inv_abc.a  = ( float )AdcaResult3;//
	                Io_inv_abc.a  = ( Io_inv_abc.a - Io_inv_offset.a ) * Io_inv_gain.a;//0.0110922945218;   //
	                Io_inv_abc.b  = ( float )AdcaResult4;//
	                Io_inv_abc.b  = ( Io_inv_abc.b - Io_inv_offset.b ) * Io_inv_gain.b;//0.0111569620208;   //
	                Io_inv_abc.c  = ( float )AdcaResult5;//
	                Io_inv_abc.c  = ( Io_inv_abc.c - Io_inv_offset.c ) * Io_inv_gain.c;//0.0110240000033;   //


	                //GERADOR DE ANGULO DE REFERÊNCIA
	                //teta_inv = ( droop_P_Omeg.y * Ts_dsp ) + teta_inv;  //frequency integral
	                f_mav_two( &omega_filt, &droop_P_Omeg.y );

	                teta_inv = ( (droop_P_Omeg.y) * Ts_omeg ) + teta_inv;
	                if ( teta_inv >= 2*pi )
	                {   teta_inv = teta_inv - (2*pi);
	                    if ( flag_dyn_test == 1 )
	                    {
	                        flag_dyn_test2     = 1;//SERÁ HABILITADO EXT TRIGGER E PINO DE SAÍDA (PINOS 13 E 14)
	                        index_dyn_test     = 0;
	                        cont_samp_dyn_test = 0;
	                        flag_dyn_test      = 0;
	                    }
	                }
	                cos_teta = cos(teta_inv);
	                sen_teta = sin(teta_inv);

	                if ( flag_dyn_test2 == 1 )
	                {   GpioDataRegs.GPASET.bit.GPIO13=1;   GpioDataRegs.GPASET.bit.GPIO14=1;   GpioDataRegs.GPASET.bit.GPIO26 = 1;  }//EXT TRIGGER YOKOGAWA; FLAG CONV2
	                else
	                {   GpioDataRegs.GPACLEAR.bit.GPIO13=1; GpioDataRegs.GPACLEAR.bit.GPIO14=1; GpioDataRegs.GPACLEAR.bit.GPIO26 = 1; }//EXT TRIGGER YOKOGAWA; FLAG CONV2

	                /*if(cont_omeg == 0)
	                {
	                    teta_inv = ( (omega_filt.y_filt) * Ts_omeg ) + teta_inv;

	                    if ( teta_inv >= 2*pi )
                            {   teta_inv = teta_inv - (2*pi); }
	                    cos_teta = cos(teta_inv);
	                    sen_teta = sin(teta_inv);
	                }  //frequency integral
	                cont_omeg = cont_omeg + 1;
	                if ( cont_omeg >= 5 )
	                    {cont_omeg = 0;}
                    */
	                //teta_inv = ( omega_filt.y_filt * Ts_dsp ) + teta_inv;  //frequency integral

	                f_abc_AlfaBeta_X( &Vo_inv_alfbet , &Vo_inv_abc );       //( struct alf_bet_x *output, struct abc_x *input )//invariante em potência
                    f_AlfaBeta_dq_X(  &Vo_inv_dq     , &Vo_inv_alfbet );    //( struct dq_x *output , struct alf_bet_x *input )

                    f_abc_AlfaBeta_X( &Ilf_alfbet   , &Ilf_abc );           //( struct alf_bet_x *output, struct abc_x *input )//invariante em potência
	                f_AlfaBeta_dq_X(  &Ilf_dq       , &Ilf_alfbet );        //( struct dq_x *output , struct alf_bet_x *input )

	                f_abc_AlfaBeta_X( &Io_inv_alfbet , &Io_inv_abc );       //( struct alf_bet_x *output, struct abc_x *input )//invariante em potência
	                f_AlfaBeta_dq_X(  &Io_inv_dq     , &Io_inv_alfbet );    //( struct dq_x *output , struct alf_bet_x *input )
	                f_mav_two( &Io_inv_d_filt, &Io_inv_dq.d );
	                f_mav_two( &Io_inv_q_filt, &Io_inv_dq.q );

	                f_lpf_fo_analog_em( &lpf_Vcc, &Vcc );

	                //lpf_Vcc.y_lpf=400;
	                if ( Segundos > 1 )//Pré carga do barramento CC --- && Controle_ON == 1
	                {//Segundos > 1 && lpf_Vcc.y_lpf >= 360
	                 //Segundos > 1
	                    GpioDataRegs.GPCSET.bit.GPIO86=1;// Fecha K1
	                    Controle_ON = 1;
	                    if ( Segundos > 2 && Controle_ON == 1 )
	                    {
	                        GpioDataRegs.GPCSET.bit.GPIO84=1;// Fecha K2
	                    }
	                }

	                //if (1==1){
	                if ( Segundos > 3 && Controle_ON == 1 ) //esse é o correto
	                {//Segundos > 2 && lpf_Vcc.y_lpf < 600 && Controle_ON == 1
	                    //Segundos > 2 && lpf_Vcc.y_lpf > 360 && lpf_Vcc.y_lpf < 600 && Controle_ON == 1
	                 //Segundos > 2 && lpf_Vcc.y_lpf < 600 && Controle_ON == 1


                        if ( Segundos > 3 || ramp_enable == 1 )//Rampa para elevar tensão.
                        {
                            droop_Q_E.y_nom = droop_Q_E.y_nom + 4.0E-3;
                            if ( 1 == f_satura_vble( &droop_Q_E.y_nom ,  221.0 , 0 ) )//char f_satura_vble( float *vble,  float *upper_limit, float *lower_limit )
                                {   ramp_enable = 0;    }
                        }

                         //CALCULO POTÊNCIA ATIVA E REATIVA
                         //p_inst = ( Vo_inv_dq.d * Io_inv_dq.d ) + ( Vo_inv_dq.q * Io_inv_dq.q );
                         //q_inst = ( Vo_inv_dq.q * Io_inv_dq.d ) - ( Vo_inv_dq.d * Io_inv_dq.q );
                         //p_inst = ( Vo_inv_dq.d * Io_inv_d_filt.y_filt ) + ( Vo_inv_dq.q * Io_inv_q_filt.y_filt );
                         //q_inst = ( Vo_inv_dq.q * Io_inv_d_filt.y_filt ) - ( Vo_inv_dq.d * Io_inv_q_filt.y_filt );
                         p_inst = ( Vo_inv_alfbet.alf * Io_inv_alfbet.alf ) + ( Vo_inv_alfbet.bet * Io_inv_alfbet.bet );
                         q_inst = ( Vo_inv_alfbet.bet * Io_inv_alfbet.alf ) - ( Vo_inv_alfbet.alf * Io_inv_alfbet.bet );

                         f_lpf_fo_analog_em( &lpf_fo_Pav , &p_inst );                           //( struct lpf_fo *vbles, float *input )
                         f_lpf_fo_analog_em( &lpf_fo_Qav , &q_inst );                           //( struct lpf_fo *vbles, float *input )

                         //DROOP
                         f_droopPw_sec_Pref( &droop_P_Omeg , &lpf_fo_Pav.y_lpf , 0 );           //( struct droop *droop_vbles   , float *Av_power, float ref_sec )
                         f_droopQE_sec_eref( &droop_Q_E    , &lpf_fo_Qav.y_lpf , 0 );           //( struct droop *droop_vbles   , float *Av_power, float ref_sec )

                         if ( flag_dyn_test2 == 1 )
                         {
                             if ( cont_samp_dyn_test == 0 )
                             {
                                 E_dyn_test_v[index_dyn_test] = droop_Q_E.y;//sen_teta;//
                                 w_dyn_test_v[index_dyn_test] = droop_P_Omeg.y;//teta_inv;//
                                 P_dyn_test_v[index_dyn_test] = lpf_fo_Pav.y_lpf;
                                 Q_dyn_test_v[index_dyn_test] = lpf_fo_Qav.y_lpf;

                                 if ( index_dyn_test == N_delay_degrau )
                                 {  f_enable_kx_dyn_test( &tipo_teste_dyn );  }   //ACIONA CONTATORA DEGRAU
                                 index_dyn_test               = index_dyn_test + 1;
                             }
                             cont_samp_dyn_test = cont_samp_dyn_test + 1;

                             if ( cont_samp_dyn_test == Ncont_samp )//CONTADOR SUBAMOSTRAGEM
                             {  cont_samp_dyn_test = 0; }
                             if ( index_dyn_test == pos_dyn_test_v )// CONTADOR FINALIZAÇÃO TESTE DINÂMICO 800ms=48 ciclos
                             {    flag_dyn_test2 = 0; index_dyn_test = 0; cont_samp_dyn_test = 0;   }
                         }

                         //CÁLCULO TENSÃO DE REFERÊNCIA INCLUINDO Zvirtual
                         Vo_inv_ref_dq.d = droop_Q_E.y - ( Rv * Io_inv_d_filt.y_filt - Lv * omeg_nom * Io_inv_q_filt.y_filt );
                         Vo_inv_ref_dq.q = 0           - ( Rv * Io_inv_q_filt.y_filt + Lv * omeg_nom * Io_inv_d_filt.y_filt );

                         //MALHA DE TENSÃO
                         Vo_err_dq.d = Vo_inv_ref_dq.d - Vo_inv_dq.d;
                         Vo_err_dq.q = Vo_inv_ref_dq.q - Vo_inv_dq.q;
                         f_pi_control_be( &pi_Vd, &Vo_err_dq.d );
                         f_pi_control_be( &pi_Vq, &Vo_err_dq.q );

                         //MALHA DE CORRENTE
                         //Ilf_err_dq.d = ( pi_Vd.y_pi - ( Cf * droop_P_Omeg.y * Vo_inv_dq.q ) + kff*Io_inv_dq.d ) - Ilf_dq.d;
                         //Ilf_err_dq.q = ( pi_Vq.y_pi + ( Cf * droop_P_Omeg.y * Vo_inv_dq.d ) + kff*Io_inv_dq.q ) - Ilf_dq.q;
                         Ilf_err_dq.d = ( pi_Vd.y_pi - ( Cf * omeg_nom       * Vo_inv_dq.q ) + kff*Io_inv_d_filt.y_filt ) - Ilf_dq.d;
                         Ilf_err_dq.q = ( pi_Vq.y_pi + ( Cf * omeg_nom       * Vo_inv_dq.d ) + kff*Io_inv_q_filt.y_filt ) - Ilf_dq.q;
                         f_pi_control_be( &pi_Id, &Ilf_err_dq.d );
                         f_pi_control_be( &pi_Iq, &Ilf_err_dq.q );

                         aci_dq.d = pi_Id.y_pi - ( Lf * I_Vcc_nom * omeg_nom     * Ilf_dq.q );
                         aci_dq.q = pi_Iq.y_pi + ( Lf * I_Vcc_nom * omeg_nom     * Ilf_dq.d );

                         f_dq_AlfaBeta_X( &aci_alfbet , &aci_dq );
                         f_AlfaBeta_abc_X( &aci_abc, &aci_alfbet );//( struct abc_x *output, struct alf_bet_x *input )

                         f_satura_aci( &aci_abc, 1, -1 );                // ( struct abc_x *aci_abc, float upper_limit, float lower_limit )
                         f_scale_aci( &aci_abc ); //f_scale_aci( struct abc_x *output ) // VERIFICAR TBPRD= A KTE DENTRO DA FUNÇAÕ!!!!

                         WctrlA = aci_abc.a;
                         WctrlB = aci_abc.b;
                         WctrlC = aci_abc.c;

	                    // PWM invertido -> A chave de baixo, B chave de cima
	                    EPwm1Regs.CMPA.half.CMPA = WctrlA;  //fase A (amarela)
	                    EPwm1Regs.CMPB = WctrlA;

	                    EPwm2Regs.CMPA.half.CMPA = WctrlB;  //fase B (branca)
	                    EPwm2Regs.CMPB = WctrlB;

	                    EPwm3Regs.CMPA.half.CMPA = WctrlC;  //fase C (vermelha)
	                    EPwm3Regs.CMPB = WctrlC;

	                    //MAV
	                    //f_mav_four( &mav_Vcfa , &Vo_inv_abc.a );

	                    //Saturar Vcfa
	                    //f_satura_vble_s( &satura_Vcfa, &Vo_inv_abc.a );       //void f_satura_vble_s( struct saturador *vbles, float *input )
	                    //satura_Vcfa.y_sat = Vo_inv_abc.a;
	                    //f_satura_vble( &satura_Vcfa.y_sat ,  satura_Vcfa.upper_limit, satura_Vcfa.lower_limit );//void f_satura_vble( float *vble,  float *upper_limit, float *lower_limit )


	                    if(Desliga_sistema == 1){
	                        abre_chaves();
	                        while(1){}
	                    }
	                }
	                else{   abre_chaves();  }

	                //removi prote
	                // Proteção (Correntes do Inversor ou Tensão no barramento CC) ////

	                if (Io_inv_abc.a>29.1 || Io_inv_abc.b>29.1 || Io_inv_abc.c>29.1 || Io_inv_abc.a<-29.1 || Io_inv_abc.b<-29.1 || Io_inv_abc.c<-29.1 || Vo_inv_dq.d>420 || Vo_inv_dq.q>400 || Vo_inv_abc.a>306 || Vo_inv_abc.b>306 || Vo_inv_abc.c>306 || Vo_inv_abc.a<-306 || Vo_inv_abc.b<-306 || Vo_inv_abc.c<-306 || lpf_Vcc.y_lpf>600) //|| lpf_Vcc.y_lpf<400)
	                {
	                    //GpioDataRegs.GPASET.bit.GPIO26 = 1;PINO FUNCIONA COMO PROTEÇÃO
                        abre_chaves();
                        Protecao = 1;
                        //while(1){}
	                }

	                FlagDeConversao = 0;//fim loop while
	                FlagSpiTx       = 0;
                    count_tx_sci1   = count_tx_sci1 + 1;
                    count_tx_sci2   = count_tx_sci2 + 1;

	                GpioDataRegs.GPBCLEAR.bit.GPIO60 = 1;

	                //========================================================================================
	                //################################ FIM FLAG DE CONVERSÃO #################################
	                //========================================================================================
	            }
		else
		{
		    if ( tipo_teste_dyn_ant != tipo_teste_dyn )//ATUALIZA CONDIÇÃO INICIAL DE CONTATORAS PARA TESTE DINÂMICO
		    {
		        tipo_teste_dyn_ant = tipo_teste_dyn;
		        f_initial_cond_kx( &tipo_teste_dyn );   //COLOCA CONTATORAS NA CONDIÇÃO INICIAL DO TESTE
		    }
		    if ( abs(Io_inv_abc.a) > max_i )
		    {
		        max_i = abs(Io_inv_abc.a);
		    }
		    if ( abs(Io_inv_abc.b) > max_i )
		    {
		        max_i = abs(Io_inv_abc.b);
		    }
		    if ( abs(Io_inv_abc.c) > max_i )
            {
		        max_i = abs(Io_inv_abc.c);
            }
		        //TRANSMISSÃO SPI -DAC MCP 4922 --> scale y=ax+b; a = 4095 / (in_max-in_min);  b= -xmin / a
		    if ( FlagSpiTx == 0 )
		    {
		        if ( sw_spi_signal == 0 )
		        {// ( float *chA_data, float *chB_data, float gain_chA, float offset_chA, float gain_chB, float offset_chB )
                    f_write_spi_tx_buffer_dac( &Vo_err_dq.d , &pi_Vd.y_pi , -6.774751908 , 2054 , -6.774751908 , 2054 );}
		        else if ( sw_spi_signal == 1 )
		        { // ( float *chA_data, float *chB_data, float gain_chA, float offset_chA, float gain_chB, float offset_chB )
		            f_write_spi_tx_buffer_dac( &Vo_inv_abc.a , &Vo_inv_abc.b , -6.774751908 , 2054 , -6.774751908 , 2054 );}
		        else if ( sw_spi_signal == 2 )
		        {   f_write_spi_tx_buffer_dac( &droop_P_Omeg.y , &teta_inv , 81.9 , -28665 , 651.739 , 0 );}
		        else if ( sw_spi_signal == 3 )
		        {   f_write_spi_tx_buffer_dac( &Vo_inv_alfbet.alf , &teta_inv , 6.9 , 2054 , 651.739 , 0 );}
		        else if ( sw_spi_signal == 4 )
		        {   f_write_spi_tx_buffer_dac( &Vo_inv_alfbet.bet , &teta_inv , 6.9 , 2054 , 651.739 , 0 );}
		        else if ( sw_spi_signal == 5 )
		        {   f_write_spi_tx_buffer_dac( &Vo_inv_abc.a , &teta_inv , 6.9 , 2054 , 651.739 , 0 );}
		        else //( sw_spi_signal == 6 )
		        {   f_write_spi_tx_buffer_dac( &Vo_inv_abc.b , &teta_inv , 6.9 , 2054 , 651.739 , 0 );}

		        if ( 1 == SciaRegs.SCICTL2.bit.TXEMPTY ) //Verifica se última SCI Tx foi finalizada
		        {
		            count_tx_sci2 = 0;
		            if ( flag_sci <= n_var_tx_sci - 2 )
		            {       //scale y=ax+b; a = 255 / (in_max-in_min);  b= -xmin * a
		                SciaRegs.SCITXBUF = address_sci[ flag_sci ];    //Send Address
		                //f_flo_write_sci_tx_idle_line_split( &buffer_tx_sci[ flag_sci ], 0.425, 127.5 );   //f_flo_write_sci_tx_idle_line( float *data, float gain, float offset )
		                while ( !SciaRegs.SCICTL2.bit.TXRDY )   {}
		                SciaRegs.SCITXBUF           = 'x';
		                //f_flo_write_sci_tx_idle_line
		                flag_sci = flag_sci + 1;
		            }
		            else if ( flag_sci == n_var_tx_sci - 1 )//SENT TETA_INV --> DIFFERENT GAIN AND OFFSET
		            {
		                SciaRegs.SCITXBUF = address_sci[ flag_sci ];    //Send Address
		                //f_flo_write_sci_tx_idle_line_split( &buffer_tx_sci[ flag_sci ], 40.58, 0 );
		                while ( !SciaRegs.SCICTL2.bit.TXRDY )   {}
		                SciaRegs.SCITXBUF           = 'y';
		                flag_sci = flag_sci + 1;
		            }
		            else if ( flag_sci == 255 )//IDLE
		            {//count_tx_sci1 deve ser enviado depois do idle, pois o que estiver no buffer será desconsiderado (acaba mandando o x
		                //SciaRegs.SCICTL1.bit.TXWAKE = 1;        //forces an 11 bit iddle (time separation between blocks) in iddle-line mode
		                //SciaRegs.SCITXBUF           = 'x';      //This is no-care data to force iddle
		                flag_sci                    = 0;
		            }
		            else
		            {
		                SciaRegs.SCITXBUF           = 255;          //Send address end-of-sequence (Sync data 1 byte)
		                flag_sci                    = 255;
		                while ( !SciaRegs.SCICTL2.bit.TXRDY )   {}
		                SciaRegs.SCITXBUF           = count_tx_sci1;//send sync data
		                count_tx_sci1     = 0;
		                //LOAD BUFFER FOR THE NEXT TX SEQUENCE
		                f_load_sci_buffer_f( buffer_tx_sci, &Vo_inv_alfbet.alf, &Vo_inv_alfbet.bet, &Vo_inv_abc.b, &teta_inv );
		            }

		        }

		    }

		}
		//============================================================================================
		//##################################### FIM DO LOOP INFINITO #################################
		//============================================================================================
	}
	//================================================================================================
	//####################################### FIM DA FUNÇÃO PRINCIPAL ################################
	//================================================================================================
}

interrupt void  adc_isr(void)
{

  	// Atribui os dados recebidos para os ADRESULTx
  	// Desloca 4 bit aquisição analogia em 12 bit 

//-------------------Tensões-----------------------
	AdcaResult0 = (AdcRegs.ADCRESULT0 >>4);//Vo_inv_abc.a
	AdcaResult1 = (AdcRegs.ADCRESULT1 >>4);//Vo_inv_abc.b
	AdcaResult2 = (AdcRegs.ADCRESULT2 >>4);//Vo_inv_abc.c
	AdcaResult6 = (AdcRegs.ADCRESULT6 >>4);//Vcc
//-------------------------------------------------
//--------------Correntes do Filtro---------------
	AdcaResult3 = (AdcRegs.ADCRESULT3 >>4);//Io_inv_abc.a
	AdcaResult4 = (AdcRegs.ADCRESULT4 >>4);//Io_inv_abc.b
	AdcaResult5 = (AdcRegs.ADCRESULT5 >>4);//Io_inv_abc.c
//------------------------------------------------
//--------------Correntes de carga----------------
	AdcbResult2 = (AdcRegs.ADCRESULT8 >>4);//Ilf_abc.a
	AdcbResult3 = (AdcRegs.ADCRESULT9 >>4);//Ilf_abc.b
	AdcbResult4 = (AdcRegs.ADCRESULT10 >>4);//Ilf_abc.c
//------------------------------------------------

	//leo removeu, voltar
  	// Contatador para lógica de partida
    if ( Segundos < 59 && flag_cal == 1 && Controle_ON ==1 )
    {   //(Segundos < 5 && lpf_Vcc.y_lpf >= 360)
        //Segundos < 5 && St_precarga == 1
 		Counter_Timer++;
 		if( Counter_Timer > 39999 )
 		{
 		   Counter_Timer = 0;
 		   Segundos      = Segundos + 1;
 		}
    }
	
	FlagDeConversao=1;

  	// Reinitialize for next ADC sequence
  	AdcRegs.ADCTRL2.bit.RST_SEQ1 = 1;         // Reset SEQ1
  	AdcRegs.ADCST.bit.INT_SEQ1_CLR = 1;       // Clear INT SEQ1 bit

//	AdcRegs.ADCTRL2.bit.RST_SEQ2 = 1;         // Reset SEQ1
//  	AdcRegs.ADCST.bit.INT_SEQ2_CLR = 1;       // Clear INT SEQ1 bit
  	if ( sync_adc_pwm == 1 )
  	{   GpioDataRegs.GPACLEAR.bit.GPIO27 = 1;}// CLearPulso ADC_SOC conversor 2

	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;   // Acknowledge interrupt to PIE
}

interrupt void epwm1_isr(void)
{
   // Clear INT flag for this timer
   EPwm1Regs.ETCLR.bit.INT = 1;

   // Acknowledge this interrupt to receive more interrupts from group 3
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}

interrupt void epwm6_isr(void)
{
   // Clear INT flag for this timer
   EPwm6Regs.ETCLR.bit.INT = 1;

   // Setar gpio
   if ( sync_adc_pwm == 1 )
   {    GpioDataRegs.GPASET.bit.GPIO27=1;}// Pulso ADC_SOC conversor 2
   // Acknowledge this interrupt to receive more interrupts from group 3
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}

interrupt void sciaRxFifoIsr(void)
{
    /*Uint16 i;

    for(i=0;i<8;i++)
    {
       rdataA[i]=SciaRegs.SCIRXBUF.all;  // Read data
    }
    for(i=0;i<8;i++)                     // Check received data
    {
       if(rdataA[i] != ( (rdata_pointA+i) & 0x00FF) ) error();
    }
    rdata_pointA = (rdata_pointA+1) & 0x00FF;
    */
    SciaRegs.SCIFFRX.bit.RXFFOVRCLR=1;   // Clear Overflow flag - p612 Write 1 to clear RXFFOVF flag in bit 15
    SciaRegs.SCIFFRX.bit.RXFFINTCLR=1;   // Clear Interrupt flag - p613  Write 1 to clear RXFFINT flag in bit 7

    PieCtrlRegs.PIEACK.all|=PIEACK_GROUP9;       // Issue PIE ack
}

void scia_fifo_init()
{   //SCICCR defines the character format, protocol, and communications mode used by the SCI
    // p597 - Table 10-7
    SciaRegs.SCICCR.bit.SCICHAR       = 8-1;    //DATA LENGTH 8 char bits
    SciaRegs.SCICCR.bit.LOOPBKENA     = 0;      // 1 = Enable loop back
    SciaRegs.SCICCR.bit.ADDRIDLE_MODE = 0;      // 0 =iddle-line; 1 = address bit mode
    SciaRegs.SCICCR.bit.PARITYENA     = 0;      // 0 =parity disabled; 1 = parity enabled
    SciaRegs.SCICCR.bit.PARITY        = 0;      // 0 = odd; 1 = even
    SciaRegs.SCICCR.bit.STOPBITS      = 0;      // 0 = 1 stop bit; 1 = 2 stop bits

    // p600 - Table 10-8
   SciaRegs.SCICTL1.all = 0x0003;                // ENABLE TX AND RX; Disable RX ERR, SLEEP, TXWAKE

   // p601 - Table 10-9 e 10-10
   SciaRegs.SCIHBAUD   = 0x0000;
   SciaRegs.SCILBAUD   = 40;         //.BRR = LSPCLK / ( SCI BAUDRATE * 8 ) - 1; lspclk = 37.5 MHz (p65)
   // 19200=243 (err=0.058%), 38400=121 (err=0.058%), 115200 = 40 (err=0.76%), 128000=36 (err=1.035%), 256000=17 (err=1.72%)-não funcionou

   // p603 - Table 10-11
   SciaRegs.SCICTL2.bit.TXINTENA   = 0;
   SciaRegs.SCICTL2.bit.RXBKINTENA = 1;

   //SCIFFTX controls the transmit FIFO interrupt, FIFO enhancements, and reset for the SCI transmit and receive channels
   // p610 - Table 10-16
   SciaRegs.SCIFFTX.all=0xC028;     //SCI Reset, SCI FIFO enable, Transmit FIFO interrrupt enable, Transmit FIFO interrupt level bits
   SciaRegs.SCIFFRX.all=0x0028;     //Receive FIFO interrupt enable, Receive FIFO interrupt level bits

   //contains the status of auto-baud detect, clears the auto-baud flag, and calibrate for A-detect bit
   SciaRegs.SCIFFCT.all=0x00;

   //All affected logic is held in the specified reset state until a 1 is written to SW RESET (the bit values following a reset are shown beneath each register diagram in this section).
   SciaRegs.SCICTL1.all =0x0023;     // Relinquish SCI from Reset-- ESCOLHER BEM DE NOVO

   SciaRegs.SCIFFTX.bit.TXFIFOXRESET=1;
   SciaRegs.SCIFFRX.bit.RXFIFORESET=1;
}



void ConfigEpwm()
{

	//EPWM1 - MODULO 1 - CONFIGURACAO
   // Setup TBCLK
    //p296 - Table3-21
    //Determine the period of the time-base counter. This sets the PWM frequency
   EPwm1Regs.TBPRD = TIMER_TBPRD;  // 10kHZ = 7500, 18k=4166, 20k=3750        // Set timer period 801 TBCLKs = valor maximo da triangular - Vt_pico=FC/(2*Fsw)

   //set time-base counter phase of the selected ePWM relative to the time-base that is supplying the synchronization input signal
   EPwm1Regs.TBPHS.half.TBPHS = 0x0000;           // Phase is 0   defasagem = 0
   EPwm1Regs.TBCTR = 0x0000;                      // Clear counter limpa contador
   
   // Setup counter mode
   //p297 - Table3-24
   EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up-down  PWM Simetrico (triangular)
   EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE;        // Disable phase loading
   EPwm1Regs.TBCTL.bit.SYNCOSEL = 1;              // Synchronization output select: 1 = tbctr=0; 2 = tbctr=tbprd; 3=disable;
   EPwm1Regs.TBCTL.bit.PHSDIR = 1;                //direction the time-base counter (TBCTR) will count after a synchronization EVENT
   EPwm1Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       // Clock ratio to SYSCLKOUT. Determine part of the time-base clock prescale value. TBCLK = SYSCLKOUT / (HSPCLKDIV × CLKDIV)
   EPwm1Regs.TBCTL.bit.CLKDIV = TB_DIV1;			// Determine part of the time-base clock prescale value. TBCLK = SYSCLKOUT / (HSPCLKDIV × CLKDIV)

   // Setup shadowing
   EPwm1Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
   EPwm1Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
   EPwm1Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;  // Load on Zero
   EPwm1Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;   


   // Set actions
   EPwm1Regs.AQCTLA.bit.CAU = AQ_SET; //AQ_SET;             // Set PWM1A on event A, up count (CAU no incremento da triangular)												  // PWM1A pulso alto quando referencia (CMPA) = triangular (AQ_SET)
   EPwm1Regs.AQCTLA.bit.CAD = AQ_CLEAR;//AQ_CLEAR;           // Clear PWM1A on event A, down count (CAD no decremento da triangular)
   EPwm1Regs.AQCTLB.bit.CBU = AQ_CLEAR; //AQ_CLEAR;             // Set PWM1B on event B, up count
   EPwm1Regs.AQCTLB.bit.CBD = AQ_SET; //AQ_SET;           // Clear PWM1B on event B, down count
   
   
//   EPwm1Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;     	//Habilita Dead-band module
//   EPwm1Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;     	//Habilita HI complementar
//   EPwm1Regs.DBCTL.bit.IN_MODE = DBA_ALL;
//   EPwm1Regs.DBFED = 75;							//FED = 75 TBPRD (500ns)
//  EPwm1Regs.DBRED = 75;							//RED = 75 TBPRD (500ns)

	//EPWM2 - MODULO 2 - CONFIGURACAO
   // Setup TBCLK
   EPwm2Regs.TBPRD = TIMER_TBPRD;//         // Set timer period 801 TBCLKs = valor maximo da triangular
   EPwm2Regs.TBPHS.half.TBPHS = 0x0000;           // Phase is 0   defasagem = 0
   EPwm2Regs.TBCTR = 0x0000;                      // Clear counter limpa contador
   
   // Setup counter mode
   EPwm2Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up  PWM Simetrico
   if ( sync_adc_pwm == 1 )
   {    EPwm2Regs.TBCTL.bit.PHSEN = TB_ENABLE;}        // Disable phase loading
   else
   {    EPwm2Regs.TBCTL.bit.PHSEN = TB_DISABLE;}
   EPwm2Regs.TBCTL.bit.SYNCOSEL = 1;              // Synchronization output select: 1 = tbctr=0; 2 = tbctr=tbprd; 3=disable;
   EPwm2Regs.TBCTL.bit.PHSDIR = 1;                //direction the time-base counter (TBCTR) will count after a synchronization EVENT
   EPwm2Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       // Clock ratio to SYSCLKOUT
   EPwm2Regs.TBCTL.bit.CLKDIV = TB_DIV1;		// Estava TB_DIV2

   // Setup shadowing
   EPwm2Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
   EPwm2Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
   EPwm2Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;  // Load on Zero
   EPwm2Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;   


   // Set actions
   EPwm2Regs.AQCTLA.bit.CAU = AQ_SET; //AQ_SET;             // Set PWM1A on event A, up count (CAU no incremento da triangular)												  // PWM1A pulso alto quando referencia (CMPA) = triangular (AQ_SET)
   EPwm2Regs.AQCTLA.bit.CAD = AQ_CLEAR; //AQ_CLEAR;           // Clear PWM1A on event A, down count (CAD no decremento da triangular)											  // PWM1A pulsa baixo quando refencia (CMPA) = triangular (AQ_CLEAR
   EPwm2Regs.AQCTLB.bit.CBU = AQ_CLEAR; //AQ_CLEAR;             // Set PWM1B on event B, up count
   EPwm2Regs.AQCTLB.bit.CBD = AQ_SET; //AQ_SET;           // Clear PWM1B on event B, down count

   // Interrupt where we will change the Compare Values
   //EPwm2Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;      // Select INT on Zero event
   //EPwm2Regs.ETSEL.bit.INTEN = 1;                 // Enable INT
   //EPwm2Regs.ETPS.bit.INTPRD = ET_3RD;            // Generate INT on 3rd event
   
//   EPwm2Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;     	//Habilita Dead-band module
//   EPwm2Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;     	//Habilita HI complementar
//   EPwm2Regs.DBCTL.bit.IN_MODE = DBA_ALL;
//   EPwm2Regs.DBFED = 75;							//FED = 75 TBPRD (500ns)
//   EPwm2Regs.DBRED = 75;							//RED = 75 TBPRD (500ns)
   
   
   	//EPWM3 - MODULO 2 - CONFIGURACAO
   // Setup TBCLK
   EPwm3Regs.TBPRD = TIMER_TBPRD;//37500*4;           // Set timer period 801 TBCLKs = valor maximo da triangular
   EPwm3Regs.TBPHS.half.TBPHS = 0x0000;           // Phase is 0   defasagem = 0
   EPwm3Regs.TBCTR = 0x0000;                      // Clear counter limpa contador
   
   // Setup counter mode
   EPwm3Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up  PWM Simetrico
   if ( sync_adc_pwm == 1 )
   {    EPwm3Regs.TBCTL.bit.PHSEN = TB_ENABLE;}        // Disable phase loading
   else
   {    EPwm3Regs.TBCTL.bit.PHSEN = TB_DISABLE;}
   EPwm3Regs.TBCTL.bit.SYNCOSEL = 1;              // Synchronization output select: 1 = tbctr=0; 2 = tbctr=tbprd; 3=disable;
   EPwm3Regs.TBCTL.bit.PHSDIR = 1;                //direction the time-base counter (TBCTR) will count after a synchronization EVENT
   EPwm3Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;       // Clock ratio to SYSCLKOUT
   EPwm3Regs.TBCTL.bit.CLKDIV = TB_DIV1;		// Estava TB_DIV2

   // Setup shadowing
   EPwm3Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
   EPwm3Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
   EPwm3Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;  // Load on Zero
   EPwm3Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;   


   // Set actions
   EPwm3Regs.AQCTLA.bit.CAU = AQ_SET; //AQ_SET;             // Set PWM1A on event A, up count (CAU no incremento da triangular)												  // PWM1A pulso alto quando referencia (CMPA) = triangular (AQ_SET)
   EPwm3Regs.AQCTLA.bit.CAD = AQ_CLEAR; //AQ_CLEAR;           // Clear PWM1A on event A, down count (CAD no decremento da triangular)
   EPwm3Regs.AQCTLB.bit.CBU = AQ_CLEAR; //AQ_CLEAR;             // Set PWM1B on event B, up count
   EPwm3Regs.AQCTLB.bit.CBD = AQ_SET; //AQ_SET;           // Clear PWM1B on event B, down count

   
//   EPwm3Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;     	//Habilita Dead-band module
//   EPwm3Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;     	//Habilita HI complementar
//   EPwm3Regs.DBCTL.bit.IN_MODE = DBA_ALL;
//   EPwm3Regs.DBFED = 75;							//FED = 75 TBPRD (500ns)
//   EPwm3Regs.DBRED = 75;							//RED = 75 TBPRD (500ns)

//

}


void Gpio_select(void)
{

	EALLOW;
	    //   GPAMUX1: GPIO A Mux 1 Register (GPIO0 to 15) - P 104 - Table 1-50
		// See table 1-47 - p 101
	    GpioCtrlRegs.GPAMUX1.all=0;					// GPIO15 ... GPIO0 = General Puropse I/O
		GpioCtrlRegs.GPAMUX2.all=0;					// Seleciona GPIO16...GPIO31 = General Purpouse-MODIFICAR AQUI CAN
		GpioCtrlRegs.GPBMUX1.all=0;
		GpioCtrlRegs.GPBMUX2.all=0;
		GpioCtrlRegs.GPCMUX2.all=0;


		//  GPADIR: GPIO A Direction Register (0=input/1=output) - P 119 - table 1-62
		GpioCtrlRegs.GPADIR.all=0xFFFFFFFF;			// Seleciona GPIO31 ... GPIO0 como saida
		GpioCtrlRegs.GPBDIR.bit.GPIO60=1;           //TEMPO CÓDIGO DSP
		GpioCtrlRegs.GPBDIR.bit.GPIO61=1;			// Seleciona GPIO61 como saída
		GpioCtrlRegs.GPBDIR.bit.GPIO62=1;           //K3
		GpioCtrlRegs.GPBDIR.bit.GPIO58=1;           //K4
		GpioCtrlRegs.GPCDIR.bit.GPIO84=1;           //K2
		GpioCtrlRegs.GPCDIR.bit.GPIO86=1;           //K1
		EDIS;

		//  GPAPUD: Allow you to specify which pins should have an internal pullup resister enabled - P 120 - Table 1-65
		GpioCtrlRegs.GPAPUD.all=0;
		GpioCtrlRegs.GPBPUD.bit.GPIO60=0;
		GpioCtrlRegs.GPBPUD.bit.GPIO61=0;			// Habilita resistor de pull-up para o pino GPIO61
		GpioCtrlRegs.GPBPUD.bit.GPIO62=0;
		GpioCtrlRegs.GPBPUD.bit.GPIO58=0;
		GpioCtrlRegs.GPCPUD.bit.GPIO84=0;
		GpioCtrlRegs.GPCPUD.bit.GPIO86=0;

		//  GPACLEAR: GPIO A Data Clear Register (GPIO0 to 31) - P1087
		GpioDataRegs.GPACLEAR.all=0xFFFFFFFF;		// Atribui zero para GPIO31 ... GPIO0
		GpioDataRegs.GPBCLEAR.bit.GPIO60=1;			// Atribui zero para o pino GPIO60
		GpioDataRegs.GPBCLEAR.bit.GPIO61=1;			// Atribui zero para o pino GPIO61
		GpioDataRegs.GPBSET.bit.GPIO62=1;
		GpioDataRegs.GPBSET.bit.GPIO58=1;
		GpioDataRegs.GPCSET.bit.GPIO84=1;         // Atribui zero para o pino
		GpioDataRegs.GPCSET.bit.GPIO86=1;         // Atribui zero para o pino
}




/*interrupt void cpu_timer0_isr(void)
{
    CpuTimer0.InterruptCount++;		// increment time counter
   	GpioDataRegs.GPBTOGGLE.bit.GPIO34 = 1; // toggle LED at GPIO34
   	// Service the watchdog every Timer 0 interrupt
   	//EALLOW;
	//SysCtrlRegs.WDKEY = 0x55;		// Service watchdog #1
	//EDIS;
   	// Acknowledge this interrupt to receive more interrupts from group 1
   	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}*/



void InitEPwmSyncGpio_user(void)
{

   EALLOW;

/* Configure EPWMSYNCI  */

/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user.
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

//   GpioCtrlRegs.GPAPUD.bit.GPIO6 = 0;    // Enable pull-up on GPIO6 (EPWMSYNCI)
   GpioCtrlRegs.GPBPUD.bit.GPIO32 = 0;   // Enable pull-up on GPIO32 (EPWMSYNCI)

/* Set qualification for selected pins to asynch only */
// This will select synch to SYSCLKOUT for the selected pins.
// Comment out other unwanted lines.

//   GpioCtrlRegs.GPAQSEL1.bit.GPIO6 = 0;   // Synch to SYSCLKOUT GPIO6 (EPWMSYNCI)
   GpioCtrlRegs.GPBQSEL1.bit.GPIO32 = 0;  // Synch to SYSCLKOUT GPIO32 (EPWMSYNCI)

/* Configure EPwmSync pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be EPwmSync functional pins.
// Comment out other unwanted lines.

//   GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 2;    // Enable pull-up on GPIO6 (EPWMSYNCI)
   GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 2;   // Enable pull-up on GPIO32 (EPWMSYNCI)



/* Configure EPWMSYNC0  */

/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user.
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

// GpioCtrlRegs.GPAPUD.bit.GPIO6 = 0;    // Enable pull-up on GPIO6 (EPWMSYNC0)
   GpioCtrlRegs.GPBPUD.bit.GPIO33 = 0;   // Enable pull-up on GPIO33 (EPWMSYNC0)

// GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 3;    // Enable pull-up on GPIO6 (EPWMSYNC0)
   GpioCtrlRegs.GPBMUX1.bit.GPIO33 = 2;   // Enable pull-up on GPIO33 (EPWMSYNC0)

}


void f_initial_cond_kx( int *tipo_teste_dyn )
{
    if ( *tipo_teste_dyn == 0 || *tipo_teste_dyn == 4 )//CARGAS DESLIGADS
    {
        GpioDataRegs.GPBCLEAR.bit.GPIO62=1;
        GpioDataRegs.GPBCLEAR.bit.GPIO58=1;
    }
    else if ( *tipo_teste_dyn == 1 || *tipo_teste_dyn == 3 )// CARGA 1 LIGADA (K3-PINO62)
    {
        GpioDataRegs.GPBSET.bit.GPIO62=1;
        GpioDataRegs.GPBCLEAR.bit.GPIO58=1;
    }
    else if ( *tipo_teste_dyn == 2 || *tipo_teste_dyn == 6 )// CARGA 1 E 2 LIGADAS (K3-PINO62 E K4 PINO 58)
    {
        GpioDataRegs.GPBSET.bit.GPIO62=1;
        GpioDataRegs.GPBSET.bit.GPIO58=1;
    }
    else if ( *tipo_teste_dyn == 5 || *tipo_teste_dyn == 7 )// CARGA 1 E 2 LIGADAS (K3-PINO62 E K4 PINO 58)
    {
        GpioDataRegs.GPBCLEAR.bit.GPIO62=1;
        GpioDataRegs.GPBSET.bit.GPIO58=1;
    }
}

void f_enable_kx_dyn_test( int *tipo_teste_dyn )
{
    if ( *tipo_teste_dyn == 0 || *tipo_teste_dyn == 2 )//LIGAR CARGA 1 DESLIGAR CARGA 2
    {
        GpioDataRegs.GPBSET.bit.GPIO62=1;
        GpioDataRegs.GPBCLEAR.bit.GPIO58=1;
    }
    else if ( *tipo_teste_dyn == 1 || *tipo_teste_dyn == 5 )// CARGA 1 E 2 LIGADAS (K3-PINO62 E K4 PINO 58)
    {
        GpioDataRegs.GPBSET.bit.GPIO62=1;
        GpioDataRegs.GPBSET.bit.GPIO58=1;
    }
    else if ( *tipo_teste_dyn == 3 || *tipo_teste_dyn == 7 )// AMBAS CARGAS DESLIGADAS
    {
        GpioDataRegs.GPBCLEAR.bit.GPIO62=1;
        GpioDataRegs.GPBCLEAR.bit.GPIO58=1;
    }
    else if ( *tipo_teste_dyn == 4 || *tipo_teste_dyn == 6 )// DESLIGAR CARGA 1, LIGAR CARGA 2
    {
        GpioDataRegs.GPBCLEAR.bit.GPIO62=1;
        GpioDataRegs.GPBSET.bit.GPIO58=1;
    }
}
