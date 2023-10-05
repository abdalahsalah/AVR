/*
 * DIO_program.c

 *
 *  Created on: ???/???/????
 *      Author: user
 */

#include "../../lib/std_types.h"  // Standard data types
#include "../../lib/BIT_MATH.h"   // Bit manipulation macros
#include "DIO_register.h"           // DIO register definitions
#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_private.h"


u8 DIO_SetPinDirection (u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy)
{
    u8 Local_u8ErrorState=0;
	/* Make sure that the Port ID and Pin ID are in the valid range */
	if (u8PinIdCopy <= DIO_u8PIN7)
	{
        if(u8PinDirCopy==DIO_u8PIN_INPUT)
        {
            switch(u8PortIdCopy)
            {
			case DIO_u8PORTA : CLR_BIT(DDRA,u8PinIdCopy); break;
			case DIO_u8PORTB : CLR_BIT(DDRB,u8PinIdCopy); break;
			case DIO_u8PORTC : CLR_BIT(DDRC,u8PinIdCopy); break;
			case DIO_u8PORTD : CLR_BIT(DDRD,u8PinIdCopy); break;
            default: Local_u8ErrorState=1;
            }
        }
        else if(u8PinDirCopy==DIO_u8PIN_OUTPUT)
        {
            switch(u8PortIdCopy)
            {
			case DIO_u8PORTA : SET_BIT(DDRA,u8PinIdCopy); break;
			case DIO_u8PORTB : SET_BIT(DDRB,u8PinIdCopy); break;
			case DIO_u8PORTC : SET_BIT(DDRC,u8PinIdCopy); break;
			case DIO_u8PORTD : SET_BIT(DDRD,u8PinIdCopy); break;
            default: Local_u8ErrorState=1; break;
            }
        }
        else
        {
            Local_u8ErrorState=1;
        }
    }
    else
    {
        Local_u8ErrorState=1;
    }

    return Local_u8ErrorState;
}

u8 DIO_SetPortDirection (u8 u8PortId, u8 u8PortDir)
{
    u8 Local_u8ErrorState=0;
    switch(u8PortId)
    {
			case DIO_u8PORTA : DDRA = u8PortDir ; break;
			case DIO_u8PORTB : DDRB = u8PortDir ; break;
			case DIO_u8PORTC : DDRC = u8PortDir ; break;
			case DIO_u8PORTD : DDRD = u8PortDir ; break;
            default: Local_u8ErrorState=1; break;
    }

    return Local_u8ErrorState;
}

u8 DIO_SetPinValue(u8 u8PortIdCopy , u8 u8PinIdCopy, u8 u8PinValCopy)
{
    u8 Local_u8ErrorState=0;
	/* Make sure that the Port ID and Pin ID are in the valid range */
	if (u8PinIdCopy <= DIO_u8PIN7)
	{
        if(u8PinValCopy==DIO_u8PIN_LOW)
        {
            switch(u8PortIdCopy)
            {
			case DIO_u8PORTA : CLR_BIT(PORTA,u8PinIdCopy); break;
			case DIO_u8PORTB : CLR_BIT(PORTB,u8PinIdCopy); break;
			case DIO_u8PORTC : CLR_BIT(PORTC,u8PinIdCopy); break;
			case DIO_u8PORTD : CLR_BIT(PORTD,u8PinIdCopy); break;
            default: Local_u8ErrorState=1;
            }
        }
        else if(u8PinValCopy==DIO_u8PIN_HIGH)
        {
            switch(u8PortIdCopy)
            {
			case DIO_u8PORTA : SET_BIT(PORTA,u8PinIdCopy); break;
			case DIO_u8PORTB : SET_BIT(PORTB,u8PinIdCopy); break;
			case DIO_u8PORTC : SET_BIT(PORTC,u8PinIdCopy); break;
			case DIO_u8PORTD : SET_BIT(PORTD,u8PinIdCopy); break;
            default: Local_u8ErrorState=1; break;
            }
        }
        else
        {
            Local_u8ErrorState=1;
        }
    }
    else
    {
        Local_u8ErrorState=1;
    }

    return Local_u8ErrorState;
}

u8 DIO_SetPortValue     (u8 u8PortId, u8 u8PortVal)
{
    u8 Local_u8ErrorState=0;
    switch(u8PortId)
    {
			case DIO_u8PORTA : PORTA = u8PortVal ; break;
			case DIO_u8PORTB : PORTB = u8PortVal ; break;
			case DIO_u8PORTC : PORTC = u8PortVal ; break;
			case DIO_u8PORTD : PORTD = u8PortVal ; break;
            default: Local_u8ErrorState=1; break;
    }

    return Local_u8ErrorState;
}

u8 DIO_GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy , u8* Pu8_ValCopy)
{
    u8 Local_u8ErrorState=0;
    if((Pu8_ValCopy!=NULL && u8PinIdCopy <= DIO_u8PIN7))
    {
    switch(u8PortIdCopy)
        {
			case DIO_u8PORTA : *Pu8_ValCopy = GET_BIT(PINA , u8PinIdCopy) ; break;
			case DIO_u8PORTB : *Pu8_ValCopy = GET_BIT(PINB , u8PinIdCopy) ; break;
			case DIO_u8PORTC : *Pu8_ValCopy = GET_BIT(PINC , u8PinIdCopy) ; break;
			case DIO_u8PORTD : *Pu8_ValCopy = GET_BIT(PIND , u8PinIdCopy) ; break;
            default: Local_u8ErrorState=1; break;
        }
    }
    else
    {
        Local_u8ErrorState=1;
    }

    return Local_u8ErrorState;

}

