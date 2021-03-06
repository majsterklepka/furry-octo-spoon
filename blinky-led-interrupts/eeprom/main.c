/*!
 * @file main.c
 * @brief eeprom code for AVR
 *
 * @author Pawel Sobotka
 * @license GNU GPLv3
 * @copyright (c)2021 Pawel Sobotka, all rights reserved
 *
 * @date 2021-04-24
 *
 *
 */



#ifndef F_CPU
#define F_CPU 	1000000UL
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <stdlib.h>
#include <stdio.h>

const uint16_t EEMEM time1 = 0xD7;

const uint16_t EEMEM time2 = 0xF6;


int main()
{

	return 0;

}
