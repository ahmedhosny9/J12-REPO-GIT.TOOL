/*
 * ADC.c
 *
 * Created: 7/16/2020 11:12:00 PM
 *  Author: ahmed
 */ 

#include "ADC.h"
#include "ATMEGA32_Regs.h"


void ADC_Init(void)
{
   #if   ADC_VOLTAGE_REF      == ADC_VREF_AVCC
   
SET_BIT(ADMUX,6);
CLR_BIT(ADMUX,7);

#endif

#if      ADC_CHANNEL          == ADC_CHANNEL_1

SET_BIT(ADMUX,0);

#endif

   #if   ADC_ADJUST           == ADC_RIGHT_ADJUST

CLR_BIT(ADMUX,5);

#endif

   #if   ADC_CON_TRIGER       == ADC_AUTO_TRIGGER

SET_BIT(ADCSRA,5);


#endif

   #if   ADC_PRESC            == ADC_PRESC_128

SET_BIT(ADCSRA,0);
SET_BIT(ADCSRA,1);
SET_BIT(ADCSRA,2);

#endif

   #if   ADC_INTERRUPT_STATUS == ADC_INTERRUPT_DISABLE

CLR_BIT(ADCSRA,3);

#endif	

/*enable adc*/

SET_BIT(ADCSRA,7);
	
}

void ADC_Read(uint16* val)
{
uint16 	Digital_value = 0;

SET_BIT(ADCSRA,6);


#if ADC_INTERRUPT_STATUS == ADC_INTERRUPT_DISABLE

while( ! GET_BIT(ADCSRA,4));

Digital_value = ADC_Adjust;

*val=( (  Digital_value * 500 ) /1024 );   //5v=5000mv  5000/10mv == 500  2~10=1024

#endif


}