/*
 * HKEY_PAD_config.h
 *
 *  Created on: Aug 5, 2023
 *      Author: Yasmen
 */

#ifndef HKEY_PAD_CONFIG_H_
#define HKEY_PAD_CONFIG_H_


#define KEYPAD_PORT   DIO_PORTA
#define COL_PORT   DIO_PORTC
#define ROW_PORT   DIO_PORTD


#define KEYPAD_R0     PIN2
#define KEYPAD_R1     PIN3
#define KEYPAD_R2     PIN4
#define KEYPAD_R3     PIN5

#define KEYPAD_C0     PIN2
#define KEYPAD_C1     PIN3
#define KEYPAD_C2     PIN4
#define KEYPAD_C3     PIN5

#define COL_SIZE       4
#define ROW_SIZE       4

#define NO_KEY         0

#define KEYPAD_TYPE    {{'7' , '8' , '9' , '/'},\
					    {'4' , '5' , '6' , 'X'},\
					    {'1' , '2' , '3' , '-'},\
					    {'C' , '0' , '=' , '+'}}

#endif /* HKEY_PAD_CONFIG_H_ */
