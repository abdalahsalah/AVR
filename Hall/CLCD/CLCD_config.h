/*
 * CLCD_config.h

 *
 *  Created on: ???/???/????
 *      Author: user
 */

#ifndef HALL_CLCD_CLCD_CONFIG_H_
#define HALL_CLCD_CLCD_CONFIG_H_

#define CLCD_DATA_PORT        DIO_u8PORTA

#define CLCD_CTRL_PORT        DIO_u8PORTB

#define CLCD_RS_PIN           DIO_u8PIN0
#define CLCD_RW_PIN           DIO_u8PIN1
#define CLCD_E_PIN            DIO_u8PIN2

#define CLCD_CLEAR_CMD 		  0b00000001


#endif /* HALL_CLCD_CLCD_CONFIG_H_ */
