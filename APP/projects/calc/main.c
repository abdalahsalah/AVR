//#include "../../../MCAL/PORT/PORT_interface.h"
//#include "../../../lib/std_types.h"
//#include "../../../Hall/CLCD/CLCD_interface.h"
//#include "../../../Hall/KAYPAD/KPD_interface.h"
//#include "../../../Hall/KAYPAD/KPD_confg.h"
//#include "../../../MCAL/DIO/DIO_interface.h"
//#include <util/delay.h>
//
//int main(void) {
//    start();
//    s32 num1 = 0, num2 = 0, operation = 0, prod = 0;
//    s32 num_flag = 0;
//
//    while (1) {
//        s32 value = KPD_u8GetPressedkey();
//
//        if (value != KPD_NO_PREESED_KEY) {
//            if (value == '#') {
//                CLCD_voidClearLCD();
//                clearCalculatorState(&num1, &num2, &operation, &prod, &num_flag);
//            } else if ((value >= '0' && value <= '9') && num_flag == 0) {
//                num1 = (num1 * 10) + (value - '0');
//                CLCD_voidSendData(value);
//            } else if ((value >= '0' && value <= '9') && num_flag == 1) {
//                num2 = (num2 * 10) + (value - '0');
//                CLCD_voidSendData(value);
//            } else if (value == '+' || value == '-' || value == '*' || value == '/') {
//                num_flag = 1;
//                operation = value;
//                CLCD_voidSendData(value);
//            } else if (value == '=') {
//                CLCD_voidClearLCD();
//                switch (operation) {
//                    case '+':
//                        prod = num1 + num2;
//                        break;
//                    case '-':
//                        prod = num1 - num2;
//                        break;
//                    case '*':
//                        prod = num1 * num2;
//                        break;
//                    case '/':
//                        if (num2 != 0) {
//                            prod = num1 / num2;
//                        } else {
//                            // Handle division by zero error
//                            CLCD_voidSendString("Error: Division");
//                            CLCD_voidGoToXY(1,0);
//                            CLCD_voidSendString("By ZERO");
//                            _delay_ms(2000);
//                            CLCD_voidClearLCD();
//                            clearCalculatorState(&num1, &num2, &operation, &prod, &num_flag);
//                            continue;  // Skip the display of the result
//                        }
//                        break;
//                    default:
//                        prod = num1;
//                        break;
//                }
//
//                if (prod < 0) {
//                    CLCD_voidSendData('-');
//                    CLCD_voidDisplayNumber(abs(prod));
//                } else {
//                    CLCD_voidDisplayNumber(prod);
//                }
//
//                num1 = prod;
//                num2 = 0;
//                operation = 0;
//                prod = 0;
//                num_flag = 0;
//            }
//        }
//    }
//}
