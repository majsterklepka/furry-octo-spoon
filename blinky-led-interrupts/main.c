/*!
 * @file main.c
 * @brief blinky led with timers and interrupts
 *
 * @author Pawel Sobotka
 * @date 2021-03-23
 * @license GNU GPLv3
 * @copyright (C)2021 Pawel Sobotka, all rights reserved
 *
 */

#ifndef F_CPU
#define F_CPU 	1000000UL
#endif

#define LED_PIN	PB0

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <stdlib.h>
#include <stdio.h>

const uint16_t  EEMEM time1 = 0xF7;

const uint16_t EEMEM time2 = 0xC2;

int time_low;
int time_high;


ISR(TIMER1_OVF_vect)
{
	PORTB ^= (1 << LED_PIN);
	TCNT1L = time_low;
	TCNT1H = time_high;
}


int main(void)
{
	time_low = 0;
	time_high = 0;

	DDRB |= (0x01 << LED_PIN);
	PORTB |= (0 << LED_PIN);
	time_low = eeprom_read_word(&time1);
	time_high = eeprom_read_word(&time2);
	TCNT1L = time_low;
	TCNT1H = time_high;
	TCCR1B |= (0 << CS12 ) | ( 1 << CS11 ) | ( 1 << CS10);
	TIMSK |= (1 << TOIE1);
	sei();

	while(1)
	{

	}


	return 0;

}
