/*
 * HKEY_PAD_program.c
 *
 *  Created on: Aug 5, 2023
 *      Author: Yasmen
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MDIO_interface.h"



#include "HKEY_PAD_interface.h"
#include "HKEY_PAD_config.h"


u8 HKeyPad_u8GetKey (void)
{
	u8 Local_u8PressedKey = 0xff;
	u8 Local_u8KeyIsPressed = NOT_PRESSED;

	u8 Local_u8ColIterator=0;
	u8 Local_u8RowIterator=0;


	u8 Col_array[COL_SIZE] = {KEYPAD_C0, KEYPAD_C1, KEYPAD_C2, KEYPAD_C3};
	u8 Row_array[ROW_SIZE] = {KEYPAD_R0, KEYPAD_R1, KEYPAD_R2, KEYPAD_R3};
	u8 Keypad_arr[ROW_SIZE][COL_SIZE] = KEYPAD_TYPE;

	u8 flag = 0;

	for(Local_u8ColIterator=0 ; Local_u8ColIterator < COL_SIZE ; Local_u8ColIterator++)
	{
		MDIO_Error_State_tSetPinValue(COL_PORT, Col_array[Local_u8ColIterator],DIO_LOW);

		for(Local_u8RowIterator=0 ; Local_u8RowIterator < ROW_SIZE ; Local_u8RowIterator++)
		{
			MDIO_Error_State_tGetPinValue(ROW_PORT,Row_array[Local_u8RowIterator],&Local_u8KeyIsPressed);

			if(Local_u8KeyIsPressed==PRESSED)
			{
				Local_u8PressedKey = Keypad_arr[Local_u8RowIterator][Local_u8ColIterator];
				while(Local_u8KeyIsPressed==PRESSED)
				{
					MDIO_Error_State_tGetPinValue(ROW_PORT,Row_array[Local_u8RowIterator],&Local_u8KeyIsPressed);

				}
				flag = 1;
				//HLCD_voidSendData(Local_u8PressedKey);
				break;
				//return Local_u8PressedKey;
			}

		}
		MDIO_Error_State_tSetPinValue(COL_PORT,Col_array[Local_u8ColIterator],DIO_HIGH);
		if(flag)
		{
			break;
		}

	}
	return Local_u8PressedKey;
}
/*
u8 HKeyPad_u8GetKeyb(void)
{

	u8 Local_u8PressedKey=NOT_PRESSED, Local_u8_ColumnIndex, Local_u8_RowIndex,Local_u8_PinState;

	static u8 Local_u8KeypadArr[ROW_SIZE][COL_SIZE]= KEYPAD_TYPE;


	static u8 Local_u8KeypadCoulmnArr[COL_SIZE]={KEYPAD_C0, KEYPAD_C1, KEYPAD_C2, KEYPAD_C3};
	 static u8 Local_u8KeypadROWArr[ROW_SIZE]={KEYPAD_R0, KEYPAD_R1, KEYPAD_R2, KEYPAD_R3};
	for(Local_u8_ColumnIndex=0;Local_u8_ColumnIndex<COL_SIZE;Local_u8_ColumnIndex++){
		MDIO_Error_State_tGetPinValue(KEYPAD_PORT,Row_array[Local_u8RowIterator],&Local_u8KeyIsPressed);
	for(Local_u8_RowIndex=0;Local_u8_RowIndex<ROW_SIZE;Local_u8_RowIndex++){
		MDIO_Error_State_tGetPinValue(KEYPAD_PORT,Local_u8KeypadROWArr[Local_u8_RowIndex],&Local_u8_PinState);
		if(DIO_LOW==Local_u8_PinState){
			Local_u8PressedKey=Local_u8KeypadArr[Local_u8_RowIndex][Local_u8_ColumnIndex];

			while(Local_u8_PinState==DIO_LOW){
				MDIO_Error_State_tGetPinValue(KEYPAD_PORT,Local_u8KeypadROWArr[Local_u8_RowIndex],&Local_u8_PinState);

			}
			return Local_u8PressedKey;

	}
	}
	MDIO_Error_State_tSetPinValue(KEYPAD_PORT,Local_u8KeypadCoulmnArr[Local_u8_ColumnIndex],DIO_HIGH);

	}
	return Local_u8PressedKey;
}*/
