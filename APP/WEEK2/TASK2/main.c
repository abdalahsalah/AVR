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

int main() {
	//PA -> ANODE

	// 7-Segment array

	u8 segcthda []= {
			0b00111111, // 0
			0b00000110, // 1
			0b01011011, // 2
			0b01001111, // 3
			0b01100110, // 4
			0b01101101, // 5
			0b01111101, // 6
			0b00000111, // 7
			0b01111111, // 8
			0b01101111  // 9
	};
	u8 pinstate=0,counter=0;

	// port A as output

	DIO_SetPortDirection(DIO_u8PORTA,DIO_u8PORT_OUTPUT);

	// pull up of pin 0 and 1 port B

	DIO_SetPinDirection(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_INPUT);
	DIO_SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_HIGH);
	DIO_SetPinDirection(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_INPUT);
	DIO_SetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_HIGH);

	// TURN OFF SEGMENT

	DIO_SetPortValue(DIO_u8PORTA,DIO_u8PORT_HIGH);


	while(1)
	{

		pinstate=GET_BIT(PINB,DIO_u8PIN0);

		if(pinstate==0)
		{
			counter++;
			if(counter > 8)
			{
				counter=0;
			}
			PORTA= ~segcthda[counter];

			while(GET_BIT(PINB,DIO_u8PIN0)==0);
		}

		if(GET_BIT(PINB,DIO_u8PIN1)==0)
		{
			counter--;
			PORTA= ~segcthda[counter];

			while(GET_BIT(PINB,DIO_u8PIN1)==0);
		}

	}
	return 0;
}
