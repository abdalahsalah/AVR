/*
 * main.c

 *
 *  Created on: ???/???/????
 *      Author: user
 */
#include "../../../lib/std_types.h"
#include "../../../MCAL/DIO/DIO_interface.h"
#include <util/delay.h>

void main() {

	DIO_SetPortDirection(DIO_u8PORTA,DIO_u8PORT_OUTPUT);
	while(1)
	{
		for (int i=0;i<=5;i++)
		{
			DIO_SetPinValue(DIO_u8PORTA,i,DIO_u8PIN_HIGH);
			_delay_ms(100);
			DIO_SetPinValue(DIO_u8PORTA,i,DIO_u8PIN_LOW);
			_delay_ms(100);

		}
	}

}

