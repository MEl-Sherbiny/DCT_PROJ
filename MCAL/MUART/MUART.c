#include "MUART.h"

u8* GP_u8CurrentString;
void MUART_voidInit(u32 a_u32BaudRate, u8 a_u8charSize){
    u16 L_u16UBRRVal = F_OSC / (16 * a_u32BaudRate) - 1;
    UBRRL = (u8) L_u16UBRRVal;
    CLR_BIT(UBRRH, 7);
    UBRRH = (u8) (L_u16UBRRVal >> 8);
    SET_BIT(UCSRB, 4);
    SET_BIT(UCSRB, 3);

    SET_BIT(UCSRC, 7);
    switch(a_u8charSize){
        case 5:
            CLR_BIT(UCSRC, 1);
            CLR_BIT(UCSRC, 2);
            CLR_BIT(UCSRB, 2);
            break;
        case 6:
            SET_BIT(UCSRC, 1);
            CLR_BIT(UCSRC, 2);
            CLR_BIT(UCSRB, 2);
            break;
        case 7:
            CLR_BIT(UCSRC, 1);
            SET_BIT(UCSRC, 2);
            CLR_BIT(UCSRB, 2);
            break;
        case 8:
            SET_BIT(UCSRC, 1);
            SET_BIT(UCSRC, 2);
            CLR_BIT(UCSRB, 2);
            break;
    }
}

void MUART_voidTx(u8 a_u8Data){
    while(!READ_BIT(UCSRA, 5));
    UDR = a_u8Data;
    while(!READ_BIT(UCSRA, 6));
}

void MUART_voidSendChar(void){
    static u8 SL_u8CurrentPos = 0;
    MUART_voidTx(GP_u8CurrentString[SL_u8CurrentPos++]);
    if(GP_u8CurrentString[SL_u8CurrentPos] == '\0'){
        CLR_BIT(UCSRB, 6);
        SL_u8CurrentPos = 0;
    }
}

void MUART_voidTxStr(u8* a_u8String){
    while(READ_BIT(UCSRB, 6)); //wait till previous string send
    SET_BIT(SREG, 7);
    SET_BIT(UCSRB, 6);
    GP_u8CurrentString = a_u8String;
    MUART_voidSendChar();
}

u8 MUART_u8Rx(void){
    // while(!READ_BIT(UCSRA, 7));
    if(READ_BIT(UCSRC, 7))
        return UDR;
    else
        return INCOMPLETE_RECIEVE;
}

void __vector_15 (void)__attribute__((signal)) ;
void __vector_15 (void){
    MUART_voidSendChar();
}
