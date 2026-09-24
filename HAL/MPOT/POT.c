/*
 * POT.c
 *
 *  Created on: Sep 24, 2026
 *      Author: Mohammed El-Sherbini
 */

#include "../../LIB/BitMath.h"
#include "../../LIB/STD_type.h"
#include "../../MCAL/MDIO/DIO.h"
#include "../../MCAL/MADC/ADC.h"
#include "POT.h"

void POT_voidInit(void)
{

}
u16   POT_u16GetCurrent(void)
{
    MADC_voidStartConversion(POT_ADC_CHANNEL);
    return MADC_u16GetDataUsingPolling();
}
