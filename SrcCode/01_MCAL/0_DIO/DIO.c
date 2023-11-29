#include <stddef.h>
#include "STD_TYPES.h"
#include "bit_math.h"
#include "DIO.h"

#define PORTA *((volatile char *)0X3B)
#define DDRA *((volatile char *)0X3A)
#define PINA *((volatile char *)0X39)
#define PORTB *((volatile char *)0X38)
#define DDRB *((volatile char *)0X37)
#define PINB *((volatile char *)0X36)
#define PORTC *((volatile char *)0X35)
#define DDRC *((volatile char *)0X34)
#define PINC *((volatile char *)0X33)
#define PORTD *((volatile char *)0X32)
#define DDRD *((volatile char *)0X31)
#define PIND *((volatile char *)0X30)



 


/* pin configuration */

DIO_enuErrorStatus_t DIO_enuSetPinConfiguration(DIO_enuPortnames_t Copy_enuPortnames_t,DIO_enuPinNum_t Copy_enuPinNum_t,DIO_enuConfiguration_t Copy_enuConfiguration_t)
{
	DIO_enuErrorStatus_t  Ret_enuErrorStatus = DIO_enuNOK;
	if (Copy_enuPortnames_t>DIO_enuPortD||Copy_enuPortnames_t<DIO_enuPortA)
	{
		Ret_enuErrorStatus = DIO_enuNOK;
	}
	else if (Copy_enuPinNum_t>DIO_enuPin7||Copy_enuPinNum_t<DIO_enuPin0)
	{
		Ret_enuErrorStatus = DIO_enuNOK;
	}
	else if (Copy_enuConfiguration_t>DIO_enuInputExternalPullDown||Copy_enuConfiguration_t<DIO_enuOutPut)
	{
		Ret_enuErrorStatus = DIO_enuNOK;
	}
	else
	{
		Ret_enuErrorStatus = DIO_enuOK;
		switch (Copy_enuPortnames_t)
		{      case DIO_enuPortA :
			        switch ( Copy_enuConfiguration_t)
			        { 
			             case DIO_enuOutPut :
							 SET_BIT(DDRA,Copy_enuPinNum_t)	;			  
			        		 break;
							 
						 case DIO_enuInputInternalPullUp :
							 CLR_BIT(DDRA,Copy_enuPinNum_t);
							 SET_BIT(PORTA,Copy_enuPinNum_t);
							 break;
							 
						  case DIO_enuInputExternalPullDown :
							 CLR_BIT(DDRA,Copy_enuPinNum_t);
							 CLR_BIT(PORTA,Copy_enuPinNum_t);
							 break;
						 default:
						     break;
			        }
			    	break ;
				
				
				case DIO_enuPortB :
					switch ( Copy_enuConfiguration_t)
					{
						case DIO_enuOutPut :
							SET_BIT(DDRB,Copy_enuPinNum_t);
							break;
							
						case DIO_enuInputInternalPullUp :
							CLR_BIT(DDRB,Copy_enuPinNum_t);
							SET_BIT(PORTB,Copy_enuPinNum_t);
							break;
							
						case DIO_enuInputExternalPullDown :
							CLR_BIT(DDRB,Copy_enuPinNum_t);
							CLR_BIT(PORTB,Copy_enuPinNum_t);
							break;
						default:
							break;
					}
					break ;
				
				
				case DIO_enuPortC :
					switch ( Copy_enuConfiguration_t)
					{
						case DIO_enuOutPut :
							SET_BIT(DDRC,Copy_enuPinNum_t);
							break;
						case DIO_enuInputInternalPullUp :
							CLR_BIT(DDRC,Copy_enuPinNum_t);
							SET_BIT(PORTC,Copy_enuPinNum_t);
							break;
						case DIO_enuInputExternalPullDown :
							CLR_BIT(DDRC,Copy_enuPinNum_t);
							CLR_BIT(PORTC,Copy_enuPinNum_t);
							break;
						default:
							break;
					}
					break ;
				
				case DIO_enuPortD :
					switch ( Copy_enuConfiguration_t)
					{
						case DIO_enuOutPut :
							SET_BIT(DDRD,Copy_enuPinNum_t);
							break;
						case DIO_enuInputInternalPullUp :
							CLR_BIT(DDRD,Copy_enuPinNum_t);
							SET_BIT(PORTD,Copy_enuPinNum_t);
							break;
						case DIO_enuInputExternalPullDown :
							CLR_BIT(DDRD,Copy_enuPinNum_t);
							CLR_BIT(PORTD,Copy_enuPinNum_t);
							break;
						default:
							break;
					}
					break ;
				default:
					break;
		}
		}
		
		
	return Ret_enuErrorStatus ;	
		
}




/* port configuration */

DIO_enuErrorStatus_t DIO_enuSetPortConfiguration(DIO_enuPortnames_t Copy_enuPortnames_t,DIO_enuConfiguration_t Copy_enuConfiguration_t)
{
  DIO_enuErrorStatus_t  Ret_enuErrorStatus = DIO_enuNOK;
  
  if (Copy_enuPortnames_t>DIO_enuPortD||Copy_enuPortnames_t<DIO_enuPortA)
	 {	
	  		 Ret_enuErrorStatus = DIO_enuNOK;
		} 
  else if (Copy_enuConfiguration_t>DIO_enuInputExternalPullDown||Copy_enuConfiguration_t<DIO_enuOutPut)
	 {		
		     Ret_enuErrorStatus = DIO_enuNOK;
	    }  
  else
	{	
			 Ret_enuErrorStatus = DIO_enuOK;
			 switch (Copy_enuPortnames_t)
			 {
			 case  DIO_enuPortA :
			         switch (Copy_enuConfiguration_t)
						{			 case DIO_enuOutPut :
										 DDRA=0xff;
									 break;
									  case  DIO_enuInputInternalPullUp :
				  						DDRA=0x00;
										PORTA=0xff;
									break;
									 case  DIO_enuInputExternalPullDown :
										DDRA=0x00;
										PORTA=0x00;
									break;
									default:
									break;
						}
			 	break;
				case  DIO_enuPortB :
				      switch (Copy_enuConfiguration_t)
						{			case DIO_enuOutPut :
								     	DDRB=0xff;
									break;
									
									case  DIO_enuInputInternalPullUp :
										DDRB=0x00;
										PORTB=0xff;
									break;
									
									case  DIO_enuInputExternalPullDown :
										DDRB=0x00;
										PORTB=0x00;
									break;
									
									default:
									break;
						}
				break;
				case  DIO_enuPortC :
				switch (Copy_enuConfiguration_t)
						{			case DIO_enuOutPut :
										DDRC=0xff;
									break;
									
									case  DIO_enuInputInternalPullUp :
										DDRC=0x00;
										PORTC=0xff;
									break;
									
									case  DIO_enuInputExternalPullDown :
										DDRC=0x00;
										PORTC=0x00;
									break;
									
									default:
									break;
						}
				break;
				case  DIO_enuPortD :
				switch (Copy_enuConfiguration_t)
						{			case DIO_enuOutPut :
										DDRD=0xff;
									break;
									
									case  DIO_enuInputInternalPullUp :
										DDRD=0x00;
										PORTD=0xff;
									break;
									
									case  DIO_enuInputExternalPullDown :
										DDRD=0x00;
										PORTD=0x00;
									break;
									
									default:
									break;
						}
				break;
				default:
				break;
			 }
	  
	  
		}
  
	return Ret_enuErrorStatus ;
}





/* SET BIN */

DIO_enuErrorStatus_t DIO_enuSetPin(DIO_enuPortnames_t Copy_enuPortnames_t,DIO_enuPinNum_t copy_enuPinNum_t,DIO_enuStates_t Copy_enuStates_t)
{
	DIO_enuErrorStatus_t  Ret_enuErrorStatus = DIO_enuNOK;
	if (Copy_enuPortnames_t>DIO_enuPortD||Copy_enuPortnames_t<DIO_enuPortA)
	{
		Ret_enuErrorStatus = DIO_enuNOK;
	}
	else if (copy_enuPinNum_t>DIO_enuPin7||copy_enuPinNum_t <DIO_enuPin0)
	{
		Ret_enuErrorStatus = DIO_enuNOK;
	}
	else if (Copy_enuStates_t>DIO_enuStateLow||Copy_enuStates_t<DIO_enuStateHigh)
	{
		Ret_enuErrorStatus = DIO_enuNOK;
	}
	else
	{
		Ret_enuErrorStatus = DIO_enuOK;
		 switch (Copy_enuPortnames_t)
		 {
			 case  DIO_enuPortA :
			 switch (Copy_enuStates_t)
			 {		 case DIO_enuStateLow :
				         CLR_BIT(PORTA,copy_enuPinNum_t); 
						 break;    
				     case  DIO_enuStateHigh :
						 SET_BIT(PORTA,copy_enuPinNum_t); 
						 break;
					 default:
						break;
			 }
			 break;
			  case  DIO_enuPortB :
			  switch (Copy_enuStates_t)
			  {		 case DIO_enuStateLow :
				  CLR_BIT(PORTB,copy_enuPinNum_t);
				  break;
				  case  DIO_enuStateHigh :
				  SET_BIT(PORTB,copy_enuPinNum_t);
				  break;
				  default:
				  break;
			  }
			  break;
			   case  DIO_enuPortC :
			   switch (Copy_enuStates_t)
			   {		 case DIO_enuStateLow :
				   CLR_BIT(PORTC,copy_enuPinNum_t);
				   break;
				   case  DIO_enuStateHigh :
				   SET_BIT(PORTC,copy_enuPinNum_t);
				   break;
				   default:
				   break;
			   }
			   break;
			    case  DIO_enuPortD :
			    switch (Copy_enuStates_t)
			    {		 case DIO_enuStateLow :
				    CLR_BIT(PORTD,copy_enuPinNum_t);
				    break;
				    case  DIO_enuStateHigh :
				    SET_BIT(PORTD,copy_enuPinNum_t);
				    break;
				    default:
				    break;
			    }
			    break;
				default:
				break;
		 }
	}
	
	return Ret_enuErrorStatus ;		 
}






/* GET PIN */ 

DIO_enuErrorStatus_t DIO_enuGet(DIO_enuPortnames_t Copy_enuPortnames_t,DIO_enuPinNum_t copy_enuPinNum_t, u8* Add_Pu8PinValue)
{
	DIO_enuErrorStatus_t  Ret_enuErrorStatus = DIO_enuNOK;
	if (Copy_enuPortnames_t>DIO_enuPortD||Copy_enuPortnames_t<DIO_enuPortA)
	{
		Ret_enuErrorStatus = DIO_enuNOK;
	}
	else if (copy_enuPinNum_t>DIO_enuPin7||copy_enuPinNum_t <DIO_enuPin0)
	{
		Ret_enuErrorStatus = DIO_enuNOK;
	}
	else if(Add_Pu8PinValue == NULL)
	{
		Ret_enuErrorStatus = DIO_enuNOK;
	}
	else
	{
		Ret_enuErrorStatus = DIO_enuOK;
		switch (Copy_enuPortnames_t)
		{
			case  DIO_enuPortA :
			*Add_Pu8PinValue =GET_BIT(PINA,copy_enuPinNum_t);
			break;
			
			case  DIO_enuPortB :
			*Add_Pu8PinValue =GET_BIT(PINB,copy_enuPinNum_t);
			break; 
			
			case  DIO_enuPortC :
			*Add_Pu8PinValue = GET_BIT(PINC,copy_enuPinNum_t);
			break;
			
			case  DIO_enuPortD :
			*Add_Pu8PinValue = GET_BIT(PIND,copy_enuPinNum_t);
			break;
			
			default:
			break;
		}
	}
	
	return Ret_enuErrorStatus ;
}
	    
	










/* SET PORT */
DIO_enuErrorStatus_t DIO_enuSetport(DIO_enuPortnames_t Copy_enuPortnames_t,DIO_enuStates_t Copy_enuStates_t )
{
	DIO_enuErrorStatus_t  Ret_enuErrorStatus = DIO_enuNOK ;
	if (Copy_enuPortnames_t>DIO_enuPortD||Copy_enuPortnames_t<DIO_enuPortA)
	{
		Ret_enuErrorStatus = DIO_enuNOK ;
	} 
	else if (Copy_enuStates_t >DIO_enuStateLow||Copy_enuStates_t <DIO_enuStateHigh)
	{
		Ret_enuErrorStatus = DIO_enuNOK;
	}
	else
	{
		Ret_enuErrorStatus = DIO_enuOK;
		switch (Copy_enuPortnames_t)
		{
			case  DIO_enuPortA :
			switch (Copy_enuStates_t)
			{		 case DIO_enuStateLow :
				     PORTA=0x00;
				break;
				case  DIO_enuStateHigh :
				      PORTA=0xff;
				break;
				default:
				break;
			}
			break;
			case  DIO_enuPortB :
			switch (Copy_enuStates_t)
			{		 case DIO_enuStateLow :
				PORTB=0x00;
				break;
				case  DIO_enuStateHigh :
				PORTB=0xff;
				break;
				default:
				break;
			}
			break;
			case  DIO_enuPortC :
			switch (Copy_enuStates_t)
			{		 case DIO_enuStateLow :
				PORTC=0x00;
				break;
				case  DIO_enuStateHigh :
				PORTC=0xff;
				break;
				default:
				break;
			}
			break;
			case  DIO_enuPortD :
			switch (Copy_enuStates_t)
			{		 case DIO_enuStateLow :
				PORTD=0x00;
				break;
				case  DIO_enuStateHigh :
				PORTD=0xff;
				break;
				default:
				break;
			}
			break;
			default:
			break;
		}
	}
			
return Ret_enuErrorStatus ;						
}


/* set value port */
DIO_enuErrorStatus_t DIO_enuSetValueoport(DIO_enuPortnames_t Copy_enuPortnames_t,u8 copy_u8valueport )
{
	DIO_enuErrorStatus_t  Ret_enuErrorStatus = DIO_enuNOK ;
	if (Copy_enuPortnames_t>DIO_enuPortD||Copy_enuPortnames_t<DIO_enuPortA)
	{
		Ret_enuErrorStatus = DIO_enuNOK ;
	}
	else if (copy_u8valueport ==NULL)
	{
		Ret_enuErrorStatus = DIO_enuNOK;
	}
	else
	{
		Ret_enuErrorStatus = DIO_enuOK;
		switch (Copy_enuPortnames_t)
		{
			case  DIO_enuPortA :
			PORTA = copy_u8valueport; 
			break;
		
			case  DIO_enuPortB :
			PORTB = copy_u8valueport;
			break;
			
			case  DIO_enuPortC :
			PORTC = copy_u8valueport;
			break;
			
			case  DIO_enuPortD :
			PORTD = copy_u8valueport;
			break;
			
			
			default:
			break;
		}
	}
	
	return Ret_enuErrorStatus ;
}
