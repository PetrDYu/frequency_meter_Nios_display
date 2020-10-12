/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2_gen2_0' in SOPC Builder design 'Nios_display_system'
 * SOPC Builder design path: ../../Nios_display_system.sopcinfo
 *
 * Generated: Mon Oct 12 02:47:52 MSK 2020
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_gen2"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x00080820
#define ALT_CPU_CPU_ARCH_NIOS2_R1
#define ALT_CPU_CPU_FREQ 100000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "fast"
#define ALT_CPU_DATA_ADDR_WIDTH 0x14
#define ALT_CPU_DCACHE_BYPASS_MASK 0x80000000
#define ALT_CPU_DCACHE_LINE_SIZE 32
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_DCACHE_SIZE 2048
#define ALT_CPU_EXCEPTION_ADDR 0x00040020
#define ALT_CPU_FLASH_ACCELERATOR_LINES 0
#define ALT_CPU_FLASH_ACCELERATOR_LINE_SIZE 0
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 100000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 1
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_EXTRA_EXCEPTION_INFO
#define ALT_CPU_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 32
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_ICACHE_SIZE 4096
#define ALT_CPU_INITDA_SUPPORTED
#define ALT_CPU_INST_ADDR_WIDTH 0x14
#define ALT_CPU_NAME "nios2_gen2_0"
#define ALT_CPU_NUM_OF_SHADOW_REG_SETS 0
#define ALT_CPU_OCI_VERSION 1
#define ALT_CPU_RESET_ADDR 0x00040000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x00080820
#define NIOS2_CPU_ARCH_NIOS2_R1
#define NIOS2_CPU_FREQ 100000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "fast"
#define NIOS2_DATA_ADDR_WIDTH 0x14
#define NIOS2_DCACHE_BYPASS_MASK 0x80000000
#define NIOS2_DCACHE_LINE_SIZE 32
#define NIOS2_DCACHE_LINE_SIZE_LOG2 5
#define NIOS2_DCACHE_SIZE 2048
#define NIOS2_EXCEPTION_ADDR 0x00040020
#define NIOS2_FLASH_ACCELERATOR_LINES 0
#define NIOS2_FLASH_ACCELERATOR_LINE_SIZE 0
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 1
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_EXTRA_EXCEPTION_INFO
#define NIOS2_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_ICACHE_SIZE 4096
#define NIOS2_INITDA_SUPPORTED
#define NIOS2_INST_ADDR_WIDTH 0x14
#define NIOS2_NUM_OF_SHADOW_REG_SETS 0
#define NIOS2_OCI_VERSION 1
#define NIOS2_RESET_ADDR 0x00040000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_NIOS2_GEN2


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone V"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart_0"
#define ALT_STDERR_BASE 0x810c0
#define ALT_STDERR_DEV jtag_uart_0
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart_0"
#define ALT_STDIN_BASE 0x810c0
#define ALT_STDIN_DEV jtag_uart_0
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart_0"
#define ALT_STDOUT_BASE 0x810c0
#define ALT_STDOUT_DEV jtag_uart_0
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "Nios_display_system"


/*
 * freq configuration
 *
 */

#define ALT_MODULE_CLASS_freq altera_avalon_pio
#define FREQ_BASE 0x81080
#define FREQ_BIT_CLEARING_EDGE_REGISTER 0
#define FREQ_BIT_MODIFYING_OUTPUT_REGISTER 0
#define FREQ_CAPTURE 0
#define FREQ_DATA_WIDTH 32
#define FREQ_DO_TEST_BENCH_WIRING 0
#define FREQ_DRIVEN_SIM_VALUE 0
#define FREQ_EDGE_TYPE "NONE"
#define FREQ_FREQ 100000000
#define FREQ_HAS_IN 1
#define FREQ_HAS_OUT 0
#define FREQ_HAS_TRI 0
#define FREQ_IRQ -1
#define FREQ_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FREQ_IRQ_TYPE "NONE"
#define FREQ_NAME "/dev/freq"
#define FREQ_RESET_VALUE 0
#define FREQ_SPAN 16
#define FREQ_TYPE "altera_avalon_pio"


/*
 * freq_base configuration
 *
 */

#define ALT_MODULE_CLASS_freq_base altera_avalon_pio
#define FREQ_BASE_BASE 0x81000
#define FREQ_BASE_BIT_CLEARING_EDGE_REGISTER 0
#define FREQ_BASE_BIT_MODIFYING_OUTPUT_REGISTER 0
#define FREQ_BASE_CAPTURE 0
#define FREQ_BASE_DATA_WIDTH 32
#define FREQ_BASE_DO_TEST_BENCH_WIRING 0
#define FREQ_BASE_DRIVEN_SIM_VALUE 0
#define FREQ_BASE_EDGE_TYPE "NONE"
#define FREQ_BASE_FREQ 100000000
#define FREQ_BASE_HAS_IN 0
#define FREQ_BASE_HAS_OUT 1
#define FREQ_BASE_HAS_TRI 0
#define FREQ_BASE_IRQ -1
#define FREQ_BASE_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FREQ_BASE_IRQ_TYPE "NONE"
#define FREQ_BASE_NAME "/dev/freq_base"
#define FREQ_BASE_RESET_VALUE 0
#define FREQ_BASE_SPAN 16
#define FREQ_BASE_TYPE "altera_avalon_pio"


/*
 * freq_en configuration
 *
 */

#define ALT_MODULE_CLASS_freq_en altera_avalon_pio
#define FREQ_EN_BASE 0x81020
#define FREQ_EN_BIT_CLEARING_EDGE_REGISTER 0
#define FREQ_EN_BIT_MODIFYING_OUTPUT_REGISTER 0
#define FREQ_EN_CAPTURE 0
#define FREQ_EN_DATA_WIDTH 1
#define FREQ_EN_DO_TEST_BENCH_WIRING 0
#define FREQ_EN_DRIVEN_SIM_VALUE 0
#define FREQ_EN_EDGE_TYPE "NONE"
#define FREQ_EN_FREQ 100000000
#define FREQ_EN_HAS_IN 1
#define FREQ_EN_HAS_OUT 0
#define FREQ_EN_HAS_TRI 0
#define FREQ_EN_IRQ -1
#define FREQ_EN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FREQ_EN_IRQ_TYPE "NONE"
#define FREQ_EN_NAME "/dev/freq_en"
#define FREQ_EN_RESET_VALUE 0
#define FREQ_EN_SPAN 16
#define FREQ_EN_TYPE "altera_avalon_pio"


/*
 * hal configuration
 *
 */

#define ALT_INCLUDE_INSTRUCTION_RELATED_EXCEPTION_API
#define ALT_MAX_FD 32
#define ALT_SYS_CLK none
#define ALT_TIMESTAMP_CLK none


/*
 * jtag_uart_0 configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart_0 altera_avalon_jtag_uart
#define JTAG_UART_0_BASE 0x810c0
#define JTAG_UART_0_IRQ 0
#define JTAG_UART_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_0_NAME "/dev/jtag_uart_0"
#define JTAG_UART_0_READ_DEPTH 64
#define JTAG_UART_0_READ_THRESHOLD 8
#define JTAG_UART_0_SPAN 8
#define JTAG_UART_0_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_0_WRITE_DEPTH 64
#define JTAG_UART_0_WRITE_THRESHOLD 8


/*
 * key configuration
 *
 */

#define ALT_MODULE_CLASS_key altera_avalon_pio
#define KEY_BASE 0x810a0
#define KEY_BIT_CLEARING_EDGE_REGISTER 0
#define KEY_BIT_MODIFYING_OUTPUT_REGISTER 0
#define KEY_CAPTURE 0
#define KEY_DATA_WIDTH 1
#define KEY_DO_TEST_BENCH_WIRING 0
#define KEY_DRIVEN_SIM_VALUE 0
#define KEY_EDGE_TYPE "NONE"
#define KEY_FREQ 100000000
#define KEY_HAS_IN 1
#define KEY_HAS_OUT 0
#define KEY_HAS_TRI 0
#define KEY_IRQ -1
#define KEY_IRQ_INTERRUPT_CONTROLLER_ID -1
#define KEY_IRQ_TYPE "NONE"
#define KEY_NAME "/dev/key"
#define KEY_RESET_VALUE 0
#define KEY_SPAN 16
#define KEY_TYPE "altera_avalon_pio"


/*
 * lcd_data configuration
 *
 */

#define ALT_MODULE_CLASS_lcd_data altera_avalon_pio
#define LCD_DATA_BASE 0x81060
#define LCD_DATA_BIT_CLEARING_EDGE_REGISTER 0
#define LCD_DATA_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LCD_DATA_CAPTURE 0
#define LCD_DATA_DATA_WIDTH 8
#define LCD_DATA_DO_TEST_BENCH_WIRING 0
#define LCD_DATA_DRIVEN_SIM_VALUE 0
#define LCD_DATA_EDGE_TYPE "NONE"
#define LCD_DATA_FREQ 100000000
#define LCD_DATA_HAS_IN 0
#define LCD_DATA_HAS_OUT 0
#define LCD_DATA_HAS_TRI 1
#define LCD_DATA_IRQ -1
#define LCD_DATA_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LCD_DATA_IRQ_TYPE "NONE"
#define LCD_DATA_NAME "/dev/lcd_data"
#define LCD_DATA_RESET_VALUE 0
#define LCD_DATA_SPAN 16
#define LCD_DATA_TYPE "altera_avalon_pio"


/*
 * lcd_e configuration
 *
 */

#define ALT_MODULE_CLASS_lcd_e altera_avalon_pio
#define LCD_E_BASE 0x81030
#define LCD_E_BIT_CLEARING_EDGE_REGISTER 0
#define LCD_E_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LCD_E_CAPTURE 0
#define LCD_E_DATA_WIDTH 1
#define LCD_E_DO_TEST_BENCH_WIRING 0
#define LCD_E_DRIVEN_SIM_VALUE 0
#define LCD_E_EDGE_TYPE "NONE"
#define LCD_E_FREQ 100000000
#define LCD_E_HAS_IN 0
#define LCD_E_HAS_OUT 1
#define LCD_E_HAS_TRI 0
#define LCD_E_IRQ -1
#define LCD_E_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LCD_E_IRQ_TYPE "NONE"
#define LCD_E_NAME "/dev/lcd_e"
#define LCD_E_RESET_VALUE 0
#define LCD_E_SPAN 16
#define LCD_E_TYPE "altera_avalon_pio"


/*
 * lcd_rs configuration
 *
 */

#define ALT_MODULE_CLASS_lcd_rs altera_avalon_pio
#define LCD_RS_BASE 0x81050
#define LCD_RS_BIT_CLEARING_EDGE_REGISTER 0
#define LCD_RS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LCD_RS_CAPTURE 0
#define LCD_RS_DATA_WIDTH 1
#define LCD_RS_DO_TEST_BENCH_WIRING 0
#define LCD_RS_DRIVEN_SIM_VALUE 0
#define LCD_RS_EDGE_TYPE "NONE"
#define LCD_RS_FREQ 100000000
#define LCD_RS_HAS_IN 0
#define LCD_RS_HAS_OUT 1
#define LCD_RS_HAS_TRI 0
#define LCD_RS_IRQ -1
#define LCD_RS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LCD_RS_IRQ_TYPE "NONE"
#define LCD_RS_NAME "/dev/lcd_rs"
#define LCD_RS_RESET_VALUE 0
#define LCD_RS_SPAN 16
#define LCD_RS_TYPE "altera_avalon_pio"


/*
 * lcd_rw configuration
 *
 */

#define ALT_MODULE_CLASS_lcd_rw altera_avalon_pio
#define LCD_RW_BASE 0x81040
#define LCD_RW_BIT_CLEARING_EDGE_REGISTER 0
#define LCD_RW_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LCD_RW_CAPTURE 0
#define LCD_RW_DATA_WIDTH 1
#define LCD_RW_DO_TEST_BENCH_WIRING 0
#define LCD_RW_DRIVEN_SIM_VALUE 0
#define LCD_RW_EDGE_TYPE "NONE"
#define LCD_RW_FREQ 100000000
#define LCD_RW_HAS_IN 0
#define LCD_RW_HAS_OUT 1
#define LCD_RW_HAS_TRI 0
#define LCD_RW_IRQ -1
#define LCD_RW_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LCD_RW_IRQ_TYPE "NONE"
#define LCD_RW_NAME "/dev/lcd_rw"
#define LCD_RW_RESET_VALUE 0
#define LCD_RW_SPAN 16
#define LCD_RW_TYPE "altera_avalon_pio"


/*
 * led configuration
 *
 */

#define ALT_MODULE_CLASS_led altera_avalon_pio
#define LED_BASE 0x81090
#define LED_BIT_CLEARING_EDGE_REGISTER 0
#define LED_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LED_CAPTURE 0
#define LED_DATA_WIDTH 8
#define LED_DO_TEST_BENCH_WIRING 0
#define LED_DRIVEN_SIM_VALUE 0
#define LED_EDGE_TYPE "NONE"
#define LED_FREQ 100000000
#define LED_HAS_IN 0
#define LED_HAS_OUT 1
#define LED_HAS_TRI 0
#define LED_IRQ -1
#define LED_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LED_IRQ_TYPE "NONE"
#define LED_NAME "/dev/led"
#define LED_RESET_VALUE 0
#define LED_SPAN 16
#define LED_TYPE "altera_avalon_pio"


/*
 * onchip_memory2_0 configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_memory2_0 altera_avalon_onchip_memory2
#define ONCHIP_MEMORY2_0_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_MEMORY2_0_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_MEMORY2_0_BASE 0x40000
#define ONCHIP_MEMORY2_0_CONTENTS_INFO ""
#define ONCHIP_MEMORY2_0_DUAL_PORT 0
#define ONCHIP_MEMORY2_0_GUI_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_0_INIT_CONTENTS_FILE "Nios_display_system_onchip_memory2_0"
#define ONCHIP_MEMORY2_0_INIT_MEM_CONTENT 1
#define ONCHIP_MEMORY2_0_INSTANCE_ID "NONE"
#define ONCHIP_MEMORY2_0_IRQ -1
#define ONCHIP_MEMORY2_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_MEMORY2_0_NAME "/dev/onchip_memory2_0"
#define ONCHIP_MEMORY2_0_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_MEMORY2_0_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_0_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_MEMORY2_0_SINGLE_CLOCK_OP 0
#define ONCHIP_MEMORY2_0_SIZE_MULTIPLE 1
#define ONCHIP_MEMORY2_0_SIZE_VALUE 200000
#define ONCHIP_MEMORY2_0_SPAN 200000
#define ONCHIP_MEMORY2_0_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_MEMORY2_0_WRITABLE 1


/*
 * sw configuration
 *
 */

#define ALT_MODULE_CLASS_sw altera_avalon_pio
#define SW_BASE 0x81070
#define SW_BIT_CLEARING_EDGE_REGISTER 0
#define SW_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SW_CAPTURE 0
#define SW_DATA_WIDTH 4
#define SW_DO_TEST_BENCH_WIRING 0
#define SW_DRIVEN_SIM_VALUE 0
#define SW_EDGE_TYPE "NONE"
#define SW_FREQ 100000000
#define SW_HAS_IN 1
#define SW_HAS_OUT 0
#define SW_HAS_TRI 0
#define SW_IRQ -1
#define SW_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SW_IRQ_TYPE "NONE"
#define SW_NAME "/dev/sw"
#define SW_RESET_VALUE 0
#define SW_SPAN 16
#define SW_TYPE "altera_avalon_pio"


/*
 * sysid_qsys_0 configuration
 *
 */

#define ALT_MODULE_CLASS_sysid_qsys_0 altera_avalon_sysid_qsys
#define SYSID_QSYS_0_BASE 0x810b8
#define SYSID_QSYS_0_ID 1
#define SYSID_QSYS_0_IRQ -1
#define SYSID_QSYS_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_QSYS_0_NAME "/dev/sysid_qsys_0"
#define SYSID_QSYS_0_SPAN 8
#define SYSID_QSYS_0_TIMESTAMP 1602455547
#define SYSID_QSYS_0_TYPE "altera_avalon_sysid_qsys"


/*
 * time_del configuration
 *
 */

#define ALT_MODULE_CLASS_time_del altera_avalon_pio
#define TIME_DEL_BASE 0x81010
#define TIME_DEL_BIT_CLEARING_EDGE_REGISTER 0
#define TIME_DEL_BIT_MODIFYING_OUTPUT_REGISTER 0
#define TIME_DEL_CAPTURE 0
#define TIME_DEL_DATA_WIDTH 32
#define TIME_DEL_DO_TEST_BENCH_WIRING 0
#define TIME_DEL_DRIVEN_SIM_VALUE 0
#define TIME_DEL_EDGE_TYPE "NONE"
#define TIME_DEL_FREQ 100000000
#define TIME_DEL_HAS_IN 0
#define TIME_DEL_HAS_OUT 1
#define TIME_DEL_HAS_TRI 0
#define TIME_DEL_IRQ -1
#define TIME_DEL_IRQ_INTERRUPT_CONTROLLER_ID -1
#define TIME_DEL_IRQ_TYPE "NONE"
#define TIME_DEL_NAME "/dev/time_del"
#define TIME_DEL_RESET_VALUE 0
#define TIME_DEL_SPAN 16
#define TIME_DEL_TYPE "altera_avalon_pio"

#endif /* __SYSTEM_H_ */
