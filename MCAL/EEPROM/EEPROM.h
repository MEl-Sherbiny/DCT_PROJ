/*
 * EEPROM.h
 *
 *  Created on: Sep 23, 2026
 *      Author: Mohammed El-Sherbini
 */

#ifndef MCAL_EEPROM_EEPROM_H_
#define MCAL_EEPROM_EEPROM_H_

#define EEARL  (*(volatile u16*)(0x3E))
//#define EEARH  (*(volatile u8*)(0x3F))     »„« «‰ «·„Ì„Ê—Ì „  «»⁄Ì‰ »œ·  ﬁ”Ì„Â„ ÂÊ ÂÌ«Œœ «· ‰Ì‰ „⁄ »⁄÷
#define EEDR   (*(volatile u8*)(0x3D))
#define EECR   (*(volatile u8*)(0x3C))

void EEPROM_voidWrite  (u16 A_u16Adress , u8 A_u8Data);
u8   EEPROM_u8Read (u16 A_u16Adress );

#endif /* MCAL_EEPROM_EEPROM_H_ */
