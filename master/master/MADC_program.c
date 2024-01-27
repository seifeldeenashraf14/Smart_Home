/*
 * MADC_program.c
 *
 *  Created on: Aug 9, 2023
 *      Author: Yasmen
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MADC_interface.h"
#include "MADC_registers.h"
#include "MADC_private.h"
#include "MADC_config.h"


void MADC_voidInit (void)
{
	/* SELECT V REF */
	CLR_BIT(ADMUX,ADMUX_REFS1);
	SET_BIT(ADMUX,ADMUX_REFS0);
	/* SELECT RIGHT ADUJST */
	CLR_BIT(ADMUX,ADMUX_ADLAR);
	/*SELECT PRESCALER MCU GRQ  32  */
	SET_BIT(ADCSRA,ADCSRA_ADPS0);
	CLR_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS2);
	/* ADC ENABLE */
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}
u16 MADC_u16GetValue(u8 copy_u8AdcChannel)
{
	/* clear the selection bits  */
	ADMUX&=0b1100000;
	/* select ADC channel */
	ADMUX|=copy_u8AdcChannel;
	/* ADC start conversion */
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	/* busy wait until ADC complete conversion */
	while(GET_BIT(ADCSRA,ADCSRA_ADIF)==0);
	/* clear ADC flag */
	SET_BIT(ADCSRA,ADCSRA_ADIF);

	return ADC_DATA_REG;


}


/*u16 TEMP_Read (void)
 {
	 u16 volt =MADC_u16GetValue(LM35_CH);
	 u16 temp =volt;
	 return temp;
 }*/
