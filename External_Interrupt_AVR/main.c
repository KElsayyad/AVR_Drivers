/*
 * main.c
 *
 *  Created on: 5 Feb 2021
 *      Author: Kareem
 */

#include "Int_Interface.h"
#include "avr/delay.h"
void main (void)
{
	Exti_Init();
	while (1)
	{
		TOG_BIT(PORTD, PIN3);
		_delay_ms(1000);
	}
}
