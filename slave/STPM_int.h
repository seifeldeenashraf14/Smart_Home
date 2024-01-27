/*
 * STPM_int.h
 *
 *  Created on: May 31, 2022
 *      Author: Hossary
 */

#ifndef HAL_STPM_STPM_INT_H_
#define HAL_STPM_STPM_INT_H_

#define STPM_YELLOW_PORT 	 DIO_PORTD
#define STPM_BLUE_PORT 		 DIO_PORTD
#define STPM_PINK_PORT 		 DIO_PORTD
#define STPM_ORANGE_PORT	 DIO_PORTD

#define STPM_BLUE_PIN		 PIN0
#define STPM_PINK_PIN		 PIN1
#define STPM_YELLOW_PIN		 PIN6
#define STPM_ORANGE_PIN		 PIN7

#define STEPER_DELAY 20

#define COIL_DISABLE	DIO_LOW
#define COIL_ENABLE		DIO_HIGH

void STPM_vInit(void);
void STPM_vRCW(u16 A_u16Angle);
void STPM_vRCCW(u16 A_u16Angle);
void STPM_vRotateSteps(u16 A_u16Steps);
void STPM_vRotateCSteps(u16 A_u16Steps);
void STPM_vStop(void);

#endif /* HAL_STPM_STPM_INT_H_ */
