#ifndef LCD_H_
#define LCD_H_

#include "../mcal/standard_types.h"

#define LCD_DATA_BITS_MODE 4 /* Configures the LCD to 4 or 8 bit mode */

#if((LCD_DATA_BITS_MODE != 4) && (LCD_DATA_BITS_MODE != 8)) /* Ensure only valid values (4 or 8) are used */

#error "Number of Data bits should be equal to 4 or 8"

#endif

#define LCD_RS_PORT_ID                 PORTA_ID /* RS port ID */
#define LCD_RS_PIN_ID                  PIN1_ID  /* RS pin ID */

#define LCD_ENABLE_PORT_ID             PORTA_ID /* Enable port ID */
#define LCD_ENABLE_PIN_ID              PIN2_ID  /* Enable pin ID */

#define LCD_DATA_PORT_ID               PORTA_ID /* Data port ID */

#if (LCD_DATA_BITS_MODE == 4) /* 4 bit mode pins */

#define LCD_DB4_PIN_ID                 PIN3_ID
#define LCD_DB5_PIN_ID                 PIN4_ID
#define LCD_DB6_PIN_ID                 PIN5_ID
#define LCD_DB7_PIN_ID                 PIN6_ID

#endif

#define LCD_CLEAR_COMMAND                    0x01 /* Clear screen command */

#define LCD_GO_TO_HOME                       0x02 /* Return home command */

#define LCD_TWO_LINES_EIGHT_BITS_MODE        0x38 /* 8 bit mode, 2 lines display */
#define LCD_TWO_LINES_FOUR_BITS_MODE         0x28 /* 4 bit mode, 2 lines display */

#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33 /* Initialisation step 1 for 4-bit mode command */
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32 /* Initialisation step 2 for 4-bit mode command */

#define LCD_CURSOR_OFF                       0x0C /* Turn off the cursor command */
#define LCD_CURSOR_ON                        0x0E /* Turn on the cursor command */
#define LCD_SET_CURSOR_LOCATION              0x80

void LCD_init(void);                                                  /* Initialises the LCD based on the selected data mode */
void LCD_sendCommand(uint8 command);                                  /* Sends a command to the LCD */
void LCD_displayCharacter(uint8 data);                                /* Displays a single character on the LCD */
void LCD_displayString(const char *Str);                              /* Displays a string on the LCD */
void LCD_moveCursor(uint8 row,uint8 col);                             /* Moves the cursor to the desired row and column on the LCD */
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str); /* Displays a string at the desired row and columns on the LCD */
void LCD_integerToString(int data);                                   /* Converts an integer to string and displays it on the LCD */
void LCD_clearScreen(void);                                           /* Clears the LCD screen */

#endif
