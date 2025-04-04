#ifndef GPIO_H_
#define GPIO_H_

#include "standard_types.h"

#define NUMBER_OF_PORTS           4 /* Total number of ports */
#define NUMBER_OF_PINS_PER_PORT   8 /* Number of pins per port */

#define PORTA_ID 0 /* Port A identifier */
#define PORTB_ID 1 /* Port B identifier */
#define PORTC_ID 2 /* Port C identifier */
#define PORTD_ID 3 /* Port D identifier */

#define PIN0_ID 0 /* Pin 0 identifier */
#define PIN1_ID 1 /* Pin 1 identifier */
#define PIN2_ID 2 /* Pin 2 identifier */
#define PIN3_ID 3 /* Pin 3 identifier */
#define PIN4_ID 4 /* Pin 4 identifier */
#define PIN5_ID 5 /* Pin 5 identifier */
#define PIN6_ID 6 /* Pin 6 identifier */
#define PIN7_ID 7 /* Pin 7 identifier */

typedef enum
{
	PIN_INPUT, /* Sets pin as input */
	PIN_OUTPUT /* Sets pin as output */
}GPIO_PinDirectionType;

typedef enum
{
	PORT_INPUT,        /* Sets port as input */
	PORT_OUTPUT = 0xFF /* Sets port as output */
}GPIO_PortDirectionType;

void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction); /* Configures the direction of a specific pin */
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value);                              /* Writes logic high or logic low on a specific pin */
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num);                                           /* Returns the status of a specific pin */

void GPIO_setupPortDirection(uint8 port_num, GPIO_PortDirectionType direction); /* Configures the direction of the entire port */
void GPIO_writePort(uint8 port_num, uint8 value);                               /* Writes a value on the entire port */
uint8 GPIO_readPort(uint8 port_num);                                            /* Returns the value of the entire port */

#endif
