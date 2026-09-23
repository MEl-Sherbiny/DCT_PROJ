/*
 * LM35.h
 *
 *  Created on: Sep 23, 2026
 *      Author: Filopatir Samir
 */

#ifndef HAL_HLM35_LM35_H_
#define HAL_HLM35_LM35_H_

#include "../../LIB/STD_type.h"
#include "../../MCAL/MADC/ADC.h"

#define LM35_ADC_CHANNEL    ADC_CH0

void LM35_voidInit(void);
u8   LM35_u8GetTemperature(void);

#endif /* HAL_HLM35_LM35_H_ */
