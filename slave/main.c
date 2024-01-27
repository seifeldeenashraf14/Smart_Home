/*
 * main.c
 *
 *  Created on: Sep 3, 2023
 *      Author: Yasmen
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MDIO_interface.h"
#include "MTIMER_interface.h"
#include "MGIE_interface.h"
#include "STPM_int.h"
#include "SPI_interface.h"
#include "main.h"
#include "util/delay.h"


void Servo(u16 angle);
void seven_segment_display(u8 n);


int main ()
{
	/* INTIAL  */
	PORT_voidInit(); // DIO INIT
	STPM_vInit();    // STEPPER INIT
	SPI_voidInitSlave(); // SPI_INIT

	/* INTIALIZE TIMER1 FOR SERVO MOTOR */
	MTIMER1_voidInit(FAST_PWM_NON_INVERTING,TOP_FPWM_ICR1,DIV_8);
	MTIMER1_voidSetTopValue(20000,TOP_FPWM_ICR1);

	u8 SPI_data;

	while(1)
	{
		
		SPI_data=SPI_u8Tranceive(80);
		
		if (SPI_data>=50)
		{


			MDIO_EnumSetPortValue(DIO_PORTA,~SPI_data);
			_delay_ms(7);

		}
		else if(SPI_data<50)
		{
			_delay_ms(5);

			static u8 f=0;
			MDIO_Error_State_tSetPinValue(DIO_PORTD,PIN2,DIO_HIGH);
			int D1=SPI_data%10 ;
			int D2=SPI_data/10 ;
			if (f==0)
			{
				MDIO_Error_State_tSetPinValue(DIO_PORTD,PIN2,DIO_HIGH);
				MDIO_Error_State_tSetPinValue(DIO_PORTD,PIN3,DIO_LOW);
				seven_segment_display(D1);
				f=1 ;
			}
			else
			{
				MDIO_Error_State_tSetPinValue(DIO_PORTD,PIN2,DIO_LOW);
				MDIO_Error_State_tSetPinValue(DIO_PORTD,PIN3,DIO_HIGH);
				seven_segment_display(D2);
				f=0 ;
			}

			
			if ((SPI_data>35)&&(SPI_data<40))
			{
				MDIO_Error_State_tSetPinValue(DIO_PORTB,PIN0,DIO_HIGH);

			}
			else
			{
				MDIO_Error_State_tSetPinValue(DIO_PORTB,PIN0,DIO_LOW);

			}

		}

		switch(SPI_data)
		{
		case '1': Servo(ANGLE_180);break;                            //the door will open
		case '2' : Servo(ANGLE_0);break;                             //the door will close
		case '3':MDIO_Error_State_tSetPinValue(DIO_PORTB,PIN0,DIO_HIGH);break;//the door will open
		case '4':MDIO_Error_State_tSetPinValue(DIO_PORTB,PIN0,DIO_LOW);break;//the door will close
		case '5':STPM_vRCW(270);break;                                 //the  garage door will open
		case '6':STPM_vRCCW(270);break;                               //the garage door will close
		case '7':MDIO_EnumSetPortValue(DIO_PORTA,DIO_HIGH);break;       //LIGHT ON
		case '8':MDIO_EnumSetPortValue(DIO_PORTA,DIO_LOW);break;         //LIGHT OFF

		}






	}

}


void Servo(u16 angle)
{
	MTIMER1_voidSetDutyCycle(angle);
}
void seven_segment_display(u8 n)
{
	u8 segment_num[10]={0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};

	MDIO_EnumSetPortValue(DIO_PORTC,segment_num[n]);
	MDIO_EnumSetPortValue(DIO_PORTC,segment_num[n]);
}


