#include "DIO.h"


#include <avr/delay.h>




int main(void)
{  DIO_enuSetPinConfiguration(DIO_enuPortA,DIO_enuPin0,DIO_enuOutPut);
	DIO_enuSetPin(DIO_enuPortA,DIO_enuPin0,DIO_enuStateLow);
	DIO_enuSetPinConfiguration(DIO_enuPortA,DIO_enuPin1,DIO_enuOutPut);
	DIO_enuSetPin(DIO_enuPortA,DIO_enuPin1,DIO_enuStateLow);
	while(1)
	{
		//TODO:: Please write your application code
		DIO_enuSetPin(DIO_enuPortA,DIO_enuPin0,DIO_enuStateHigh);
		_delay_ms( 1000);
		DIO_enuSetPin(DIO_enuPortA,DIO_enuPin0,DIO_enuStateLow);
		DIO_enuSetPin(DIO_enuPortA,DIO_enuPin1,DIO_enuStateHigh);
		_delay_ms( 1000);
		DIO_enuSetPin(DIO_enuPortA,DIO_enuPin1,DIO_enuStateLow);
		
		
	}
}