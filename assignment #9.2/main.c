/*
 * KeyPad.c
 *
 * Created: 04/07/2020 01:39:01 م
 * Author : Ali
 */ 

#include "LCD.h"
#include "KeyPad.h"
#include "temp.h"
#define F_CPU 16000000

#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	//uint8 value = 0;
	
	LCD_Init();
	KeyPad_Init();
	TEMP_Init();
	
	LCD_GoTo(0,0);
	LCD_Clear();
	LCD_WriteString("  welcome sir   ");

	
    while (1) 
    {
		PASSWORD_FUN();
		
		
	}
	}
		
		/*value = KeyPad_GetValue();
		
		if(value)
		{
			LCD_WriteChar(value);
		}
		

    }
}*/

