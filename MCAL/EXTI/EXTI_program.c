/*
 * EXTI_program.c

 *
 *  Created on: ???/???/????
 *      Author: user
 */

#include "../../lib/std_types.h"  // Standard data types
#include "../../lib/BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_register.h"
#include "EXTI_config.h"

/*Global pointer to function to hold int0 ISR address */

void (*EXTI_pvInt0Func)(void)=NULL;

/*Global pointer to function to hold int1 ISR address */

void (*EXTI_pvInt1Func)(void)=NULL;

/*Global pointer to function to hold int2 ISR address */

void (*EXTI_pvInt2Func)(void)=NULL;

void EXTI_voidInt0Init(void)
{
/*1- check sense control*/

#if INT0_SENSE == low_level
	CLR_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENSE == on_change
	SET_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENSE == falling_edge
	CLR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENSE == rising_edge
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#else
#error "Wrong INT0_SENSE confg option"
#endif

	/*peripheral interrupt enable for int0 */
#if INT0_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT0);
#elif INT0_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT0);
#else
#error "Wrong INT0_INITIAL_STATE option"
#endif
}
void EXTI_voidInt1Init(void)
{
/*1- check sense control*/

#if INT1_SENSE == low_level
	CLR_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);

#elif INT1_SENSE == on_change
	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);

#elif INT1_SENSE == falling_edge
	CLR_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);

#elif INT1_SENSE == rising_edge
	SET_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
#else
#error "Wrong INT0_SENSE confg option"
#endif

	/*peripheral interrupt enable for int0 */
#if INT1_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT1);
#elif INT1_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT1);
#else
#error "Wrong INT1_INITIAL_STATE option"
#endif
}
void EXTI_voidInt2Init(void)
{
#if INT2_SENSE == falling_edge
	CLR_BIT(MCUCSR,MCUCSR_INT2);
#elif INT2_SENSE == rising_edge
	SET_BIT(MCUCSR,MCUCSR_INT2);
#else
#error "Wrong INT0_SENSE confg option"
#endif

	/*peripheral interrupt enable for int0 */
#if INT2_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT0);
#elif INT2_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT0);
#else
#error "Wrong INT1_INITIAL_STATE option"
#endif
}
u8 EXTI_u8INT0Setcallback(void(*Copy_pvInt0func)(void))
{
	u8 Local_u8errorstatus=OK;
	if(Copy_pvInt0func != NULL)
	{
		EXTI_pvInt0Func=Copy_pvInt0func;
	}
	else
	{
		Local_u8errorstatus=NULL_POINTER;
	}

	return Local_u8errorstatus;
}
u8 EXTI_u8INT1Setcallback(void(*Copy_pvInt1func)(void))
{
	u8 Local_u8errorstatus=OK;
	if(Copy_pvInt1func != NULL)
	{
		EXTI_pvInt1Func=Copy_pvInt1func;
	}
	else
	{
		Local_u8errorstatus=NULL_POINTER;
	}

	return Local_u8errorstatus;
}
/*INT0 ISR*/
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if(EXTI_pvInt0Func!=NULL)
	{
		EXTI_pvInt0Func();
	}
	else
	{
		/* Do Nothing*/
	}
}
/*INT1 ISR*/
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if(EXTI_pvInt1Func!=NULL)
	{
		EXTI_pvInt1Func();
	}
	else
	{
		/* Do Nothing*/
	}
}
/*INT2 ISR*/
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if(EXTI_pvInt2Func!=NULL)
	{
		EXTI_pvInt2Func();
	}
	else
	{
		/* Do Nothing*/
	}
}



