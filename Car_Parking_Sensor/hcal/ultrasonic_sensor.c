#include "ultrasonic_sensor.h"
#include "../mcal/icu.h"
#include "../mcal/gpio.h"
#include <util/delay.h>

uint16 g_distance = 0;
uint8  g_edgeCount = 0;

void UltraSonic_init(void)
{
	ICU_ConfigType ICU_configurations = {F_CPU_8, RISING};  /* Preferred configurations for the ICU */

	ICU_setCallBack(Ultrasonic_edgeProcessing);             /* Sets the call back function */
	ICU_init(&ICU_configurations);                          /* Initialises the ICU to the preferred configurations */

	GPIO_setupPinDirection(PORTD_ID, PIN6_ID, PIN_INPUT);   /* Configures the echo pin as input */
	GPIO_setupPinDirection(PORTD_ID, PIN7_ID, PIN_OUTPUT);  /* Configures the trigger pin as output */

	GPIO_writePin(PORTD_ID, PIN7_ID, LOGIC_LOW);            /* Trigger pin initially low */
}

void Ultrasonic_Trigger(void)
{
	GPIO_writePin(PORTD_ID, PIN7_ID, LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(PORTD_ID, PIN7_ID, LOGIC_LOW);
}

uint16 Ultrasonic_readDistance(void)
{
	Ultrasonic_Trigger();

	while(g_edgeCount != 0);

	g_distance = (float)((g_distance * 0.0085) + 0.5);

	return g_distance;
}

void Ultrasonic_edgeProcessing(void)
{
	g_edgeCount++;

	if (g_edgeCount == 1)
	{
		ICU_clearTimerValue();

		ICU_setEdgeDetectionType(FALLING);
	}
	else if (g_edgeCount == 2)
	{
		g_distance = ICU_getInputCaptureValue();

		ICU_setEdgeDetectionType(RISING);
		g_edgeCount = 0;
	}
}
