/*
 * CLCD_program.c

 *
 *  Created on: ???/???/????
 *      Author: user
 */


#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"
#include <util/delay.h>



void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	/*Set RS Pin Low for command*/
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);

	/*Set RW Pin to low for write */
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	/*Set command to data port */
	DIO_SetPortValue(CLCD_DATA_PORT,Copy_u8Command);

	/*Send enable pulse*/
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

}

void CLCD_voidSendData(u8 Copy_u8Data)
{
	/*Set RS Pin High for data*/
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);

	/*Set RW Pin to low for write */
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	/*Set data to data port */
	DIO_SetPortValue(CLCD_DATA_PORT,Copy_u8Data);

	/*Send enable pulse*/
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

}

void CLCD_voidInit(void)

{
	/*wait for more than 30 ms */
	_delay_ms(40);

	/* function set command : 2 line , 5*8 font size */
	CLCD_voidSendCommand(0b00111100);

	/* display on off control: display enable, disable cursor , no blink cursor*/
	CLCD_voidSendCommand(0b00001100);

	/* clear display */
	CLCD_voidSendCommand(1);

}

void CLCD_voidSendString(const char* Copy_pcString)
{
	u8 Local_u8Counter = 0;
	while (Copy_pcString[Local_u8Counter] != '\0')
	{
		CLCD_voidSendData(Copy_pcString[Local_u8Counter++]);
	}
}

void CLCD_voidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8Address;

	if(Copy_u8XPos==0)
	{
		Local_u8Address=Copy_u8YPos;
	}
	else if(Copy_u8XPos==1)
	{
		Local_u8Address=Copy_u8YPos+0x40;
	}
	CLCD_voidSendCommand(Local_u8Address+ 128);
}

void CLCD_voidDisplaySpecialCharacter(u8* Copy_u8ArrayPtr, u8 Copy_u8BlockNum, u8 Copy_XPos, u8 Copy_YPos)
{
	u8 Local_u8CGRAMAddress = 0;

	Local_u8CGRAMAddress=Copy_u8BlockNum*8;

	CLCD_voidSendCommand(Local_u8CGRAMAddress+64);

	for(u8 Local_u8Counter = 0; Local_u8Counter < 8; Local_u8Counter++)
	{
		CLCD_voidSendData(Copy_u8ArrayPtr[Local_u8Counter]);
	}

	CLCD_voidGoToXY(Copy_XPos,Copy_YPos);

	CLCD_voidSendData(Copy_u8BlockNum);
}

void CLCD_voidDisplayNumber(u32 Copy_u32Number)
{
	if (Copy_u32Number == 0)
	{
		CLCD_voidSendData('0');
	}
	else
	{
	u8 Local_u8Digit = 0, Local_u8Counter = 0, Local_u8digitCount = 0;;
	u32 Local_u32Temp =  Copy_u32Number;
	do {
		Local_u8digitCount++;
		Local_u32Temp /= 10;
	} while (Local_u32Temp != 0);

	u8 Local_u8ArrDigits[Local_u8digitCount];

	while (Copy_u32Number != 0 && Local_u8Counter < Local_u8digitCount)
	{
		Local_u8Digit = Copy_u32Number % 10;
		Local_u8ArrDigits[Local_u8Counter] = Local_u8Digit;
		Local_u8Counter++;
		Copy_u32Number = Copy_u32Number / 10;
	}
	Local_u8digitCount--;
	for (Local_u8Counter = 0 ; Local_u8Counter <= Local_u8digitCount ; Local_u8Counter++)
	{

		switch (Local_u8ArrDigits[Local_u8digitCount - Local_u8Counter])
		{
			case 0: CLCD_voidSendData('0'); break;
			case 1: CLCD_voidSendData('1'); break;
			case 2: CLCD_voidSendData('2'); break;
			case 3: CLCD_voidSendData('3'); break;
			case 4: CLCD_voidSendData('4'); break;
			case 5: CLCD_voidSendData('5'); break;
			case 6: CLCD_voidSendData('6'); break;
			case 7: CLCD_voidSendData('7'); break;
			case 8: CLCD_voidSendData('8'); break;
			case 9: CLCD_voidSendData('9'); break;
		}
	}
	}
}

void CLCD_voidClearLCD(void)
{
	CLCD_voidSendCommand(CLCD_CLEAR_CMD);
}
