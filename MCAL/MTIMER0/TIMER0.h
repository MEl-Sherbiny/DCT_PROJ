/*
 * Timer0.h
 *
 *  Created on: Sep 20, 2026
 *      Author: win 10
 */

#ifndef MCAL_MTIMER0_TIMER0_H_
#define MCAL_MTIMER0_TIMER0_H_

#define TIMER0_PRESCALLER1       1
#define TIMER0_PRESCALLER8       8
#define TIMER0_PRESCALLER64      64
#define TIMER0_PRESCALLER256     256
#define TIMER0_PRESCALLER1024    1024

#define TIMER0_OVF               1
#define TIMER0_PWM_PHASE_CORRECT 2
#define TIMER0_CTC               3
#define TIMER0_FAST_PWM          4

#define TCCR0   (*(volatile u8*)(0x53))
#define TCNT0   (*(volatile u8*)(0x52))
#define OCR0    (*(volatile u8*)(0x5C))
#define TIMSK   (*(volatile u8*)(0x59))
#define SREG    (*(volatile u8*)(0x5F))

void MTimer0_voidInit (u16 A_u16Prescaller , u8 A_u8Mode) ;
void MTimer0_voidSetDT (u32 A_u32TimeInMiocro , void (*fptr)(void)) ;
void MTimer0_voidSetCompareValue(u8 A_u8Value) ;

#endif /* MCAL_MTIMER0_TIMER0_H_ */
