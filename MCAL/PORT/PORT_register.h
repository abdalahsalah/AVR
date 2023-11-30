/*
 * PORT_register.h

 *
 *  Created on: ???/???/????
 *      Author: user
 */

#ifndef MCAL_PORT_PORT_REGISTER_H_
#define MCAL_PORT_PORT_REGISTER_H_

#define DDRA   *((volatile u8*)0x3A)
#define DDRB   *((volatile u8*)0x37)
#define DDRC   *((volatile u8*)0x34)
#define DDRD   *((volatile u8*)0x31)

#define PORTA  *((volatile u8*)0x3B)
#define PORTB  *((volatile u8*)0x38)
#define PORTC  *((volatile u8*)0x35)
#define PORTD  *((volatile u8*)0x32)


#endif /* MCAL_PORT_PORT_REGISTER_H_ */
