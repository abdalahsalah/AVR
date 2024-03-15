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
#include <util/delay.h>
//void PWM(void);
void main(void)
{
	u8 Local_u8counter=0;
	PORT_voidInit();
	TIMER0_voidInit();
	TIMER0_outputfastpwmmode();
	//TIMER0_u8Setcallback(&PWM);
	//GIE_voidEnable();
	while(1)
	{
		for(Local_u8counter=0;Local_u8counter<255;Local_u8counter++)
		{
			TIMER0_u8setcompmatchvalue(Local_u8counter);
			_delay_ms(10);
		}

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
