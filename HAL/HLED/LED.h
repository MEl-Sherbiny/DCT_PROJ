/*
 * LED.h
 *
 *  Created on: Sep 16, 2026
 *      Author: Mohammed El-Sherbini
 */


#ifndef HAL_HLED_LED_H_
#define HAL_HLED_LED_H_

void HLED_voidInit    (u8 A_u8LedPort , u8 A_u8LedPin) ;
void HLED_voidTurnOn  (u8 A_u8LedPort , u8 A_u8LedPin) ;
void HLED_voidTurnOff (u8 A_u8LedPort , u8 A_u8LedPin) ;
void HLED_voidTog     (u8 A_u8LedPort , u8 A_u8LedPin) ;
#endif /* HAL_HLED_LED_H_ */
