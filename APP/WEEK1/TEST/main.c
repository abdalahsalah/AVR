/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: user
 */


#include "../../../lib/std_types.h"
#include "../../../MCAL/PORT/PORT_interface.h"
#include "../../../MCAL/DIO/DIO_interface.h"
#include "../../../MCAL/GIE/GIE_interface.h"
#include "../../../MCAL/EXTI/EXTI_interface.h"

void int0_isr(void);
void int1_isr(void);
void main(void)
{
	PORT_voidInit();
	EXTI_voidInt0Init();
	EXTI_voidInt1Init();
	EXTI_u8INT0Setcallback(int0_isr);
	EXTI_u8INT1Setcallback(int1_isr);
	GIE_voidEnable();

	while(1)
	{

	}
}

void int0_isr(void)
{
	DIO_SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
}
void int1_isr(void)
{
	DIO_SetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_HIGH);
}

