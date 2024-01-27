#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MDIO_interface.h"
#include "MSPI_config.h"
#include "MSPI_registers.h"
#include "MSPI_private.h"
#include "MSPI_interface.h"

void MSPI_voidInit(void)
{
	/*enable SPI*/
   SET_BIT(SPCR,SPCR_SPE);

   /*selcet data order LSB send first*/
   SET_BIT(SPCR,SPCR_DORD);

   /*select SPI mode*/
#if  MSTR_SLAVE ==MASTER
   SET_BIT(SPCR,SPCR_MSTR);

   SET_BIT(SPCR,SPCR_SPR0);
   CLR_BIT(SPCR,SPCR_SPR1);
   CLR_BIT(SPSR ,SPSR_SPI2X);


#elif MSTR_SLAVE ==SLAVE
   CLR_BIT(SPCR,SPCR_MSTR);
#else
#warning "Invalid Input";
#endif

   /*select clock polarity as leading edge is rising*/
    CLR_BIT(SPCR, SPCR_CPOL);

    /*select clock phase as setup*/
    SET_BIT(SPCR,SPCR_CPHA);

}
u8 MSPI_u8Transcive(u8 copy_u8Data)
{
    SPDR=copy_u8Data;
    while(GET_BIT(SPSR , SPSR_SPIF)==0);
    return SPDR;


}
