/*************************************************/
/* Author : Yasmen                               */
/* Layer  : MCAL                                 */
/* Date   : 2/8/2023                             */
/* Module : DIO                                  */
/* Version: 1.00                                 */
/*************************************************/


#ifndef  _M_DIO_CNFIG_H
#define  _M_DIO_CNFIG_H


#define PORTA_PIN0_DIR    OUTPUT
#define PORTA_PIN1_DIR    OUTPUT
#define PORTA_PIN2_DIR    OUTPUT
#define PORTA_PIN3_DIR    OUTPUT
#define PORTA_PIN4_DIR    OUTPUT
#define PORTA_PIN5_DIR    OUTPUT
#define PORTA_PIN6_DIR    OUTPUT
#define PORTA_PIN7_DIR    OUTPUT

#define PORTB_PIN0_DIR    OUTPUT
#define PORTB_PIN1_DIR    OUTPUT
#define PORTB_PIN2_DIR    OUTPUT  //EXTI2
#define PORTB_PIN3_DIR    OUTPUT
#define PORTB_PIN4_DIR    INPUT     //SLAVE SELECT
#define PORTB_PIN5_DIR    OUTPUT    //MOSI
#define PORTB_PIN6_DIR    INPUT     //MISO
#define PORTB_PIN7_DIR    INPUT    //clk

#define PORTC_PIN0_DIR    OUTPUT
#define PORTC_PIN1_DIR    OUTPUT
#define PORTC_PIN2_DIR    OUTPUT
#define PORTC_PIN3_DIR    OUTPUT
#define PORTC_PIN4_DIR    OUTPUT
#define PORTC_PIN5_DIR    OUTPUT
#define PORTC_PIN6_DIR    OUTPUT
#define PORTC_PIN7_DIR    OUTPUT

#define PORTD_PIN0_DIR    OUTPUT
#define PORTD_PIN1_DIR    OUTPUT
#define PORTD_PIN2_DIR    OUTPUT  //EXTI0
#define PORTD_PIN3_DIR    OUTPUT  //EXTI1
#define PORTD_PIN4_DIR    OUTPUT
#define PORTD_PIN5_DIR    OUTPUT
#define PORTD_PIN6_DIR    OUTPUT
#define PORTD_PIN7_DIR    OUTPUT

#define PORTA_PIN0_INITIAL_VALUE    HIGH
#define PORTA_PIN1_INITIAL_VALUE    HIGH
#define PORTA_PIN2_INITIAL_VALUE    HIGH
#define PORTA_PIN3_INITIAL_VALUE    HIGH
#define PORTA_PIN4_INITIAL_VALUE    HIGH
#define PORTA_PIN5_INITIAL_VALUE    HIGH
#define PORTA_PIN6_INITIAL_VALUE    HIGH
#define PORTA_PIN7_INITIAL_VALUE    HIGH

#define PORTB_PIN0_INITIAL_VALUE    LOW
#define PORTB_PIN1_INITIAL_VALUE    LOW
#define PORTB_PIN2_INITIAL_VALUE    LOW
#define PORTB_PIN3_INITIAL_VALUE    LOW
#define PORTB_PIN4_INITIAL_VALUE    LOW
#define PORTB_PIN5_INITIAL_VALUE    LOW
#define PORTB_PIN6_INITIAL_VALUE    LOW
#define PORTB_PIN7_INITIAL_VALUE    LOW

#define PORTC_PIN0_INITIAL_VALUE    LOW
#define PORTC_PIN1_INITIAL_VALUE    LOW
#define PORTC_PIN2_INITIAL_VALUE    LOW
#define PORTC_PIN3_INITIAL_VALUE    LOW
#define PORTC_PIN4_INITIAL_VALUE    LOW
#define PORTC_PIN5_INITIAL_VALUE    LOW
#define PORTC_PIN6_INITIAL_VALUE    LOW
#define PORTC_PIN7_INITIAL_VALUE    LOW

#define PORTD_PIN0_INITIAL_VALUE    LOW
#define PORTD_PIN1_INITIAL_VALUE    LOW
#define PORTD_PIN2_INITIAL_VALUE    LOW  //KEYPAD
#define PORTD_PIN3_INITIAL_VALUE    LOW
#define PORTD_PIN4_INITIAL_VALUE    LOW
#define PORTD_PIN5_INITIAL_VALUE    LOW
#define PORTD_PIN6_INITIAL_VALUE    LOW
#define PORTD_PIN7_INITIAL_VALUE    LOW

#endif