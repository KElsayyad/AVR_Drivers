/*
 * LCD_Prog.c
 *
 *  Created on: Oct 31, 2020
 *      Author: Mohamed
 */
#include "DIO_Int.h"
#include "DIO_Reg.h"
#include "util/delay.h"
#include <stdio.h>
#define FourBitLCD
#define LCD_Port PORTA

void LCD_Init(void)
{
#ifdef EightBitLCD
	//RS c0
	Dio_SetPinDirection(GroupC, PIN0, OUTPUT);
	//RW
	Dio_SetPinDirection(GroupC, PIN1, OUTPUT);
	//E
	Dio_SetPinDirection(GroupC, PIN2, OUTPUT);
	//data lines
	Dio_SetPinDirection(GroupD, PIN0, OUTPUT);
	Dio_SetPinDirection(GroupD, PIN1, OUTPUT);
	Dio_SetPinDirection(GroupD, PIN2, OUTPUT);
	Dio_SetPinDirection(GroupD, PIN3, OUTPUT);
	Dio_SetPinDirection(GroupD, PIN4, OUTPUT);
	Dio_SetPinDirection(GroupD, PIN5, OUTPUT);
	Dio_SetPinDirection(GroupD, PIN6, OUTPUT);
	Dio_SetPinDirection(GroupD, PIN7, OUTPUT);
	_delay_ms(30);
	LCD_WriteCommand(0b00111000);//function set
	_delay_ms(1);
	LCD_WriteCommand(0b00001110);//display on/off setting
	_delay_ms(1);
	LCD_WriteCommand(0b00000001);//display clear
	_delay_ms(1);
	LCD_WriteCommand(0b00000110);//entry mode set
#endif
#ifdef FourBitLCD
	//RS c0
	Dio_SetPinDirection(GroupB, PIN1, OUTPUT);
	//RW
	Dio_SetPinDirection(GroupB, PIN2, OUTPUT);
	//E
	Dio_SetPinDirection(GroupB, PIN3, OUTPUT);
	//data lines
	Dio_SetPinDirection(LCD_Port, PIN4, OUTPUT);
	Dio_SetPinDirection(LCD_Port, PIN5, OUTPUT);
	Dio_SetPinDirection(LCD_Port, PIN6, OUTPUT);
	Dio_SetPinDirection(LCD_Port, PIN7, OUTPUT);

	_delay_ms(30);
	LCD_WriteCommand(0x02);
	_delay_ms(1);
	LCD_WriteCommand(0x28);
	_delay_ms(1);
	LCD_WriteCommand(0x0c);
	_delay_ms(1);
	LCD_WriteCommand(0x06);
	_delay_ms(1);
	LCD_WriteCommand(0x01);
	_delay_ms(2);
#endif
}

void LCD_WriteCommand(u8 Command)
{
#ifdef EightBitLCD
	Dio_SetPinValue(GroupC, PIN0, LOW);	//RS low
	Dio_SetPinValue(GroupC, PIN1, LOW);	//RW low
	PORTD=Command;
	Dio_SetPinValue(GroupC, PIN2, HIGH);//set enable pin high
	_delay_ms(20);
	Dio_SetPinValue(GroupC, PIN2, LOW);	//set enable pin low
	_delay_ms(20);
#endif
#ifdef FourBitLCD
	LCD_Port = (LCD_Port & 0x0F) | (Command & 0xF0); //Sending upper nibble
	Dio_SetPinValue(GroupB, PIN1, LOW);	//RS low
	Dio_SetPinValue(GroupB, PIN2, LOW);	//RW low
	Dio_SetPinValue(GroupB, PIN3, HIGH);//set enable pin high
	_delay_us(1);
	Dio_SetPinValue(GroupB, PIN3, LOW);	//set enable pin low
	_delay_us(200);
	LCD_Port = (LCD_Port & 0x0F) | (Command << 4);//Sending lower nibble
	Dio_SetPinValue(GroupB, PIN3, HIGH);//set enable pin high
	_delay_us(1);
	Dio_SetPinValue(GroupB, PIN3, LOW);//set enable pin low
	_delay_ms(2);
#endif
}

void LCD_WriteData(u8 Data)
{
#ifdef EightBitLCD
	//RS high
	Dio_SetPinValue(GroupC, PIN0, HIGH);
	//RW low
	Dio_SetPinValue(GroupC, PIN1, LOW);
	PORTD=Data;
	//set enable pin high
	Dio_SetPinValue(GroupC, PIN2, HIGH);
	_delay_ms(20);
	//set enable pin low
	Dio_SetPinValue(GroupC, PIN2, LOW);
	_delay_ms(20);
#endif
#ifdef FourBitLCD
	LCD_Port = (LCD_Port & 0x0F) | (Data & 0xF0); //Sending upper nibble
	Dio_SetPinValue(GroupB, PIN1, HIGH);	//RS high
	Dio_SetPinValue(GroupB, PIN2, LOW);	//RW low
	Dio_SetPinValue(GroupB, PIN3, HIGH);//set enable pin high
	_delay_us(1);
	Dio_SetPinValue(GroupB, PIN3, LOW);	//set enable pin low
	_delay_us(200);
	LCD_Port = (LCD_Port & 0x0F) | (Data << 4);//Sending lower nibble
	Dio_SetPinValue(GroupB, PIN3, HIGH);//set enable pin high
	_delay_us(1);
	Dio_SetPinValue(GroupB, PIN3, LOW);//set enable pin low
	_delay_ms(2);
#endif
}


void LCD_Clear(void)
{
	LCD_WriteCommand(0x01);		/* Clear display */
	_delay_ms(2);
	LCD_WriteCommand(0x80);		/* Cursor at home position */
}


void LCD_WriteWord(u8 *Word)
{
	u8 index=0;
	while(Word[index]!='\0')
	{
		LCD_WriteData(Word[index]);
		index++;
	}
}

void LCD_WriteWord_xy (u8 row, u8 pos, u8 *str)	/* Send string to LCD with xy position */
{
	if (row == 0 && pos<16)
		LCD_WriteCommand((pos & 0x0F)|0x80);	/* Command of first row and required position<16 */
	else if (row == 1 && pos<16)
		LCD_WriteCommand((pos & 0x0F)|0xC0);	/* Command of first row and required position<16 */
	LCD_WriteWord(str);		/* Call LCD string function */
}

void LCD_SensorReading (u32 SensRead)
{
	u8 string [10];
    sprintf(string, "%d", SensRead);
	LCD_WriteWord(string);
}

