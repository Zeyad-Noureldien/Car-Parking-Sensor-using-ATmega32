#ifndef ICU_H_
#define ICU_H_

#include "standard_types.h"

typedef enum          /* Prescaler value */
{
	NO_CLOCK,         /* No clock */
	F_CPU_CLOCK,      /* Clock = F_CPU */
	F_CPU_8,          /* Clock = F_CPU/8 */
	F_CPU_64,         /* Clock = F_CPU/64 */
	F_CPU_256,        /* Clock = F_CPU/256 */
	F_CPU_1024        /* Clock = F_CPU/1024 */
}ICU_ClockType;

typedef enum          /* Event capture edge */
{
	FALLING,
	RISING
}ICU_EdgeType;

typedef struct
{
	ICU_ClockType clock;
	ICU_EdgeType edge;
}ICU_ConfigType;

void ICU_init(const ICU_ConfigType * Config_Ptr);           /* Initialises the input capture unit */
void ICU_setCallBack(void(*a_ptr)(void));                   /* Sets the callback function address */
void ICU_setEdgeDetectionType(const ICU_EdgeType edgeType); /* Sets the required edge detection */
uint16 ICU_getInputCaptureValue(void);                      /* Returns the timer1 value when the input is captured */
void ICU_clearTimerValue(void);                             /* Clears the timer1 value to start counting from 0 */
void ICU_deInit(void);                                      /* De-initialises the input capture unit */

#endif
