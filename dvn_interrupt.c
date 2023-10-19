#include "dvn_interrupt.h"
#include "dvn_gpio.h"
/*
	MOI KHI XAY RA NGAT O LINE0 , LINE1 ,LINE2 THI NO SE NHAY VAO CAC HAM : 
	ISR(INT0_vect){}
	ISR(INT1_vect){}
	ISR(INT2_vect){}
	KHAI BAO CAC HAM NAY TRONG HAM MAIN DE SU DUNG -> 5TING
*/


void dvn_interrupt_gpio(enum dvn_interrupt_gpio _INT ,enum dvn_interrupt_type _INT_TYPE ){
	switch(_INT){
		case INT_0: 
			GICR |= (1<<6);
			switch(_INT_TYPE){
				case INT_FALLING: 
					MCUCR &= ~(3);
					MCUCR |= (1<<1);
					break;
				case INT_RISING:
					MCUCR |= (3);
					break;
				default : 
					break;
			}
			break ;
		case INT_1:
		GICR |= (1<<7);
		switch(_INT_TYPE){
			case INT_FALLING:
				MCUCR &= ~(3<<2);
				MCUCR |= (1<<3);
				break;
			case INT_RISING:
				MCUCR |= (3<<2);
				break;
			default :
				break;
		}
			break ;
		case INT_2:
			GICR |= (1<<5);
			switch(_INT_TYPE){
				case INT_FALLING:
					MCUCSR &= ~(1<<6);
					break;
				case INT_RISING:
					MCUCSR |= (1<<6);
					break;
				default:
					break;
			}
		default :
			break;	
	};
		
	sei();
	
};