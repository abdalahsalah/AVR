///*
// * main.c


//
// *
// *  Created on: ???/???/????
// *      Author: user
// */
#include "../../../lib/std_types.h"
#include "../../../MCAL/DIO/DIO_interface.h"
#include "../../../Hall/LED/LED_interface.h"
#include <util/delay.h>

void main() {

	LED_T LED[5]={
			{DIO_u8PORTA,DIO_u8PIN0,LED_u8SourceConnection},
			{DIO_u8PORTA,DIO_u8PIN1,LED_u8SourceConnection},
			{DIO_u8PORTA,DIO_u8PIN2,LED_u8SourceConnection},
			{DIO_u8PORTA,DIO_u8PIN3,LED_u8SourceConnection},
			{DIO_u8PORTA,DIO_u8PIN4,LED_u8SourceConnection}
	};
	for(u8 i=0;i<=5;i++)
	{
		LED_u8Initialize(&LED[i]);
	}

	while(1)
	{
		for (int i=0;i<=5;i++)
		{
		    LED_u8TurnOnLED(&LED[i]);
			_delay_ms(100);
			LED_u8TurnOffLED(&LED[i]);
			_delay_ms(100);

		}
	}

}

