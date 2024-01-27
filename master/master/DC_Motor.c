#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "MDIO_interface.h"
#include "DC_Motor.h"

void Stepper_Motor_Forward(void)
{
	MDIO_Error_State_tSetPinValue(MOTORSTEEPER_PORT,MOTORSTEEPER_PIN1,DIO_LOW);
	MDIO_Error_State_tSetPinValue(MOTORSTEEPER_PORT,MOTORSTEEPER_PIN1,DIO_LOW);
	MDIO_Error_State_tSetPinValue(MOTORSTEEPER_PORT,MOTORSTEEPER_PIN2,DIO_HIGH);
	MDIO_Error_State_tSetPinValue(MOTORSTEEPER_PORT,MOTORSTEEPER_PIN3,DIO_HIGH);
	MDIO_Error_State_tSetPinValue(MOTORSTEEPER_PORT,MOTORSTEEPER_PIN4,DIO_HIGH);
	_delay_ms (2);
	MDIO_Error_State_tSetPinValue(MOTORSTEEPER_PORT,MOTORSTEEPER_PIN1,DIO_HIGH);
	MDIO_Error_State_tSetPinValue(MOTORSTEEPER_PORT,MOTORSTEEPER_PIN2,DIO_LOW);
	MDIO_Error_State_tSetPinValue(MOTORSTEEPER_PORT,MOTORSTEEPER_PIN3,DIO_HIGH);
	MDIO_Error_State_tSetPinValue(MOTORSTEEPER_PORT,MOTORSTEEPER_PIN4,DIO_HIGH);
	_delay_ms (2);
	MDIO_Error_State_tSetPinValue(MOTORSTEEPER_PORT,MOTORSTEEPER_PIN1,DIO_HIGH);
	MDIO_Error_State_tSetPinValue(MOTORSTEEPER_PORT,MOTORSTEEPER_PIN2,DIO_HIGH);
	MDIO_Error_State_tSetPinValue(MOTORSTEEPER_PORT,MOTORSTEEPER_PIN3,DIO_LOW);
	MDIO_Error_State_tSetPinValue(MOTORSTEEPER_PORT,MOTORSTEEPER_PIN4,DIO_HIGH);
	_delay_ms (2);
	MDIO_Error_State_tSetPinValue(MOTORSTEEPER_PORT,MOTORSTEEPER_PIN1,DIO_HIGH);
	MDIO_Error_State_tSetPinValue(MOTORSTEEPER_PORT,MOTORSTEEPER_PIN2,DIO_HIGH);
	MDIO_Error_State_tSetPinValue(MOTORSTEEPER_PORT,MOTORSTEEPER_PIN3,DIO_HIGH);
	MDIO_Error_State_tSetPinValue(MOTORSTEEPER_PORT,MOTORSTEEPER_PIN4,DIO_LOW);
	_delay_ms (2);
}
void Stepper_Motor_Reverse(void)
{
	MDIO_Error_State_tSetPinValue(MOTORSTEEPER_PORT,MOTORSTEEPER_PIN4,DIO_LOW);
	MDIO_Error_State_tSetPinValue(MOTORSTEEPER_PORT,MOTORSTEEPER_PIN3,DIO_HIGH);
	MDIO_Error_State_tSetPinValue(MOTORSTEEPER_PORT,MOTORSTEEPER_PIN2,DIO_HIGH);
	MDIO_Error_State_tSetPinValue(MOTORSTEEPER_PORT,MOTORSTEEPER_PIN1,DIO_HIGH);
	_delay_ms (2);
	MDIO_Error_State_tSetPinValue(MOTORSTEEPER_PORT,MOTORSTEEPER_PIN4,DIO_HIGH);
	MDIO_Error_State_tSetPinValue(MOTORSTEEPER_PORT,MOTORSTEEPER_PIN3,DIO_LOW);
	MDIO_Error_State_tSetPinValue(MOTORSTEEPER_PORT,MOTORSTEEPER_PIN2,DIO_HIGH);
	MDIO_Error_State_tSetPinValue(MOTORSTEEPER_PORT,MOTORSTEEPER_PIN1,DIO_HIGH);
	_delay_ms (2);
	MDIO_Error_State_tSetPinValue(MOTORSTEEPER_PORT,MOTORSTEEPER_PIN4,DIO_HIGH);
	MDIO_Error_State_tSetPinValue(MOTORSTEEPER_PORT,MOTORSTEEPER_PIN3,DIO_HIGH);
	MDIO_Error_State_tSetPinValue(MOTORSTEEPER_PORT,MOTORSTEEPER_PIN2,DIO_LOW);
	MDIO_Error_State_tSetPinValue(MOTORSTEEPER_PORT,MOTORSTEEPER_PIN1,DIO_HIGH);
	_delay_ms (2);
	MDIO_Error_State_tSetPinValue(MOTORSTEEPER_PORT,MOTORSTEEPER_PIN4,DIO_HIGH);
	MDIO_Error_State_tSetPinValue(MOTORSTEEPER_PORT,MOTORSTEEPER_PIN3,DIO_HIGH);
	MDIO_Error_State_tSetPinValue(MOTORSTEEPER_PORT,MOTORSTEEPER_PIN2,DIO_HIGH);
	MDIO_Error_State_tSetPinValue(MOTORSTEEPER_PORT,MOTORSTEEPER_PIN1,DIO_LOW);
	_delay_ms (2);
}

void DC_Motor_Forward(void)
{
	MDIO_Error_State_tSetPinValue(MOTOR_DCTransPORT,MOTOR_DCPIN2 ,DIO_LOW);
	MDIO_Error_State_tSetPinValue(MOTOR_DCTransPORT,MOTOR_DCPIN1,DIO_HIGH);
}
void DC_Motor_Reverse(void)
{
	MDIO_Error_State_tSetPinValue(MOTOR_DCTransPORT,MOTOR_DCPIN2 ,DIO_HIGH);
	MDIO_Error_State_tSetPinValue(MOTOR_DCTransPORT,MOTOR_DCPIN1,DIO_LOW);
}
void DC_Motor_Stop(void)
{
	MDIO_Error_State_tSetPinValue(MOTOR_DCTransPORT,MOTOR_DCPIN2 ,DIO_LOW);
	MDIO_Error_State_tSetPinValue(MOTOR_DCTransPORT,MOTOR_DCPIN1,DIO_LOW);
}
