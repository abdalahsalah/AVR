/*
 * SPI.h
 *
 *  Created on: ???/???/????
 *      Author: user
 */

#ifndef MCAL_SPI_SPI_H_
#define MCAL_SPI_SPI_H_

void SPI_ReceiveString(u8 *str);
void SPI_SendString(u8 *str);
u8 SPI_ReceiveByte();
void SPI_SendByte(u8 data);
void SPI_InitSlave();
void SPI_InitMaster();


#endif /* MCAL_SPI_SPI_H_ */
