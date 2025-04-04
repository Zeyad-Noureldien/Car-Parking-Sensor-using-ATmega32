#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_

#define SET_BIT(REGISTER,BIT) (REGISTER |= (1 << BIT)) /* Writes logic high on the bit */

#define CLEAR_BIT(REGISTER,BIT) (REGISTER &= (~(1 << BIT))) /* Writes logic low on the bit */

#define TOGGLE_BIT(REGISTER,BIT) (REGISTER ^= (1 << BIT)) /* Toggles the bit */

#define GET_BIT(REGISTER, BIT) (((REGISTER) >> (BIT)) & 0x01) /* Returns the logic status of the bit */

#define BIT_IS_SET(REGISTER,BIT) (REGISTER & (1<<BIT)) /* Checks if the bit is logic high */

#define BIT_IS_CLEAR(REGISTER,BIT) (!(REGISTER & (1<<BIT))) /* Checks if the bit is logic low */

#define ROTATE_RIGHT(REGISTER,NUMBER) (REGISTER = (REGISTER >> NUMBER) | (REGISTER << (sizeof(REGISTER) - NUMBER))) /* Rotates the register right by the number of bits */

#define ROTATE_LEFT(REGISTER,NUMBER) (REGISTER = (REGISTER << NUMBER) | (REGISTER >> (sizeof(REGISTER) - NUMBER))) /* Rotates the register left by the number of bits */

#endif
