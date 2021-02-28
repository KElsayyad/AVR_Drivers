/*
 * Int_Prog.c
 *
 *  Created on: 5 Feb 2021
 *      Author: Kareem
 */
#include "Int_Interface.h"

void Exti_Init (void)
{
	// set GIE pin global interrupt enable
	SET_BIT(SREG, 7);
	//set PIE pin
	SET_BIT(GICR, 6);
	//config interrupt mode
	MCUCR = 0b00000011; //rising edge

}

ISR (INT0_vect)
{
	Dio_SetPinValue(PORTD, PIN2, HIGH);
	Dio_SetPinDirection(GroupD, PIN3, OUTPUT);
	TOG_BIT(PORTD, PIN3);
}

