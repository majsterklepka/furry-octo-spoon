/*
 * @file blink-led.c
 * @brief avr-gcc example blinking led
 * 
 * @date 2020-12-04
 * @license GNU GPLv3
 * @author Paweł Sobótka
 *
 */

#ifndef F_CPU
#define F_CPU 1000000L
#endif

#include <avr/io.h>
#include <util/delay.h>

/*
 * F_CPU      = 8000000 Hz
 * CKDIV8     = 1
 * real F_CPU = 1000000 Hz
 *
 */


int main(void)
{
	DDRB |= _BV(DDB0);

	while(1)
	{
		PORTB |= _BV(0);
		_delay_ms(500);
		PORTB &= ~_BV(0);
		_delay_ms(500);
	}

	return 0;
}
