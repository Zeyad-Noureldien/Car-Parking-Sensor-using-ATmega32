#include "gpio.h"
#include "common_macros.h"
#include <avr/io.h>

void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction)
{
	if ((port_num >= NUMBER_OF_PORTS) || (pin_num >= NUMBER_OF_PINS_PER_PORT))
	{
		/* Invalid port or pin number, do nothing */
	}
	else
	{
		switch (port_num)
		{
		case PORTA_ID:
			if (direction == PIN_INPUT)
			{
				CLEAR_BIT(DDRA, pin_num);
			}
			else
			{
				SET_BIT(DDRA, pin_num);
			}
			break;
		case PORTB_ID:
			if (direction == PIN_INPUT)
			{
				CLEAR_BIT(DDRB, pin_num);
			}
			else
			{
				SET_BIT(DDRB, pin_num);
			}
			break;
		case PORTC_ID:
			if (direction == PIN_INPUT)
			{
				CLEAR_BIT(DDRC, pin_num);
			}
			else
			{
				SET_BIT(DDRC, pin_num);
			}
			break;
		case PORTD_ID:
			if (direction == PIN_INPUT)
			{
				CLEAR_BIT(DDRD, pin_num);
			}
			else
			{
				SET_BIT(DDRD, pin_num);
			}
			break;
		}
	}
}

void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value)
{
	if ((port_num >= NUMBER_OF_PORTS) || (pin_num >= NUMBER_OF_PINS_PER_PORT))
	{
		/* Invalid port or pin number, do nothing */
	}
	else if ((value != LOGIC_HIGH) && (value != LOGIC_LOW))
	{
		/* Invalid logic level, do nothing */
	}
	else
	{
		switch (port_num)
		{
		case PORTA_ID:
			if (value == LOGIC_HIGH)
			{
				SET_BIT(PORTA, pin_num);
			}
			else
			{
				CLEAR_BIT(PORTA, pin_num);
			}
			break;
		case PORTB_ID:
			if (value == LOGIC_HIGH)
			{
				SET_BIT(PORTB, pin_num);
			}
			else
			{
				CLEAR_BIT(PORTB, pin_num);
			}
			break;
		case PORTC_ID:
			if (value == LOGIC_HIGH)
			{
				SET_BIT(PORTC, pin_num);
			}
			else
			{
				CLEAR_BIT(PORTC, pin_num);
			}
			break;
		case PORTD_ID:
			if (value == LOGIC_HIGH)
			{
				SET_BIT(PORTD, pin_num);
			}
			else
			{
				CLEAR_BIT(PORTD, pin_num);
			}
			break;
		}
	}
}

uint8 GPIO_readPin(uint8 port_num, uint8 pin_num)
{
	if ((port_num >= NUMBER_OF_PORTS) || (pin_num >= NUMBER_OF_PINS_PER_PORT))
	{
		return LOGIC_LOW; /* Invalid port or pin number, return default value */
	}
	else
	{
		switch (port_num)
		{
		case PORTA_ID:
			if (BIT_IS_SET(PINA, pin_num))
			{
				return LOGIC_HIGH;
			}
			else
			{
				return LOGIC_LOW;
			}
			break;
		case PORTB_ID:
			if (BIT_IS_SET(PINB, pin_num))
			{
				return LOGIC_HIGH;
			}
			else
			{
				return LOGIC_LOW;
			}
			break;
		case PORTC_ID:
			if (BIT_IS_SET(PINC, pin_num))
			{
				return LOGIC_HIGH;
			}
			else
			{
				return LOGIC_LOW;
			}
			break;
		case PORTD_ID:
			if (BIT_IS_SET(PIND, pin_num))
			{
				return LOGIC_HIGH;
			}
			else
			{
				return LOGIC_LOW;
			}
			break;
		default:
			return LOGIC_LOW;
		}
	}
}

void GPIO_setupPortDirection(uint8 port_num, GPIO_PortDirectionType direction)
{
	if (port_num >= NUMBER_OF_PORTS)
	{
		/* Invalid port number, do nothing */
	}
	else
	{
		switch (port_num)
		{
		case PORTA_ID:
			DDRA = direction;
			break;
		case PORTB_ID:
			DDRB = direction;
			break;
		case PORTC_ID:
			DDRC = direction;
			break;
		case PORTD_ID:
			DDRD = direction;
			break;
		}
	}
}

void GPIO_writePort(uint8 port_num, uint8 value)
{
	if (port_num >= NUMBER_OF_PORTS)
	{
		/* Invalid port number, do nothing */
	}
	else
	{
		switch (port_num)
		{
		case PORTA_ID:
			PORTA = value;
			break;
		case PORTB_ID:
			PORTB = value;
			break;
		case PORTC_ID:
			PORTC = value;
			break;
		case PORTD_ID:
			PORTD = value;
			break;
		}
	}
}

uint8 GPIO_readPort(uint8 port_num)
{
	if (port_num >= NUMBER_OF_PORTS)
	{
		return LOGIC_LOW; /* Invalid port number, return default value */
	}
	else
	{
		switch (port_num)
		{
		case PORTA_ID:
			return PORTA;
			break;
		case PORTB_ID:
			return PORTB;
			break;
		case PORTC_ID:
			return PORTC;
			break;
		case PORTD_ID:
			return PORTD;
			break;
		default:
			return LOGIC_LOW;
			break;
		}
	}
}
