/*
 * TIMER_private.h

 *
 *  Created on: ???/???/????
 *      Author: user
 */

#ifndef MCAL_TIMERS_TIMER_PRIVATE_H_
#define MCAL_TIMERS_TIMER_PRIVATE_H_

#define     NORMAL        	1
#define		PWM        		2
#define		CTC     		3
#define		Fast_PWM      	4

#define     clkI_8        	1
#define		clkI_64        	2
#define		clkI_256     	3
#define		clkI_1024      	4

#define     clearoncompmatch_setontop      1
#define     setoncompmatch_clearontop      2

#define     Compare_Match_Interrupt          1
#define     Overflow_Interrupt         		 2
#define     DESABLE                          3

#endif /* MCAL_TIMERS_TIMER_PRIVATE_H_ */
