/*
 * MADC_interface.h
 *
 *  Created on: Aug 9, 2023
 *      Author: Yasmen
 */

#ifndef MADC_INTERFACE_H_
#define MADC_INTERFACE_H_

void MADC_voidInit (void);
u16 MADC_u16GetValue(u8 copy_u8AdcChannel);

#define ADC_CHANNEL0 0
#define ADC_CHANNEL1 1
#define ADC_CHANNEL2 2
#define ADC_CHANNEL3 3
#define ADC_CHANNEL4 4
#define ADC_CHANNEL5 5
#define ADC_CHANNEL6 6
#define ADC_CHANNEL7 7

u16 TEMP_Read (void);

#endif /* MADC_INTERFACE_H_ */
