/*
 * DC_Motor.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: THE LAPTOP SHOP
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

void Stepper_Motor_Forward(void);
void Stepper_Motor_reverse(void);

void DC_Motor_Forward(void);
void DC_Motor_reverse(void);
void DC_Motor_stop(void);

#define MOTOR_DCTransPORT  DIO_PORTC

#define MOTOR_DCPIN1  PIN0
#define MOTOR_DCPIN2  PIN1

#define MOTORSTEEPER_PORT  DIO_PORTD

#define MOTORSTEEPER_PIN1  PIN0
#define MOTORSTEEPER_PIN2  PIN1
#define MOTORSTEEPER_PIN3  PIN2
#define MOTORSTEEPER_PIN4  PIN3

#define DC_MOTOR          0
#define Stepper_MOTOR     1


#endif /* DC_MOTOR_H_ */
