/*
 * calc.c

 *
 *  Created on: ???/???/????
 *      Author: user
 */
#include "../../../MCAL/PORT/PORT_interface.h"
#include "../../../lib/std_types.h"
#include "../../../Hall/CLCD/CLCD_interface.h"
#include "../../../Hall/KAYPAD/KPD_interface.h"
#include "../../../Hall/KAYPAD/KPD_confg.h"
#include "../../../MCAL/DIO/DIO_interface.h"
#include <util/delay.h>
void start(void)
{
	PORT_voidInit();
	CLCD_voidInit();
	CLCD_voidSendString("welcome !");
	_delay_ms(1000);
	CLCD_voidClearLCD();
	CLCD_voidSendString("this is simple");
	CLCD_voidGoToXY(1,0);
	CLCD_voidSendString("calculator");
	_delay_ms(1000);
	CLCD_voidClearLCD();
	CLCD_voidSendString("not calculator");
	_delay_ms(1000);
	CLCD_voidClearLCD();
	CLCD_voidSendString("press on to");
	CLCD_voidGoToXY(1,0);
	CLCD_voidSendString("start");
}
void clearcalc(s32 num1,s32 num2, s32 operation ,s32 prod, s32 num_flag)
{
	CLCD_voidClearLCD();
	num1=0;num2=0;operation=0;prod=0;num_flag=0;
}


