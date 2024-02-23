/*
 * ADC_interface.h
 *
 *  Created on: ???/???/????
 *      Author: user
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

#define      AREF             1
#define      AVCC             2
#define      Internal_Voltage 3

#define      ADC_PRESCALER_MASK   0b11111000
#define      DIV_FACTOR_2            0
#define      DIV_FACTOR_4            2
#define      DIV_FACTOR_8            3
#define      DIV_FACTOR_16           4
#define      DIV_FACTOR_32           5
#define      DIV_FACTOR_64           6
#define      DIV_FACTOR_128          7

#define      SINGLE_ENDED_ADC0       0
#define      SINGLE_ENDED_ADC1       1
#define      SINGLE_ENDED_ADC2       2
#define      SINGLE_ENDED_ADC3       3
#define      SINGLE_ENDED_ADC4       4
#define      SINGLE_ENDED_ADC5       5
#define      SINGLE_ENDED_ADC6       6
#define      SINGLE_ENDED_ADC7       7
#define      SINGLE_ENDED_1_22V      30
#define      SINGLE_ENDED_GND        31
void ADC_voidInit(void);

u8 ADC_GetChannelReading(u8 Copy_u8Channel);

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
