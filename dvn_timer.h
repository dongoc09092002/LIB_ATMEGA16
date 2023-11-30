#ifndef DVN_TIMER_H
#define DVN_TIMER_H
#include "avr/interrupt.h"
/*
	KIEU TIMER_NORMAL : DUNG DE SU DUNG HAM DELAY_MS VA DELAY_US
	{
		HAM dvn_timer_delay_us : DOI SO TRUYEN VAO 0 < US < 200
	}
*/
//------------------------------------------CAC DOI TUONG STRUCT-------------------------------------------------------
//CAC MODE CUA TIMER
enum dvn_timer_mode{
	TIMER_NORMAL,
	TIMER_PWM	
};
//CAC TIMER
enum dvn_timer_number{
	TIMER_0,   // 8  bits 
	//TIMER_1,      16 bits => DUNG DE TINH THOI GIAN => KHONG SU DUNG
	TIMER_2,   // 8  bits
};

enum dvn_timer_tick{
	TIMER_MS,
	TIMER_US,	
};

//----------------------------------------------CAC HAM XU LY DU LIEU--------------------------------------------------
void dvn_timer_normal_enable(enum dvn_timer_number _TIMER_NUMBER,enum dvn_timer_tick  _TIMER_TICK);

void dvn_timer_pwm_enable(enum dvn_timer_number _TIMER_NUMBER , uint8_t percent);

void dvn_timer_normal_disable(enum dvn_timer_number _TIMER_NUMBER);

void dvn_timer_delay_ms(enum dvn_timer_number _TIMER_NUMBER,uint32_t ms);

void dvn_timer_delay_us(enum dvn_timer_number _TIMER_NUMBER,uint8_t us);

void dvn_timer_start_count();
void dvn_timer_stop_count();
uint16_t dvn_timer_get_count();
#endif
