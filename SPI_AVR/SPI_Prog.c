/*
 * SPI_Prog.c
 *
 *  Created on: 20 Feb 2021
 *      Author: Kareem
 */
#include "SPI_Int.h"
void SPI_InitMaster(void)
{
	//SS PIN
	Dio_SetPinDirection(GroupB, 4, OUTPUT);
	//MOSI PIN
	Dio_SetPinDirection(GroupB, 5, OUTPUT);
	//MISO PIN
	Dio_SetPinDirection(GroupB, 6, INPUT);
	//SCK PIN
	Dio_SetPinDirection(GroupB, 7, OUTPUT);

	//Master mode
	SET_BIT(SPCR, 4);
	//Enable SPI
	SET_BIT(SPCR, 6);
	//Set clock rate to fso/4
	CLR_BIT(SPCR, 0);
	CLR_BIT(SPCR, 1);
	CLR_BIT(SPSR, 0);

}
void SPI_InitSlave(void)
{
	//SS PIN
	Dio_SetPinDirection(GroupB, 4, INPUT);
	//MOSI PIN
	Dio_SetPinDirection(GroupB, 5, INPUT);
	//MISO PIN
	Dio_SetPinDirection(GroupB, 6, OUTPUT);
	//SCK PIN
	Dio_SetPinDirection(GroupB, 7, INPUT);

	//Slave mode
	CLR_BIT(SPCR, 4);
	//Enable SPI
	SET_BIT(SPCR, 6);
}
void SPI_SendByte(u8 data)
{
	SPDR = data;
	while (GET_BIT(SPSR, 7) == 0);
}
u8 SPI_ReceiveByte(void)
{
	u8 data;
	while (GET_BIT(SPSR, 7) == 0);
	data = SPDR;
	return (data);

}
