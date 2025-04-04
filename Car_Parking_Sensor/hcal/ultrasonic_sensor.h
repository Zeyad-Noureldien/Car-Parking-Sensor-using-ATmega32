#ifndef HCAL_ULTRASONIC_SENSOR_H_
#define HCAL_ULTRASONIC_SENSOR_H_

#include "../mcal/standard_types.h"

#define ULTRASONIC_SENSOR_TRIGGER_PORT PORTD_ID /* Trigger port identifier */
#define ULTRASONIC_SENSOR_TRIGGER_PIN  PIN7_ID  /* Trigger pin identifier */

#define ULTRASONIC_SENSOR_ECHO_PORT    PORTD_ID /* Echo port identifier */
#define ULTRASONIC_SENSOR_ECHO_PIN     PIN6_ID  /* Echo pin identifier */

void UltraSonic_init(void);           /* Initialises the ultra-sonic sensor to the preferred settings */
void Ultrasonic_Trigger(void);        /* Sends a trigger signal through the trigger */
uint16 Ultrasonic_readDistance(void); /* Returns the distance value in centimetres */
void Ultrasonic_edgeProcessing(void); /* Call back function that processes the edges for the input capture unit */

#endif
