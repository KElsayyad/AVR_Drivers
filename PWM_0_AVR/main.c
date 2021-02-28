/*
 * main.c
 *
 *  Created on: 13 Feb 2021
 *      Author: Kareem
 */

#include "Timer_Counter_Int.h"
#include "Std_Types.h"
#include "util/delay.h"

void main (void)
{
Timer_Counter_Init();
	while(1)
	{
		PWM_Write(50);
		_delay_ms(3000);
		PWM_Write(200);
		_delay_ms(3000);
	}
}
