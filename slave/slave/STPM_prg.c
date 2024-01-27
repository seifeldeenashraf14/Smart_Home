/*
 * STPM_prg.c
 *
 *  Created on: May 31, 2022
 *      Author: Hossary
 */

#include "STD_TYPES.h"
#include "MDIO_interface.h"
#include "STPM_int.h"
#include <util/delay.h>

void STPM_vInit(void) {
	/* Disable all coils */
	STPM_vStop();
}

void STPM_vRCW(u16 A_u16Angle) {
	u16 L_u16I;
	u16 L_u16Iterations = A_u16Angle / 0.17578125 / 4 + 1;

	/* Disable all coils */
	STPM_vStop();

	for(L_u16I = 0; L_u16I < L_u16Iterations; L_u16I++) {
		MDIO_Error_State_tSetPinValue(STPM_BLUE_PORT, STPM_BLUE_PIN, COIL_ENABLE);
		_delay_ms(STEPER_DELAY);
		MDIO_Error_State_tSetPinValue(STPM_BLUE_PORT, STPM_BLUE_PIN, COIL_DISABLE);

		/* for second Activation */
		MDIO_Error_State_tSetPinValue(STPM_PINK_PORT, STPM_PINK_PIN, COIL_ENABLE);
		_delay_ms(STEPER_DELAY);
		MDIO_Error_State_tSetPinValue(STPM_PINK_PORT, STPM_PINK_PIN, COIL_DISABLE);

		/* for third Activation */
		MDIO_Error_State_tSetPinValue(STPM_YELLOW_PORT, STPM_YELLOW_PIN, COIL_ENABLE);
		_delay_ms(STEPER_DELAY);
		MDIO_Error_State_tSetPinValue(STPM_YELLOW_PORT, STPM_YELLOW_PIN, COIL_DISABLE);

		/* for fourth Activation */
		MDIO_Error_State_tSetPinValue(STPM_ORANGE_PORT, STPM_ORANGE_PIN, COIL_ENABLE);
		_delay_ms(STEPER_DELAY);
		MDIO_Error_State_tSetPinValue(STPM_ORANGE_PORT, STPM_ORANGE_PIN, COIL_DISABLE);
	}
}

void STPM_vRCCW(u16 A_u16Angle) {
	u16 L_u16I;
	u16 L_u16Iterations = A_u16Angle / 0.17578125 / 4 + 1;

	/* Disable all coils */
	STPM_vStop();

	for(L_u16I = 0; L_u16I < L_u16Iterations; L_u16I++) {
		MDIO_Error_State_tSetPinValue(STPM_ORANGE_PORT, STPM_ORANGE_PIN, COIL_ENABLE);
		_delay_ms(STEPER_DELAY);
		MDIO_Error_State_tSetPinValue(STPM_ORANGE_PORT, STPM_ORANGE_PIN, COIL_DISABLE);

		/* for second Activation */
		MDIO_Error_State_tSetPinValue(STPM_YELLOW_PORT, STPM_YELLOW_PIN, COIL_ENABLE);
		_delay_ms(STEPER_DELAY);
		MDIO_Error_State_tSetPinValue(STPM_YELLOW_PORT, STPM_YELLOW_PIN, COIL_DISABLE);

		/* for third Activation */
		MDIO_Error_State_tSetPinValue(STPM_PINK_PORT, STPM_PINK_PIN, COIL_ENABLE);
		_delay_ms(STEPER_DELAY);
		MDIO_Error_State_tSetPinValue(STPM_PINK_PORT, STPM_PINK_PIN, COIL_DISABLE);

		/* for fourth Activation */
		MDIO_Error_State_tSetPinValue(STPM_BLUE_PORT, STPM_BLUE_PIN, COIL_ENABLE);
		_delay_ms(STEPER_DELAY);
		MDIO_Error_State_tSetPinValue(STPM_BLUE_PORT, STPM_BLUE_PIN, COIL_DISABLE);
	}
}

void STPM_vRotateSteps(u16 A_u16Steps) {
	u16 i;

	/* Disable all coils */
	STPM_vStop();

	for(i = 0; i <= A_u16Steps; i++) {
		MDIO_Error_State_tSetPinValue(STPM_BLUE_PORT, STPM_BLUE_PIN, COIL_ENABLE);
		_delay_ms(STEPER_DELAY);
		MDIO_Error_State_tSetPinValue(STPM_BLUE_PORT, STPM_BLUE_PIN, COIL_DISABLE);

		/* for second Activation */
		MDIO_Error_State_tSetPinValue(STPM_PINK_PORT, STPM_PINK_PIN, COIL_ENABLE);
		_delay_ms(STEPER_DELAY);
		MDIO_Error_State_tSetPinValue(STPM_PINK_PORT, STPM_PINK_PIN, COIL_DISABLE);

		/* for third Activation */
		MDIO_Error_State_tSetPinValue(STPM_YELLOW_PORT, STPM_YELLOW_PIN, COIL_ENABLE);
		_delay_ms(STEPER_DELAY);
		MDIO_Error_State_tSetPinValue(STPM_YELLOW_PORT, STPM_YELLOW_PIN, COIL_DISABLE);

		/* for fourth Activation */
		MDIO_Error_State_tSetPinValue(STPM_ORANGE_PORT, STPM_ORANGE_PIN, COIL_ENABLE);
		_delay_ms(STEPER_DELAY);
		MDIO_Error_State_tSetPinValue(STPM_ORANGE_PORT, STPM_ORANGE_PIN, COIL_DISABLE);
	}
}

void STPM_vRotateCSteps(u16 A_u16Steps) {
	u16 L_u16I;

	/* Disable all coils */
	STPM_vStop();

	for(L_u16I = 0; L_u16I < A_u16Steps; L_u16I++) {
		MDIO_Error_State_tSetPinValue(STPM_ORANGE_PORT, STPM_ORANGE_PIN, COIL_ENABLE);
		_delay_ms(STEPER_DELAY);
		MDIO_Error_State_tSetPinValue(STPM_ORANGE_PORT, STPM_ORANGE_PIN, COIL_DISABLE);

		/* for second Activation */
		MDIO_Error_State_tSetPinValue(STPM_YELLOW_PORT, STPM_YELLOW_PIN, COIL_ENABLE);
		_delay_ms(STEPER_DELAY);
		MDIO_Error_State_tSetPinValue(STPM_YELLOW_PORT, STPM_YELLOW_PIN, COIL_DISABLE);

		/* for third Activation */
		MDIO_Error_State_tSetPinValue(STPM_PINK_PORT, STPM_PINK_PIN, COIL_ENABLE);
		_delay_ms(STEPER_DELAY);
		MDIO_Error_State_tSetPinValue(STPM_PINK_PORT, STPM_PINK_PIN, COIL_DISABLE);

		/* for fourth Activation */
		MDIO_Error_State_tSetPinValue(STPM_BLUE_PORT, STPM_BLUE_PIN, COIL_ENABLE);
		_delay_ms(STEPER_DELAY);
		MDIO_Error_State_tSetPinValue(STPM_BLUE_PORT, STPM_BLUE_PIN, COIL_DISABLE);
	}
}

void STPM_vStop(void) {
	MDIO_Error_State_tSetPinValue(STPM_BLUE_PORT, STPM_BLUE_PIN, COIL_DISABLE);
	MDIO_Error_State_tSetPinValue(STPM_PINK_PORT, STPM_PINK_PIN, COIL_DISABLE);
	MDIO_Error_State_tSetPinValue(STPM_YELLOW_PORT, STPM_YELLOW_PIN, COIL_DISABLE);
	MDIO_Error_State_tSetPinValue(STPM_ORANGE_PORT, STPM_ORANGE_PIN, COIL_DISABLE);
}



