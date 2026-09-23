/*
 * ADC.h
 *
 *  Created on: Sep 22, 2026
 *      Author: Mohammed El-Sherbini
 */


#ifndef MCAL_MADC_ADC_H_
#define MCAL_MADC_ADC_H_

#define ADC_INTERRUPT_ENABLE  1


#define ADC_REF_EXTERNAL         0
#define ADC_REF_AVCC             1
#define ADC_REF_INTERNAL_2_56    2

#define ADC_PRESCALLER2        2
#define ADC_PRESCALLER4        4
#define ADC_PRESCALLER8        8
#define ADC_PRESCALLER16       16
#define ADC_PRESCALLER32       32
#define ADC_PRESCALLER64       64
#define ADC_PRESCALLER128      128

#define ADC_CH0    0
#define ADC_CH1    1
#define ADC_CH2    2
#define ADC_CH3    3
#define ADC_CH4    4
#define ADC_CH5    5
#define ADC_CH6    6
#define ADC_CH7    7

#define ADMUX         (*(volatile u8*)(0x27))
#define ADCSRA        (*(volatile u8*)(0x26))
#define ADC           (*(volatile u16*)(0x24))
#define SFIOR         (*(volatile u8*)(0x50))
#define SREG          (*(volatile u8*)(0x5F))

void MADC_voidInit (u8 A_u8Prescaller , u8 A_u8Ref) ;
void MADC_voidStartConversion (u8 A_u8ChannelNum) ;
u16  MADC_u16GetDataUsingInterrupt (void) ;
u16  MADC_u16GetDataUsingPolling (void) ;
void MADC_voidCallBack (void(*fptr)(void)) ;
#endif /* MCAL_MADC_ADC_H_ */
