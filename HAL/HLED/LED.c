
#include "../../LIB/BitMath.h"
#include "../../LIB/STD_type.h"
#include "../../MCAL/MDIO/DIO.h"

#include "LED.h"

void HLED_voidInit (u8 A_u8LedPort , u8 A_u8LedPin)
{
	MDIO_voidInitPin(A_u8LedPort , A_u8LedPin , DIO_OUTPUT) ;
}
void HLED_voidTurnOn (u8 A_u8LedPort , u8 A_u8LedPin)
{
	MDIO_voidSetPinValue(A_u8LedPort , A_u8LedPin , DIO_HIGH) ;
}
void HLED_voidTurnOff (u8 A_u8LedPort , u8 A_u8LedPin)
{
	MDIO_voidSetPinValue(A_u8LedPort , A_u8LedPin , DIO_LOW) ;
}
void HLED_voidTog (u8 A_u8LedPort , u8 A_u8LedPin)
{
	MDIO_voidTogPin (A_u8LedPort , A_u8LedPin) ;
}
