/*
 * main.c
 *
 *  Created on: Sep 23, 2026
 *      Author: Mohammed El-Sherbini
 */

#include "../LIB/BitMath.h"
#include "../LIB/STD_type.h"
#include "../HAL/HLED/LED.h"
#include "../HAL/HLM35/LM35.h"
#include "../HAL/MPOT/POT.h"
#include "../HAL/HERROR/HERROR.h"
#include "../MCAL/MEXTI/EXTI.h"
#include "../MCAL/EEPROM/EEPROM.h"
#include "../MCAL/MUART/MUART.h"
#include "../MCAL/MDIO/DIO.h"
#include "../MCAL/MADC/ADC.h"

#define HIGH_TEMP 40
#define LOW_CURRENT 100 //about 0.5v
#define HIGH_CURRENT 900 //about 4.5v

int main(void)
{
	u8 G_u8TempErrorLogged = 0;
	u8 G_u8LowCurrErrorLogged = 0;
	u8 G_u8HighCurrErrorLogged = 0;

	HLED_voidInit(DIO_PORTD ,DIO_PIN7);
	 /* 1. Initialize MADC with Prescaler 64 and VREF = AVCC */
	    MADC_voidInit(ADC_PRESCALLER64, ADC_REF_AVCC);

	    /* 2. Initialize LM35 */
	    LM35_voidInit();
	    POT_voidInit();
		HERROR_voidCheckErrorRequestInit("123", 3, 9600);
	    u8 L_u8CurrentTemp = 0 ;
	    u16 L_u16CurrentCurr = 1;


	    while (1)
	    {
	        u8 L_u8ErrorExists = 0;

		    /* 4. Read current temperature from LM35 */
		    	        L_u8CurrentTemp = LM35_u8GetTemperature();
		    	        L_u16CurrentCurr = POT_u16GetCurrent();
		    	        if (L_u16CurrentCurr >= HIGH_CURRENT)
		    	        {
		    	        	L_u8ErrorExists = 1;
		    	        	HERROR_voidSetError(ERROR_CODE_HIGH_CURRENT);
		    	        }
		    	        if (L_u16CurrentCurr <= LOW_CURRENT)
		    	         {
		    	        	L_u8ErrorExists = 1;
		    	         	HERROR_voidSetError(ERROR_CODE_LOW_CURRENT);
		    	         }
		    	        /* 5. Check Threshold for Temperature (DTC 0x52) */
		    	        if (L_u8CurrentTemp > HIGH_TEMP)
		    	        {
		    	        	L_u8ErrorExists = 1;
		    	        	HERROR_voidSetError(ERROR_CODE_HIGH_TEMP);
		    	        }

		    	        if (L_u8ErrorExists == 1 )
		    	        {
		    	        	HLED_voidTurnOn(DIO_PORTD ,DIO_PIN7);
						}
		    	        else
		    	        {
    		    	        HLED_voidTurnOff(DIO_PORTD ,DIO_PIN7);
		    	        }

						HERROR_voidCheckErrorRequest();

	    }
}



