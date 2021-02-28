/*
 * main.c
 *
 *  Created on: 16 Feb 2021
 *      Author: Kareem
 */

#include "UART_Int.h"

void main(void)
{
		u8 x;
		UART_Init();
	while(1)
	{
		x=UART_Receive();
		UART_Send(x);
	}
}
