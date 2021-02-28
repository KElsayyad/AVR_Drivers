/*
 * ADC_Prog.c
 *
 *  Created on: 6 Feb 2021
 *      Author: Kareem
 */

#include "ADC_Int.h"
#include "util/delay.h"


void ADC_Init (void)
{
	//volt REF selection, right adjust, channel adjust
	ADMUX = 0b01000001;
	//enable ADC
	SET_BIT(ADCSRA,7);
	//ADC prescaler selection
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	CLR_BIT(ADCSRA,2);
}
u16 Analog_Read (void)
{
	//u16 reading;
	u16 readingLOW;
	u16 readingHigh;
	//start conversion
	SET_BIT(ADCSRA,6);

	//wait for conversion
	while (GET_BIT(ADCSRA,4) == 0);
	_delay_ms(10);

	//clear interrupt flag
	SET_BIT(ADCSRA,4);

	//return ADC counter value
	readingLOW = (u16)ADCL;
	readingHigh = (u16)(ADCH<<8);
	return (readingLOW | readingHigh);

	/*if (GET_BIT(ADCH,0) == 0)
		CLR_BIT(reading,9);
		else SET_BIT(reading,9);
	if (GET_BIT(ADCH,1) == 0)
		CLR_BIT(reading,10);
		else SET_BIT(reading,10);
	return (reading);*/
}

s32 Analog_Value (void)
{
u32 ADC_Read = 0;
u32 Analog_Val = 0;
ADC_Read = Analog_Read();
Analog_Val = ((ADC_Read *5*1000)/1023); //give in mV
return (Analog_Val);
}

u8 map(u32 x, u16 in_min, u16 in_max, u16 out_min, u16 out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

