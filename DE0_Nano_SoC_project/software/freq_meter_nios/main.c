#include "sys/alt_stdio.h"
#include "sys/alt_irq.h"
#include "system.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "altera_avalon_pio_regs.h"
#include "hd44780_no_freertos.c"
#include "alt_types.h"

int n = 0, freq_base = 200000000, time_del = 0, sw0, sw123;

void freq_to_lcd()
{
	int write_en = 0;
	char zagolovok [] = {0xAB,0x61,0x63,0xBF,0x6F,0xBF,0x61}, znachenie [20];
	if(IORD_ALTERA_AVALON_PIO_DATA(FREQ_EN_BASE))
	{
		write_en++;
		//printf("frequency enable\n");
		if (write_en == 1)
		{
			//printf("home\n");
			//hd44780_clear();
			itoa(IORD_ALTERA_AVALON_PIO_DATA(FREQ_BASE), znachenie, 10);
			hd44780_position(0, 0/*strlen(znachenie) + 12*/);
			//hd44780_print(zagolovok);
			//printf("frequency\n");
			hd44780_print("frequency");
			hd44780_print("=");
			//alt_putstr(znachenie);
			hd44780_print(znachenie);

			IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, 1 << n);
			n++;
			if (n == LED_DATA_WIDTH) n = 0;
		}
	}
	else write_en = 0;

}

int set_freq_base()
{

	if (sw0 != IORD_ALTERA_AVALON_PIO_DATA(SW_BASE) & 0x01)
	{
		for(int i = 0; i < ALT_CPU_CPU_FREQ / 1000; i++);
		sw0 = IORD_ALTERA_AVALON_PIO_DATA(SW_BASE) & 0x01;
		if (sw0 == 0) freq_base = 200000000;
		else freq_base = 50000000;
		IOWR_ALTERA_AVALON_PIO_DATA(FREQ_BASE_BASE, freq_base);
		printf("freq_base = %d",freq_base);
	}
}

int set_time_del()
{
	if (sw123 != ((IORD_ALTERA_AVALON_PIO_DATA(SW_BASE) & 0x0E) >> 1))
		{
			for(int i = 0; i < ALT_CPU_CPU_FREQ / 1000; i++);
			sw123 = ((IORD_ALTERA_AVALON_PIO_DATA(SW_BASE) & 0x0E) >> 1);
			time_del = sw123;
			IOWR_ALTERA_AVALON_PIO_DATA(TIME_DEL_BASE, time_del);
			printf("time_del = %d",time_del);
		}
}

int main()
{
	hd44780_init();
	IOWR_ALTERA_AVALON_PIO_DATA(FREQ_BASE_BASE, freq_base);
	IOWR_ALTERA_AVALON_PIO_DATA(TIME_DEL_BASE, time_del);
	while(1)
	{
		set_freq_base();
		set_time_del();
		freq_to_lcd();
	}
}
