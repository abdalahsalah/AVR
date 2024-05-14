/*
 * USART_prog.c

 *
 *  Created on: ???/???/????
 *      Author: user
 */

#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#include"USART_confg.h"
#include"USART_intrface.h"
#include"USART_priv.h"
#include"USART_reg.h"

void USART_init(void)
{

	u8 Localu8UCSRCvalue=0;
	SET_BIT(Localu8UCSRCvalue,7); //USE UCSRC
	// set char size 8 bit
	SET_BIT(Localu8UCSRCvalue,UCSRC_UCSZ1);
	SET_BIT(Localu8UCSRCvalue,UCSRC_UCSZ0);

	UCSRC=Localu8UCSRCvalue;

	UBRRL=51; //BAUD RATE 9600 bit/sec

	SET_BIT(UCSRB,UCSRB_TXEN); //enable tx
	SET_BIT(UCSRB,UCSRB_RXEN); //enable rx



}
void USART_send_data(u8 Copy_u8data)
{
	while(GET_BIT(UCSRA,UCSRA_UDRE)==0); //wait until transmit data is empty
	UDR=Copy_u8data;
}
u8 USART_recive_data(void)
{
	while(GET_BIT(UCSRA,UCSRA_RXC)==0);
	return UDR;
}
