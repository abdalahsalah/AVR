/*
 * KPD_confg.h
 *
 *  Created on: ???/???/????
 *      Author: user
 */

#ifndef HALL_KAYPAD_KPD_CONFG_H_
#define HALL_KAYPAD_KPD_CONFG_H_

#define KPD_PORT        DIO_u8PORTD

#define KPD_COLUMN0_PIN       DIO_u8PIN0
#define KPD_COLUMN1_PIN       DIO_u8PIN1
#define KPD_COLUMN2_PIN       DIO_u8PIN2
#define KPD_COLUMN3_PIN       DIO_u8PIN3

#define KPD_ROW0_PIN       DIO_u8PIN4
#define KPD_ROW1_PIN       DIO_u8PIN5
#define KPD_ROW2_PIN       DIO_u8PIN6
#define KPD_ROW3_PIN       DIO_u8PIN7

#define KPD_NO_PREESED_KEY      0xff

#define KPD_ARR_VALUE   {{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'#','0','=','+'}}

#endif /* HALL_KAYPAD_KPD_CONFG_H_ */
