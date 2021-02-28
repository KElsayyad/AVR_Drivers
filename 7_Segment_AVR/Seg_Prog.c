/*
 * 7Seg_Prog.c
 *
 *  Created on: 31 Jan 2021
 *      Author: Kareem
 */

#include "Seg_Int.h"
#define delay_time 10


void Seg_Init (void)
{
	//Data lines
	Dio_SetPinDirection(GroupA, PIN4, OUTPUT);
	Dio_SetPinDirection(GroupA, PIN5, OUTPUT);
	Dio_SetPinDirection(GroupA, PIN6, OUTPUT);
	Dio_SetPinDirection(GroupA, PIN7, OUTPUT);

	//Transistors
	Dio_SetPinDirection(GroupB, PIN1, INPUT);
	Dio_SetPinDirection(GroupB, PIN2, INPUT);
}

void Seg_WriteNum (u8 Number)
{
if (Number == 0)
	PORTA = 0x00;
if (Number == 1)
	PORTA = 0x10;
if (Number == 2)
	PORTA = 0x20;
if (Number == 3)
	PORTA = 0x30;
if (Number == 4)
	PORTA = 0x40;
if (Number == 5)
	PORTA = 0x50;
if (Number == 6)
	PORTA = 0x60;
if (Number == 7)
	PORTA = 0x70;
if (Number == 8)
	PORTA = 0x80;
if (Number == 9)
	PORTA = 0x90;
}

void Seg_Count (u8 Max_Count)
{
	u8 counter, i;

	for (counter = 0; counter <= Max_Count; counter++)
	{
		for (i = 0; i<=50; i++)
		{
		Seg_WriteNum(counter%10);
		Dio_SetPinValue(GroupB, PIN1, HIGH);
		_delay_ms(delay_time);
		Dio_SetPinValue(GroupB, PIN1,  LOW);

		Seg_WriteNum(counter/10);
		Dio_SetPinValue(GroupB, PIN2, HIGH);
		_delay_ms(delay_time);
		Dio_SetPinValue(GroupB, PIN2,  LOW);
		}
	}
}
