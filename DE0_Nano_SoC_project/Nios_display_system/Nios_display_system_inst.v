	Nios_display_system u0 (
		.clk_clk          (<connected-to-clk_clk>),          //       clk.clk
		.freq_export      (<connected-to-freq_export>),      //      freq.export
		.freq_base_export (<connected-to-freq_base_export>), // freq_base.export
		.freq_en_export   (<connected-to-freq_en_export>),   //   freq_en.export
		.key_export       (<connected-to-key_export>),       //       key.export
		.lcd_data_export  (<connected-to-lcd_data_export>),  //  lcd_data.export
		.lcd_e_export     (<connected-to-lcd_e_export>),     //     lcd_e.export
		.lcd_rs_export    (<connected-to-lcd_rs_export>),    //    lcd_rs.export
		.lcd_rw_export    (<connected-to-lcd_rw_export>),    //    lcd_rw.export
		.led_export       (<connected-to-led_export>),       //       led.export
		.reset_reset_n    (<connected-to-reset_reset_n>),    //     reset.reset_n
		.sw_export        (<connected-to-sw_export>),        //        sw.export
		.time_del_export  (<connected-to-time_del_export>)   //  time_del.export
	);

