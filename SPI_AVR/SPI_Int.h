/*
 * SPI_Int.h
 *
 *  Created on: 20 Feb 2021
 *      Author: Kareem
 */

#ifndef SPI_INT_H_
#define SPI_INT_H_
#include "Std_Types.h"
#include "DIO_Int.h"
#include "DIO_Reg.h"

#define SPCR *((volatile u8*) 0x2D)
#define SPSR *((volatile u8*) 0x2E)
#define SPDR *((volatile u8*) 0x2F)

void SPI_InitMaster(void);
void SPI_InitSlave(void);
void SPI_SendByte(u8 data);
u8 SPI_ReceiveByte(void);


#endif /* SPI_INT_H_ */
