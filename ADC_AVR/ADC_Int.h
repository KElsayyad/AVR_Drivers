/*
 * ADC_Int.h
 *
 *  Created on: 6 Feb 2021
 *      Author: Kareem
 */

#ifndef ADC_INT_H_
#define ADC_INT_H_

#include "Std_Types.h"
#include "DIO_Reg.h"
#include "DIO_Int.h"
#include "Utilities.h"

#define ADMUX  *((volatile u8*) 0x27)
#define ADCSRA *((volatile u8*) 0x26)
#define SFIOR  *((volatile u8*) 0x50)
#define ADCL   *((volatile u8*) 0x24)
#define ADCH   *((volatile u8*) 0x25)
void ADC_Init (void);
u16 Analog_Read (void);
s32 Analog_Value (void);
u8 map(u32 x, u16 in_min, u16 in_max, u16 out_min, u16 out_max);


#endif /* ADC_INT_H_ */
