/*
 * main.c
 *
 *  Created on: 30 Jan 2021
 *      Author: Kareem
 */

#include "Keypad_Int.h"

void main (void)
{
u8 Num ;
KeyPad_Init();
DDRA = 0xFF;

	while (1)
	{
		Num=Keypad_GetKey();
		if( Num!=0xff)
			PORTA = Num;

	}
}
