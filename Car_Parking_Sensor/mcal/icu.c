#include "icu.h"
#include "common_macros.h"
#include "gpio.h"
#include <avr/interrupt.h>

static volatile void (*g_callBackPtr)(void) = NULL_PTR;

ISR(TIMER1_CAPT_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		(*g_callBackPtr)(); /* Calls the call back function after the edge is detected */
	}
}

void ICU_init(const ICU_ConfigType * Config_Ptr)
{
	sei();

	CLEAR_BIT(DDRD, PIN6_ID); /* Configures ICP1 as input pin */

	SET_BIT(TCCR1A, FOC1A); /* Configures timer1 to operate in normal mode */
	SET_BIT(TCCR1A, FOC1B);

	TCCR1B &= 0xF8;              /* Inserts the required clock value in the first three bits (CS10, CS11 and CS12) of the TCCR1B register */
	TCCR1B |= (Config_Ptr->clock);

	TCCR1B &= 0xBF;                   /* Inserts the required edge type in ICES1 in the TCCR1B register */
	TCCR1B |= ((Config_Ptr->edge)<<6);

	TCNT1 = 0; /* Initial Value for timer1 */

	ICR1 = 0; /* Initial Value for the input capture register */

	SET_BIT(TIMSK, TICIE1); /* Enables the input capture interrupt to generate an interrupt when an edge is detected on the ICP1 pin */
}

void ICU_setCallBack(void(*a_ptr)(void))
{
	g_callBackPtr = a_ptr; /* Saves the address of the call back function in a global variable */
}

void ICU_setEdgeDetectionType(const ICU_EdgeType a_edgeType)
{
	TCCR1B &= 0xBF;            /* Inserts the required edge type in the ICES1 bit in the TCCR1B register */
	TCCR1B |= (a_edgeType<<6);
}

uint16 ICU_getInputCaptureValue(void)
{
	return ICR1;
}

void ICU_clearTimerValue(void)
{
	TCNT1 = 0;
}

void ICU_deInit(void)
{
	TCCR1A = 0; /* Clear all timer1 and input capture unit register */
	TCCR1B = 0;
	TCNT1 = 0;
	ICR1 = 0;

	TIMSK &= ~(1<<TICIE1); /* Disable the input capute interrupt */

	g_callBackPtr = NULL_PTR; /* Reset the global pointer value */
}
