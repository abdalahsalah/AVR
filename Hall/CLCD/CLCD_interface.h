/*
 * CLCD_interface.h
 *
 *  Created on: ???/???/????
 *      Author: user
 */

#ifndef HALL_CLCD_CLCD_INTERFACE_H_
#define HALL_CLCD_CLCD_INTERFACE_H_

void CLCD_voidSendCommand(u8 Copy_u8Command);

void CLCD_voidSendData(u8 Copy_u8Data);

void CLCD_voidInit(void);

void CLCD_voidSendString(const char* Copy_pcString);

void CLCD_voidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos);

void CLCD_voidDisplaySpecialCharacter(u8* Copy_u8ArrayPtr, u8 Copy_u8BlockNum, u8 Copy_XPos, u8 Copy_YPos);

void CLCD_voidDisplayNumber(u32 Copy_u32Number);

void CLCD_voidClearLCD(void);
#endif /* HALL_CLCD_CLCD_INTERFACE_H_ */
