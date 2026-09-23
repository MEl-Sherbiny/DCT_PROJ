/*
 * main.c
 *
 *  Created on: Sep 23, 2026
 *      Author: Mohammed El-Sherbini
 */

#include "../LIB/BitMath.h"
#include "../LIB/STD_type.h"
#include "../MCAL/MDIO/DIO.h"
#include "../HAL/HLED/LED.h"
#include "../HAL/HLM35/LM35.h"
#include "../MCAL/MEXTI/EXTI.h"
#include "../MCAL/EEPROM/EEPROM.h"

/* ------ EEPROM Addresses ------ */
#define EEPROM_ADDR_TEMP_ERROR       0x000
#define EEPROM_ADDR_CURRENT_HIGH     0x001
#define EEPROM_ADDR_CURRENT_LOW      0x002

/* ------ Error Codes ------ */
#define ERROR_CODE_HIGH_TEMP         0x50
#define ERROR_CODE_HIGH_CURRENT      0x51
#define ERROR_CODE_LOW_CURRENT       0x52

int main(void)
{
	u8 G_u8TempErrorLogged = 0;
	HLED_voidInit(DIO_PORTD ,DIO_PIN7);
	 /* 1. Initialize MADC with Prescaler 64 and VREF = AVCC */
	    MADC_voidInit(ADC_PRESCALLER64, ADC_REF_AVCC);

	    /* 2. Initialize LM35 */
	    LM35_voidInit();
	    u8 L_u8CurrentTemp = 0;
	    u8 TEMP_THRESHOLD = 40 ;

	    while (1)
	    {

		    /* 4. Read current temperature from LM35 */
		    	        L_u8CurrentTemp = LM35_u8GetTemperature();

		    	        /* 5. Check Threshold for Temperature (DTC 0x52) */
		    	        if (L_u8CurrentTemp > TEMP_THRESHOLD)
		    	        {
		    	        	HLED_voidTurnOn(DIO_PORTD ,DIO_PIN7);
		    	        	if (G_u8TempErrorLogged == 0)
		    	        	        {
		    	        	            EEPROM_voidWrite(EEPROM_ADDR_TEMP_ERROR, ERROR_CODE_HIGH_TEMP);
		    	        	            G_u8TempErrorLogged = 1;
		    	        	        }
		    	        }
		    	        if (L_u8CurrentTemp <= TEMP_THRESHOLD)
		    	        {
		    	        	HLED_voidTurnOff(DIO_PORTD ,DIO_PIN7);
		    	        }

	    }
}
