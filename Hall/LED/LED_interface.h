/*
 * LED_interface.h
 *
 *  Created on: ???/???/????
 *      Author: user
 */

#ifndef HALL_LED_LED_INTERFACE_H_
#define HALL_LED_LED_INTERFACE_H_

// Definitions for LED connection types
#define LED_u8SourceConnection 1
#define LED_u8SinkConnection 0

// Structure to hold LED information
typedef struct
{
    u8 LED_u8Port;           // Port of the LED
    u8 LED_u8Pin;            // Pin of the LED
    u8 LED_u8ConnectionType; // Connection type of the LED (source/sink)
} LED_T;

// Function prototypes for LED control
u8 LED_u8TurnOnLED(const LED_T *LED);   // Turn on the LED
u8 LED_u8TurnOffLED(const LED_T *LED);  // Turn off the LED
u8 LED_u8Initialize(const LED_T *LED);   // Initialize the LED
u8 LED_u8Toggle(const LED_T *LED);       // Toggle the LED



#endif /* HALL_LED_LED_INTERFACE_H_ */
