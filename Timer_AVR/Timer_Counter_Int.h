/*
 * Timer_Counter_Int.h
 *
 *  Created on: Nov 20, 2020
 *      Author: Mohamed
 */

#ifndef TIMER_COUNTER_INT_H_
#define TIMER_COUNTER_INT_H_

#define TCCR0 *((volatile u8*)0x53)
#define TCNT0 *((volatile u8*)0x52)
#define TIMSK *((volatile u8*)0x59)
#define SREG  *((volatile u8*)0x5F)

void Timer_Counter_Init(void);


#endif /* TIMER_COUNTER_INT_H_ */
