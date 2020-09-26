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

typedef int bool;

#include <string.h>

#pragma diag_warning 188

char rus_code_mas[] = {0x41,0xA0,0x42,0xA1,0xE0,0x45,0xA2,0xA3,0xA4,0xA5,0xA6,0x4B,0xA7,0x4D,0x48,0x4F,0xA8,0x50,0x43,0x54,0xA9,0xAA,0x58,0xE1,0xAB,0xAC,0xE2,0xAD,0xAE,0x62,0xAF,0xB0,0xB1,0x61,0xB2,0xB3,0xB4,0xE3,0x65,0xB5,0xB6,0xB7,0xB8,0xB9,0xBA,0xBB,0xBC,0xBD,0x6F,0xBE,0x70,0x63,0xBF,0x79,0xE4,0x78,0xE5,0xC0,0xC1,0xE6,0xC2,0xC3,0xC4,0xC5,0xC6,0xC7};
char rus_letter_mas[] = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя";
//char rus_letter_mas[] = {'А', 'Б', 'В', 'Г', 'Д', 'Е', 'Ё', 'Ж', 'З', 'И', 'Й', 'К', 'Л', 'М', 'Н', 'О', 'П', 'Р', 'С', 'Т', 'У', 'Ф', 'Х', 'Ц', 'Ч', 'Ш', 'Щ', 'Ъ', 'Ы', 'Ь', 'Э', 'Ю', 'Я', 'а', 'б', 'в', 'г', 'д', 'е','ё', 'ж', 'з', 'и', 'й', 'к', 'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'ъ', 'ы', 'ь', 'э', 'ю', 'я'};
//char rus_letter_mas[] = {"А", "Б", "В", "Г", "Д", "Е", "Ё", "Ж", "З", "И", "Й", "К", "Л", "М", "Н", "О", "П", "Р", "С", "Т", "У", "Ф", "Х", "Ц", "Ч", "Ш", "Щ", "Ъ", "Ы", "Ь", "Э", "Ю", "Я", "а", "б", "в", "г", "д", "е","ё", "ж", "з", "и", "й", "к", "л", "м", "н", "о", "п", "р", "с", "т", "у", "ф", "х", "ц", "ч", "ш", "щ", "ъ", "ы", "ь", "э", "ю", "я"};

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
		for(int i = 0; i < 5000; i++);
	}
	IOWR_ALTERA_AVALON_PIO_DATA(LCD_E_BASE, 0);
	for(int i = 0; i < 5000; i++);
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

static void hd44780_write(const alt_u8 data, const bool reg)
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
	//printf("%x\n", data);
	
	enable(TRUE);
	//alt_putstr("enable\n");
	while(!read_busy());
}

/**
 * Clear the LCD
 */
void hd44780_clear()
{
	int data = 0x01;
	int rs = 0;
	/*if( xSemaphoreTake( Mutex_write_lcd, portMAX_DELAY ) == pdTRUE )
	{
		xQueueSendToBack(Queue_lcd_data, &data, portMAX_DELAY);
		xQueueSendToBack(Queue_lcd_rs, &rs, portMAX_DELAY);
		xSemaphoreGive( Mutex_write_lcd );
	}*/
	hd44780_write(data, rs);
}

/**
 * Move cursor home
 */
void hd44780_home()
{
	int data = 0x02;
	int rs = 0;
	/*if( xSemaphoreTake( Mutex_write_lcd, portMAX_DELAY ) == pdTRUE )
	{
		xQueueSendToBack(Queue_lcd_data, &data, portMAX_DELAY);
		xQueueSendToBack(Queue_lcd_rs, &rs, portMAX_DELAY);
		xSemaphoreGive( Mutex_write_lcd );
	}*/
	hd44780_write(data, rs);
}

/**
 * Display settings
 *
 * @param enable	LCD on/off
 * @param cursor	Cursor on/off
 * @param blink		Blinking cursor on/off
 *
 */
void hd44780_display(const bool enable, const bool cursor, const bool blink)
{
	alt_u16 command = HD44780_DISPLAY;

	if (enable)
		command |= HD44780_DISPLAY_ON;
	if (cursor)
		command |= HD44780_CURSOR_ON;
	if (blink)
		command |= HD44780_BLINK_ON;

	int rs = 0;
	/*if( xSemaphoreTake( Mutex_write_lcd, portMAX_DELAY ) == pdTRUE )
	{
		xQueueSendToBack(Queue_lcd_data, &command, portMAX_DELAY);
		xQueueSendToBack(Queue_lcd_rs, &rs, portMAX_DELAY);
		xSemaphoreGive( Mutex_write_lcd );
	}*/
	hd44780_write(command, rs);
}

/**
 * Position the cursor
 *
 * @param row	Row
 * @param col	Column
 */
void hd44780_position(const alt_u8 row, const alt_u8 col)
{
	alt_u16 command = HD44780_DGRAM;
	const alt_u8 offsets[] = { 0x00, 0x40, 0x14, 0x54 };

	command |= col + offsets[row];
	int rs = 0;
	/*if( xSemaphoreTake( Mutex_write_lcd, portMAX_DELAY ) == pdTRUE )
	{
		xQueueSendToBack(Queue_lcd_data, &command, portMAX_DELAY);
		xQueueSendToBack(Queue_lcd_rs, &rs, portMAX_DELAY);
		xSemaphoreGive( Mutex_write_lcd );
	}*/
	hd44780_write(command, rs);
}

/**
 * Set a UDG
 *
 * @param pos	UDG number
 * @param udg	UDG definition
 */
void hd44780_cgram(const alt_u8 pos, const char udg[8])
{
	alt_u8 i;
	alt_u16 command = HD44780_CGRAM;

	if (pos < 8) alt_putstr("pos cgram failed");

	command |= pos * 8;

	int rs = 0;
	/*if( xSemaphoreTake( Mutex_write_lcd, portMAX_DELAY ) == pdTRUE )
	{
		xQueueSendToBack(Queue_lcd_data, &command, portMAX_DELAY);
		xQueueSendToBack(Queue_lcd_rs, &rs, portMAX_DELAY);*/
		hd44780_write(command, rs);
		rs = 1;
		for (i = 0; i < 8; i++)
		{
				/*xQueueSendToBack(Queue_lcd_data, &udg[i], portMAX_DELAY);
				xQueueSendToBack(Queue_lcd_rs, &rs, portMAX_DELAY);*/
				hd44780_write(udg[i], rs);
		}
		/*xSemaphoreGive( Mutex_write_lcd );
	}*/
}

/**
 * Send a single character to the LCD
 *
 * @param chr	Character to send
 */
void hd44780_put(const char chr)
{
	int rs = 1;
	/*if( xSemaphoreTake( Mutex_write_lcd, portMAX_DELAY ) == pdTRUE )
	{
		
			xQueueSendToBack(Queue_lcd_data, &chr, portMAX_DELAY);
			xQueueSendToBack(Queue_lcd_rs, &rs, portMAX_DELAY);
			xSemaphoreGive( Mutex_write_lcd );
	
	}*/
	hd44780_write(chr, rs);
}

/**
 * Send a string to the LCD
 *
 * @param string	String to send
 */
void hd44780_print(const char* string)
{
	alt_u8 i = 0;
	int rs = 1;
	
	for(; i < strlen(string); i++)
	{
		hd44780_put(string[i]);
	}
}

/**
 * Send a formatted string to the LCD
 *
 * @param fmt	String format
 * @param ...	Variable arguments (see printf())
 */
void hd44780_printf(const char *fmt, ...)
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
		hd44780_put(character);
	}
}

/**
 * Initialise the LCD
 */
void hd44780_init()
{
	int data, rs = 0;
	alt_putstr("initialisation start\n");
	//function set
	/*if( xSemaphoreTake( Mutex_write_lcd, portMAX_DELAY ) == pdTRUE )
	{*/
		//vTaskDelay(35*10);
		for(int i = 0; i < 5000000; i++);
		data = 0x3C;
		/*xQueueSendToBack(Queue_lcd_data, &data, portMAX_DELAY);
		xQueueSendToBack(Queue_lcd_rs, &rs, portMAX_DELAY);*/
		hd44780_write(data, rs);
		alt_putstr("initialisation function\n");
		//display and cursor control
		data = 0x0C;
		/*xQueueSendToBack(Queue_lcd_data, &data, portMAX_DELAY);
		xQueueSendToBack(Queue_lcd_rs, &rs, portMAX_DELAY);*/
		hd44780_write(data, rs);
		alt_putstr("initialisation display\n");
		//display clear
		data = 0x01;
		/*xQueueSendToBack(Queue_lcd_data, &data, portMAX_DELAY);
		xQueueSendToBack(Queue_lcd_rs, &rs, portMAX_DELAY);*/
		hd44780_write(data, rs);
		alt_putstr("clear display\n");
		//entry mode set
		data = 0x06;
		/*xQueueSendToBack(Queue_lcd_data, &data, portMAX_DELAY);
		xQueueSendToBack(Queue_lcd_rs, &rs, portMAX_DELAY);*/
		hd44780_write(data, rs);
		/*xSemaphoreGive( Mutex_write_lcd );
	}*/
	alt_putstr("initialisation finished\n");
	/* hd44780_clear();
	hd44780_home(); */
}
