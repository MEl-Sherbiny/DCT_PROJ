/*
 * POT.h
 *
 *  Created on: Sep 24, 2026
 *      Author: Mohammed El-Sherbini
 */

#ifndef HAL_MPOT_POT_H_
#define HAL_MPOT_POT_H_

#define POT_ADC_CHANNEL    ADC_CH1

void POT_voidInit(void);
u16   POT_u16GetCurrent(void);

#endif /* HAL_MPOT_POT_H_ */
