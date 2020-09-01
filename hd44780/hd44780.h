/**
 * @file
 * @defgroup 	HD44780 HD44780 4-Bit LCD Driver
 * @{
 * @brief		An interrupt driven library for HD44780-based LCD displays
 * @author		Al Brown
 * @copyright	Copyright &copy; 2013 Al Brown
 */

/*
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

#ifndef __HD44780_H
#define __HD44780_H

//#include "main.h"
#include "alt_types.h"


#define HD44780_QUEUE_FREQ  5000	/**< Update Frequency */
#define HD44780_QUEUE_SIZE  500		/**< Queue Size */

typedef int bool;

/**
 * Lines
 */
typedef enum
{
	HD44780_LINES_1 = 0x00, 		/**< 1 Line */
	HD44780_LINES_2 = 0x08			/**< 2 or 4 Lines */
} hd44780_lines_t;

/**
 * Font
 */
typedef enum
{
	HD44780_FONT_5x8  = 0x00,		/**< Standard Font */
	HD44780_FONT_5x10 = 0x04 		/**< Large Font */
} hd44780_font_t;
static void hd44780_write(const alt_u8 data, const bool reg);
void hd44780_clear(xQueueHandle Queue_lcd_data, xQueueHandle Queue_lcd_rs, xSemaphoreHandle Mutex_write_lcd);
void hd44780_home(xQueueHandle Queue_lcd_data, xQueueHandle Queue_lcd_rs, xSemaphoreHandle Mutex_write_lcd);
void hd44780_display(xQueueHandle Queue_lcd_data, xQueueHandle Queue_lcd_rs, xSemaphoreHandle Mutex_write_lcd, const bool enable, const bool cursor, const bool blink);
void hd44780_position(xQueueHandle Queue_lcd_data, xQueueHandle Queue_lcd_rs, xSemaphoreHandle Mutex_write_lcd, const alt_u8 row, const alt_u8 col);
void hd44780_cgram(xQueueHandle Queue_lcd_data, xQueueHandle Queue_lcd_rs, xSemaphoreHandle Mutex_write_lcd, const alt_u8 pos, const char row[8]);
void hd44780_put(xQueueHandle Queue_lcd_data, xQueueHandle Queue_lcd_rs, xSemaphoreHandle Mutex_write_lcd, const char chr);
void hd44780_print(xQueueHandle Queue_lcd_data, xQueueHandle Queue_lcd_rs, xSemaphoreHandle Mutex_write_lcd, const char* string);
void hd44780_printf(xQueueHandle Queue_lcd_data, xQueueHandle Queue_lcd_rs, xSemaphoreHandle Mutex_write_lcd, const char *fmt, ...);
void hd44780_init(xQueueHandle Queue_lcd_data, xQueueHandle Queue_lcd_rs, xSemaphoreHandle Mutex_write_lcd);

#endif

/** @}*/
