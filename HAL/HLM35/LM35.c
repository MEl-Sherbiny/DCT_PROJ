/*
 * LM35.c
 *
 *  Created on: Sep 23, 2026
 *      Author: Filopatir Samir
 */
#include "../../LIB/STD_type.h"
#include "../../MCAL/MADC/ADC.h"
#include "LM35.h"

void LM35_voidInit(void)
{
	  /* initlization */
}

u8 LM35_u8GetTemperature(void)
{
    u16 L_u16DigitalValue = 0;
    u32 L_u32MilliVolt = 0;
    u8  L_u8Temperature = 0;

    /* 1. Start conversion on configured channel using MADC */
    MADC_voidStartConversion(LM35_ADC_CHANNEL);

    /* 2. Get data using polling */
    L_u16DigitalValue = MADC_u16GetDataUsingPolling();

    /* 3. Convert Digital Value to Millivolts (VREF = 5000mV) */
    L_u32MilliVolt = ((u32)L_u16DigitalValue * 5000UL) / 1023UL;

    /* 4. LM35 gives 10mV per degree Celsius */
    L_u8Temperature = (u8)(L_u32MilliVolt / 10);

    return L_u8Temperature;
}
