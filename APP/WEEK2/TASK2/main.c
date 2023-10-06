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
	u8 segcthda []= { 0x3F, 0x06 ,0x5B,0x4F , 0x66 ,0x6D,0x7D, 0x07, 0x7F,0x6F};
	DIO_SetPortDirection(DIO_u8PORTB,DIO_u8PORT_OUTPUT);
	for(u8 i=0;i<2;i++)
	{
		DIO_SetPinDirection(DIO_u8PORTA,i,DIO_u8PIN_INPUT);
		DIO_SetPinValue(DIO_u8PORTA,i,DIO_u8PIN_HIGH);
	}
	u8 i;
	while(1)
	{

		if(GET_BIT(PINA,DIO_u8PIN0)==0)
		{
			i++;
			while(i<=9)
	        {
				PORTB=segcthda[i];
			}
			i=9;
		}
		if(GET_BIT(PINA,DIO_u8PIN1)==0)
		{
			i--;
			PORTB=segcthda[i];
		}
		if(i==0||i<=0)
		{
			PORTB=segcthda[0];
		}




	}
}
