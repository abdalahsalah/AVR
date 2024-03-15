/*
 * TIMER_program.c

 *
 *  Created on: ???/???/????
 *      Author: user
 */

#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#include "TIMER_interface.h"
#include "TIMER_register.h"
#include "TIMER_private.h"
#include "TIMER_configrtion.h"
static void (*TIMER0_pvCallBackFunc)(void)=NULL;

void TIMER0_voidInit(void)
{
	/*Select mode*/
#if TIMER0_MODE==NORMAL
	CLR_BIT(TCCR0,TCCR0_WGM01);
	CLR_BIT(TCCR0,TCCR0_WGM00);
#elif TIMER0_MODE==CTC
	SET_BIT(TCCR0,TCCR0_WGM01);
	CLR_BIT(TCCR0,TCCR0_WGM00);
#elif TIMER0_MODE==PWM
	CLR_BIT(TCCR0,TCCR0_WGM01);
	SET_BIT(TCCR0,TCCR0_WGM00);
#elif TIMER0_MODE==Fast_PWM
	SET_BIT(TCCR0,TCCR0_WGM01);
	SET_BIT(TCCR0,TCCR0_WGM00);
#else
#error "Wrong TIMER0_MODE confg option"
#endif
	/*Output compare match interrupt enable*/
#if TIMER0_INTERRUPT_MODE==Compare_Match_Interrupt
	SET_BIT(TIMSK,TIMSK_OCIE0);

#elif TIMER0_INTERRUPT_MODE==Overflow_Interrupt
	SET_BIT(TIMSK,TIMSK_TOIE0);
#elif TIMER0_INTERRUPT_MODE==DESABLE
	CLR_BIT(TIMSK,TIMSK_TOIE0);
	CLR_BIT(TIMSK,TIMSK_OCIE0);
#else
#error "Wrong TIMER0_INTERRUPT_MODE confg option"
#endif
	/*Select prescaler*/
#if TIMER0_PRE==clkI_8
	/*Select prescaler div by 8*/
	CLR_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
#elif TIMER0_PRE==clkI_64
	/*Select prescaler div by 64*/
	SET_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
#elif TIMER0_PRE==clkI_256
	/*Select prescaler div by 256*/
	CLR_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS02);
#elif TIMER0_PRE==clkI_1024
	/*Select prescaler div by 1024*/
	SET_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS02);
#else
#error "Wrong TIMER0_INTERRUPT_MODE confg option"
#endif
}

void TIMER0_outputfastpwmmode(void)
{

#if Fast_PWM_mode==clearoncompmatch_setontop
		CLR_BIT(TCCR0,TCCR0_COM00);
		SET_BIT(TCCR0,TCCR0_COM01);
#elif Fast_PWM_mode==setoncompmatch_clearontop
		CLR_BIT(TCCR0,TCCR0_COM00);
		SET_BIT(TCCR0,TCCR0_COM01);
#else
#error "Wrong TIMER0_Fast_PWM_MODE confg option"
#endif

}

void TIMER0_u8setcompmatchvalue(u8 copy_u8value)
{
	OCR0=copy_u8value;
}

u8 TIMER0_u8Setcallback(void(*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8errorstatus=OK;
	if(Copy_pvCallBackFunc != NULL)
	{
		TIMER0_pvCallBackFunc= Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8errorstatus=NULL_POINTER;
	}

	return Local_u8errorstatus;
}

void __vector_10 (void)__attribute__((signal));
void __vector_10 (void)
{
	if(TIMER0_pvCallBackFunc!= NULL)
	{
		TIMER0_pvCallBackFunc();
	}
}
