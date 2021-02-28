/*
 * LCD_Int.h
 *
 *  Created on: Oct 31, 2020
 *      Author: Mohamed
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

#include "Std_Types.h"
void LCD_Init(void);
void LCD_WriteCommand(u8 Command);
void LCD_WriteData(u8 Data);
void LCD_WriteWord(u8 *Word);
void LCD_Clear(void);
void LCD_WriteWord_xy (u8 row, u8 pos, u8 *str);
void LCD_SensorReading (u32 num);
#endif /* LCD_INT_H_ */
