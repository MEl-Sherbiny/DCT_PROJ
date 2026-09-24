#ifndef HERROR_H
#define HERROR_H

#include "../../LIB/BitMath.h"
#include "../../LIB/STD_type.h"
#include "../../MCAL/EEPROM/EEPROM.h"
#include "../../MCAL/MUART/MUART.h"

/* ------ EEPROM Addresses ------ */
#define EEPROM_ADDR_TEMP_ERROR       0x000
#define EEPROM_ADDR_CURRENT_HIGH     0x001
#define EEPROM_ADDR_CURRENT_LOW      0x002

/* ------ Error Codes ------ */
#define ERROR_CODE_HIGH_TEMP         0x50
#define ERROR_CODE_HIGH_CURRENT      0x51
#define ERROR_CODE_LOW_CURRENT       0x52

void HERROR_voidSetError(u8 a_u8Error);
void HERROR_voidCheckErrorRequestInit(u8* a_u8PassKey, u8 a_u8PassLength, u32 a_u32BaudRate);
void HERROR_voidCheckErrorRequest(void);
void HERROR_u32PrintErrors(void);

#endif