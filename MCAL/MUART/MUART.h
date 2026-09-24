#ifndef MUART_H
#define MUART_H
#include "../../LIB/STD_type.h"
#include "../../LIB/BitMath.h"

#define UDR         (*((volatile u8*) (0x2C)))
#define UCSRA       (*((volatile u8*) (0x2B)))
#define UCSRB       (*((volatile u8*) (0x2A)))
#define UCSRC       (*((volatile u8*) (0x40)))
#define UBRRH       (*((volatile u8*) (0x40)))
#define UBRRL       (*((volatile u8*) (0x29)))
#define SREG        (*(volatile u8*)(0x5F))
#define F_OSC       8000000u
#define INCOMPLETE_RECIEVE 0
void MUART_voidInit(u32 a_u32BaudRate, u8 a_u8charSize);
void MUART_voidTx(u8 a_u8Data);
u8 MUART_voidTxStr(u8* a_u8String);
u8 MUART_u8Rx(void);


#endif