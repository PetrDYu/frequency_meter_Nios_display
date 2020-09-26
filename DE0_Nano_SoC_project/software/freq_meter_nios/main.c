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

int n = 0;

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

int main()
{
	hd44780_init();
	while(1)
	{
		freq_to_lcd();
	}
}
