
module Nios_display_system (
	clk_clk,
	freq_export,
	freq_base_export,
	freq_en_export,
	key_export,
	lcd_data_export,
	lcd_e_export,
	lcd_rs_export,
	lcd_rw_export,
	led_export,
	reset_reset_n,
	sw_export,
	time_del_export);	

	input		clk_clk;
	input	[31:0]	freq_export;
	output	[31:0]	freq_base_export;
	input		freq_en_export;
	input		key_export;
	inout	[7:0]	lcd_data_export;
	output		lcd_e_export;
	output		lcd_rs_export;
	output		lcd_rw_export;
	output	[7:0]	led_export;
	input		reset_reset_n;
	input	[3:0]	sw_export;
	output	[31:0]	time_del_export;
endmodule
