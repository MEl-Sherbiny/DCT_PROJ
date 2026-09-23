/*
 * Timer0.c
 *
 *  Created on: Sep 20, 2026
 *      Author: win 10
 */

#include "../../LIB/BitMath.h"
#include "../../LIB/STD_type.h"
#include "../MDIO/DIO.h"
#include "Timer0.h"
#include <util/delay.h>
u32 G_u32Timer0Prescaller ;
u32 G_u32DesiredCounts ;
void (*Timer0_ptr)(void) ;
void MTimer0_voidInit (u16 A_u16Prescaller , u8 A_u8Mode)
{
	G_u32Timer0Prescaller = A_u16Prescaller ;
	switch (A_u16Prescaller)
	{
	case TIMER0_PRESCALLER1    :
		SET_BIT(TCCR0 , 0) ;
		CLR_BIT(TCCR0 , 1) ;
		CLR_BIT(TCCR0 , 2) ;
		break ;
	case TIMER0_PRESCALLER8    :
		CLR_BIT(TCCR0 , 0) ;
		SET_BIT(TCCR0 , 1) ;
		CLR_BIT(TCCR0 , 2) ;
		break ;
	case TIMER0_PRESCALLER64   :
		SET_BIT(TCCR0 , 0) ;
		SET_BIT(TCCR0 , 1) ;
		CLR_BIT(TCCR0 , 2) ;
		break ;
	case TIMER0_PRESCALLER256  :
		CLR_BIT(TCCR0 , 0) ;
		CLR_BIT(TCCR0 , 1) ;
		SET_BIT(TCCR0 , 2) ;
		break ;
	case TIMER0_PRESCALLER1024 :
		SET_BIT(TCCR0 , 0) ;
		CLR_BIT(TCCR0 , 1) ;
		SET_BIT(TCCR0 , 2) ;
		break ;
	}

	switch (A_u8Mode)
	{
	case TIMER0_OVF               :
		CLR_BIT(TCCR0 , 6) ;
		CLR_BIT(TCCR0 , 3) ;
		SET_BIT(TIMSK , 0) ;
		SET_BIT(SREG  , 7) ;
		break ;
	case TIMER0_PWM_PHASE_CORRECT :
		SET_BIT(TCCR0 , 6) ;
		CLR_BIT(TCCR0 , 3) ;
		MDIO_voidInitPin(DIO_PORTB , DIO_PIN3 , DIO_OUTPUT) ;
		CLR_BIT(TCCR0 , 4) ;
		SET_BIT(TCCR0 , 5) ;
		break ;
	case TIMER0_CTC               :
		CLR_BIT(TCCR0 , 6) ;
		SET_BIT(TCCR0 , 3) ;
		break ;
	case TIMER0_FAST_PWM          :
		SET_BIT(TCCR0 , 6) ;
		SET_BIT(TCCR0 , 3) ;
		MDIO_voidInitPin(DIO_PORTB , DIO_PIN3 , DIO_OUTPUT) ;
		CLR_BIT(TCCR0 , 4) ;
		SET_BIT(TCCR0 , 5) ;
		break ;
	}
}
void MTimer0_voidSetDT (u32 A_u32TimeInMiocro , void (*fptr)(void))
{
	f32 L_f32OverflowTime = (256.0 * (f32)G_u32Timer0Prescaller) / ((f32)F_CPU / 1000000.0);
	f32 L_f32DesiredOverFlowCounts = (f32)A_u32TimeInMiocro/(L_f32OverflowTime) ;
	u32 L_u32PreLoadValue ;
	Timer0_ptr = fptr ;
	if (L_f32DesiredOverFlowCounts < 1.0)
	{
		G_u32DesiredCounts = 1 ;
		L_u32PreLoadValue = 256 - 256*L_f32DesiredOverFlowCounts ;
		TCNT0 = L_u32PreLoadValue ;
	}
	else if (L_f32DesiredOverFlowCounts == 1.0)
	{
		G_u32DesiredCounts = 1 ;
	}
	else if (L_f32DesiredOverFlowCounts > 1.0)
	{
		G_u32DesiredCounts = L_f32DesiredOverFlowCounts ;
		if ((L_f32DesiredOverFlowCounts - (u32)L_f32DesiredOverFlowCounts) != 0.0)
		{
			G_u32DesiredCounts ++ ;
			L_u32PreLoadValue = 256 - 256*(L_f32DesiredOverFlowCounts - (u32)L_f32DesiredOverFlowCounts) ;
			TCNT0 = L_u32PreLoadValue ;
		}
	}
}
void MTimer0_voidSetCompareValue(u8 A_u8Value)
{
	OCR0 = A_u8Value ;
}
void __vector_11 (void)__attribute__((signal)) ;
void __vector_11 (void)
{
	static u32 LS_u32Counter = 0 ;
	LS_u32Counter ++ ;
	if (LS_u32Counter == G_u32DesiredCounts)
	{
		Timer0_ptr () ;
		LS_u32Counter = 0 ;
	}
}
