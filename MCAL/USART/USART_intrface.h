/*
 * USART_intrface.h
 *
 *  Created on: ???/???/????
 *      Author: user
 */

#ifndef MCAL_USART_USART_INTRFACE_H_
#define MCAL_USART_USART_INTRFACE_H_

void USART_init(void);
void USART_send_data(u8 Copy_u8data);
u8 USART_recive_data(void);

#endif /* MCAL_USART_USART_INTRFACE_H_ */
