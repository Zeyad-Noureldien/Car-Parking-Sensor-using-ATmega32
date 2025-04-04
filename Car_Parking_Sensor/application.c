#include "hcal/lcd.h"
#include "hcal/buzzer.h"
#include "hcal/led.h"
#include "hcal/ultrasonic_sensor.h"
#include <util/delay.h>

int main()
{
	LCD_init();
	BUZZER_init();
	LEDS_init();
	UltraSonic_init();

	uint16 distance = 0;

	LCD_displayString("Distance =    cm");

	for(;;)
	{
		distance = Ultrasonic_readDistance(); /* Measure the distance */

		LCD_moveCursor(0, 11); /* Distance value display position */

		if (distance >= 100) /* Display the distance value */
		{
			LCD_integerToString(distance);
		}
		else if (distance >= 10 && distance <= 100)
		{
			LCD_integerToString(distance);
			LCD_displayCharacter(' ');
		}
		else if (distance < 10)
		{
			LCD_integerToString(distance);
			LCD_displayString("  ");
		}

		if (distance > 20) /* LEDs and buzzer control depending on distance value */
		{
			LED_off(RED_LED);
			LED_off(GREEN_LED);
			LED_off(BLUE_LED);

			BUZZER_off();
		}
		else if (distance >= 16 && distance <= 20)
		{
			LED_on(RED_LED);
			LED_off(GREEN_LED);
			LED_off(BLUE_LED);

			BUZZER_off();
		}
		else if (distance <= 15 && distance >= 11)
		{
			LED_on(RED_LED);
			LED_on(GREEN_LED);
			LED_off(BLUE_LED);

			BUZZER_off();
		}
		else if (distance <= 10 && distance >= 6)
		{
			LED_on(RED_LED);
			LED_on(GREEN_LED);
			LED_on(BLUE_LED);

			BUZZER_off();
		}
		else if (distance <= 5 && distance != 0) /* Flash LEDs and buzzer when distance is less than or equal 5 cm */
		{
			while (distance <= 5)
			{
				LCD_moveCursor(0, 11);
				LCD_integerToString(distance);
				LCD_displayStringRowColumn(1, 6, "STOP");

				BUZZER_on();
				LED_on(RED_LED);
				LED_on(GREEN_LED);
				LED_on(BLUE_LED);

				_delay_ms(500);

				BUZZER_off();
				LED_off(RED_LED);
				LED_off(GREEN_LED);
				LED_off(BLUE_LED);

				_delay_ms(500);

				distance = Ultrasonic_readDistance();
			}

			LCD_displayStringRowColumn(1, 6, "    "); /* Clear the "STOP" message */
		}
	}
}
