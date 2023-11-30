#include "dvn_adc.h"
void dvn_adc_enable(enum dvn_adc_port _ADC_PORT){
	//to reset 2 bit 6,7 in ADMUX
	ADMUX &= ~(3<<6);
	//choose mode 01 with AVCC
	ADMUX |= (1<<6);
	switch(_ADC_PORT){
		case ADC_0:
			//choose ADC_0
			ADMUX &= ~(31);
			break;
		case ADC_1:
			//choose ADC_1
			ADMUX &= ~(31);
			ADMUX |= (1<<0);
			break;
		case ADC_2:
			//choose ADC_1
			ADMUX &= ~(31);
			ADMUX |= (1<<1);
			break;
		case ADC_3:
			//choose ADC_1
			ADMUX &= ~(31);
			ADMUX |= (3<<0);
			break;
		case ADC_4:
			//choose ADC_1
			ADMUX &= ~(31);
			ADMUX |= (1<<2);
			break;
		case ADC_5:
			//choose ADC_1
			ADMUX &= ~(31);
			ADMUX |= (1<<2);
			ADMUX |= (1<<0);
			break;
		case ADC_6:
			//choose ADC_1
			ADMUX &= ~(31);
			ADMUX |= (3<<1);
			break;
		case ADC_7:
			//choose ADC_1
			ADMUX &= ~(31);
			ADMUX |= (7<<0);
			break;
		default : 
			break;
	};	
	//Division Factor = 8
	ADCSRA &= (7);
	ADCSRA |= (3);
	//enable ADC
	ADCSRA |= (1<<7);
	//Start convert
	ADCSRA |= (1<<6);
};

uint16_t dvn_adc_read_data(enum dvn_adc_port _ADC_PORT){
	dvn_adc_enable(_ADC_PORT);
	while((ADCSRA & (1<<ADIF)) == 0);
	return ADCW;
};