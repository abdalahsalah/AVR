/*
 * TIMER_interface.h
 *
 *  Created on: ???/???/????
 *      Author: user
 */

#ifndef MCAL_TIMERS_TIMER_INTERFACE_H_
#define MCAL_TIMERS_TIMER_INTERFACE_H_

void TIMER0_voidInit(void);
u8 TIMER0_u8Setcallback(void(*Copy_pvCallBackFunc)(void));
void TIMER0_u8setcompmatchvalue(u8 copy_u8value);
void TIMER0_outputfastpwmmode(void);
#endif /* MCAL_TIMERS_TIMER_INTERFACE_H_ */
