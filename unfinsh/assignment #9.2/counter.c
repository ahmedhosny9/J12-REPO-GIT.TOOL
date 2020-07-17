/*
 * counter.c
 *
 * Created: 7/17/2020 11:40:47 AM
 *  Author: ahmed
 */ 



#include "counter.h"
#include "ATMEGA32_Regs.h"

uint8 CounterRegister_InitValue = 0;
uint32 Number_OverFlows = 0;


void Timer_Init(void)
{
	/*Initilize Timer 0  as Normal mode */
	TCCR0 |= 0x00 ;
	
	TIMSK |= 0x01;
	
	SREG |= 0x80;
	
}

void Timer_Start(void)
{
	
	/* start timer with prescaler   1024 */
	TCCR0 |= 0x05;
	
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
	
	Number_OverFlows = Total_Ticks / 256 ;
	
	CounterRegister_InitValue = 256 - (Total_Ticks % 256) ; //256 - ((  ((float) Total_Ticks / 256 ) - Number_OverFlows ) * 256 );
	
	
	TCNT0 = CounterRegister_InitValue ;
	
	Number_OverFlows ++;
	
}

