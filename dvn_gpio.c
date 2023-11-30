#include "dvn_gpio.h"

void dvn_gpio_output(enum dvn_gpio_port _GPIO ,enum dvn_gpio_pin _PIN){
	switch( _GPIO ){
		case GPIOA:
			DDRA |= (1 << _PIN);
			break;
		case GPIOB:
			DDRB |= (1 << _PIN);
			break;
		case GPIOC:
			DDRC |= (1 << _PIN);
			break;
		case GPIOD:
			DDRD |= (1 << _PIN);
			break;
		default :
			break;
	}	
};
void dvn_gpio_input(enum dvn_gpio_port _GPIO ,enum dvn_gpio_pin _PIN){
	switch( _GPIO ){
		case GPIOA:
		DDRA &= ~(1 << _PIN);
		break;
		case GPIOB:
		DDRB &= ~(1 << _PIN);
		break;
		case GPIOC:
		DDRC &= ~(1 << _PIN);
		break;
		case GPIOD:
		DDRD &= ~(1 << _PIN);
		break;
		default :
		break;
	}
};
void dvn_gpio_write_pin(enum dvn_gpio_port _GPIO, enum dvn_gpio_pin _PIN , uint8_t state_pin){
	switch( _GPIO ){
		case GPIOA:
			if(state_pin == 0){
				PORTA &= ~(1<<_PIN);
			}
			else{
				PORTA |= (1<<_PIN);
			}
		break;
		case GPIOB:
			if(state_pin == 0){
				PORTB &= ~(1<<_PIN);
			}
			else{
				PORTB |= (1<<_PIN);
			}
		break;
		case GPIOC:
			if(state_pin == 0){
				PORTC &= ~(1<<_PIN);
			}
			else{
				PORTC |= (1<<_PIN);
			}
		break;
		case GPIOD:
			if(state_pin == 0){
				PORTD &= ~(1<<_PIN);
			}
			else{
				PORTD |= (1<<_PIN);
			}
		break;
		default :
		break;
	}
		
};
uint8_t dvn_gpio_read_pin(enum dvn_gpio_port _GPIO, enum dvn_gpio_pin _PIN){
	
	switch(_GPIO){
		case GPIOA:
		if( (PINA & (1<<_PIN)) == 0){
			return 0;
		}
		else {
			return 1;
		}
		break;
		case GPIOB:
		if( (PINB & (1<<_PIN)) == 0){
			return 0;
		}
		else {
			return 1;
		}
		break;
		case GPIOC:
		if( (PINC & (1<<_PIN)) == 0){
			return 0;
		}
		else {
			return 1;
		}
		break;
		case GPIOD:
		if( (PIND & (1<<_PIN)) == 0){
			return 0;
		}
		else {
			return 1;
		}
		break;
		default :
		break;
	}
	return 0;
};

void dvn_gpio_toggle_pin(enum dvn_gpio_port _GPIO ,enum dvn_gpio_pin _PIN){
	if(dvn_gpio_read_pin(_GPIO,_PIN) == 0){
		dvn_gpio_write_pin(_GPIO,_PIN,1);
	}
	else{
		dvn_gpio_write_pin(_GPIO,_PIN,0);
	}
};