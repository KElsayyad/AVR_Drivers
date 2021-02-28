/*
 * Keypad_Int.h
 *
 *  Created on: 30 Jan 2021
 *      Author: Kareem
 */

#ifndef KEYPAD_INT_H_
#define KEYPAD_INT_H_

#include "Std_Types.h"
#include "DIO_Int.h"
#include "DIO_Reg.h"
#include "Utilities.h"

void KeyPad_Init (void);
u8 Keypad_GetKey (void);

#endif /* KEYPAD_INT_H_ */
