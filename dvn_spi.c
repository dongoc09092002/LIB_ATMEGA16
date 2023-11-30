#include "dvn_spi.h"
ISR(SPI_STC_vect){
	dvn_spi_receive();
}

void dvn_spi_master_init(){
	//SETUP SPI
	DDRB |=	(1<<SCK_PIN) | (1<<MOSI_PIN) | (1<<SS_PIN);
	SPCR |= (1<<SPE) | (1<<MSTR) | (1<<SPR0) | (1<<CPHA);
	//XET CHAN SS LEN MUC CAO	
	dvn_gpio_write_pin(GPIOB,SS_PIN,1);
}

void dvn_spi_slave_init(){
	//SETUP SPI
	DDRB = (1<<MISO_PIN);
	SPCR |= (1<<SPIE) | (1<<SPE) | (1<<MSTR);
	//SPIE : BAT SPI INTERUPT
	//SPE : ENABLE SPI
	//dvn_gpio_write_pin(GPIOB,SS_PIN,1);
	sei();
}
//GUI DU LIEU
void dvn_spi_transmit( uint8_t data){
	dvn_gpio_write_pin(GPIOB,SS_PIN,0);
	SPDR = data;
	while(bit_is_clear(SPSR,SPIF));
	_delay_ms(10);
	dvn_gpio_write_pin(GPIOB,SS_PIN,1);
}


