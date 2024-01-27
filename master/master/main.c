#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "MDIO_interface.h"
#include "CLCD_interface.h"
#include "HKEY_PAD_interface.h"
#include "MADC_interface.h"
#include "MSPI_interface.h"
#include "App.h"

int main()
{
	PORT_voidInit();
	CLCD_void_Init();
	MADC_voidInit();
	MSPI_voidInit();
    u8 dummy=80;
    u8 receive_data_LDR;
    u8 LED_value;
	while(1)
	{
		receive_data_LDR=MSPI_u8Transcive(dummy);
		if(receive_data_LDR==80)
		{
			MDIO_EnumSetPortValue(DIO_PORTB,0XFF);
		}
		//LED_value=MAP_U16MAPPING(1024,0,255,0,receive_data_LDR);
	}
}




