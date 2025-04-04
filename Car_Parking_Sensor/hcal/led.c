#include "led.h"
#include "../mcal/gpio.h"

void LEDS_init(void) /* Initialises the LEDs */
{
	GPIO_setupPinDirection(RED_LED_PORT, RED_LED_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(GREEN_LED_PORT, RED_LED_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(BLUE_LED_PORT, RED_LED_PIN, PIN_OUTPUT);

    LED_off(RED_LED);
    LED_off(GREEN_LED);
    LED_off(BLUE_LED);
}

void LED_on(LED_ID id) /* Turns on a specific LED */
{
	switch (id)
	{
	case RED_LED:
        if (RED_LED_LOGIC == POSITIVE_LOGIC) {
            GPIO_writePin(RED_LED_PORT, RED_LED_PIN, LOGIC_HIGH);
        } else {
            GPIO_writePin(RED_LED_PORT, RED_LED_PIN, LOGIC_LOW);
        }
        break;
	case GREEN_LED:
        if (GREEN_LED_LOGIC == POSITIVE_LOGIC) {
            GPIO_writePin(GREEN_LED_PORT, GREEN_LED_PIN, LOGIC_HIGH);
        } else {
            GPIO_writePin(GREEN_LED_PORT, GREEN_LED_PIN, LOGIC_LOW);
        }
        break;
    case BLUE_LED:
        if (BLUE_LED_LOGIC == POSITIVE_LOGIC) {
            GPIO_writePin(BLUE_LED_PORT, BLUE_LED_PIN, LOGIC_HIGH);
        } else {
            GPIO_writePin(BLUE_LED_PORT, BLUE_LED_PIN, LOGIC_LOW);
        }
        break;
	}
}

void LED_off(LED_ID id) /* Turns off a specific LED */
{
    switch (id)
    {
        case RED_LED:
            if (RED_LED_LOGIC == POSITIVE_LOGIC) {
                GPIO_writePin(RED_LED_PORT, RED_LED_PIN, LOGIC_LOW);
            } else {
                GPIO_writePin(RED_LED_PORT, RED_LED_PIN, LOGIC_HIGH);
            }
            break;
        case GREEN_LED:
            if (GREEN_LED_LOGIC == POSITIVE_LOGIC) {
                GPIO_writePin(GREEN_LED_PORT, GREEN_LED_PIN, LOGIC_LOW);
            } else {
                GPIO_writePin(GREEN_LED_PORT, GREEN_LED_PIN, LOGIC_HIGH);
            }
            break;
        case BLUE_LED:
            if (BLUE_LED_LOGIC == POSITIVE_LOGIC) {
                GPIO_writePin(BLUE_LED_PORT, BLUE_LED_PIN, LOGIC_LOW);
            } else {
                GPIO_writePin(BLUE_LED_PORT, BLUE_LED_PIN, LOGIC_HIGH);
            }
            break;
    }
}
