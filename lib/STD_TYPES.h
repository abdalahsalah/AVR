/*
 * STD_TYPES.h
 *
 *  Created on: ???/???/????
 *      Author: user
 */

#ifndef LIB_STD_TYPES_H_
#define LIB_STD_TYPES_H_

/* Boolean Values */
#ifndef FALSE
#define FALSE       (0)
#endif
#ifndef TRUE
#define TRUE        (1)
#endif


typedef unsigned char         u8;          /*           0 .. 255             */
typedef signed char           s8;          /*        -128 .. +127            */
typedef unsigned short        u16;         /*           0 .. 65535           */
typedef signed short          s16;         /*      -32768 .. +32767          */
typedef unsigned long         u32;         /*           0 .. 4294967295      */
typedef signed long           s32;         /* -2147483648 .. +2147483647     */
typedef unsigned long long    u64;         /*       0..18446744073709551615  */
typedef signed long long      s64;
typedef float                 f32;
typedef double                f64;

#define  NULL 0
#define  OK   0
#define  NOK  1
#define  NULL_POINTER  2

#endif /* LIB_STD_TYPES_H_ */
