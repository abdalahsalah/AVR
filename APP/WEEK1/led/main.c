/////*
//// * main.c
////
//// *
//// *  Created on: ???/???/????
//// *      Author: user
//// */
////
#include "../../../lib/std_types.h"
#include "../../../MCAL/DIO/DIO_interface.h"
#include "../../../Hall/LED/LED_interface.h"
#include <util/delay.h>
void main() {

	LED_T led1={DIO_u8PORTA,DIO_u8PIN0,LED_u8SourceConnection};
	LED_u8Initialize(&led1);
	while(1)
	{
		_delay_ms(500);
		LED_u8TurnOnLED(&led1);
		_delay_ms(500);
		LED_u8TurnOffLED(&led1);
	}
}
