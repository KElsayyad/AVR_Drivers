/*
 * main.c
 *
 *  Created on: 29 Jan 2021
 *      Author: Kareem
 */

#include "Seg_Int.h"
#define Max_Count 99


void main(void)
{
	//initialization
	Seg_Init();

	while(1)
	{
		Seg_Count(Max_Count);
	}
}
