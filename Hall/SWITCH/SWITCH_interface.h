/*
 * SWITCH_interface.h
 *
 *  Created on: ???/???/????
 *      Author: user
 */

#ifndef HALL_SWITCH_SWITCH_INTERFACE_H_
#define HALL_SWITCH_SWITCH_INTERFACE_H_

// Define the clock frequency for delay functions
#define F_CPU 8000000  // Example frequency, adjust as needed

// Definitions for SWITCH debounce types
#define SWITCH_u8Bounce 1
#define SWITCH_u8Debounce 0

// Definitions for SWITCH pull-up/pull-down types
#define SWITCH_u8PullUp 0
#define SWITCH_u8PullDown 1
#define SWITCH_u8InternalPullUp 2

// Definitions for SWITCH states
#define SWITCH_u8Pressed 1
#define SWITCH_u8NotPressed 0

// Structure to hold SWITCH information
typedef struct
{
    u8 SWITCH_u8port;           // Port of the SWITCH
    u8 SWITCH_u8pin;            // Pin of the SWITCH
    u8 SWITCH_u8ConnectionType; // Connection type of the SWITCH
    u8 SWITCH_u8BounceType;     // Bounce type of the SWITCH
} SWITCH_T;

// Variable to store SWITCH state
u8 SWITCH_state;

// Function prototype to get the pressed state of a SWITCH
u8 SWITCH_u8Switchgetpressed(const SWITCH_T *SWITCH, u8 *copySwitchState);

// Function prototype to initialize a SWITCH
u8 SWITCH_u8Switchinitialize(const SWITCH_T *SWITCH);

#endif /* HALL_SWITCH_SWITCH_INTERFACE_H_ */
