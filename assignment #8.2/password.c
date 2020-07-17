/*
 * password.c
 *
 * Created: 7/15/2020 11:06:35 PM
 *  Author: ahmed
 */ 
#include "LCD.h"
#include "KeyPad.h"
#include "password.h"
#define F_CPU 16000000
#include <util/delay.h>

uint8 i = 0, val = 0, save[3]={0,0,0},load[3]={0,0,0};
sint32 temp = 0;

void PASSWORD_FUN(void)
{
		
LCD_GoTo(1,0);
LCD_WriteString("save pass = "); //start from location 14 in lcd ro 2.

while(1){
		
		val = KeyPad_GetValue();
		if(val){save[i]=val; i++; LCD_WriteChar(val);val=0;}
        if (i==3){i=0;break;}
		}
		
		LCD_Clear();
 LCD_GoTo(0,0);
 LCD_WriteString("   thank you   "); //start from location 14 in lcd ro 2.       
LCD_GoTo(1,0);
LCD_WriteString(" password saved "); //start from location 14 in lcd ro 2.

CHACKPASS_FUN();	
		}
		
void CHACKPASS_FUN(void)
{
	
 LCD_Clear();		
LCD_GoTo(0,0);
LCD_WriteString("enter pass = "); //start from location 14 in lcd ro 2.		
		
while(1){
	
    val=0;
    val = KeyPad_GetValue();
	
	if (val && i==0){LCD_WriteChar('*');load[i]=val;i++;val=0;}
	  if (val && i==1){LCD_WriteChar('*');load[i]=val;i++;val=0;}
		if (val && i==2){LCD_WriteChar('*');load[i]=val;i=0;val=0;break;}
		}
		
	LCD_Clear();
	uint8 s=0,l=0;
	for(i=0;i<3;i++)
	{
		s=save[i];l=load[i];
		if (s!=l)
		{
			LCD_Clear();
			LCD_WriteString(" error password ");
			LCD_GoTo(1,0);
			LCD_WriteString("wait 1s to enter");
			_delay_ms(100);
			i=0;
			CHACKPASS_FUN();
		}
	}
	if (s==l)       {LCD_Clear();
		             LCD_WriteString("password correct");
		             LCD_GoTo(1,0);
		             LCD_WriteString("move to temp sys");
					 LCD_Clear();
					 i=0;
		TEMP_FUN(); }   // generc adc 
		
 }
	
	void TEMP_FUN(void)
	{
		LCD_WriteString("TEMP(S) = ");
		
		while(1){
		val = KeyPad_GetValue();
			
		val=0;
		val = KeyPad_GetValue();
			
		TEMP_Read(&temp);
		val = KeyPad_GetValue();
		
		LCD_GoTo(0,11);
		val = KeyPad_GetValue();
		
		LCD_WriteIntger(temp);
		val = KeyPad_GetValue();
		
		if (val=='c'){val=0; LCD_Clear(); LCD_WriteString(" reset  password"); LCD_Clear(); main();}
	
		 _delay_ms(50);
		 
		val = KeyPad_GetValue();
		         }
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		
	/*while(i)
	{
		 
		 
		
	}
	
	
	


	for(;o<2;o++){
		if(strcmp(name[o], nm)==0&&strcmp(password[o], ps)==0){
			printf("        Been confirmed Thank you   \n\n         ");
			control();
		}
	
void passcp(void){
	char erro=0;
	erro++;
	char o=0;

	printf("Enter the name and old password\n");

	printf("enter your name         = ");
	scanf("%s",nm);
	printf("enter your old password = ");
	scanf("%s",ps);

	for(;o<2;o++){
		if(strcmp(name[o], nm)==0&&strcmp(password[o], ps)==0){

			printf("Thank you reset your password\n\n");

			if(o==0){printf("Enter the new password ahmed = ");scanf("%s",password[0]);
			}
			if(o==1){printf("Enter the new password hosny = ");scanf("%s",password[1]);;
			}
			control();
		}
	}
	if(error==1){ printf("Error old password try again 1"); passcp();
	}
	if(error==2){ printf("Error old password try again 2"); passcp();
	}
	if(error==3){ printf("Error old password return to choose system"); control();
	}
}


void error(void){



	if(r==0){printf("  error in the password.\n Try again ( remaining 2 ) \n");r++; pass();
	}

	if(r==1){printf("  error in the password.\n Try again ( remaining 1 ) \n");r++;pass();
	}

	if(r==2){printf("          good bye you are an criminal XD            \n");pass();
	}


}
	
	
}*/