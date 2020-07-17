/*
 * Timer.c
 *
 * Created: 17/07/2020 12:28:31 م
 *  Author: Ali
 */ 


#include "Timer.h"
#include "BIT_Math.h"


 uint8 CounterRegister_InitValue = 0;
 uint32 Number_ctc = 0;


void Timer_Init(void)
{
	/*Initilize Timer 0  as Normal mode */
	
	TCCR0 |= 0b00001000;//ctc WGM21 make bin 3
	
	TIMSK |= 0b00000010;//ctc OCIE0 make bin 1
	
	SREG |= 0x80;
	
}

void Timer_Start(void)
{
	
	/* start timer with prescaler   1024 */
	TCCR0 |= 0b00000111;
	
}

void Timer_Stop(void)
{
	
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
	
}


void Timer_SetDelay(uint32 Delay_Ms)
{
	/* tick time in micro second */
	uint8 Tick_Time_us = (1024 / 16);
	
	uint32 Total_Ticks = (Delay_Ms * 1000) / Tick_Time_us;
	
   OCR0=Total_Ticks;
   
	Number_ctc++;
	
	
}

