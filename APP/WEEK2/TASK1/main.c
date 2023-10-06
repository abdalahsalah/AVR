/*
 * main.c

 *
 *  Created on: ???/???/????
 *      Author: user
 */
#include "../../../lib/std_types.h"
#include "../../../MCAL/DIO/DIO_interface.h"
#include "../../../MCAL/DIO/DIO_register.h"
#include "../../../lib/BIT_MATH.h"
#include <util/delay.h>

void main() {

	for(u8 i=0;i<2;i++)
	{
		DIO_SetPinDirection(DIO_u8PORTA,i,DIO_u8PIN_OUTPUT);
		DIO_SetPinValue(DIO_u8PORTA,i,DIO_u8PIN_LOW);
	}
	for(u8 i=0;i<3;i++)
	{
		DIO_SetPinDirection(DIO_u8PORTB,i,DIO_u8PIN_INPUT);
		DIO_SetPinValue(DIO_u8PORTB,i,DIO_u8PIN_HIGH);
	}
	while(1)
	{

		if(GET_BIT(PINB ,DIO_u8PIN0)==0)
		{
			DIO_SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
		}
		else if(GET_BIT(PINB ,DIO_u8PIN1)==0)
		{
			DIO_SetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_HIGH);
		}
		else if(GET_BIT(PINB ,DIO_u8PIN2)==0)
		{
			DIO_SetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_HIGH);
			DIO_SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
		}
		else
		{
			DIO_SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
			DIO_SetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_LOW);
			DIO_SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
		}

	}


}

