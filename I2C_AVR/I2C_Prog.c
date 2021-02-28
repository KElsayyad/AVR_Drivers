/*
 * I2C_Prog.c
 *
 *  Created on: 26 Feb 2021
 *      Author: Kareem
 */

#include "Std_Types.h"
#include "I2C_Int.h"
#include "Utilities.h"
void I2c_Init_Master(void)
{
	//bit rate = 400.000 kbps, F_CPU = 16M   SCL freq= F_CPU/(16+2(TWBR).4^TWPS),
	TWBR=0x03;
    //setting prescaller to 1
	CLR_BIT(TWSR, 0);
	CLR_BIT(TWSR, 1);
	//Enable I2C
	SET_BIT(TWCR ,2);
}
void I2c_Init_Slave(void)
{
	//provide slave address, my address will be 0x01
	TWAR = 0x02;
	//Enable I2C
	SET_BIT(TWCR, 2);
}
void I2c_Start(void)
{
	//Clear TWI interrupt flag, Put start condition on SDA, Enable TWI
	SET_BIT(TWCR, 7);
	SET_BIT(TWCR, 5);
	SET_BIT(TWCR, 2);
	//Wait till start condition is transmitted
	while (GET_BIT(TWCR, 7) == 0);
	//while (!(TWCR & (1<<TWINT)));
	//Check value of TWI Status Register equal to start
	while ((TWSR & 0xF8) != 0x08);
}
void I2c_Repeated_start(void)
{
	//Clear TWI interrupt flag, Put start condition on SDA, Enable TWI
	SET_BIT(TWCR, 7);
	SET_BIT(TWCR, 5);
	SET_BIT(TWCR, 2);
	// Wait till start condition is transmitted
	while (GET_BIT(TWCR, 7) == 0);
	//Check value of TWI Status Register equal to start
	while ((TWSR & 0xF8) != 0x10);
}
void I2c_Write_byte(u8 byte)
{
	// put data in TWDR
	TWDR = byte;
	//Clear TWI interrupt flag, Enable TWI
	SET_BIT(TWCR, 7);
	SET_BIT(TWCR, 2);
	//Wait till complete TWDR byte transmitted
	while (GET_BIT(TWCR, 7) == 0);
	// Check for the acknowledgment
	while ((TWSR & 0xF8) != 0x28);
}
u8 I2c_Read_byte(void)
{
	u8 data;
	data = TWDR;
	//Clear TWI interrupt flag, Enable TWI
	SET_BIT(TWCR, 7);
	SET_BIT(TWCR, 2);
	//Wait till complete TWDR byte transmitted
	while (GET_BIT(TWCR, 7) == 0);
	// Check for the acknowledgment
	while ((TWSR & 0xF8) != 0x58);
	// return data
	return (data);
}
void I2c_Stop(void)
{
	//Clear TWI interrupt flag,Put stop condition, Enable TWI
	SET_BIT(TWCR, 7);
	SET_BIT(TWCR, 4);
	SET_BIT(TWCR, 2);
}
void I2c_Send_slave_address_with_write_req(u8 slave_address)
{
	//Address and write instruction
	//Clear TWI interrupt flag, Enable TWI
	//Wait till complete TWDR byte transmitted
	// Check for the acknowledgment
}
void I2c_Send_slave_address_with_read_req(u8 slave_address)
{
	// Address and read instruction
	//Clear TWI interrupt flag, Enable TWI
	//Wait till complete TWDR byte transmitted
	// Check for the acknowledgment
}

