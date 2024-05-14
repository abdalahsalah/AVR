/*
 * SPI.c

 *
 *  Created on: ???/???/????
 *      Author: user
 */
#include <avr/io.h>
#include "../../lib/std_types.h"
#include "../../lib/BIT_MATH.h"
#include "SPI.h"

void SPI_InitMaster()
{
	DDRB |= (1<<PB4)|(1<<PB5)|(1<<PB7);
	SPCR |= (1<<SPE)|(1<<MSTR);
}

void SPI_InitSlave()
{
	DDRB |= (1<<PB6);
	SPCR |= (1<<SPE);
}

void SPI_SendByte(u8 data)
{
	SPDR = data;
	while(Bit_Is_Clear(SPSR,SPIF));
}

u8 SPI_ReceiveByte()
{
	while(Bit_Is_Clear(SPSR,SPIF));
	return SPDR;
}

void SPI_SendString(u8 *str)
{
	while(*str)
	{
		SPI_SendByte(*str);
		str++;
	}
}

void SPI_ReceiveString(u8 *str)
{
	u8 i = 0;
	str[i] = SPI_ReceiveByte();
	while(str[i] != '#')
	{
		i++;
		str[i] = SPI_ReceiveByte();
	}
	str[i] = '\0';
}
