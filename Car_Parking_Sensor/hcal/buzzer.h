#ifndef BUZZER_H_
#define BUZZER_H_

#define BUZZER_PORT PORTC_ID /* Buzzer port identifier */
#define BUZZER_PIN PIN5_ID   /* Buzzer pin identifier */

void BUZZER_init(void); /* Initialises the buzzer to the desired settings */
void BUZZER_on(void);   /* Turns on the buzzer */
void BUZZER_off(void);  /* Turns off the buzzer */

#endif
