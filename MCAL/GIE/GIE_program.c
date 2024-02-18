/*
 * GIE_program.c
 *
 *  Created on: ???/???/????
 *      Author: user
 */

#include "../../lib/std_types.h"  // Standard data types
#include "../../lib/BIT_MATH.h"
#include "GIE_interface.h"
#include "GIE_register.h"

void GIE_voidEnable(void)
{
	SET_BIT(SREG,SREG_I);
}
void GIE_voidDisable(void)
{
	CLR_BIT(SREG,SREG_I);
}
