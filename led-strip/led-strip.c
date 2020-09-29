/*
 * @file led-strip.c
 * @brief avr-gcc example
 *
 * @author Pawel Sobótka
 * @license GNU GPLv3
 * @copyright (C)2020 Pawel Sobótka, all rights reserved
 * @date 2020-09-29
 *
 */
#include <avr/io.h>
#include <util/delay.h>

#define PORT_LED 	PORTB
#define PORT_LED_DDR	DDRB


void toggle_LED(int n)
{	
	if ( n != 7){
		PORT_LED ^= _BV(n);
		_delay_ms(125);
		PORT_LED ^= _BV(n+1);
	       _delay_ms(125);
	} else {
		PORT_LED &= ~_BV(n);
		_delay_ms(125);
	}	
}

int main(void)
{
	PORT_LED = 0x00;
	PORT_LED_DDR = 0xFF;
	int i;

	while(1)
	{
		PORT_LED |= _BV(0);
		_delay_ms(500);

		for(i = 0; i < 7; i++)
		{
			toggle_LED(i);
			_delay_ms(500);
		}
	}

	return 0;
}
