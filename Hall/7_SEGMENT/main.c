/*
 * main.c

 *
 *  Created on: ???/???/????
 *      Author: user
 */
#include "_7SEGMENT_interface.h"

	int main()
	{
	_7SEGMENT_T ssg1={DIO_u8PORTA,DIO_u8PORTB,DIO_u8PIN0,_7SEGMENT_u8COMMONCATHODE,_7SEGMENT_u8Decoder,DIO_u8PIN2};
		_7SEGMENT_u8Initialize(&ssg1);
		while(1)
		{
			_7SEGMENT_u8ShowNumber(&ssg1,4);
		}
	return 0;
	}

