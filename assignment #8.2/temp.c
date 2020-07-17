/*
 * temp.c
 *
 * Created: 7/17/2020 12:21:52 AM
 *  Author: ahmed
 */ 

#include "temp.h"


void TEMP_Init(void)
{
	ADC_Init();
}
void TEMP_Read(uint16* TEMP)
{
	ADC_Read(TEMP);
	
}