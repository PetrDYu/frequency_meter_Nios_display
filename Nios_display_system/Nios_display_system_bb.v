
module Nios_display_system (
	clk_clk,
	freq_export,
	key_export,
	lcd_data_export,
	lcd_e_export,
	lcd_rs_export,
	lcd_rw_export,
	led_export,
	reset_reset_n,
	sdram_addr,
	sdram_ba,
	sdram_cas_n,
	sdram_cke,
	sdram_cs_n,
	sdram_dq,
	sdram_dqm,
	sdram_ras_n,
	sdram_we_n,
	sw_export,
	sdram_clk_clk);	

	input		clk_clk;
	input	[31:0]	freq_export;
	input	[2:0]	key_export;
	inout	[7:0]	lcd_data_export;
	output		lcd_e_export;
	output		lcd_rs_export;
	output		lcd_rw_export;
	output	[9:0]	led_export;
	input		reset_reset_n;
	output	[11:0]	sdram_addr;
	output	[1:0]	sdram_ba;
	output		sdram_cas_n;
	output		sdram_cke;
	output		sdram_cs_n;
	inout	[15:0]	sdram_dq;
	output	[1:0]	sdram_dqm;
	output		sdram_ras_n;
	output		sdram_we_n;
	input	[9:0]	sw_export;
	output		sdram_clk_clk;
endmodule
