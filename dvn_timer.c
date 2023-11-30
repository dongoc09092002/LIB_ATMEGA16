#include "dvn_timer.h"
#include <stdint.h>
uint32_t time = 0;
ISR(TIMER0_OVF_vect){
	TCNT0 = 130;
	time ++ ;
}	
ISR(TIMER2_OVF_vect){
	TCNT2 = 130;
	time ++ ;
}
void dvn_timer_normal_enable(enum dvn_timer_number _TIMER_NUMBER , enum dvn_timer_tick  _TIMER_TICK){
	switch(_TIMER_NUMBER){
		case TIMER_0: 
				TCCR0 &= ~(1<<3);
				TCCR0 &= ~(1<<6);
				TCCR0 &= ~(7);
				if(_TIMER_TICK == TIMER_MS){
					//PRESCALER = 64
					TCCR0 |= (3);
					TCNT0 = 130;
					TIMSK |= (1<<0);
					sei();
				}
				if(_TIMER_TICK == TIMER_US){
					//PRESCALER = 8
					TCCR0 |= (1<<1);
					TCNT0 = 0;
				}
			break;
		case TIMER_2: 
				TCCR2 &= ~(1<<3);
				TCCR2 &= ~(1<<6);
				TCCR2 &= ~(7);
				if(_TIMER_TICK == TIMER_MS){
					//PRESCALER = 64
					TCCR2 |= (3);
					TCNT2 = 130;
					TIMSK |= (1<<6);
					sei();
				}
				if(_TIMER_TICK == TIMER_US){
					//PRESCALER = 8
					TCCR2 |= (1<<1);
					TCNT2 = 0;
				}
			break;
		default:
			break;	
	};	
};

void dvn_timer_pwm_enable(enum dvn_timer_number _TIMER_NUMBER , uint8_t percent){
	uint8_t data_pwm = (uint8_t)((255*percent)/100);
	switch(_TIMER_NUMBER){
		case TIMER_0:
			DDRB |= (1<<3);
			TCNT0 = 0;
			TCCR0 |= (1<<3);
			TCCR0 |= (1<<6);
			TCCR0 &= ~(7);
			TCCR0 |= (1<<1);
			TCCR0 &= ~(3<<4);
			TCCR0 |= (1<<5);
			OCR0 = data_pwm;
			break;
		case TIMER_2:
			DDRD |= (1<<7);
			TCNT2 = 0;
			TCCR2 |= (1<<3);
			TCCR2 |= (1<<6);
			TCCR2 &= ~(7);
			TCCR2 |= (1<<1);
			TCCR2 &= ~(3<<4);
			TCCR2 |= (1<<5);
			OCR2 = data_pwm;
			break;
		default:
			break;
		};
	
}

void dvn_timer_normal_disable(enum dvn_timer_number _TIMER_NUMBER){
	switch(_TIMER_NUMBER){
		case TIMER_0: 
			 TCCR0 = 0;
		break;
		case TIMER_2:
			 TCCR2 = 0;
		break;
		default:
		break;	
	};
}

void dvn_timer_delay_ms(enum dvn_timer_number _TIMER_NUMBER,uint32_t ms){
	switch(_TIMER_NUMBER){
		case TIMER_0:	
			dvn_timer_normal_enable(TIMER_0,TIMER_MS) ;
			while(ms > time);
			time = 0 ;
			dvn_timer_normal_disable(TIMER_0);
			break;
		case TIMER_2:
			dvn_timer_normal_enable(TIMER_2,TIMER_MS) ;
			while(ms > time);
			time = 0 ;
			dvn_timer_normal_disable(TIMER_2);
		default:
			break;
	};
	
}

void dvn_timer_delay_us(enum dvn_timer_number _TIMER_NUMBER,uint8_t us){
	switch(_TIMER_NUMBER){
		case TIMER_0:
			dvn_timer_normal_enable(TIMER_0,TIMER_US);
			while(TCNT0 < us);
			TCNT0 = 0 ;
			dvn_timer_normal_disable(TIMER_0);	
			break;
		case TIMER_2:
			dvn_timer_normal_enable(TIMER_2,TIMER_US);
			while(TCNT2 < us);
			TCNT2 = 0 ;
			dvn_timer_normal_disable(TIMER_2);
			break;
		default:
			break;
	};
	
}

void dvn_timer_start_count(){
	//CHOOSE MODE
	TCCR1A |= (1<<7);
	TCCR1A |= (1<<5);
	TCCR1A &= ~(1<<6);
	TCCR1A &= ~(1<<4);
	TCCR1B &= ~(1<<4);
	TCCR1B &= ~(1<<3);
	TCCR1A &= ~(1<<1);
	TCCR1A &= ~(1<<0);
	//PRESCALE = 8
	TCCR1B &= ~(1<<0);
	TCCR1B |= (1<<1);
	TCCR1B &= ~(1<<2);
	//START
	TCNT1 = 0;
}
void dvn_timer_stop_count(){
	 TCCR1B &= ~(1 << CS10);  // XOA CS10 (PRESCALER = 0, DUNG TIMER)
	 TCCR1B &= ~(1 << CS11);  // XOA CS11
	 TCCR1B &= ~(1 << CS12);  // XOA CS12
	 TCNT1 = 0;
}
uint16_t dvn_timer_get_count(){
	return TCNT1;
}

