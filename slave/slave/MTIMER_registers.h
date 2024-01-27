/*
 * MTIMER_registers.h
 *
 *  Created on: Aug 10, 2023
 *      Author: Yasmen
 */

#ifndef MTIMER_REGISTERS_H_
#define MTIMER_REGISTERS_H_
/************************************************************************************************/
/* Timer 0 */
#define TCNT0   (*(volatile u8*)0x52)
#define TCCR0   (*(volatile u8*)0x53)
/* TCCR0 */
#define TCCR0_CS00    0
#define TCCR0_CS01    1
#define TCCR0_CS02    2
#define TCCR0_WGM01   3
#define TCCR0_COM00   4
#define TCCR0_COM01   5
#define TCCR0_WGM00   6
#define TCCR0_FOC0    7

#define TWCR    (*(volatile u8*)0x56)
#define SPMCR   (*(volatile u8*)0x57)
#define TIFR    (*(volatile u8*)0x58)
#define TIMSK   (*(volatile u8*)0x59)
/* TIMSK */
#define TIMSK_TOIE0   0
#define TIMSK_OCIE0   1
#define TIMSK_TOIE1   2
#define TIMSK_OCIE1B  3
#define TIMSK_OCIE1A  4
#define TIMSK_TICIE1  5
#define TIMSK_TOIE2   6
#define TIMSK_OCIE2   7

#define OCR0    (*(volatile u8*)0x5C)
/************************************************************************************************/
/*TIMER 1*/


#define ICR1         (*(volatile unsigned short*)0x46)
#define ICR1L        (*(volatile unsigned char*)0x46)
#define ICR1H        (*(volatile unsigned char*)0x47)
#define OCR1B        (*(volatile unsigned short*)0x48)
#define OCR1BL       (*(volatile unsigned char*)0x48)
#define OCR1BH       (*(volatile unsigned char*)0x49)
#define OCR1A        (*(volatile unsigned short*)0x4A)
#define OCR1AL       (*(volatile unsigned char*)0x4A)
#define OCR1AH       (*(volatile unsigned char*)0x4B)
#define TCNT1        (*(volatile unsigned short*)0x4C)
#define TCNT1L       (*(volatile unsigned char*)0x4C)
#define TCNT1H       (*(volatile unsigned char*)0x4D)

#define TCCR1B       (*(volatile unsigned char*)0x4E)
#define TCCR1B_ICNC1   7
#define TCCR1B_ICES1   6
#define TCCR1B_WGM13   4
#define TCCR1B_WGM12   3
#define TCCR1B_CS12    2
#define TCCR1B_CS11    1
#define TCCR1B_CS10    0




#define TCCR1A       (*(volatile unsigned char*)0x4F)
#define TCCR1A_COM1A1    7
#define TCCR1A_COM1A0    6
#define TCCR1A_COM1B1    5
#define TCCR1A_COM1B0    4
#define TCCR1A_FOC1A     3
#define TCCR1A_FOC1B     2
#define TCCR1A_WGM11     1
#define TCCR1A_WGM10     0


#define SFIOR       (*(volatile unsigned char*)0x50)

#define OSCCAL       (*(volatile unsigned char*)0x51)
#endif /* MTIMER_REGISTERS_H_ */
