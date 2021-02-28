/*
 * main.c
 *
 *  Created on: Oct 30, 2020
 *      Author: Mohamed
 */

#include "Dio_Reg.h"
#include "DIO_Int.h"
#include "Utilities.h"
#include "util/delay.h"
#include "LCD_Int.h"
#include "avr/io.h"

void main(void)
{
	LCD_Init();
	u32 var = 154;
	LCD_WriteCommand(0b10000000);
	LCD_SensorReading(var);
	while(1)
    {
    }
}
