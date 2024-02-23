/*
 * ADC_program.c

 *
 *  Created on: ???/???/????
 *      Author: user
 */
#include "../../lib/std_types.h"  // Standard data types
#include "../../lib/BIT_MATH.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "ADC_register.h"

void ADC_voidInit(void)
{

#if VOITAGE_REF==AVCC
	/*AVCC as reference voltage*/
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif VOITAGE_REF==AREF
	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif VOITAGE_REF==Internal_Voltage
	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);
#else
#error "Wrong VOITAGE_REF confg option"
#endif

#if leftright_adj==left_adj
	/*active ADC left adjust*/
	SET_BIT(ADMUX,ADMUX_ADLAR);
#elif leftright_adj==right_adj
	/*active ADC right adjust*/
	CLR_BIT(ADMUX,ADMUX_ADLAR);
#else
#error "Wrong leftright_adj confg option"
#endif


	/*set Prescaler*/
	ADCSRA&=0b11111000;
	ADCSRA|=PRESCALE_DIV;
	/*ADC Enable*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);


}

u8 ADC_GetChannelReading(u8 Copy_u8Channel)
{
	/*clear the MUX bits in ADMUX register*/
	ADMUX &=0b11100000;
	/*set the required channel into the MUX bits*/
	ADMUX |= Copy_u8Channel;
	/*start conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	/*Polling until the conversion complete flag is set*/
	while((GET_BIT(ADCSRA,ADCSRA_ADIF))==0); //flag is set
	/*Clear the conversion flag*/
	SET_BIT(ADCSRA,ADCSRA_ADIF); //flag is Clear

#if  res==_8_bit
	return ADCH;
#elif res==_10_bit
	return ADC;
#else
#error "Wrong leftright_adj confg option"
#endif
	/*Return the reading*/

}
