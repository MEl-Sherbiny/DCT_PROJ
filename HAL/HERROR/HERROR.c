#include "HERROR.h"

u8 G_u8TempErrorLogged = 0;
u8 G_u8LowCurrErrorLogged = 0;
u8 G_u8HighCurrErrorLogged = 0;
u8* GP_u8CorrectPassword;
u8 G_u8PassLength;

void HERROR_voidSetError(u8 a_u8Error){
    switch(a_u8Error){
        case ERROR_CODE_HIGH_TEMP:
            if (G_u8TempErrorLogged != 1){
                EEPROM_voidWrite(EEPROM_ADDR_TEMP_ERROR, a_u8Error);
                G_u8TempErrorLogged = 1;
            }
            break;
        case ERROR_CODE_HIGH_CURRENT:
            if (G_u8HighCurrErrorLogged != 1){
                EEPROM_voidWrite(EEPROM_ADDR_CURRENT_HIGH, a_u8Error);
                G_u8HighCurrErrorLogged = 1;
            }
            break;
        case ERROR_CODE_LOW_CURRENT:
            if (G_u8LowCurrErrorLogged != 1){
                EEPROM_voidWrite(EEPROM_ADDR_CURRENT_LOW, a_u8Error);
                G_u8LowCurrErrorLogged = 1;
            }
            break;
    }
}

void HERROR_voidCheckErrorRequestInit(u8* a_u8PassKey, u8 a_u8PassLength, u32 a_u32BaudRate){
    MUART_voidInit(a_u32BaudRate, 8);
    GP_u8CorrectPassword = a_u8PassKey;
    G_u8PassLength = a_u8PassLength;
}

void HERROR_voidCheckErrorRequest(void){
    static u8 SL_u8InputPosition = 0;
    u8 L_u8CurrentChar = MUART_u8Rx();

    if(L_u8CurrentChar == INCOMPLETE_RECIEVE)
        return;
    // MUART_voidTx(L_u8CurrentChar);
    if(L_u8CurrentChar == GP_u8CorrectPassword[SL_u8InputPosition]){
        SL_u8InputPosition++;
        // MUART_voidTx('w');
    }
    else{
        SL_u8InputPosition = 0;
        // MUART_voidTx('f');
    }
    if(SL_u8InputPosition == G_u8PassLength){
        SL_u8InputPosition = 0;
        HERROR_u32PrintErrors();
    }
}

void HERROR_u32PrintErrors(void){
    u8 L_u8HighCurrent = EEPROM_u8Read(EEPROM_ADDR_CURRENT_HIGH);
    u8 L_u8LowCurrent = EEPROM_u8Read(EEPROM_ADDR_CURRENT_LOW);
    u8 L_u8HighTemp = EEPROM_u8Read(EEPROM_ADDR_TEMP_ERROR);
    if(L_u8HighCurrent == ERROR_CODE_HIGH_CURRENT)

        MUART_voidTxStr("Error code 0x51: High Current\r\n");
    if(L_u8LowCurrent == ERROR_CODE_LOW_CURRENT)
        MUART_voidTxStr("Error code 0x52: Low Current\r\n");
    if(L_u8HighTemp == ERROR_CODE_HIGH_TEMP)
        MUART_voidTxStr("Error code 0x50: High Temperature\r\n");
}
        while(!MUART_voidTxStr("Error code 0x51: High Current\r\n"));
    if(L_u8LowCurrent == ERROR_CODE_LOW_CURRENT)
        while(!MUART_voidTxStr("Error code 0x52: Low Current\r\n"));
    if(L_u8HighTemp == ERROR_CODE_HIGH_TEMP)
        while(!MUART_voidTxStr("Error code 0x50: High Temperature\r\n"));
}

