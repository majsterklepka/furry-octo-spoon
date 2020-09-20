/*
 * @file blink-led.c
 * @brief avr-gcc example blinking led
 * 
 * @date 2020-09-19
 * @license GNU GPLv3
 * @author Paweł Sobótka
 *
 */

#ifndef F_CPU
#define F_CPU 4000000L
#endif

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRB = 0b00000001;

	while(1)
	{
		PORTB = 0b00000001;
		_delay_ms(1000);
		PORTB = 0b00000000;
		_delay_ms(1000);
	}

	return 0;
}
