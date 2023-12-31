/*
 * DIO_regester.h
 *
 *  Created on: ???/???/????
 *      Author: user
 */

#ifndef MCAL_DIO_DIO_REGISTER_H_
#define MCAL_DIO_DIO_REGISTER_H_

/* Group A Registers */
#define PORTA  *((volatile u8*)0x3B)

#define PINA   *((volatile u8*)0x39)

/* Group B Registers */
#define PORTB  *((volatile u8*)0x38)

#define PINB   *((volatile u8*)0x36)

/* Group C Registers */
#define PORTC  *((volatile u8*)0x35)

#define PINC   *((volatile u8*)0x33)

/* Group D Registers */
#define PORTD  *((volatile u8*)0x32)

#define PIND   *((volatile u8*)0x30)

#define DDRA   *((volatile u8*)0x3A)
#define DDRB   *((volatile u8*)0x37)
#define DDRC   *((volatile u8*)0x34)
#define DDRD   *((volatile u8*)0x31)

#endif /* MCAL_DIO_DIO_REGISTER_H_ */
