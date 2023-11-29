/*
 * main.c
 *
 * Created: 11/28/2023 2:02:19 PM
 *  Author: LEGION
 */ 

#include "DIO.h"


#include <avr/delay.h>

int main(void)
{  
	u8 count =0;
	 DIO_enuSetPinConfiguration(DIO_enuPortA,DIO_enuPin0,DIO_enuOutPut);
	DIO_enuSetPin(DIO_enuPortA,DIO_enuPin0,DIO_enuStateLow);
	
	DIO_enuSetPinConfiguration(DIO_enuPortA,DIO_enuPin1,DIO_enuOutPut);
	DIO_enuSetPin(DIO_enuPortA,DIO_enuPin1,DIO_enuStateLow);
	
	DIO_enuSetPinConfiguration(DIO_enuPortA,DIO_enuPin2,DIO_enuOutPut);
	DIO_enuSetPin(DIO_enuPortA,DIO_enuPin2,DIO_enuStateLow);
	
	DIO_enuSetPinConfiguration(DIO_enuPortA,DIO_enuPin3,DIO_enuOutPut);
	DIO_enuSetPin(DIO_enuPortA,DIO_enuPin3,DIO_enuStateLow);
	
	DIO_enuSetPinConfiguration(DIO_enuPortB,DIO_enuPin0,DIO_enuInputInternalPullUp);
	
	u8  pinstate ;
	
	
    while(1)
    {
        //TODO:: Please write your application code 
		DIO_enuGet(DIO_enuPortB,DIO_enuPin0 , &pinstate);
		 if (pinstate == 0)
		 {   
			 _delay_ms( 500);
			 count ++;
             DIO_enuSetValueoport(DIO_enuPortA,count);

		 }
    }
}