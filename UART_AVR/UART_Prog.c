/*
 * UART_Prog.c
 *
 *  Created on: 19 Feb 2021
 *      Author: Kareem
 */

#include "UART_Int.h"
#include "Utilities.h"

void UART_Init(void)
{
	//write on UCSRC
	SET_BIT(UCSRC, 7);
	//enable Tx,Rx
	SET_BIT(UCSRB, 3);
	SET_BIT(UCSRB, 4);
	//set to asynchronous
	CLR_BIT(UCSRC, 6);
	//no parity
	CLR_BIT(UCSRC, 4);
	CLR_BIT(UCSRC, 5);
	//1 stop bit
	CLR_BIT(UCSRC, 3);
	//data set to 8 bits
	SET_BIT(UCSRC, 1);
	SET_BIT(UCSRC, 2);
	CLR_BIT(UCSRB, 2);
	//set baud rate 9600
	UBRRL = 103;
}
void UART_Send(u8 data)
{
	while (GET_BIT(UCSRA, 5) == 0);
		UDR = data;
}
u8 UART_Receive (void)
{
	u8 data;

	while (GET_BIT(UCSRA, 7) == 0);
		data = UDR;
	return (data);
}
