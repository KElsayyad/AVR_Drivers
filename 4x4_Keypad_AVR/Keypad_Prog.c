/*
 * Keypad_Prog.c
 *
 *  Created on: 30 Jan 2021
 *      Author: Kareem
 */

#include "Keypad_Int.h"

void KeyPad_Init (void)
{
	//OUTPUT
	Dio_SetPinDirection(GroupC, PIN0, OUTPUT);
	Dio_SetPinDirection(GroupC, PIN1, OUTPUT);
	Dio_SetPinDirection(GroupC, PIN2, OUTPUT);

	//INPUT
	Dio_SetPinDirection(GroupD, PIN0, INPUT);
	Dio_SetPinDirection(GroupD, PIN1, INPUT);
	Dio_SetPinDirection(GroupD, PIN2, INPUT);
	Dio_SetPinDirection(GroupD, PIN3, INPUT);

	//Set Internal Pull-Up
	Dio_SetPinValue(GroupD, PIN0, HIGH);
	Dio_SetPinValue(GroupD, PIN1, HIGH);
	Dio_SetPinValue(GroupD, PIN2, HIGH);
	Dio_SetPinValue(GroupD, PIN3, HIGH);
}
u8 Keypad_GetKey (void)
{
	u8 Keypad_Val=0xff;

	//Iteration 1
	Dio_SetPinValue(GroupC, PIN0,  LOW);
	Dio_SetPinValue(GroupC, PIN1, HIGH);
	Dio_SetPinValue(GroupC, PIN2, HIGH);
	if (Dio_GetPinValue(GroupD, PIN0) == LOW)
		Keypad_Val = 1;
	if (Dio_GetPinValue(GroupD, PIN1) == LOW)
		Keypad_Val = 4;
	if (Dio_GetPinValue(GroupD, PIN2) == LOW)
		Keypad_Val = 7;
	if (Dio_GetPinValue(GroupD, PIN3) == LOW)
		Keypad_Val = '*';

	//Iteration 2
	Dio_SetPinValue(GroupC, PIN0, HIGH);
	Dio_SetPinValue(GroupC, PIN1,  LOW);
	Dio_SetPinValue(GroupC, PIN2, HIGH);
	if (Dio_GetPinValue(GroupD, PIN0) == LOW)
		Keypad_Val = 2;
	if (Dio_GetPinValue(GroupD, PIN1) == LOW)
		Keypad_Val = 5;
	if (Dio_GetPinValue(GroupD, PIN2) == LOW)
		Keypad_Val = 8;
	if (Dio_GetPinValue(GroupD, PIN3) == LOW)
		Keypad_Val = 0;

	//Iteration 3
	Dio_SetPinValue(GroupC, PIN0, HIGH);
	Dio_SetPinValue(GroupC, PIN1, HIGH);
	Dio_SetPinValue(GroupC, PIN2,  LOW);
	if (Dio_GetPinValue(GroupD, PIN0) == LOW)
		Keypad_Val = 3;
	if (Dio_GetPinValue(GroupD, PIN1) == LOW)
		Keypad_Val = 6;
	if (Dio_GetPinValue(GroupD, PIN2) == LOW)
		Keypad_Val = 9;
	if (Dio_GetPinValue(GroupD, PIN3) == LOW)
		Keypad_Val = '#';

	return Keypad_Val;
}
