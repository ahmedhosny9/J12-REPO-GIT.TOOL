/*
 * Timer0.c
 *
 * Created: 17/07/2020 01:04:39 م
 * Author : Ali
 */ 

#include "timer.h"
#include "LED.h"
#include <avr/interrupt.h>


 extern uint8 CounterRegister_InitValue ;
 extern uint32 Number_ctc;

int main(void)
{
    
	
	LED0_Init();
	LED0_ON();
	
	
	Timer_Init();
	
	Timer_SetDelay(1000);
	Timer_Start();
	
	
    while (1) 
    {
		
	
    }
}


ISR(TIMER0_OVF_vect)
{
	
	static uint32 counter = 0;
	
	counter++;
	
	if(counter == Number_ctc)
	{
		OCR0 = CounterRegister_InitValue;
		
		counter = 0;
		
		LED0_toggle();
		
	}
	
	
}