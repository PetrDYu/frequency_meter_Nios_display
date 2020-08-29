/*
 * STM32F4-HD44780
 *
 * An interrupt driven library for HD44780-based LCD displays
 *
 * http://eartoearoak.com/software/stm32f4-hd44780
 *
 * Copyright 2013 Al Brown
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */



//#include "main.h"

#define HD44780_TIMER 		TIM7
#define HD44780_PRIORITY 	14

#define NONE 0

#define HD44780_4BIT 		    0x00
#define HDD44780_ENTRY_LEFT	0x02
#define HD44780_DISPLAY_ON	0x04
#define HD44780_CURSOR_ON	  0x02
#define HD44780_BLINK_ON	  0x01

#define HD44780_CLEAR		    0x0001
#define HD44780_HOME		    0x0002
#define HD44780_ENTRY		    0x0004
#define HD44780_DISPLAY		  0x0008
#define HD44780_CURSOR		  0x0010
#define HD44780_FUNCTION	  0x0020
#define HD44780_CGRAM		    0x0040
#define HD44780_DGRAM		    0x0080

#define TRUE	1
#define FALSE	0
#define MODE_8_OR_4 8

//временная мера
typedef int bool;
#include <string.h>



/*typedef enum
{
	HD44780_WAIT = 1, HD44780_WAIT_NOT_BUSY, HD44780_WRITE
} hd44780_command_t;

typedef struct
{
	hd44780_command_t command;
	bool              reg;
	alt_u16               data;
	int8_t            nibble;
} hd44780_task_t;

typedef struct
{
	GPIO_TypeDef* gpio;
	u32 rs;
	u32 rw;
	u32 e;
	u32 db4;
	u32 db5;
	u32 db6;
	u32 db7;
	u8 lines;
	u8 font;
} hd44780_conf_t;

static hd44780_conf_t          Lcd_Conf;
static volatile hd44780_task_t Queue[HD44780_QUEUE_SIZE];
static volatile alt_u16            Queue_Head = 0;
static volatile alt_u16            Queue_Tail = 0;*/

//#pragma diag_warning 188


static void set_output(const bool output)
{

	IOWR_ALTERA_AVALON_PIO_DIRECTION(LCD_DATA_BASE, 0);
	if (output)
		IOWR_ALTERA_AVALON_PIO_DIRECTION(LCD_DATA_BASE, 0xFF);
}

static void enable(const bool pulse)
{
	if (pulse)
	{
		IOWR_ALTERA_AVALON_PIO_DATA(LCD_E_BASE, 0x01);
		vTaskDelay(1);
	}
	IOWR_ALTERA_AVALON_PIO_DATA(LCD_E_BASE, 0);
	vTaskDelay(1);
}

static void write(const alt_u8 data, const bool reg)
{
	set_output(TRUE);
	//alt_putstr("set_output TRUE\n");
	
	IOWR_ALTERA_AVALON_PIO_DATA(LCD_RW_BASE, 0);
	//alt_putstr("RW 0\n");
	IOWR_ALTERA_AVALON_PIO_DATA(LCD_RS_BASE, reg);
	//alt_putstr("RS installed\n");
	
	if (MODE_8_OR_4 == 8) IOWR_ALTERA_AVALON_PIO_DATA(LCD_DATA_BASE, data);
	else IOWR_ALTERA_AVALON_PIO_DATA(LCD_DATA_BASE, data << 4);
	//alt_putstr("data installed\n");
	
	enable(TRUE);
	//alt_putstr("enable\n");
}

static bool read_busy(void)
{
	alt_u8 data;

	set_output(FALSE);
	IOWR_ALTERA_AVALON_PIO_DATA(LCD_RS_BASE, 0);
	IOWR_ALTERA_AVALON_PIO_DATA(LCD_RW_BASE, 0x01);
	enable(FALSE);
	data = IORD_ALTERA_AVALON_PIO_DATA(LCD_DATA_BASE);
	enable(FALSE);
	enable(TRUE);

	if (data >> 7 == 1)
		return (TRUE);

	return (FALSE);

}

/**
 * Clear the LCD
 */
void hd44780_clear(xQueueHandle Queue_lcd_data, xQueueHandle Queue_lcd_rs, xSemaphoreHandle Mutex_write_lcd)
{
	int data = 0x01;
	int rs = 0;
	if( xSemaphoreTake( Mutex_write_lcd, portMAX_DELAY ) == pdTRUE )
	{
		xQueueSendToBack(Queue_lcd_data, &data, portMAX_DELAY);
		xQueueSendToBack(Queue_lcd_rs, &rs, portMAX_DELAY);
		xSemaphoreGive( Mutex_write_lcd );
	}
}

/**
 * Move cursor home
 */
void hd44780_home(xQueueHandle Queue_lcd_data, xQueueHandle Queue_lcd_rs, xSemaphoreHandle Mutex_write_lcd)
{
	int data = 0x02;
	int rs = 0;
	if( xSemaphoreTake( Mutex_write_lcd, portMAX_DELAY ) == pdTRUE )
	{
		xQueueSendToBack(Queue_lcd_data, &data, portMAX_DELAY);
		xQueueSendToBack(Queue_lcd_rs, &rs, portMAX_DELAY);
		xSemaphoreGive( Mutex_write_lcd );
	}
}

/**
 * Display settings
 *
 * @param enable	LCD on/off
 * @param cursor	Cursor on/off
 * @param blink		Blinking cursor on/off
 *
 */
void hd44780_display(xQueueHandle Queue_lcd_data, xQueueHandle Queue_lcd_rs, xSemaphoreHandle Mutex_write_lcd, const bool enable, const bool cursor, const bool blink)
{
	alt_u16 command = HD44780_DISPLAY;

	if (enable)
		command |= HD44780_DISPLAY_ON;
	/*else
  {
		Queue_Head = Queue_Tail = 0;
	}*/
	if (cursor)
		command |= HD44780_CURSOR_ON;
	if (blink)
		command |= HD44780_BLINK_ON;

	int rs = 0;
	if( xSemaphoreTake( Mutex_write_lcd, portMAX_DELAY ) == pdTRUE )
	{
		xQueueSendToBack(Queue_lcd_data, &command, portMAX_DELAY);
		xQueueSendToBack(Queue_lcd_rs, &rs, portMAX_DELAY);
		xSemaphoreGive( Mutex_write_lcd );
	}
}

/**
 * Position the cursor
 *
 * @param row	Row
 * @param col	Column
 */
void hd44780_position(xQueueHandle Queue_lcd_data, xQueueHandle Queue_lcd_rs, xSemaphoreHandle Mutex_write_lcd, const alt_u8 row, const alt_u8 col)
{
	alt_u16 command = HD44780_DGRAM;
	const alt_u8 offsets[] = { 0x00, 0x40, 0x14, 0x54 };

	command |= col + offsets[row];
	int rs = 0;
	if( xSemaphoreTake( Mutex_write_lcd, portMAX_DELAY ) == pdTRUE )
	{
		xQueueSendToBack(Queue_lcd_data, &command, portMAX_DELAY);
		xQueueSendToBack(Queue_lcd_rs, &rs, portMAX_DELAY);
		xSemaphoreGive( Mutex_write_lcd );
	}
}

/**
 * Set a UDG
 *
 * @param pos	UDG number
 * @param udg	UDG definition
 */
 //необходимо проработать вопрос о записи элементо массива в очередь подряд без перерыва
void hd44780_cgram(xQueueHandle Queue_lcd_data, xQueueHandle Queue_lcd_rs, xSemaphoreHandle Mutex_write_lcd, const alt_u8 pos, const char udg[8])
{
	alt_u8 i;
	alt_u16 command = HD44780_CGRAM;

	if (pos < 8) alt_putstr("pos cgram failed");

	command |= pos * 8;

	int rs = 0;
	if( xSemaphoreTake( Mutex_write_lcd, portMAX_DELAY ) == pdTRUE )
	{
		xQueueSendToBack(Queue_lcd_data, &command, portMAX_DELAY);
		xQueueSendToBack(Queue_lcd_rs, &rs, portMAX_DELAY);
		
		rs = 1;
		for (i = 0; i < 8; i++)
		{
				xQueueSendToBack(Queue_lcd_data, &udg[i], portMAX_DELAY);
				xQueueSendToBack(Queue_lcd_rs, &rs, portMAX_DELAY);
		}
		xSemaphoreGive( Mutex_write_lcd );
	}
}

/**
 * Send a single character to the LCD
 *
 * @param chr	Character to send
 */
void hd44780_put(xQueueHandle Queue_lcd_data, xQueueHandle Queue_lcd_rs, xSemaphoreHandle Mutex_write_lcd, const char chr)
{
	int rs = 1;
	if( xSemaphoreTake( Mutex_write_lcd, portMAX_DELAY ) == pdTRUE )
	{
		xQueueSendToBack(Queue_lcd_data, &chr, portMAX_DELAY);
		xQueueSendToBack(Queue_lcd_rs, &rs, portMAX_DELAY);
		xSemaphoreGive( Mutex_write_lcd );
	}
}

/**
 * Send a string to the LCD
 *
 * @param string	String to send
 */
void hd44780_print(xQueueHandle Queue_lcd_data, xQueueHandle Queue_lcd_rs, xSemaphoreHandle Mutex_write_lcd, const char* string)
{
	alt_u8 i = 0;
	int rs = 1;
	
	for(; i < strlen(string); i++)
	{
		hd44780_put(Queue_lcd_data, Queue_lcd_rs, Mutex_write_lcd, string[i]);
	}
}

/**
 * Send a formatted string to the LCD
 *
 * @param fmt	String format
 * @param ...	Variable arguments (see printf())
 */
void hd44780_printf(xQueueHandle Queue_lcd_data, xQueueHandle Queue_lcd_rs, xSemaphoreHandle Mutex_write_lcd, const char *fmt, ...)
{

	alt_u16 i;
	alt_u16 size;
	alt_u8 character;
	char buffer[32];
	va_list args;
	int rs = 1;

	va_start(args, fmt);
	size = vsprintf(buffer, fmt, args);
	for (i = 0; i < size; i++)
	{
		character = buffer[i];
		hd44780_put(Queue_lcd_data, Queue_lcd_rs, Mutex_write_lcd, character);
	}
}

/**
 * Initialise the LCD
 */
void hd44780_init(xQueueHandle Queue_lcd_data, xQueueHandle Queue_lcd_rs, xSemaphoreHandle Mutex_write_lcd)
{
	int data, rs = 0;
	alt_putstr("initialisation start\n");
	//function set
	if( xSemaphoreTake( Mutex_write_lcd, portMAX_DELAY ) == pdTRUE )
	{
		data = 0x3C;
		xQueueSendToBack(Queue_lcd_data, &data, portMAX_DELAY);
		xQueueSendToBack(Queue_lcd_rs, &rs, portMAX_DELAY);
		alt_putstr("initialisation function\n");
		//display and cursor control
		data = 0x0C;
		xQueueSendToBack(Queue_lcd_data, &data, portMAX_DELAY);
		xQueueSendToBack(Queue_lcd_rs, &rs, portMAX_DELAY);
		alt_putstr("initialisation display\n");
		//display clear
		data = 0x01;
		xQueueSendToBack(Queue_lcd_data, &data, portMAX_DELAY);
		xQueueSendToBack(Queue_lcd_rs, &rs, portMAX_DELAY);
		alt_putstr("clear display\n");
		//entry mode set
		data = 0x07;
		xQueueSendToBack(Queue_lcd_data, &data, portMAX_DELAY);
		xQueueSendToBack(Queue_lcd_rs, &rs, portMAX_DELAY);
		xSemaphoreGive( Mutex_write_lcd );
	}
	alt_putstr("initialisation finished\n");
	/* hd44780_clear();
	hd44780_home(); */
}

/*void TIM7_IRQHandler(void)
{
	exec();
	TIM_ClearITPendingBit(HD44780_TIMER, TIM_IT_Update);
}*/
