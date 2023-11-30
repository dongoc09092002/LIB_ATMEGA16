#ifndef DVN_INTERRUPT_H
#define DVN_INTERRUPT_H
#include "avr/interrupt.h"
/*
	MOI KHI XAY RA NGAT O LINE0 , LINE1 ,LINE2 THI NO SE NHAY VAO CAC HAM : 
	ISR(INT0_vect){}
	ISR(INT1_vect){}
	ISR(INT2_vect){}
	KHAI BAO CAC HAM NAY TRONG HAM MAIN DE SU DUNG -> 5TING
*/
enum dvn_interrupt_gpio{
	INT_0,
	INT_1,
	INT_2
};
enum dvn_interrupt_type{
	INT_FALLING,
	INT_RISING,
};

//BAT NGAT NGOAI UNG VOI CAC CHAN NGAT DUOC DINH NGHIA SAN TRONG CHIP
/*
	INT_0 :  PD2
	INT_1 :  PD3
	INT_2 :  PB2
*/
void dvn_interrupt_gpio(enum dvn_interrupt_gpio _INT ,enum dvn_interrupt_type _INT_TYPE );


#endif