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

/*
 * F_CPU == 4000000 Hz
 * CKDIV8=1
 * delay = delay/8;
 * real F_CPU = 500000 Hz
 *
 */


int main(void)
{
	DDRB |= (1 << DDB0);

	while(1)
	{
		PORTB |= (1 << PB0);
		_delay_ms(125);
		PORTB &= ~(1 << PB0);
		_delay_ms(125);
	}

	return 0;
}
