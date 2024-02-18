/*
 * EXTI_interface.h
 *
 *  Created on: ???/???/????
 *      Author: user
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

void EXTI_voidInt0Init(void);
void EXTI_voidInt1Init(void);
void EXTI_voidInt2Init(void);
u8 EXTI_u8INT0Setcallback(void(*Copy_pvInt0func)(void));
u8 EXTI_u8INT1Setcallback(void(*Copy_pvInt1func)(void));
u8 EXTI_u8INT2Setcallback(void(*Copy_pvInt1func)(void));

#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
