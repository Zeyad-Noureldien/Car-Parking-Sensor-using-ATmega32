#include "lcd.h"
#include "../mcal/gpio.h"
#include "../mcal/common_macros.h"
#include <stdlib.h>
#include <util/delay.h>

void LCD_init(void)
{
	GPIO_setupPinDirection(LCD_RS_PORT_ID,LCD_RS_PIN_ID,PIN_OUTPUT);         /* RS pin direction */
	GPIO_setupPinDirection(LCD_ENABLE_PORT_ID,LCD_ENABLE_PIN_ID,PIN_OUTPUT); /* Enable pin direction */

	_delay_ms(20);		/* LCD Power ON delay always > 15ms */

#if(LCD_DATA_BITS_MODE == 4) /* Configure 4 pins in the data port as output pins */

	GPIO_setupPinDirection(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,PIN_OUTPUT);

	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT1); /* Send for 4 bit initialization of LCD  */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT2);

	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE); /* use 2-lines LCD + 4-bits Data Mode + 5*7 dot display Mode */

#elif(LCD_DATA_BITS_MODE == 8)

	GPIO_setupPortDirection(LCD_DATA_PORT_ID,PORT_OUTPUT); /* Configure the data port as output port */

	LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE); /* use 2-lines LCD + 8-bits Data Mode + 5*7 dot display Mode */

#endif

	LCD_sendCommand(LCD_CURSOR_OFF);    /* cursor off */
	LCD_sendCommand(LCD_CLEAR_COMMAND); /* clear LCD at the beginning */
}

void LCD_sendCommand(uint8 command)
{
	GPIO_writePin(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOGIC_LOW);          /* Instruction Mode RS=0 */
	_delay_ms(1);                                                   /* delay for processing Tas = 50ns */
	GPIO_writePin(LCD_ENABLE_PORT_ID,LCD_ENABLE_PIN_ID,LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1);                                                   /* delay for processing Tpw - Tdws = 190ns */

#if(LCD_DATA_BITS_MODE == 4)
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,GET_BIT(command,4));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,GET_BIT(command,5));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,GET_BIT(command,6));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,GET_BIT(command,7));

	_delay_ms(1);                                                   /* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_ENABLE_PORT_ID,LCD_ENABLE_PIN_ID,LOGIC_LOW);  /* Disable LCD E=0 */
	_delay_ms(1);                                                   /* delay for processing Th = 13ns */
	GPIO_writePin(LCD_ENABLE_PORT_ID,LCD_ENABLE_PIN_ID,LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1);                                                   /* delay for processing Tpw - Tdws = 190ns */

	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,GET_BIT(command,0));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,GET_BIT(command,1));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,GET_BIT(command,2));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,GET_BIT(command,3));

	_delay_ms(1);                                                  /* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_ENABLE_PORT_ID,LCD_ENABLE_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1);                                                  /* delay for processing Th = 13ns */

#elif(LCD_DATA_BITS_MODE == 8)
	GPIO_writePort(LCD_DATA_PORT_ID,command);                      /* out the required command to the data bus D0 --> D7 */
	_delay_ms(1);                                                  /* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_ENABLE_PORT_ID,LCD_ENABLE_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1);                                                  /* delay for processing Th = 13ns */
#endif
}

void LCD_displayCharacter(uint8 data)
{
	GPIO_writePin(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOGIC_HIGH);         /* Data Mode RS=1 */
	_delay_ms(1);                                                   /* delay for processing Tas = 50ns */
	GPIO_writePin(LCD_ENABLE_PORT_ID,LCD_ENABLE_PIN_ID,LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1);                                                   /* delay for processing Tpw - Tdws = 190ns */

#if(LCD_DATA_BITS_MODE == 4)
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,GET_BIT(data,4));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,GET_BIT(data,5));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,GET_BIT(data,6));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,GET_BIT(data,7));

	_delay_ms(1);                                                   /* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_ENABLE_PORT_ID,LCD_ENABLE_PIN_ID,LOGIC_LOW);  /* Disable LCD E=0 */
	_delay_ms(1);                                                   /* delay for processing Th = 13ns */
	GPIO_writePin(LCD_ENABLE_PORT_ID,LCD_ENABLE_PIN_ID,LOGIC_HIGH); /* Enable LCD E=1 */
	_delay_ms(1);                                                   /* delay for processing Tpw - Tdws = 190ns */

	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,GET_BIT(data,0));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,GET_BIT(data,1));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,GET_BIT(data,2));
	GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,GET_BIT(data,3));

	_delay_ms(1);                                                  /* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_ENABLE_PORT_ID,LCD_ENABLE_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1);                                                  /* delay for processing Th = 13ns */

#elif(LCD_DATA_BITS_MODE == 8)
	GPIO_writePort(LCD_DATA_PORT_ID,data);                         /* out the required command to the data bus D0 --> D7 */
	_delay_ms(1);                                                  /* delay for processing Tdsw = 100ns */
	GPIO_writePin(LCD_ENABLE_PORT_ID,LCD_ENABLE_PIN_ID,LOGIC_LOW); /* Disable LCD E=0 */
	_delay_ms(1);                                                  /* delay for processing Th = 13ns */
#endif
}

void LCD_displayString(const char *Str)
{
	uint8 i = 0;
	while(Str[i] != '\0')
	{
		LCD_displayCharacter(Str[i]);
		i++;
	}
}

void LCD_moveCursor(uint8 row,uint8 col)
{
	uint8 lcd_memory_address;

	switch(row) /* Calculate the required address in the LCD DDRAM */
	{
		case 0:
			lcd_memory_address=col;
				break;
		case 1:
			lcd_memory_address=col+0x40;
				break;
		case 2:
			lcd_memory_address=col+0x10;
				break;
		case 3:
			lcd_memory_address=col+0x50;
				break;
	}

	LCD_sendCommand(lcd_memory_address | LCD_SET_CURSOR_LOCATION); /* Move the LCD cursor to this specific address */
}

void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str)
{
	LCD_moveCursor(row,col); /* go to to the required LCD position */
	LCD_displayString(Str);  /* display the string */
}

void LCD_integerToString(int data)
{
   char buff[16];           /* String to hold the ascii result */
   itoa(data,buff,10);      /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
   LCD_displayString(buff); /* Display the string */
}

void LCD_clearScreen(void)
{
	LCD_sendCommand(LCD_CLEAR_COMMAND); /* Send clear display command */
}
