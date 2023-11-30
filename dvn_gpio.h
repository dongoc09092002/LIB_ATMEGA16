#ifndef DVN_GPIO_H
#define DVN_GPIO_H
#include <avr/io.h>
#include <stdint.h>
//MOT KIEU DU LIEU DVN_GPIO_PORT : 4 PORT LA : PORTA,PORTB,PORTC,PORTD
enum dvn_gpio_port{
	GPIOA ,
	GPIOB ,
	GPIOC ,
	GPIOD
};
//MOT KIEU DU LIEU DVN_GPIO_PIN
enum dvn_gpio_pin{
	PIN_0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7	
};
//HAM DE SET CHAN LA CHE DO OUTPUT
void dvn_gpio_output(enum dvn_gpio_port _GPIO ,enum dvn_gpio_pin _PIN);

//HAM DE SET CHAN LA CHE DO INPUT
void dvn_gpio_input(enum dvn_gpio_port _GPIO ,enum dvn_gpio_pin _PIN);

//HAM DE SET CHAN LEN 1(5V) HOAC XUONG 0(0V)
void dvn_gpio_write_pin(enum dvn_gpio_port _GPIO, enum dvn_gpio_pin _PIN , uint8_t state_pin);

//HAM DE DOC GIA TRI CHAN DANG LA 1 HAY LA 0
uint8_t dvn_gpio_read_pin(enum dvn_gpio_port _GPIO, enum dvn_gpio_pin _PIN);

//HAM DE DOI CHIEU GIA TRI CUA CHAN : 0 THI SANG 1 CON 1 THI XUONG 0
void dvn_gpio_toggle_pin(enum dvn_gpio_port _GPIO ,enum dvn_gpio_pin _PIN);

#endif