/*
 * init_blocks.c
 *
 *  Created on: 19 de jun de 2020
 *  Updated 10/09/2020 - rotinas de autocalibração do offset
 *      Author: Sebastián Manrique M
 */

void f_reset_offset_vbles( struct abc_x *input )
{
    input->a = 0;
    input->b = 0;
    input->c = 0;
}

void f_calc_avg_offset( struct abc_x *input, float Adc_res_1, float Adc_res_2, float Adc_res_3 )
{
    input->a = input->a + ( inv_N_cal_offset * Adc_res_1 );
    input->b = input->b + ( inv_N_cal_offset * Adc_res_2 );
    input->c = input->c + ( inv_N_cal_offset * Adc_res_3 );
}

void f_init_droop( struct droop *droop_vbles, float k, float y_nom )
{
    droop_vbles->k     = k;
    droop_vbles->y_nom = y_nom;
    droop_vbles->y     = y_nom;
}


void f_init_pi_controllers_be( struct pi_be *pi_ctrl, float kp, float ki, float y_pi, float y_integral )
{
    pi_ctrl->kp         = kp;
    pi_ctrl->ki         = ki;
    pi_ctrl->y_pi       = y_pi;
    pi_ctrl->y_integral = y_integral;
}

void f_init_pi_controllers_tust( struct pi_tust *pi_ctrl, float kp, float ki, float y_pi, float s_ant )
{   //Bilinear transf --> s = (2/Ts) * (1-Z^-1) / (1+Z^-1); PI(s) = (kp*s + ki) / (s)
    //PI --> b0 = kp + ( 0.5*Ts*Ki );       b1 = kp - ( 0.5*Ts*Ki );
    pi_ctrl->b0     = kp + ( 0.5*Ts_dsp*ki );
    pi_ctrl->b1     = kp - ( 0.5*Ts_dsp*ki );
    pi_ctrl->y_pi   = y_pi;
    pi_ctrl->s_ant  = s_ant;
}

void f_init_mav_two_vbles( struct mav_two *mav_f)
{
    //init mav_Vcfa
    mav_f->y_filt      = 0;
    int kk = 0;
    for( kk = 0 ; kk < 2 ; kk++){
        mav_f->buffer[kk] = 0;}
    mav_f->i         = 0;
}

void f_init_mav_four_vbles( struct mav_four *mav_f)
{
    //init mav_Vcfa
    mav_f->y_filt      = 0;
    int kk = 0;
    for( kk = 0 ; kk < 4 ; kk++){
        mav_f->buffer[kk] = 0;}
    mav_f->i         = 0;
}

void f_init_mav_five_vbles( struct mav_five *mav_f)
{
    //init mav_Vcfa
    mav_f->y_filt      = 0;
    int kk = 0;
    for( kk = 0 ; kk < 5 ; kk++){
        mav_f->buffer[kk] = 0;}
    mav_f->i         = 0;
}

void f_init_mav_eight_vbles( struct mav_eight *mav_f)
{
    //init mav_Vcfa
    mav_f->y_filt      = 0;
    int kk = 0;
    for( kk = 0 ; kk < 8 ; kk++){
        mav_f->buffer[kk] = 0;}
    mav_f->i         = 0;
}

void f_init_lpf_fo_filt_vbles( struct lpf_fo *lpf_fo, float wf )    //init lpf_fo
{   //Bilinear transf --> s = (2/Ts) * (1-Z^-1) / (1+Z^-1); lpf(s) = wf / (s + wf)
    //LPF_FO --> b0 = b1 = (wf*Ts) / (2 + wf*Ts);     a1 = (wf*Ts - 2) / (wf*Ts + 2)
    lpf_fo->a1    = ( wf * Ts_dsp - 2 ) / ( wf * Ts_dsp + 2 );
    lpf_fo->b01   = ( wf * Ts_dsp )     / ( wf * Ts_dsp + 2 );
    lpf_fo->s_ant = 0;
    lpf_fo->y_lpf = 0;
}

void f_init_satura_vbles( struct saturador *satura_Vcfa, float lower, float upper )
{
    satura_Vcfa->lower_limit  = lower;
    satura_Vcfa->upper_limit  = upper;
    satura_Vcfa->y_sat        = 0;
}


void f_init_v_teste_dyn( float *V_dyn_test_v, int pos_dyn_test_v )
{
    int kk = 0;
    for( kk = 0 ; kk < pos_dyn_test_v ; kk++){
        V_dyn_test_v[kk] = 0;}
}
