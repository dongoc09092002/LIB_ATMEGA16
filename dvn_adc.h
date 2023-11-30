#ifndef DVN_ADC_H
#define DVN_ADC_H
#include <avr/io.h>
#include <stdint.h>
enum dvn_adc_port{
	ADC_0,
	ADC_1,
	ADC_2,
	ADC_3,
	ADC_4,
	ADC_5,
	ADC_6,
	ADC_7
};
void dvn_adc_enable(enum dvn_adc_port _ADC_PORT);
uint16_t dvn_adc_read_data(enum dvn_adc_port _ADC_PORT);
#endif