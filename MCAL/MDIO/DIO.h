/*
 * DIO.h
 *
 *  Created on: Sep 15, 2026
 *      Author: win 10
 */
#include "../../LIB/STD_type.h"
#include "../../LIB/BitMath.h"

#ifndef MCAL_MDIO_DIO_H_
#define MCAL_MDIO_DIO_H_

#define DIO_PORTA  0
#define DIO_PORTB  1
#define DIO_PORTC  2
#define DIO_PORTD  3

#define DIO_PIN0   0
#define DIO_PIN1   1
#define DIO_PIN2   2
#define DIO_PIN3   3
#define DIO_PIN4   4
#define DIO_PIN5   5
#define DIO_PIN6   6
#define DIO_PIN7   7

#define DIO_INPUT  0
#define DIO_OUTPUT 1

#define DIO_LOW    0
#define DIO_HIGH   1

#define DDRA   (*((u8*)(0x3A)))
#define PORTA  (*((u8*)(0x3B)))
#define PINA   (*((u8*)(0x39)))
#define DDRB   (*((u8*)(0x37)))
#define PORTB  (*((u8*)(0x38)))
#define PINB   (*((u8*)(0x36)))
#define DDRC   (*((u8*)(0x34)))
#define PORTC  (*((u8*)(0x35)))
#define PINC   (*((u8*)(0x33)))
#define DDRD   (*((u8*)(0x31)))
#define PORTD  (*((u8*)(0x32)))
#define PIND   (*((u8*)(0x30)))

void MDIO_voidInitPin     (u8 A_u8PortName , u8 A_u8PinNumber , u8 A_u8Mode ) ;
void MDIO_voidSetPinValue (u8 A_u8PortName , u8 A_u8PinNumber , u8 A_u8Value) ;
void MDIO_voidTogPin      (u8 A_u8PortName , u8 A_u8PinNumber               ) ;
u8   MDIO_u8ReadPin       (u8 A_u8PortName , u8 A_u8PinNumber               ) ;

void MDIO_voidInitPort     (u8 A_u8PortName , u8 A_u8Mode ) ;
void MDIO_voidSetPortValue (u8 A_u8PortName , u8 A_u8Value) ;
void MDIO_voidTogPort      (u8 A_u8PortName               ) ;
u8   MDIO_u8ReadPort       (u8 A_u8PortName               ) ;
#endif /* MCAL_MDIO_DIO_H_ */
