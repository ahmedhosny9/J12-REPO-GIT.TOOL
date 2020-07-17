/*
 * counter.c
 *
 * Created: 7/17/2020 11:40:47 AM
 *  Author: ahmed
 */ 



#include "counter.h"
#include "ATMEGA32_Regs.h"

uint32 num_ovf=0;

void TEMER_Init()
{
	TCCR2= 0x00;
	TIMSK= 0x01;
	SREG = 0x80;
}
void TEMER_start()
{
	TCCR2=0x05;
	
}
void TEMER_stop()
{
	TCCR2=0x00;
}
void TEMER_GEN_DELAY(uint8 delay_ms)
{
	uint8 tirk_time,num_tirk,init_val;
	
	tirk_time = 1034/16000000;
	num_tirk  = (1000*delay_ms)/tirk_time;
	
}

