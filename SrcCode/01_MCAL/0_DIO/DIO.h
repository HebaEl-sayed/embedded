#ifndef DIO_H
#define DIO_H
#include"STD_TYPES.h"

/* the enum of error status */
typedef enum
{
	DIO_enuOK,
	DIO_enuNOK
	
} DIO_enuErrorStatus_t;


/* the enum of port name */
typedef enum 
{
	 DIO_enuPortA,
     DIO_enuPortB,
     DIO_enuPortC,
     DIO_enuPortD
	 
}DIO_enuPortnames_t;


typedef enum
{   
	DIO_enuPin0,
	DIO_enuPin1,
	DIO_enuPin2,
	DIO_enuPin3,
	DIO_enuPin4,
	DIO_enuPin5,
	DIO_enuPin6,
	DIO_enuPin7
	
}DIO_enuPinNum_t;


typedef enum
{   
	DIO_enuOutPut,
	DIO_enuInputInternalPullUp,
	DIO_enuInputExternalPullDown
	
}DIO_enuConfiguration_t;


typedef enum
{   
	DIO_enuStateHigh,
	DIO_enuStateLow
	
}DIO_enuStates_t;



DIO_enuErrorStatus_t DIO_enuSetPinConfiguration(DIO_enuPortnames_t Copy_enuPortnames_t,DIO_enuPinNum_t Copy_enuPinNum_t,DIO_enuConfiguration_t Copy_enuConfiguration_t);
DIO_enuErrorStatus_t DIO_enuSetPortConfiguration(DIO_enuPortnames_t Copy_enuPortnames_t,DIO_enuConfiguration_t Copy_enuConfiguration_t);
DIO_enuErrorStatus_t DIO_enuSetPin(DIO_enuPortnames_t Copy_enuPortnames_t,DIO_enuPinNum_t copy_enuPinNum_t,DIO_enuStates_t Copy_enuStates_t);
DIO_enuErrorStatus_t DIO_enuGet(DIO_enuPortnames_t Copy_enuPortnames_t,DIO_enuPinNum_t copy_enuPinNum_t, u8* Add_Pu8PinValue);
DIO_enuErrorStatus_t DIO_enuSetport(DIO_enuPortnames_t Copy_enuPortnames_t,DIO_enuStates_t Copy_enuStates_t );
DIO_enuErrorStatus_t DIO_enuSetValueoport(DIO_enuPortnames_t Copy_enuPortnames_t,u8 copy_u8valueport );











#endif  

