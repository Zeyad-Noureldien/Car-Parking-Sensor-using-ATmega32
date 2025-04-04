#ifndef LED_H_
#define LED_H_

typedef enum
{
	RED_LED,   /* Represents the red LED */
	GREEN_LED, /* Represents the green LED */
	BLUE_LED   /* Represents the blue LED */
}LED_ID;

typedef enum {
    POSITIVE_LOGIC, /* LED turns ON when high and OFF when low */
    NEGATIVE_LOGIC  /* LED turns ON when low and OFF when high */
} LED_Logic;

#define RED_LED_PORT     PORTC_ID       /* Red LED port */
#define RED_LED_PIN      PIN0_ID        /* Red LED pin */
#define RED_LED_LOGIC    POSITIVE_LOGIC /* Red LED logic */

#define GREEN_LED_PORT   PORTC_ID       /* Green LED port */
#define GREEN_LED_PIN    PIN1_ID        /* Green LED pin */
#define GREEN_LED_LOGIC  POSITIVE_LOGIC /* Green LED logic */

#define BLUE_LED_PORT    PORTC_ID       /* Blue LED port */
#define BLUE_LED_PIN     PIN2_ID        /* Blue LED pin */
#define BLUE_LED_LOGIC   POSITIVE_LOGIC /* Blue LED logic */

void LEDS_init(void);       /* Initialises all LEDs as output and turns them off at the start */
void LED_on(LED_ID id);     /* Turns on a specific LED */
void LED_off(LED_ID id);    /* Turns off a specific LED */

#endif
