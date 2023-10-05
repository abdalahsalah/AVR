/*
 * DIO_interface.h
 *
 *  Created on: ???/???/????
 *      Author: user
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

// Constants representing port identifiers
#define DIO_u8PORTA 0
#define DIO_u8PORTB 1
#define DIO_u8PORTC 2
#define DIO_u8PORTD 3

// Constants for pin direction (input/output)
#define DIO_u8PIN_OUTPUT 1
#define DIO_u8PIN_INPUT 0

// Constants for pin value (high/low)
#define DIO_u8PIN_HIGH 1
#define DIO_u8PIN_LOW 0

// Constants for port direction (input/output)
#define DIO_u8PORT_OUTPUT 0xFF
#define DIO_u8PORT_INPUT 0

// Constants for port value (high/low)
#define DIO_u8PORT_HIGH 0xFF
#define DIO_u8PORT_LOW 0

// Constants for individual pins
#define DIO_u8PIN0 0
#define DIO_u8PIN1 1
#define DIO_u8PIN2 2
#define DIO_u8PIN3 3
#define DIO_u8PIN4 4
#define DIO_u8PIN5 5
#define DIO_u8PIN6 6
#define DIO_u8PIN7 7
/* IO Pins */
u8 DIO_SetPinValue(u8 u8PortCopy , u8 u8PinIdCopy, u8 u8PinValCopy);

u8 DIO_GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy , u8* u8PinValCopy);

u8 DIO_SetPinDirection (u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy);

/* IO Ports */
u8 DIO_SetPortDirection (u8 u8PortId, u8 u8PortDir);

u8 DIO_SetPortValue     (u8 u8PortId, u8 u8PortVal);

#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
