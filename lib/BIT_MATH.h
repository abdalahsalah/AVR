/*
 * BIT_MATH.h
 *
 *  Created on: ???/???/????
 *      Author: user
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

#define SET_BIT(VAR, BIT_NO)	(VAR|= (1<<BIT_NO))
#define CLR_BIT(VAR, BIT_NO)	(VAR&= ~(1<<BIT_NO))
#define TOGGLE_BIT(VAR, BIT_NO)		(VAR^=(1<<BIT_NO))
#define GET_BIT(VAR, BIT_NO)	((VAR>>BIT_NO) & 0x01)

#endif /* LIB_BIT_MATH_H_ */
