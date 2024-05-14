/*
 * main.c

 *
 *  Created on: ???/???/????
 *      Author: user
 */


#include "../../../lib/std_types.h"
#include "../../../lib/BIT_MATH.h"
#include "../../../MCAL/PORT/PORT_interface.h"
#include "../../../MCAL/DIO/DIO_interface.h"
#include "../../../MCAL/GIE/GIE_interface.h"
#include "../../../MCAL/TIMERS/TIMER_interface.h"
#include "../../../Hall/CLCD/CLCD_interface.h"
#include "../../../MCAL/USART/USART_intrface.h"
#include <util/delay.h>
//void PWM(void);
void main(void)
{
	PORT_voidInit();
	USART_init();

	//TIMER0_u8Setcallback(&PWM);
	//GIE_voidEnable();
	while(1)
	{
		u8 data=USART_recive_data();
		if(data=='1')
		{
			DIO_SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
		}
		else if(data=='2')
		{
			DIO_SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
		}

		USART_send_data('D');
	}
}

/*void PWM(void)
{
	static u8 Local_u8counter=0;
	Local_u8counter++;
	if(Local_u8counter==30)
	{
		DIO_SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
	}
	else if(Local_u8counter==60)
	{
		DIO_SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
		Local_u8counter=0;
	}
}*/
