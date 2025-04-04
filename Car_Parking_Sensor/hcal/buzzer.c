#include "buzzer.h"
#include "../mcal/gpio.h"

void BUZZER_init(void)
{
	GPIO_setupPinDirection(BUZZER_PORT, BUZZER_PIN, PIN_OUTPUT); /* Configures buzzer pin as output */

	BUZZER_off(); /* Turn off the buzzer at the start */
}

void BUZZER_on(void)
{
	GPIO_writePin(BUZZER_PORT, BUZZER_PIN, LOGIC_HIGH); /* Writes logic high on the buzzer pin */
}

void BUZZER_off(void)
{
	GPIO_writePin(BUZZER_PORT, BUZZER_PIN, LOGIC_LOW); /* Writes logic low on the buzzer pin */
}
