/*
 * PORT_program.c

 *
 *  Created on: ???/???/????
 *      Author: user
 */

#include "../../lib/std_types.h"
#include "PORT_config.h"
#include "PORT_private.h"
#include "PORT_interface.h"
#include "PORT_register.h"

void PORT_voidInit(void)
{
	DDRA=PORTA_DIR;
	DDRB=PORTB_DIR;
	DDRC=PORTC_DIR;
	DDRD=PORTD_DIR;

	PORTA=PORTA_INIT_VALUE;
	PORTB=PORTB_INIT_VALUE;
	PORTD=PORTD_INIT_VALUE;
	PORTD=PORTC_INIT_VALUE;
}
