/*
 * Int_Interface.h
 *
 *  Created on: 5 Feb 2021
 *      Author: Kareem
 */

#ifndef INT_INTERFACE_H_
#define INT_INTERFACE_H_

#include "Std_Types.h"
#include "DIO_Int.h"
#include "DIO_Reg.h"
#include "avr/interrupt.h"

#define SREG  *((volatile u8*) 0x5F)
#define GICR  *((volatile u8*) 0x5B)
#define MCUCR *((volatile u8*) 0x55)

void Exti_Init (void);

#endif /* INT_INTERFACE_H_ */
