/*
 * ADC.c
 *
 *  Created on: Sep 22, 2026
 *      Author: win 10
 */

#include "../../LIB/BitMath.h"
#include "../../LIB/STD_type.h"

#include "ADC.h"
void (*ADC_ptr)(void) ;
void MADC_voidInit (u8 A_u8Prescaller , u8 A_u8Ref)
{
	switch (A_u8Ref)
	{
	case  ADC_REF_EXTERNAL      :
		CLR_BIT(ADMUX , 6) ;
		CLR_BIT(ADMUX , 7) ;
		break ;
	case  ADC_REF_AVCC          :
		SET_BIT(ADMUX , 6) ;
		CLR_BIT(ADMUX , 7) ;
		break ;
	case  ADC_REF_INTERNAL_2_56 :
		SET_BIT(ADMUX , 6) ;
		SET_BIT(ADMUX , 7) ;
		break ;
	}

	switch (A_u8Prescaller)
	{
	case ADC_PRESCALLER2   :
		SET_BIT(ADCSRA , 0) ;
		CLR_BIT(ADCSRA , 1) ;
		CLR_BIT(ADCSRA , 2) ;
		break ;
	case ADC_PRESCALLER4   :
		CLR_BIT(ADCSRA , 0) ;
		SET_BIT(ADCSRA , 1) ;
		CLR_BIT(ADCSRA , 2) ;
		break ;
	case ADC_PRESCALLER8   :
		SET_BIT(ADCSRA , 0) ;
		SET_BIT(ADCSRA , 1) ;
		CLR_BIT(ADCSRA , 2) ;
		break ;
	case ADC_PRESCALLER16  :
		CLR_BIT(ADCSRA , 0) ;
		CLR_BIT(ADCSRA , 1) ;
		SET_BIT(ADCSRA , 2) ;
		break ;
	case ADC_PRESCALLER32  :
		SET_BIT(ADCSRA , 0) ;
		CLR_BIT(ADCSRA , 1) ;
		SET_BIT(ADCSRA , 2) ;
		break ;
	case ADC_PRESCALLER64  :
		CLR_BIT(ADCSRA , 0) ;
		SET_BIT(ADCSRA , 1) ;
		SET_BIT(ADCSRA , 2) ;
		break ;
	case ADC_PRESCALLER128 :
		SET_BIT(ADCSRA , 0) ;
		SET_BIT(ADCSRA , 1) ;
		SET_BIT(ADCSRA , 2) ;
		break ;
	}
#if ADC_INTERRUPT_ENABLE == 1
	SET_BIT(SREG , 7) ;
	SET_BIT(ADCSRA , 3) ;
#endif

	SET_BIT(ADCSRA , 7) ;
}

void MADC_voidStartConversion (u8 A_u8ChannelNum)
{
	switch (A_u8ChannelNum)
	{
	case ADC_CH0 :
		CLR_BIT(ADMUX , 0) ;
		CLR_BIT(ADMUX , 1) ;
		CLR_BIT(ADMUX , 2) ;
		break ;
	case ADC_CH1 :
		SET_BIT(ADMUX , 0) ;
		CLR_BIT(ADMUX , 1) ;
		CLR_BIT(ADMUX , 2) ;
		break ;
	case ADC_CH2 :
		CLR_BIT(ADMUX , 0) ;
		SET_BIT(ADMUX , 1) ;
		CLR_BIT(ADMUX , 2) ;
		break ;
	case ADC_CH3 :
		SET_BIT(ADMUX , 0) ;
		SET_BIT(ADMUX , 1) ;
		CLR_BIT(ADMUX , 2) ;
		break ;
	case ADC_CH4 :
		CLR_BIT(ADMUX , 0) ;
		CLR_BIT(ADMUX , 1) ;
		SET_BIT(ADMUX , 2) ;
		break ;
	case ADC_CH5 :
		SET_BIT(ADMUX , 0) ;
		CLR_BIT(ADMUX , 1) ;
		SET_BIT(ADMUX , 2) ;
		break ;
	case ADC_CH6 :
		CLR_BIT(ADMUX , 0) ;
		SET_BIT(ADMUX , 1) ;
		SET_BIT(ADMUX , 2) ;
		break ;
	case ADC_CH7 :
		SET_BIT(ADMUX , 0) ;
		SET_BIT(ADMUX , 1) ;
		SET_BIT(ADMUX , 2) ;
		break ;
	}
	SET_BIT(ADCSRA , 6) ;
}

u16  MADC_u16GetDataUsingInterrupt (void)
{
	return ADC ;
}
u16  MADC_u16GetDataUsingPolling (void)
{
	while (READ_BIT(ADCSRA , 4) == 0) ;
	SET_BIT(ADCSRA , 4) ;
	return ADC ;
}
void MADC_voidCallBack (void(*fptr)(void))
{
	ADC_ptr = fptr ;
}
void __vector_16 (void)__attribute__((signal)) ;
void __vector_16 (void)
{
	ADC_ptr () ;
}

