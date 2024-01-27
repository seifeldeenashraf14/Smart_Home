/*
 * MTIMER_interface.h
 *
 *  Created on: Aug 10, 2023
 *      Author: Yasmen
 */

#ifndef MTIMER_INTERFACE_H_
#define MTIMER_INTERFACE_H_

typedef enum {
	NORMAL_MODE,
	CTC_TOGGLE,
	CTC_SET,
	CTC_CLR,
	FAST_PWM_NON_INVERTING,
	FAST_PWM_INVERTING
}Timer1Modes_t;
typedef enum {
	TOP_CTC_OCR1A,
	TOP_CTC_ICR1,
	TOP_FPWM_ICR1,
	TOP_FPWM_OCR1A
}Top_t;
typedef enum {
	DIV_8,
	DIV_64,
	DIV_256
}Prescaler_t;
void MTIMER0_voidInit (void);
void MTIMER0_voidDisable(void);
void MTIMER0_voidEnable(void);
void MTIMER0_voidSetPreload (u8 copy_u8Preload);
void MTIMER0_voidCompMatchValue(u8 Copy_u8ComMatchValue);
void MTIMER0_voidSetDutyCycle(u8 Copy_u8DutyCycle);

void MTIMER1_voidInit (Timer1Modes_t copy_Timer1Mode,Top_t copy_Timer1TopMode,Prescaler_t copy_PrescalerValue);

void MTIMER1_voidSetTopValue (u16 copu_u16TopValue,Top_t copy_Timer1TopMode);
void MTIMER1_voidSetDutyCycle(u16 copy_u16DutyCycleValue);
#endif /* MTIMER_INTERFACE_H_ */
