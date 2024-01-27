/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  HAL 				*************************/
/*************************		SWC: 	CLCD				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#include"STD_TYPES.h"
#include <util/delay.h>

#include "MDIO_interface.h"

#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"

//u8 Local_u8StringCounter=0;

#if CLCD_MODE==4

void CLCD_void_Init(void)
{
	_delay_ms(40);
	CLCD_voidSendCommand(0b00100010);
	MDIO_EnumSetPortValue(CLCD_DATA_PORT,0b10000000);
	MDIO_Error_State_tSetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_HIGH);
	_delay_ms(2);
	MDIO_Error_State_tSetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_LOW);
	CLCD_voidSendCommand(0b00001100);
	CLCD_voidSendCommand(1);
}

void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	MDIO_Error_State_tSetPinValue(CLCD_CTRL_PORT , CLCD_RS_PIN , DIO_LOW);
	MDIO_Error_State_tSetPinValue(CLCD_CTRL_PORT , CLCD_RW_PIN , DIO_LOW);
	MDIO_EnumSetPortValue(CLCD_DATA_PORT,Copy_u8Command);
	MDIO_Error_State_tSetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_HIGH);
	_delay_ms(2);
	MDIO_Error_State_tSetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_LOW);
	MDIO_EnumSetPortValue(CLCD_DATA_PORT,(Copy_u8Command<<4));
	MDIO_Error_State_tSetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_HIGH);
	_delay_ms(2);
	MDIO_Error_State_tSetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_LOW);
}

void CLCD_voidSendData(u8 Copy_u8Data)
{
	/*if(Local_u8StringCounter==0x10)
	{
		CLCD_voidGoToXY(1,0);
	}*/
	MDIO_Error_State_tSetPinValue(CLCD_CTRL_PORT , CLCD_RS_PIN , DIO_HIGH);
	MDIO_Error_State_tSetPinValue(CLCD_CTRL_PORT , CLCD_RW_PIN , DIO_LOW);
	MDIO_EnumSetPortValue(CLCD_DATA_PORT,Copy_u8Data);
	MDIO_Error_State_tSetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_HIGH);
	_delay_ms(2);
	MDIO_Error_State_tSetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_LOW);
	MDIO_EnumSetPortValue(CLCD_DATA_PORT,(Copy_u8Data<<4));
	MDIO_Error_State_tSetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_HIGH);
	_delay_ms(2);
	MDIO_Error_State_tSetPinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_LOW);
	//Local_u8StringCounter++;
}

#elif CLCD_MODE==8

void CLCD_void_Init(void)
{
	_delay_ms(40);
	/*Function set command: 2 lines and 5*8 font size*/
	CLCD_voidSendCommand(0b00111000);
	/*Display on off control: display enable , disable cursor and no blink cursor*/
	CLCD_voidSendCommand(0b00001100);
	/*clear display*/
	CLCD_voidSendCommand(1);
}
void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	DIO_u8setpinValue(CLCD_CTRL_PORT , CLCD_RS_PIN , DIO_u8PIN_LOW);
	DIO_u8setpinValue(CLCD_CTRL_PORT , CLCD_RW_PIN , DIO_u8PIN_LOW);
	DIO_u8setportValue(CLCD_DATA_PORT,Copy_u8Command);
	DIO_u8setpinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8setpinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_LOW);
}

void CLCD_voidSendData(u8 Copy_u8Data)
{
	/*if(Local_u8StringCounter==0x10)
	{
		CLCD_voidGoToXY(1,0);
	}*/
	DIO_u8setpinValue(CLCD_CTRL_PORT , CLCD_RS_PIN , DIO_u8PIN_HIGH);
	DIO_u8setpinValue(CLCD_CTRL_PORT , CLCD_RW_PIN , DIO_u8PIN_LOW);
	DIO_u8setportValue(CLCD_DATA_PORT,Copy_u8Data);
	DIO_u8setpinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8setpinValue(CLCD_CTRL_PORT , CLCD_E_PIN , DIO_u8PIN_LOW);
	//Local_u8StringCounter++;
}

#endif
void CLCD_voidSendString(const char *Copy_Pcstring)
{
	u32 Local_u8Counter=0;
	while(Copy_Pcstring[Local_u8Counter] != '\0')
	{
		CLCD_voidSendData(Copy_Pcstring[Local_u8Counter]);
		Local_u8Counter++;
	}
}

void CLCD_voidGoToXY(u8 copy_u8XPos, u8 copy_u8YPos)
{
	//Local_u8StringCounter=copy_u8YPos;
	u8 Local_u8Address;
	if(copy_u8XPos==0)
	{
		Local_u8Address=copy_u8YPos;
	}
	else if(copy_u8XPos==1)
	{
		Local_u8Address=copy_u8YPos+0x40;
	}
	CLCD_voidSendCommand(0x80+Local_u8Address);
}

void CLCD_voidCLR(void)
{
	CLCD_voidSendCommand(1);
	//Local_u8StringCounter=0;
}

void CLCD_void_WriteSpecialCharacter(u8* Copy_pu8Pattern , u8 Copy_u8PatternNumber , u8 Copy_u8XPos , u8 Copy_u8YPos)
{
	u8 Local_u8Counter=0;
	u8 Local_u8CGRAMAddress=Copy_u8PatternNumber*8;
	CLCD_voidSendCommand(Local_u8CGRAMAddress+0x40);
	for(Local_u8Counter=0;Local_u8Counter<8;Local_u8Counter++)
	{
		CLCD_voidSendData(Copy_pu8Pattern[Local_u8Counter]);
	}
	CLCD_voidGoToXY(Copy_u8XPos,Copy_u8YPos);
	CLCD_voidSendData(Copy_u8PatternNumber);
}

void CLCD_void_SendNumber(s8* Copy_ps8String , s32 Copy_s32Number)
{
	s8 Local_u8String[20];
	u8 Local_u8NumLength=0,Local_u8Rem,Local_u8Counter;
	u32 Local_u32Num=Copy_s32Number;
	if(Copy_s32Number==0)
	{
		Local_u8String[0]='0';
		Local_u8String[1]='\0';
	}
	else
	{
		if(Copy_s32Number<0)
		{
			CLCD_voidSendData('-');
			Copy_s32Number*=-1;
		}
		while(Local_u32Num!=0)
		{
			Local_u8NumLength++;
			Local_u32Num/=10;
		}
		for(Local_u8Counter=0;Local_u8Counter<Local_u8NumLength;Local_u8Counter++)
		{
			Local_u8Rem=Copy_s32Number%10;
			Copy_s32Number/=10;
			Local_u8String[Local_u8NumLength-(Local_u8Counter+1)]=Local_u8Rem+'0';
		}
		Local_u8String[Local_u8NumLength]='\0';
	}
	CLCD_voidSendString(Local_u8String);
}


void LCD_WriteNumber (s32 num)
{
	u8 i=0,str[10];
	s8 j;

	if(num==0)
	{
		CLCD_voidSendData('0');
		return;
	}
	if(num<0)
	{
		CLCD_voidSendData('-');
		num=num*(-1);
	}

	while(num)
	{
		str[i]=(num%10)+'0';
		num=num/10;
		i++;
	}

	for(j=i-1;j>=0;j--)
	{

		CLCD_voidSendData(str[j]);
	}
}
void LCD_SetCursor(u8 line ,u8 cell)        // line 0:1  cell 0:15
{
	if(line==0)
	{
		CLCD_voidSendCommand(0x80|cell);   // set dd ram address to line 0 and set the cell that the user has entered
	}
	else if(line==1)
	{
		CLCD_voidSendCommand(0x80|0x40|cell);  // set dd ram address to line 1 and set the cell that the user has entered
	}
}
void CLCD_SendInt (s32 num)
{
	u8 i=0,str[10];
	s8 j;

	if(num==0)
	{
		CLCD_voidSendData('0');
		return;
	}
	if(num<0)
	{
		CLCD_voidSendData('-');
		num=num*(-1);
	}

	while(num)
	{
		str[i]=(num%10)+'0';
		num=num/10;
		i++;
	}

	for(j=i-1;j>=0;j--)
	{

		CLCD_voidSendData(str[j]);
	}
}
