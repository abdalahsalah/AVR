/*
 * ADC_config.h
 *
 *  Created on: ???/???/????
 *      Author: user
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_

#define ADC_u32TimeOut 50000

/*Voltage reference select
** options:	1-AREF
**			2-AVCC
**			3-Internal_Voltage*/
#define VOITAGE_REF    AVCC

/*Prescaler
** Options:	DIV_BY_2	(DIV_FACTOR_2)
			DIV_BY_4	(DIV_FACTOR_4)
			DIV_BY_8	(DIV_FACTOR_8)
			DIV_BY_16	(DIV_FACTOR_16)
			DIV_BY_32	(DIV_FACTOR_32)
			DIV_BY_64	(DIV_FACTOR_64)
 			DIV_BY_128	(DIV_FACTOR_128)
*/

#define PRESCALE_DIV   DIV_FACTOR_128

/*left / right adjust settings
 *  options
 *    1-left adjust    (left_adj)
 *    2-right adjust    (right_adj)
 *    */

#define leftright_adj   left_adj

/*Auto trigger mode
 *  options:
 *    1-free running    (FREE)
 *    2-Anlog Comarator (COMP)
 *    3-External interrupt request (EXTI)
 * */
#define Auto_trigger_mode  FREE
#define ENABLE   1
#define DISABLE  0
#define Auto_trigger DISABLE

/*RES settings
 *  options
 *    1-8 BIT    (_8_bit)
 *    2-10 BIT    (_10_bit)
 *    */
#define  res  _8_bit

#endif /* MCAL_ADC_ADC_CONFIG_H_ */
