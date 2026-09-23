/*
 * BitMath.h
 *
 *  Created on: Sep 15, 2026
 *      Author: Mohammed El-Sherbini
 */

#ifndef LIB_BITMATH_H_
#define LIB_BITMATH_H_

#define SET_BIT(reg , bit)   ((reg)|=(1<<(bit)))
#define TOG_BIT(reg , bit)   ((reg)^=(1<<(bit)))
#define CLR_BIT(reg , bit)   ((reg)&=(~(1<<(bit))))
#define READ_BIT(reg , bit)  (((reg)&(1<<(bit)))>>(bit))


#endif /* LIB_BITMATH_H_ */
