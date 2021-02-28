/*
 * 7Seg_Int.h
 *
 *  Created on: 31 Jan 2021
 *      Author: Kareem
 */

#include "DIO_Int.h"
#include "DIO_Reg.h"
#include "util/delay.h"
#include "Std_Types.h"

void Seg_Init (void);
void Seg_WriteNum (u8 Number);
void Seg_Count (u8 Max_Count);
