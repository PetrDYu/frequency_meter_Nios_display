	component Nios_display_system is
		port (
			clk_clk          : in    std_logic                     := 'X';             -- clk
			freq_export      : in    std_logic_vector(31 downto 0) := (others => 'X'); -- export
			freq_base_export : out   std_logic_vector(31 downto 0);                    -- export
			freq_en_export   : in    std_logic                     := 'X';             -- export
			key_export       : in    std_logic                     := 'X';             -- export
			lcd_data_export  : inout std_logic_vector(7 downto 0)  := (others => 'X'); -- export
			lcd_e_export     : out   std_logic;                                        -- export
			lcd_rs_export    : out   std_logic;                                        -- export
			lcd_rw_export    : out   std_logic;                                        -- export
			led_export       : out   std_logic_vector(7 downto 0);                     -- export
			reset_reset_n    : in    std_logic                     := 'X';             -- reset_n
			sw_export        : in    std_logic_vector(3 downto 0)  := (others => 'X'); -- export
			time_del_export  : out   std_logic_vector(31 downto 0)                     -- export
		);
	end component Nios_display_system;

	u0 : component Nios_display_system
		port map (
			clk_clk          => CONNECTED_TO_clk_clk,          --       clk.clk
			freq_export      => CONNECTED_TO_freq_export,      --      freq.export
			freq_base_export => CONNECTED_TO_freq_base_export, -- freq_base.export
			freq_en_export   => CONNECTED_TO_freq_en_export,   --   freq_en.export
			key_export       => CONNECTED_TO_key_export,       --       key.export
			lcd_data_export  => CONNECTED_TO_lcd_data_export,  --  lcd_data.export
			lcd_e_export     => CONNECTED_TO_lcd_e_export,     --     lcd_e.export
			lcd_rs_export    => CONNECTED_TO_lcd_rs_export,    --    lcd_rs.export
			lcd_rw_export    => CONNECTED_TO_lcd_rw_export,    --    lcd_rw.export
			led_export       => CONNECTED_TO_led_export,       --       led.export
			reset_reset_n    => CONNECTED_TO_reset_reset_n,    --     reset.reset_n
			sw_export        => CONNECTED_TO_sw_export,        --        sw.export
			time_del_export  => CONNECTED_TO_time_del_export   --  time_del.export
		);

