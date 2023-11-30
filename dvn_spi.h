#ifndef DVN_SPI_H
#define DVN_SPI_H
#include "dvn_gpio.h"
#include "avr/delay.h"
#include "avr/interrupt.h"
#define SCK_PIN     PIN_7
#define MISO_PIN	PIN_6
#define MOSI_PIN    PIN_5
#define SS_PIN	    PIN_4

void dvn_spi_master_init();
void dvn_spi_slave_init();
void dvn_spi_transmit(uint8_t data);
void dvn_spi_receive();
#endif
