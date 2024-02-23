/*
 * DAC_program.c

 *
 *  Created on: ???/???/????
 *      Author: user
 */

#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "DAC_interface.h"

void DAC_voidAnalogvalue(u8 Copy_u8Value,u8 Copy_u8Port)
{
	u8 Local_u8DigetalOutput=Copy_u8Value*51;
	DIO_SetPortValue(Copy_u8Port,Local_u8DigetalOutput);
}
