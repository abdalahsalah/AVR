/*
 * app.c

 *
 *  Created on: ???/???/????
 *      Author: user
 */

#include "../../../lib/std_types.h"
#include "../../../Hall/CLCD/CLCD_interface.h"
#include "../../../MCAL/DIO/DIO_interface.h"
#include "../../../MCAL/PORT/PORT_interface.h"
#include "../../../MCAL/GIE/GIE_interface.h"
#include "../../../MCAL/EXTI/EXTI_interface.h"
#include <util/delay.h>
u8 P1 = 0,P2 = 0,res1 = 0,res2 = 0,turns=5;
u8 row_ball=0,col_ball=1;
void start(void)
{
	PORT_voidInit();
	CLCD_voidInit();
	CLCD_voidSendString("welcome ");
	_delay_ms(500);
	CLCD_voidClearLCD();
	CLCD_voidSendString("PingPong");
	CLCD_voidGoToXY(1,0);
	CLCD_voidSendString("Game");
	_delay_ms(500);
	CLCD_voidClearLCD();
}
void handling()
{
	_delay_ms(500);


	if(P1>P2)
	{
		CLCD_voidClearLCD();
		CLCD_voidGoToXY(0,0);
		CLCD_voidSendString("Player 1 Won...");
		res1++;
		_delay_ms(500);
		CLCD_voidClearLCD();
		gameinit();
		row_ball=0;
		col_ball =1;
	}
	else if(P2>P1 )
	{
		CLCD_voidClearLCD();
		CLCD_voidGoToXY(0,0);
		CLCD_voidSendString("Player 2 Won...");
		res2++;
		_delay_ms(500);
		CLCD_voidClearLCD();
		gameinit();
		row_ball=0;
		col_ball =2;

	}
	P1=0,P2=0;


}
void gameinit(void)
{
	CLCD_voidSendString("p1 score ");
	CLCD_voidGoToXY(1,0);
	CLCD_voidDisplayNumber(res1);
	_delay_ms(1000);
	CLCD_voidClearLCD();
	CLCD_voidSendString("p2 score ");
	CLCD_voidGoToXY(1,0);
	CLCD_voidDisplayNumber(res2);
	_delay_ms(1000);
	CLCD_voidClearLCD();
	CLCD_voidSendString("|");
	CLCD_voidGoToXY(0,14);
	CLCD_voidSendString("|");
	CLCD_voidGoToXY(0,1);
	CLCD_voidSendString("O");
	_delay_ms(500);
	CLCD_voidGoToXY(0,1);
	CLCD_voidSendString(" ");
}
void ISR_INT0()
{
	P1+=1;
	for (col_ball = 1; col_ball < 14; col_ball++) {
	    row_ball = (col_ball & 1); // Extracting the least significant bit directly

		CLCD_voidGoToXY(row_ball,col_ball);
		CLCD_voidSendString("O");
		_delay_ms(50);
		CLCD_voidGoToXY(row_ball,col_ball);
		CLCD_voidSendString(" ");
	}
}


void ISR_INT1()
{
	P2+=1;
	for(col_ball=14;col_ball>1;col_ball--){
		row_ball = (col_ball & 1); // Extracting the least significant bit directly

		CLCD_voidGoToXY(row_ball,col_ball);
		CLCD_voidSendString("O");
		_delay_ms(50);
		CLCD_voidGoToXY(row_ball,col_ball);
		CLCD_voidSendString(" ");
	}

}
