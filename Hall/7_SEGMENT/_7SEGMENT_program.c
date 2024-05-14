///*
// * 7_SEGMENT_program.c
//
//
// *
// *  Created on: ???/???/????
// *      Author: user
// */
//#include "../../lib/STD_TYPES.h"
//#include "../../lib/BIT_MATH.h"
//#include "../../MCAL/DIO/DIO_interface.h"
//#include "_7SEGMENT_interface.h"
//
///* Lookup table for segment patterns corresponding to each number */
//static u8 _7SEGMENTNUM[10] =
//{
//	0b00111111, // 0
//	0b00000110, // 1
//	0b01011011, // 2
//	0b01001111, // 3
//	0b01100110, // 4
//	0b01101101, // 5
//	0b01111101, // 6
//	0b00000111, // 7
//	0b01111111, // 8
//	0b01101111  // 9
//};
//
///**
//* Function to display a specific number on the 7SEGMENT display.
//*
//* @param _7SEGMENT Pointer to the _7SEGMENT_T structure.
//* @param copy_u8number The number to be displayed (0-9).
//* @return Status indicating success (0) or failure (1).
//*/
//u8 _7SEGMENT_u8ShowNumber(const _7SEGMENT_T  *_7SEGMENT, const u8 copy_u8number)
//{
//	u8 local_u8error = 0;
//	s8 i = 0;
//	if ((_7SEGMENT != NULL) && (_7SEGMENT->_7SEGMENT_u8port <= DIO_u8PORTD) && (_7SEGMENT->_7SEGMENT_u8enablepin < DIO_u8PIN7) && (_7SEGMENT->_7SEGMENT_u8enableport <= DIO_u8PORTD) && (_7SEGMENT->_7SEGMENT_u8commontype < 2) && (copy_u8number < 10)  )
//	{
//
//		switch (_7SEGMENT->_7SEGMENT_u8Decoders)
//		{
//			case _7SEGMENT_u8Decoder:
//			if ((_7SEGMENT->_7SEGMENT_u8Decoderstartpin < 5))
//			{
//				switch (_7SEGMENT->_7SEGMENT_u8commontype)
//				{
//					case _7SEGMENT_u8COMMONCATHODE:
//					DIO_SetPinValue(_7SEGMENT->_7SEGMENT_u8enableport, _7SEGMENT->_7SEGMENT_u8enablepin, DIO_u8PIN_LOW);
//					for (i=0;i<4;i++)
//					{
//						if ((copy_u8number & (1 <<i)))
//						{
//							DIO_SetPinValue(_7SEGMENT->_7SEGMENT_u8port, ((_7SEGMENT->_7SEGMENT_u8Decoderstartpin) + i), DIO_u8PIN_HIGH);
//						}
//						else
//						{
//							DIO_SetPinValue(_7SEGMENT->_7SEGMENT_u8port, ((_7SEGMENT->_7SEGMENT_u8Decoderstartpin) + i), DIO_u8PIN_LOW);
//						}
//					}
//					break;
//					case _7SEGMENT_u8COMMONANODE:
//
//					DIO_SetPinValue(_7SEGMENT->_7SEGMENT_u8enableport, _7SEGMENT->_7SEGMENT_u8enablepin, DIO_u8PIN_HIGH);
//					for (i = 0; i < 4; i++)
//					{
//						if ((copy_u8number & (1 << i)))
//						{
//							DIO_SetPinValue(_7SEGMENT->_7SEGMENT_u8port, ((_7SEGMENT->_7SEGMENT_u8Decoderstartpin) + i), DIO_u8PIN_LOW);
//						}
//						else
//						{
//							DIO_SetPinValue(_7SEGMENT->_7SEGMENT_u8port, ((_7SEGMENT->_7SEGMENT_u8Decoderstartpin) + i), DIO_u8PIN_HIGH);
//						}
//					}
//					break;
//				}
//
//
//			}
//			else
//			{
//				local_u8error=1;
//			}
//			break;
//			case _7SEGMENT_u8Nodecoder:
//			switch (_7SEGMENT->_7SEGMENT_u8commontype)
//			{
//				case _7SEGMENT_u8COMMONCATHODE:
//				DIO_SetPinValue(_7SEGMENT->_7SEGMENT_u8enableport, _7SEGMENT->_7SEGMENT_u8enablepin, DIO_u8PIN_LOW);
//				DIO_SetPortValue(_7SEGMENT->_7SEGMENT_u8port, _7SEGMENTNUM[copy_u8number]);
//				break;
//				case _7SEGMENT_u8COMMONANODE:
//				DIO_SetPinValue(_7SEGMENT->_7SEGMENT_u8enableport, _7SEGMENT->_7SEGMENT_u8enablepin, DIO_u8PIN_HIGH);
//				DIO_SetPortValue(_7SEGMENT->_7SEGMENT_u8port, ~(_7SEGMENTNUM[copy_u8number]));
//				break;
//			}
//			break;
//			default: local_u8error = 1;
//		}
//	}
//	else
//	{
//		local_u8error = 1;
//	}
//
//	return local_u8error;
//}
//
///**
//* Function to hide the number displayed on the 7SEGMENT.
//*
//* @param _7SEGMENT Pointer to the _7SEGMENT_T structure.
//* @return Status indicating success (0) or failure (1).
//*/
//u8 _7SEGMENT_u8HideNumber(const _7SEGMENT_T  *_7SEGMENT)
//{
//	u8 local_u8error = 0;
//	if ((_7SEGMENT != NULL) && (_7SEGMENT->_7SEGMENT_u8port <= DIO_u8PORTD) && (_7SEGMENT->_7SEGMENT_u8enablepin < DIO_u8PIN7) && (_7SEGMENT->_7SEGMENT_u8enableport <= DIO_u8PORTD) && (_7SEGMENT->_7SEGMENT_u8commontype < 2))
//	{
//		switch (_7SEGMENT->_7SEGMENT_u8commontype)
//		{
//			case _7SEGMENT_u8COMMONCATHODE:
//			DIO_SetPinValue(_7SEGMENT->_7SEGMENT_u8enableport, _7SEGMENT->_7SEGMENT_u8enablepin, DIO_u8PIN_HIGH);
//			break;
//			case _7SEGMENT_u8COMMONANODE:
//			DIO_SetPinValue(_7SEGMENT->_7SEGMENT_u8enableport, _7SEGMENT->_7SEGMENT_u8enablepin, DIO_u8PIN_LOW);
//			break;
//		}
//
//	}
//
//	else
//	{
//		local_u8error = 1;
//	}
//	return local_u8error;
//}
//
///**
//* Function to initialize the 7SEGMENT display.
//*
//* @param _7SEGMENT Pointer to the _7SEGMENT_T structure.
//* @return Status indicating success (0) or failure (1).
//*/
//u8 _7SEGMENT_u8Initialize(const _7SEGMENT_T  *_7SEGMENT)
//{
//	u8 local_u8error = 0;
//	u8 i = 0;
//	if ((_7SEGMENT != NULL) && (_7SEGMENT->_7SEGMENT_u8port <= DIO_u8PORTD) && (_7SEGMENT->_7SEGMENT_u8enablepin < DIO_u8PIN7) && (_7SEGMENT->_7SEGMENT_u8enableport <= DIO_u8PORTD) && (_7SEGMENT->_7SEGMENT_u8commontype < 2) )
//	{
//		switch (_7SEGMENT->_7SEGMENT_u8Decoders)
//		{
//
//			case _7SEGMENT_u8Decoder:
//			if ((_7SEGMENT->_7SEGMENT_u8Decoderstartpin < 5))
//			{
//				for (i = 0; i < 4; i++)
//				{
//					DIO_SetPinDirection(_7SEGMENT->_7SEGMENT_u8port, ((_7SEGMENT->_7SEGMENT_u8Decoderstartpin) + i), DIO_u8PIN_OUTPUT);
//				}
//				DIO_SetPinDirection(_7SEGMENT->_7SEGMENT_u8enableport, _7SEGMENT->_7SEGMENT_u8enablepin, DIO_u8PIN_OUTPUT);
//
//			}
//			else
//			{
//				local_u8error=1;
//			}
//
//			break;
//			case _7SEGMENT_u8Nodecoder:
//
//			DIO_SetPortDirection(_7SEGMENT->_7SEGMENT_u8port, DIO_u8PORT_OUTPUT);
//			DIO_SetPinDirection(_7SEGMENT->_7SEGMENT_u8enableport, _7SEGMENT->_7SEGMENT_u8enablepin, DIO_u8PIN_OUTPUT);
//
//			break;
//			default:
//			local_u8error = 1;
//		}
//	}
//
//	else
//	{
//		local_u8error = 1;
//	}
//	return local_u8error;
//}
//
