/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: user
 */


#include "../../../lib/std_types.h"
#include "../../../MCAL/PORT/PORT_interface.h"
#include "../../../MCAL/DIO/DIO_interface.h"
#include "../../../MCAL/ADC/ADC_interface.h"
#include "../../../Hall/CLCD/CLCD_interface.h"
#include <util/delay.h>

void main(void)
{
	PORT_voidInit();
	CLCD_voidInit();
	CLCD_voidSendString("ABD");
	ADC_voidInit();
	u8 local_u8ADCReading;
	u16 millivolt;
	while(1)
	{

		local_u8ADCReading=ADC_GetChannelReading(0);
		millivolt=(u16)((u32)local_u8ADCReading*5000UL)/256UL;
		CLCD_voidDisplayNumber(millivolt/10);
		_delay_ms(500);
		CLCD_voidClearLCD();


	}
}

