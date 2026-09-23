/*
 * EEPROM.c
 *
 *  Created on: Sep 23, 2026
 *      Author: Mohammed El-Sherbini
 */
#include "../../LIB/BitMath.h"
#include "../../LIB/STD_type.h"

#include "EEPROM.h"

void EEPROM_voidWrite(u16 A_u16Adress , u8 A_u8Data)
{
	EEARL = A_u16Adress ;
	EEDR = A_u8Data ;
	SET_BIT(EECR , 2 );
	SET_BIT(EECR , 1 );
	while (READ_BIT( EECR , 1 ) == 1 ) ;
}
u8 EEPROM_voidRead(u16 A_u16Adress )
{
	EEARL = A_u16Adress ;
	SET_BIT(EECR , 0);
	return EEDR ;
}
