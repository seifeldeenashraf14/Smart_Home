/*
 * MTIMER_program.c
 *
 *  Created on: Aug 10, 2023
 *      Author: Yasmen
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MTIMER_interface.h"
#include "MTIMER_registers.h"
#include "MTIMER_private.h"
#include "MTIMER_config.h"

void(*Timer0_pf_OverFLow)(void)=NULL;
void(*Timer0_pf_Compare)(void)=NULL;

void MTIMER0_voidInit (void)
{
	/* select timer0 mode */
#if TIMER0_MODE == TIMER0_NORMAL
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);
	/* enable timer0 SIE*/
	SET_BIT(TIMSK,TIMSK_TOIE0);

#elif TIMER0_MODE == TIMER0_CTC
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
	/* SET OUTPUT COMPARE MATCH REG */
	OCR0=COMPARE_MATCH_VALUE;
	/* Enable ctc ISR */
	SET_BIT(TIMSK , TIMSK_OCIE0);
#elif TIMER0_MODE == TIMER0_FAST_PWM
	/*selecting  wave generation mode as fast pwm mode */
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	// select non inverting mode
	CLR_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);
#endif
	/* Prescaler Selection */
	#if TIMER0_PRESCALER==TIMER0_NO_PRESCALER
		SET_BIT(TCCR0,TCCR0_CS00);
		CLR_BIT(TCCR0,TCCR0_CS01);
		CLR_BIT(TCCR0,TCCR0_CS02);

	#elif  TIMER0_PRESCALER==TIMER0_8_PRESCALER
		CLR_BIT(TCCR0,TCCR0_CS00);
		SET_BIT(TCCR0,TCCR0_CS01);
		CLR_BIT(TCCR0,TCCR0_CS02);

	#elif  TIMER0_PRESCALER==TIMER0_64_PRESCALER
		SET_BIT(TCCR0,TCCR0_CS00);
		SET_BIT(TCCR0,TCCR0_CS01);
		CLR_BIT(TCCR0,TCCR0_CS02);

	#elif  TIMER0_PRESCALER==TIMER0_256_PRESCALER
		CLR_BIT(TCCR0,TCCR0_CS00);
		CLR_BIT(TCCR0,TCCR0_CS01);
		SET_BIT(TCCR0,TCCR0_CS02);

	#elif  TIMER0_PRESCALER==TIMER0_1024_PRESCALER
		SET_BIT(TCCR0,TCCR0_CS00);
		CLR_BIT(TCCR0,TCCR0_CS01);
		SET_BIT(TCCR0,TCCR0_CS02);

	#else
	#error "TIMRT0 Invalid Prescaler"

	#endif



}
void MTIMER0_voidEnable(void)
{
	/* SELECT TIMER0 PRESCALLER DIVISION BY 8*/
		CLR_BIT(TCCR0,TCCR0_CS00);
		SET_BIT(TCCR0,TCCR0_CS01);
		CLR_BIT(TCCR0,TCCR0_CS02);

}

void MTIMER0_voidDisable(void)
{
	/* NO CLK SOURCE */
	CLR_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);

}
void MTIMER0_voidSetPreload (u8 copy_u8Preload)
{
	TCNT0=copy_u8Preload;
}

void MTIMER0_voidSetDutyCycle(u8 Copy_u8Dutycycle){
	OCR0 =Copy_u8Dutycycle ;
}

void MTIMER1_voidInit (Timer1Modes_t copy_Timer1Mode,Top_t copy_Timer1TopMode,Prescaler_t copy_PrescalerValue)
{
	switch(copy_Timer1Mode)
	{
	case NORMAL_MODE:CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	                 CLR_BIT(TCCR1A,TCCR1A_COM1B0);
	                 CLR_BIT(TCCR1A,TCCR1A_COM1A1);
	                 CLR_BIT(TCCR1A,TCCR1A_COM1B1);
	                 break;
	case CTC_TOGGLE:CLR_BIT(TCCR1A,TCCR1A_COM1A0);
                    SET_BIT(TCCR1A,TCCR1A_COM1B0);
                    CLR_BIT(TCCR1A,TCCR1A_COM1A1);
                    CLR_BIT(TCCR1A,TCCR1A_COM1B1);
                    break;
	case CTC_SET :  SET_BIT(TCCR1A,TCCR1A_COM1A0);
                    SET_BIT(TCCR1A,TCCR1A_COM1B0);
                    SET_BIT(TCCR1A,TCCR1A_COM1A1);
                    SET_BIT(TCCR1A,TCCR1A_COM1B1);
                    break;
	case CTC_CLR :  CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	                CLR_BIT(TCCR1A,TCCR1A_COM1B0);
                    SET_BIT(TCCR1A,TCCR1A_COM1A1);
                    SET_BIT(TCCR1A,TCCR1A_COM1B1);
                    break;
	case FAST_PWM_NON_INVERTING :
		           CLR_BIT(TCCR1A,TCCR1A_COM1A0);
                   CLR_BIT(TCCR1A,TCCR1A_COM1B0);
                   SET_BIT(TCCR1A,TCCR1A_COM1A1);
                   SET_BIT(TCCR1A,TCCR1A_COM1B1);
                   break;
	case FAST_PWM_INVERTING :
		            SET_BIT(TCCR1A,TCCR1A_COM1A0);
			        SET_BIT(TCCR1A,TCCR1A_COM1B0);
	                SET_BIT(TCCR1A,TCCR1A_COM1A1);
	                SET_BIT(TCCR1A,TCCR1A_COM1B1);
	                break;
	default:break;

	}
	switch (copy_Timer1TopMode)
	{
	case TOP_CTC_ICR1:
		            CLR_BIT(TCCR1A,TCCR1A_WGM10);
		            CLR_BIT(TCCR1A,TCCR1A_WGM11);
		            SET_BIT(TCCR1B,TCCR1B_WGM12);
		            SET_BIT(TCCR1B,TCCR1B_WGM13);
		            break;
	case TOP_CTC_OCR1A:
			        CLR_BIT(TCCR1A,TCCR1A_WGM10);
			        CLR_BIT(TCCR1A,TCCR1A_WGM11);
			        SET_BIT(TCCR1B,TCCR1B_WGM12);
			        CLR_BIT(TCCR1B,TCCR1B_WGM13);
			        break;
	case TOP_FPWM_ICR1:
		             CLR_BIT(TCCR1A,TCCR1A_WGM10);
		             SET_BIT(TCCR1A,TCCR1A_WGM11);
				     SET_BIT(TCCR1B,TCCR1B_WGM12);
				     SET_BIT(TCCR1B,TCCR1B_WGM13);
				     break;
	case TOP_FPWM_OCR1A:
		             SET_BIT(TCCR1A,TCCR1A_WGM10);
			         SET_BIT(TCCR1A,TCCR1A_WGM11);
					 SET_BIT(TCCR1B,TCCR1B_WGM12);
					 SET_BIT(TCCR1B,TCCR1B_WGM13);
					 break;
	default: break;

	}
	switch (copy_PrescalerValue)
	{
	case DIV_8 :
                    CLR_BIT(TCCR1B,TCCR1B_CS10);
                    SET_BIT(TCCR1B,TCCR1B_CS11);
                    CLR_BIT(TCCR1B,TCCR1B_CS12);
                    break;
	case DIV_64 :
		            SET_BIT(TCCR1B,TCCR1B_CS10);
	                SET_BIT(TCCR1B,TCCR1B_CS11);
	                CLR_BIT(TCCR1B,TCCR1B_CS12);
	                break;
	case DIV_256 :
		            CLR_BIT(TCCR1B,TCCR1B_CS10);
		            CLR_BIT(TCCR1B,TCCR1B_CS11);
		            SET_BIT(TCCR1B,TCCR1B_CS12);
		            break;
	default: break;

	}

}
void MTIMER1_voidSetTopValue (u16 copu_u16TopValue,Top_t copy_Timer1TopMode)
{
	switch (copy_Timer1TopMode)
	{
	case TOP_FPWM_ICR1: ICR1=copu_u16TopValue;break;
	case TOP_FPWM_OCR1A: OCR1A=copu_u16TopValue;break;
	default :break;
	}


}
void MTIMER1_voidSetDutyCycle(u16 copy_u16DutyCycleValue)
{
	 OCR1A=copy_u16DutyCycleValue;
}

