/*
 * EXTI_config.h
 *
 *  Created on: ???/???/????
 *      Author: user
 */

#ifndef MCAL_EXTI_EXTI_CONFIG_H_
#define MCAL_EXTI_EXTI_CONFIG_H_

/* Options:
		 * low_level
		 * on_change
		 * falling_edge
		 * rising_edge
*/
#define INT0_SENSE   falling_edge

/* Options:
		 * ENABLED
		 * DISABLED
*/

#define INT0_INITIAL_STATE  ENABLED

/* Options:
		 * low_level
		 * on_change
		 * falling_edge
		 * rising_edge
*/
#define INT1_SENSE   falling_edge

/* Options:
		 * ENABLED
		 * DISABLED
*/

#define INT1_INITIAL_STATE  ENABLED

/* Options:
		 * falling_edge
		 * rising_edge
*/
#define INT2_SENSE   falling_edge

/* Options:
		 * ENABLED
		 * DISABLED
*/

#define INT2_INITIAL_STATE  DISABLED

#endif /* MCAL_EXTI_EXTI_CONFIG_H_ */
