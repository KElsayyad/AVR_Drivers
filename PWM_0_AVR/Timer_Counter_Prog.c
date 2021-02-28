/*
 * Timer_Counter_Prog.c
 *
 *  Created on: Nov 20, 2020
 *      Author: Mohamed
 */

#include "Timer_Counter_Int.h"
#include "Std_Types.h"
#include "Utilities.h"
#include "Dio_Reg.h"
#include "Dio_Int.h"

void Timer_Counter_Init(void)
{
	Dio_SetPinDirection(GroupB, PIN3, OUTPUT);
	//set PWM mode to fast PWM
	SET_BIT(TCCR0, 3);
	SET_BIT(TCCR0, 6);
	//non inverted PWM
	SET_BIT(TCCR0, 4);
	SET_BIT(TCCR0, 5);
	//configure the timer prescaler
	CLR_BIT(TCCR0, 0);
	SET_BIT(TCCR0, 1);
	CLR_BIT(TCCR0, 2);
}

void PWM_Write (u8 PWM_Value)
{
	OCR0 = PWM_Value;
}
