/*
 * TIMER2.c
 *
 *  Created on: Sep 21, 2026
 *      Author: Mohammed El-Sherbini
 */


#include "../../LIB/STD_type.h"
#include "../../LIB/BitMath.h"
#include "../MDIO/DIO.h"
#include "TIMER2.h"
#include <util/delay.h>

 u32 G_u32Counter = 0;
 u32 G_u32TimerPrescaller ;
 volatile u32 G_u32Desicount ;
 void (*Timer2_ptr)(void);
void MTIMER2_voidInit(u16 A_u16Prescaller , u8 A_u8Mode)
{
	G_u32TimerPrescaller = A_u16Prescaller;
	switch(A_u16Prescaller)
	{
	case TIMER2_PRESCALLER1    :
	    SET_BIT(TCCR2 ,0);
	    CLR_BIT(TCCR2 ,1);
	    CLR_BIT(TCCR2 ,2);
	    break;
	case TIMER2_PRESCALLER8    :
	    CLR_BIT(TCCR2 ,0);
	    SET_BIT(TCCR2 ,1);
	    CLR_BIT(TCCR2 ,2);
	    break;
	case TIMER2_PRESCALLER64   :
	    CLR_BIT(TCCR2 ,0);
	    CLR_BIT(TCCR2 ,1);
	    SET_BIT(TCCR2 ,2);
	    break;
	case TIMER2_PRESCALLER256  :
	    CLR_BIT(TCCR2 ,0);
	    SET_BIT(TCCR2 ,1);
	    SET_BIT(TCCR2 ,2);
	    break;
	case TIMER2_PRESCALLER1024 :
	    SET_BIT(TCCR2 ,0);
	    SET_BIT(TCCR2 ,1);
	    SET_BIT(TCCR2 ,2);
	    break;
	}

     switch(A_u8Mode)
     {
       case TIMER2_OVF :
    	   CLR_BIT(TCCR2 , 6);
    	   CLR_BIT(TCCR2 , 3);
    	   SET_BIT(TIMSK ,6 ); // ====================================
    	   SET_BIT(SREG , 7 );
    	   break;
       case TIMER2_PWM_PC :
    	   SET_BIT(TCCR2 , 6);
       	   CLR_BIT(TCCR2 , 3);
    	   break;
       case TIMER2_CTC :
    	   CLR_BIT(TCCR2 , 6);
    	   SET_BIT(TCCR2 , 3);
       	   break;
       case TIMER2_FPWM :
    	   SET_BIT(TCCR2 , 6) ;
    	   		SET_BIT(TCCR2 , 3) ;
    	   		MDIO_voidInitPin(DIO_PORTB , DIO_PIN3 , DIO_OUTPUT) ;
    	   		CLR_BIT(TCCR2 , 4) ;
    	   		SET_BIT(TCCR2 , 5) ;
    	   		break ;
     }
}

void MTIMER2_voidSetDT(u32 A_u32Time , void (*fptr)(void))
{
	f32 L_f32OverflowTime = (256.0 * (f32)G_u32TimerPrescaller) / ((f32)F_CPU / 1000000.0);
  f32 L_f32DesierdOVFcount = (f32)A_u32Time / L_f32OverflowTime;
  u32 L_u32Preloadvalue ;
  Timer2_ptr = fptr ;
  if (L_f32DesierdOVFcount < 1.0 )
  {
	  G_u32Desicount = 1 ;
	  L_u32Preloadvalue = 256 - (256 * L_f32DesierdOVFcount) ;
	  TCNT2 = L_u32Preloadvalue;
  }
  else if (L_f32DesierdOVFcount == 1)
  {
	  G_u32Desicount = 1 ;
  }
  else if (L_f32DesierdOVFcount > 1.0)
  {
	  G_u32Desicount = L_f32DesierdOVFcount ;
	  if ((L_f32DesierdOVFcount - (u32)L_f32DesierdOVFcount) != 0.0 )
	  {
		  G_u32Desicount ++;
		  L_u32Preloadvalue = 256 - 256 * (L_f32DesierdOVFcount - (u32)L_f32DesierdOVFcount)  ;
		  TCNT2 = L_u32Preloadvalue ;
	  }
  }

}

void __vector_5 (void)__attribute((signal));
void __vector_5 (void)
{

	G_u32Counter ++;
	if (G_u32Counter == G_u32Desicount)
	{
		Timer2_ptr ();
		G_u32Counter = 0;
	}
}
