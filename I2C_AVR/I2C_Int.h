/*
 * I2C_Int.h
 *
 *  Created on: 26 Feb 2021
 *      Author: Kareem
 */

#ifndef I2C_INT_H_
#define I2C_INT_H_
#include "Std_Types.h"

void I2c_Init_Master(void);
void I2c_Init_Slave(void);
void I2c_Start(void);
void I2c_Repeated_start(void);
void I2c_Write_byte(u8 byte);
u8   I2c_Read_byte(void);
void I2c_Stop(void);
void I2c_Send_slave_address_with_write_req(u8 slave_address);
void I2c_Send_slave_address_with_read_req(u8 slave_address);

#define TWBR *((volatile u8*) 0x20)
#define TWCR *((volatile u8*) 0x56)
#define TWSR *((volatile u8*) 0x21)
#define TWDR *((volatile u8*) 0x23)
#define TWAR *((volatile u8*) 0x22)


#endif /* I2C_INT_H_ */
