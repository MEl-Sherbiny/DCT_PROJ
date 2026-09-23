/*
 * EXTI.h
 *
 *  Created on: Sep 23, 2026
 *      Author: Mohammed El-Sherbini
 */

#ifndef MCAL_MEXTI_EXTI_H_
#define MCAL_MEXTI_EXTI_H_

#define EXTI_SENCE_LOW_LEVEL    0
#define EXTI_SENCE_ON_CHANGE    1
#define EXTI_SENCE_FALLING      2
#define EXTI_SENCE_RISING       3

#define MCUCR    (*(volatile u8*)(0x55))
#define MCUCSR   (*(volatile u8*)(0x54))
#define GICR     (*(volatile u8*)(0x5B))
#define GIFR     (*(volatile u8*)(0x5A))
#define SREG     (*(volatile u8*)(0x5F))

void MEXTI0_Init(u8 A_u8Mode);
void MEXTI1_Init(u8 A_u8Mode);
void MEXTI2_Init(u8 A_u8Mode);

void MEXTI0_voidCallBAck(void (*fptr)(void));
void MEXTI1_voidCallBAck(void (*fptr)(void));
void MEXTI2_voidCallBAck(void (*fptr)(void));

#endif /* MCAL_MEXTI_EXTI_H_ */
