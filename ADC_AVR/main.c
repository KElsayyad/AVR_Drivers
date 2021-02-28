/*
 * main.c
 *
 *  Created on: 6 Feb 2021
 *      Author: Kareem
 */
#include "ADC_Int.h"

void main (void)
{
	Dio_SetPinDirection(GroupC,2,OUTPUT);
	Dio_SetPinDirection(GroupC,7,OUTPUT);
	PORTC=0x00;
	ADC_Init();
	s32 Analog_Val;
	while(1)
	{
		Analog_Val = Analog_Value();

		if (Analog_Val<1500)
		{
			Dio_SetPinValue(GroupC,2,HIGH);
			Dio_SetPinValue(GroupC,7, LOW);
		}
		else if (Analog_Val>1500)
		{
			Dio_SetPinValue(GroupC,2, LOW);
			Dio_SetPinValue(GroupC,7,HIGH);
		}
		else
			PORTB = 0x00;

	}
}
