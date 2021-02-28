/*
 * UART_Int.h
 *
 *  Created on: 19 Feb 2021
 *      Author: Kareem
 */

#ifndef UART_INT_H_
#define UART_INT_H_

#include "Std_Types.h"

#define UDR     *((volatile u8*) 0x2C)
#define UCSRA   *((volatile u8*) 0x2B)
#define UCSRB   *((volatile u8*) 0x2A)
#define UCSRC   *((volatile u8*) 0x40)
#define UBRRL   *((volatile u8*) 0x29)
#define UBRRH   *((volatile u8*) 0x40)

void UART_Init(void);
void UART_Send(u8 data);
u8 UART_Receive (void);

#endif /* UART_INT_H_ */
