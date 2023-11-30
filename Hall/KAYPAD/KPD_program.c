/*
 * KPD_program.c

 *
 *  Created on: ???/???/????
 *      Author: user
 */

#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "KPD_confg.h"
#include "KPD_interface.h"
#include "KPD_private.h"
#include <util/delay.h>


u8 KPD_u8GetPressedkey(void)
{
	u8 Local_u8Pressedkey=KPD_NO_PREESED_KEY,Local_u8ColumnIdx,Local_u8RowIdx,Local_u8PinState;

	static u8 Local_u8KPDArr[4][4] = KPD_ARR_VALUE;

	static u8 Local_u8KPDColumnArr[COLUMN_NUM]={KPD_COLUMN0_PIN,KPD_COLUMN1_PIN,KPD_COLUMN2_PIN,KPD_COLUMN3_PIN};

	static u8 Local_u8KPDROWSArr[ROW_NUM]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};

	for(Local_u8ColumnIdx=0;Local_u8ColumnIdx<COLUMN_NUM;Local_u8ColumnIdx++)
	{
		/*Activate current column*/
		DIO_SetPinValue(KPD_PORT,Local_u8KPDColumnArr[Local_u8ColumnIdx],DIO_u8PIN_LOW);

		for(Local_u8RowIdx=0;Local_u8RowIdx<ROW_NUM;Local_u8RowIdx++)
		{
			/*Read the current row*/
			DIO_GetPinValue(KPD_PORT,Local_u8KPDROWSArr[Local_u8RowIdx],&Local_u8PinState);

			/*check if switch is pressed*/
			if(DIO_u8PIN_LOW==Local_u8PinState)
			{
				Local_u8Pressedkey=Local_u8KPDArr[Local_u8RowIdx][Local_u8ColumnIdx];

				/*poling(busy waiting) until the key is released*/
				while(DIO_u8PIN_LOW==Local_u8PinState)
				{
					DIO_GetPinValue(KPD_PORT,Local_u8KPDROWSArr[Local_u8RowIdx],&Local_u8PinState);
				}
				return Local_u8Pressedkey;
			}
		}
		/*Deactivate current column*/
		DIO_SetPinValue(KPD_PORT,Local_u8KPDColumnArr[Local_u8ColumnIdx],DIO_u8PIN_HIGH);
	}
	return Local_u8Pressedkey;
}
