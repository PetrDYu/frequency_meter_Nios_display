#include "sys/alt_stdio.h"
#include "sys/alt_irq.h"
#include "system.h"
#include <stdio.h>
//#include <stdarg.h>
#include <stdlib.h>
//#include <string.h>
#include "altera_avalon_pio_regs.h"
#include "hd44780_no_freertos.c"
#include "alt_types.h"

int n = 0, freq_base = 0, time_del = 0, sw0, sw123, len_znach = 0;

static void handler_freq_en (void * context);

void freq_to_lcd();
void set_freq_base();
void set_time_del();

volatile int edge_capture;

static void init_freq_en_IRQ();


int main()
{
	alt_putstr("Start\n");
	hd44780_init();
	init_freq_en_IRQ();
	IOWR_ALTERA_AVALON_PIO_DATA(FREQ_BASE_BASE, freq_base);
	//printf("freq_base init: ", freq_base);
	IOWR_ALTERA_AVALON_PIO_DATA(TIME_DEL_BASE, time_del);
	//printf("time_del init: ", time_del);
	while(1)
	{
		set_freq_base();
		set_time_del();
//		freq_to_lcd();
	}
	return 0;
}

void freq_to_lcd()
{
//	int write_en = 0;
	char zagolovok [] = {0xAB,0x61,0x63,0xBF,0x6F,0xBF,0x61}, znachenie [20];
/*	if(IORD_ALTERA_AVALON_PIO_DATA(FREQ_EN_BASE))
	{
		write_en++;
		//printf("frequency enable\n");
		if (write_en == 1)
		{
			//printf("home\n");
			//hd44780_clear();*/
			itoa(IORD_ALTERA_AVALON_PIO_DATA(FREQ_BASE), znachenie, 10);
			hd44780_position(0, 0);
			//hd44780_print(zagolovok);
			//printf("frequency\n");
			if (strlen(znachenie) < len_znach) hd44780_clear();
			hd44780_print("frequency");
			hd44780_print("=");
			//alt_putstr(znachenie);
			hd44780_print(znachenie);
			len_znach = strlen(znachenie);

			IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 1 << n);
			n++;
			if (n == LED_DATA_WIDTH) n = 0;
/*		}
	}
	else write_en = 0;*/

}

void set_freq_base()
{

	if (sw0 != (IORD_ALTERA_AVALON_PIO_DATA(SW_BASE) & 0x01))
	{
		for(int i = 0; i < ALT_CPU_CPU_FREQ / 4 ; i++);
		sw0 = IORD_ALTERA_AVALON_PIO_DATA(SW_BASE) & 0x01;
		if (sw0 == 0) freq_base = 400000000;
		else freq_base = 50000000;
		IOWR_ALTERA_AVALON_PIO_DATA(FREQ_BASE_BASE, freq_base);
		printf("freq_base = %d\n",freq_base);
	}
}

void set_time_del()
{
	if (sw123 != ((IORD_ALTERA_AVALON_PIO_DATA(SW_BASE) & 0x0E) >> 1))
	{
		for(int i = 0; i < ALT_CPU_CPU_FREQ / 4; i++);
		sw123 = ((IORD_ALTERA_AVALON_PIO_DATA(SW_BASE) & 0x0E) >> 1);
		time_del = sw123;
		IOWR_ALTERA_AVALON_PIO_DATA(TIME_DEL_BASE, time_del);
		printf("time_del = %d\n",time_del);
	}
}

static void init_freq_en_IRQ()
{
	void* edge_capture_ptr = (void*) &edge_capture;
	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(FREQ_EN_BASE, 0xf);
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(FREQ_EN_BASE, 0x0);
	alt_ic_isr_register(FREQ_EN_IRQ_INTERRUPT_CONTROLLER_ID,
	FREQ_EN_IRQ,
	handler_freq_en,
	edge_capture_ptr, 0x0);
}

static void handler_freq_en (void * context)
{
	volatile int* edge_capture_ptr = (volatile int*) context;

	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(FREQ_EN_BASE, 0);
	freq_to_lcd();
}
