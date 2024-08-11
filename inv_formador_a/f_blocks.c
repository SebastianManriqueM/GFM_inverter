/*
 * f_blocks.c
 *
 *  Created on: 19 de jun de 2020
 *      Author: Sebastián Manrique M
 */
//PROROTYPES OF FUNCTIONS USED HERE
//void f_satura_vble( float *vble,  float *upper_limit, float *lower_limit );
//#include "f_blocks.h"
//______________________________
//------- DROOP_CONTROL -------||
//_____________________________||
void f_droopPw_sec_Pref( struct droop *droop_vbles   , float *Av_power, float ref_sec )
{
    droop_vbles->y = ( ( *Av_power - ref_sec ) * -droop_vbles->k ) + droop_vbles->y_nom;
}

void f_droopQE_sec_eref( struct droop *droop_vbles   , float *Av_power, float ref_sec )
{
    droop_vbles->y = (  *Av_power * -droop_vbles->k ) + droop_vbles->y_nom + ref_sec;
}



//______________________________
//---------PI_CONTROL ---------||
//_____________________________||
void f_pi_control_be( struct pi_be *pi_ctrl, float *err )
{
    pi_ctrl->y_integral = pi_ctrl->y_integral    + ( Ts_dsp * *err );
    pi_ctrl->y_pi       = ( pi_ctrl->kp * *err ) + ( pi_ctrl->ki * pi_ctrl->y_integral );
}

void f_pi_control_tust( struct pi_tust *pi_ctrl, float *err )
{
    pi_ctrl->y_pi  = ( pi_ctrl->b0 * *err ) + ( pi_ctrl->s_ant );
    pi_ctrl->s_ant = ( pi_ctrl->b1 * *err ) - pi_ctrl->y_pi;        //Atualiza s_ant para próxima iteração
}

//______________________________
//---------LPF FILTERS---------||
//_____________________________||
void f_mav_two( struct mav_two *vbles, float *input )
{
    vbles->y_filt           = vbles->y_filt + *input*0.5 - vbles->buffer[vbles->i];
    vbles->buffer[vbles->i] = *input*0.5;
    vbles->i                = vbles->i + 1;
    if (vbles->i  > 1){
        vbles->i = 0; }
}
void f_mav_four( struct mav_four *vbles, float *input )
{
    vbles->y_filt           = vbles->y_filt + *input*0.25 - vbles->buffer[vbles->i];
    vbles->buffer[vbles->i] = *input*0.25;
    vbles->i                = vbles->i + 1;
    if (vbles->i  > 3){
        vbles->i = 0; }
}

void f_mav_five( struct mav_five *vbles, float *input )
{
    vbles->y_filt           = vbles->y_filt + *input*0.2 - vbles->buffer[vbles->i];
    vbles->buffer[vbles->i] = *input*0.2;
    vbles->i                = vbles->i + 1;
    if (vbles->i  > 4){
        vbles->i = 0; }
}

void f_mav_eight( struct mav_eight *vbles, float *input )
{
    vbles->y_filt           = vbles->y_filt + *input*0.125 - vbles->buffer[vbles->i];
    vbles->buffer[vbles->i] = *input*0.125;
    vbles->i                = vbles->i + 1;
    if (vbles->i  > 7){
        vbles->i = 0; }
}


void f_lpf_fo_analog_em( struct lpf_fo *vbles, float *input )
{   //Transposed Direct Form II
    vbles->y_lpf = ( vbles->b01 * *input )   +   vbles->s_ant;
    vbles->s_ant = ( -vbles->a1 * vbles->y_lpf ) + ( vbles->b01 * *input ); //Atualiza s_ant para próxima iteração
}


//______________________________
//--------- SATURADOR ---------||
//_____________________________||
void f_satura_vble_s( struct saturador *vbles, float *input )
{
    vbles->y_sat = *input;
    if ( vbles->y_sat > vbles->upper_limit )
    {
        vbles->y_sat = vbles->upper_limit;
    }
    if ( vbles->y_sat < vbles->lower_limit )
    {
        vbles->y_sat = vbles->lower_limit;
    }
}

int f_satura_vble( float *vble,  float upper_limit, float lower_limit )
{
    int flag_output = 0;
    if ( *vble > upper_limit )
    {
        *vble = upper_limit;
        flag_output = 1;
    }
    else if ( *vble < lower_limit )
    {
        *vble = lower_limit;
        flag_output = 2;
    }
    return flag_output;
}

void f_satura_aci( struct abc_x *aci_abc, float upper_limit, float lower_limit )
{
    if ( aci_abc->a > upper_limit )
    {
        aci_abc->a = upper_limit;
    }
    else if ( aci_abc->a < lower_limit )
    {
        aci_abc->a = lower_limit;
    }

    if ( aci_abc->b > upper_limit )
    {
       aci_abc->b = upper_limit;
    }
    else if ( aci_abc->b < lower_limit )
    {
        aci_abc->b = lower_limit;
    }

    if ( aci_abc->c > upper_limit )
    {
        aci_abc->c = upper_limit;
    }
    else if ( aci_abc->c < lower_limit )
    {
        aci_abc->c = lower_limit;
    }
}

//______________________________
//--- SCALE CONTROL ACTION ----||
//_____________________________||
f_scale_aci( struct abc_x *aci_abc )
{//Scale control action
    aci_abc->a = ( aci_abc->a + 1 ) * 1875;//aci_abc->a * I_Vcc_nom * 4166;
    aci_abc->b = ( aci_abc->b + 1 ) * 1875;// aci_abc->b * I_Vcc_nom * 4166;
    aci_abc->c = ( aci_abc->c + 1 ) * 1875;// aci_abc->c * I_Vcc_nom * 4166;
}


//______________________________
//-----------SPI DAC-----------||
//_____________________________||
void f_write_spi_tx_buffer_dac( float *chA_data, float *chB_data, float gain_chA, float offset_chA, float gain_chB, float offset_chB )
{   //FUNÇÃO PARA ESCREVER NO DAC MCP 4922 (DOIS CANAIS - INTERFACE SPI)
    //DAC POSSUI 12 BITS. 4 MSB SÃO INSTRUÇÕES 15=nA/B; 14=Vref input buffer(0); 13=Gain (0); 12=nSHDN(1)

    Uint16 convert_spi  = 0;
    float convert_spi_f = 0;

    //CANAL A
    // y = ax + b
    convert_spi_f = ( *chA_data * gain_chA ) + offset_chA;
    if ( convert_spi_f > 4095 ){    convert_spi_f = 4095;        }  //SATURA EM 12 BITS 2^12 - 1
    if ( convert_spi_f < 0 )   {    convert_spi_f = 0;           }  //SATURA EM 12 BITS 2^12 - 1
    convert_spi   = (Uint16)convert_spi_f;
    convert_spi   = convert_spi + 4096;
    if ( SpiaRegs.SPIFFTX.bit.TXFFST < 16 ) {       //Verifica que registrador de transmissão não esteja cheio
        // Data length = 16 Bits, << shift 0 bits
        SpiaRegs.SPITXBUF = convert_spi;
    }
    //CANAL B
    convert_spi_f = (*chB_data * gain_chB) + offset_chB;
    if ( convert_spi_f > 4095 ){    convert_spi_f = 4095;        }  //SATURA EM 12 BITS 2^12 - 1
    if ( convert_spi_f < 0 )   {    convert_spi_f = 0;           }  //SATURA EM 12 BITS 2^12 - 1
    convert_spi   = (Uint16)convert_spi_f;
    convert_spi   = convert_spi + 4096 + 32768;
    if ( SpiaRegs.SPIFFTX.bit.TXFFST < 16 ) {
        // Data length = 16 Bits, << shift 0 bits
        SpiaRegs.SPITXBUF = convert_spi;
    }
    FlagSpiTx = 1;      //Global variable
}

//______________________________
//----------SCI WRITE----------||
//_____________________________||

void f_flo_write_sci_tx_idle_line_split( float *data, float gain, float offset )
{
    //scale data
    //TRANSMISSÃO SCI SPLIT--> scale y=ax+b; a = 65535 / (in_max-in_min);  b= -xmin * a;
    Uint16 sci_dataA    = 0;
    float convert_sci_f = 0;

    convert_sci_f       = round( ( *data * gain ) + offset );//0.358521 + 143.5 );
    if ( convert_sci_f > 65534 )  {   convert_sci_f = 65534;    }
    if ( convert_sci_f < 0 )    {   convert_sci_f = 0;      }
    sci_dataA = (Uint16) convert_sci_f;

    while ( !SciaRegs.SCICTL2.bit.TXRDY )   {}
    SciaRegs.SCITXBUF           = ( sci_dataA >> 8 ) & 0x0FF;   //this is the data - MSB.
    while ( !SciaRegs.SCICTL2.bit.TXRDY )   {}
    SciaRegs.SCITXBUF           = sci_dataA & 0x0FF;            //this is the data - LSB.
    //SciaRegs.SCICTL1.bit.TXWAKE = 1;        //forces an 11 bit iddle (time separation between blocks) in iddle-line mode
    //SciaRegs.SCITXBUF           = sci_dataA;   //This is no-care data to force iddle
}


void f_flo_write_sci_tx_idle_line( float *data, float gain, float offset )
{
    //scale data
    //TRANSMISSÃO SCI--> scale y=ax+b; a = 255 / (in_max-in_min);  b= -xmin * a; a=0.40997, b=127.5;
    float convert_sci_f = 0;

    convert_sci_f       = round( ( *data * gain ) + offset );//0.358521 + 143.5 );
    if ( convert_sci_f > 254 )  {   convert_sci_f = 254;    }
    if ( convert_sci_f < 0 )    {   convert_sci_f = 0;      }

    SciaRegs.SCITXBUF           = (Uint16) convert_sci_f;   //this is the data.
    //SciaRegs.SCICTL1.bit.TXWAKE = 1;        //forces an 11 bit iddle (time separation between blocks) in iddle-line mode
    //SciaRegs.SCITXBUF           = sci_dataA;   //This is no-care data to force iddle
}

void f_chr_write_sci_tx_idle_line( char data )
{
    SciaRegs.SCITXBUF           = data;   //this is the data.
    SciaRegs.SCICTL1.bit.TXWAKE = 1;      //forces an 11 bit iddle (time separation between blocks) in iddle-line mode
    SciaRegs.SCITXBUF           = data;   //This is no-care data to force iddle
}


//______________________________
//-----LOAD_SCI_BUFFER_F-------||
//_____________________________||
void f_load_sci_buffer_f( float *buffer_tx_sci, float *data1, float *data2, float *data3, float *data4 )
{
    buffer_tx_sci[0] = *data1;
    buffer_tx_sci[1] = *data2;
    buffer_tx_sci[2] = *data3;
    buffer_tx_sci[3] = *data4;
}
