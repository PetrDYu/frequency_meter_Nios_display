#include "sys/alt_stdio.h"
#include "sys/alt_irq.h"
#include "system.h"
#include <stdio.h>
#include <stdarg.h>
#include "FreeRTOS.h"
#include "semphr.h"
#include "queue.h"
#include "task.h"
#include "altera_avalon_pio_regs.h"
#include "hd44780.c"
#include "alt_types.h"

xQueueHandle Queue_lcd_data, Queue_lcd_rs;
xSemaphoreHandle Mutex_write_lcd;
int n = 0;

void sayHello( void *p){
	char data[] = "%s, %s, %d, ", data2[] = "asd", data3[] = "sdf";
	int data4 = 20;
while(1){
	printf("Hello, world!\n");
	hd44780_printf(Queue_lcd_data, Queue_lcd_rs, Mutex_write_lcd, data, data2, data3, data4);

	vTaskDelay(1000*10);
 }
}


void sayInBitween (void *p){
while(1){
 printf("In between\n");
 IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 1 << n);
 n++;
 if (n == 10) n = 0;
 vTaskDelay(300*10);
 }
}
void task_lcd_write(void *p)
{
	hd44780_init(Queue_lcd_data, Queue_lcd_rs, Mutex_write_lcd);
	int data, rs;
	while(1)
	{
		xQueueReceive(Queue_lcd_data, &data, portMAX_DELAY);
		xQueueReceive(Queue_lcd_rs, &rs, portMAX_DELAY);
		write(data, rs);
		while(!read_busy());
	}
}
int main()
{
	alt_putstr("Hello from Nios II!\n");
	Queue_lcd_data = xQueueCreate(100, 1);
	Queue_lcd_rs = xQueueCreate(100, 1);
	Mutex_write_lcd = xSemaphoreCreateMutex();
	xTaskCreate(task_lcd_write, "task_lcd_write", configMINIMAL_STACK_SIZE, NULL, 2, NULL);
	xTaskCreate(sayHello, "sayHello", configMINIMAL_STACK_SIZE, NULL, 2, NULL);
	printf("sayHello inst\n");
	xTaskCreate(sayInBitween, "sayInBitween",configMINIMAL_STACK_SIZE,NULL,2,NULL);
	printf("sayInBitween inst\n");
	vTaskStartScheduler();
	return 0;
}
