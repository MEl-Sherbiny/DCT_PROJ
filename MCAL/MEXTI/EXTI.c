/*
 * EXTI.c
 *
 *  Created on: Sep 23, 2026
 *      Author: Mohammed El-Sherbini
 */

#include "../../LIB/BitMath.h"
#include "../../LIB/STD_type.h"

#include "EXTI.h"

void (*EXTI0_Ptr)(void);
void (*EXTI1_Ptr)(void);
void (*EXTI2_Ptr)(void);

void MEXTI0_Init(u8 A_u8Mode) {
	SET_BIT(SREG, 7);
	SET_BIT(GICR, 6);
	switch (A_u8Mode) {
	case EXTI_SENCE_LOW_LEVEL:
		CLR_BIT(MCUCR, 0);
		CLR_BIT(MCUCR, 1);
		break;
	case EXTI_SENCE_ON_CHANGE:
		SET_BIT(MCUCR, 0);
		CLR_BIT(MCUCR, 1);
		break;
	case EXTI_SENCE_FALLING:
		CLR_BIT(MCUCR, 0);
		SET_BIT(MCUCR, 1);
		break;
	case EXTI_SENCE_RISING:
		SET_BIT(MCUCR, 0);
		SET_BIT(MCUCR, 1);
		break;
	}

}
void MEXTI1_Init(u8 A_u8Mode) {
	SET_BIT(SREG, 7);
	SET_BIT(GICR, 7);

	switch (A_u8Mode) {
	case EXTI_SENCE_LOW_LEVEL:
		CLR_BIT(MCUCR, 2);
		CLR_BIT(MCUCR, 3);
		break;
	case EXTI_SENCE_ON_CHANGE:
		SET_BIT(MCUCR, 2);
		CLR_BIT(MCUCR, 3);
		break;
	case EXTI_SENCE_FALLING:
		CLR_BIT(MCUCR, 2);
		SET_BIT(MCUCR, 3);
		break;
	case EXTI_SENCE_RISING:
		SET_BIT(MCUCR, 2);
		SET_BIT(MCUCR, 3);
		break;
	}

}
void MEXTI2_Init(u8 A_u8Mode) {
	SET_BIT(SREG, 7);
	SET_BIT(GICR, 5);

	switch (A_u8Mode) {
	case EXTI_SENCE_FALLING:
		CLR_BIT(MCUCSR, 0);
		break;
	case EXTI_SENCE_RISING:
		SET_BIT(MCUCSR, 0);
		break;
	}

}

void MEXTI0_voidCallBAck(void (*fptr)(void))
{
	EXTI0_Ptr = fptr ;
}
void MEXTI1_voidCallBAck(void (*fptr)(void))
{
	EXTI1_Ptr = fptr ;
}
void MEXTI2_voidCallBAck(void (*fptr)(void))
{
	EXTI2_Ptr = fptr ;
}

void __vector_1 (void)__attribute__((signal));
void __vector_1 (void)
{
	EXTI0_Ptr();
}
void __vector_2 (void)__attribute__((signal));
void __vector_2 (void)
{
	EXTI1_Ptr();
}
void __vector_3 (void)__attribute__((signal));
void __vector_3 (void)
{
	EXTI2_Ptr();
}





