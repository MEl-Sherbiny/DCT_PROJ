/*
 * TIMER2.h
 *
 *  Created on: Sep 21, 2026
 *      Author: Mohammed El-Sherbini
 */

#ifndef MCAL_MTIMER2_TIMER2_H_
#define MCAL_MTIMER2_TIMER2_H_


#define TIMER2_PRESCALLER1      1
#define TIMER2_PRESCALLER8      8
#define TIMER2_PRESCALLER64     64
#define TIMER2_PRESCALLER256    256
#define TIMER2_PRESCALLER1024   1024

#define TIMER2_OVF     1
#define TIMER2_PWM_PC  2
#define TIMER2_CTC     3
#define TIMER2_FPWM    4

#define TCCR2   (*(volatile u8*)(0x45))
#define TCNT2   (*(volatile u8*)(0x44))
#define OCR2    (*(volatile u8*)(0x43))
#define TIMSK   (*(volatile u8*)(0x59))
#define SREG    (*(volatile u8*)(0x5F))

void MTIMER2_voidInit(u16 A_u16Prescaller , u8 A_u8Mode);
void MTIMER2_voidSetDT(u32 A_u32TimeMicro , void (*fptr)(void));


#endif /* MCAL_MTIMER2_TIMER2_H_ */
