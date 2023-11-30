/*
 * SWITCH_program.c

 *
 *  Created on: ???/???/????
 *      Author: user
 */

#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "SWITCH_interface.h"
#include <util/delay.h>

// Function to get the pressed state of a SWITCH
u8 SWITCH_u8Switchgetpressed(const SWITCH_T *SWITCH, u8 *copySwitchState) {
	u8 local_u8error = 0, local_pinValue;

	if ((copySwitchState != NULL) && (SWITCH != NULL) && (SWITCH->SWITCH_u8pin <= DIO_u8PIN7) && (SWITCH->SWITCH_u8port <= DIO_u8PORTD) && (SWITCH->SWITCH_u8BounceType < 2) && (SWITCH->SWITCH_u8ConnectionType < 3)) {
		// Configure pin as input

		// Apply bounce or debounce based on connection type
		if (SWITCH->SWITCH_u8BounceType == SWITCH_u8Bounce) {
			// Apply bounce handling by reading the pin value after a delay
			DIO_GetPinValue(SWITCH->SWITCH_u8port, SWITCH->SWITCH_u8pin, &local_pinValue);
			_delay_ms(500);
			DIO_GetPinValue(SWITCH->SWITCH_u8port, SWITCH->SWITCH_u8pin, &local_pinValue);
		} else if (SWITCH->SWITCH_u8BounceType == SWITCH_u8Debounce) {
			// Apply debounce by reading the pin value twice
			DIO_GetPinValue(SWITCH->SWITCH_u8port, SWITCH->SWITCH_u8pin, &local_pinValue);
		}

		// Determine the switch state based on connection type and pin value
		switch (SWITCH->SWITCH_u8ConnectionType) {
			case SWITCH_u8PullUp:
				*copySwitchState = (local_pinValue) ? SWITCH_u8NotPressed : SWITCH_u8Pressed;
				break;
			case SWITCH_u8PullDown:
				*copySwitchState = (local_pinValue) ? SWITCH_u8Pressed : SWITCH_u8NotPressed;
				break;
			case SWITCH_u8InternalPullUp:
				DIO_SetPinValue(SWITCH->SWITCH_u8port, SWITCH->SWITCH_u8pin, DIO_u8PIN_OUTPUT);
				*copySwitchState = (local_pinValue) ? SWITCH_u8NotPressed : SWITCH_u8Pressed;
				break;
		}
	} else {
		local_u8error = 1;  // Invalid pin, set error flag
	}
	return local_u8error;
}

// Function to initialize a SWITCH
u8 SWITCH_u8Switchinitialize(const SWITCH_T *SWITCH) {
	u8 local_u8error = 0;

	if ((SWITCH != NULL) && (SWITCH->SWITCH_u8pin <= DIO_u8PIN7) && (SWITCH->SWITCH_u8port <= DIO_u8PORTD) && (SWITCH->SWITCH_u8BounceType < 2) && (SWITCH->SWITCH_u8ConnectionType < 2)) {
		DIO_SetPinDirection(SWITCH->SWITCH_u8port, SWITCH->SWITCH_u8pin, DIO_u8PIN_INPUT);
	} else {
		local_u8error = 1;
	}
	return local_u8error;
}

