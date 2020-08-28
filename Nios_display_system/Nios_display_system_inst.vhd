	component Nios_display_system is
		port (
			clk_clk         : in    std_logic                     := 'X';             -- clk
			freq_export     : in    std_logic_vector(31 downto 0) := (others => 'X'); -- export
			key_export      : in    std_logic_vector(2 downto 0)  := (others => 'X'); -- export
			lcd_data_export : inout std_logic_vector(7 downto 0)  := (others => 'X'); -- export
			lcd_e_export    : out   std_logic;                                        -- export
			lcd_rs_export   : out   std_logic;                                        -- export
			lcd_rw_export   : out   std_logic;                                        -- export
			led_export      : out   std_logic_vector(9 downto 0);                     -- export
			reset_reset_n   : in    std_logic                     := 'X';             -- reset_n
			sdram_addr      : out   std_logic_vector(11 downto 0);                    -- addr
			sdram_ba        : out   std_logic_vector(1 downto 0);                     -- ba
			sdram_cas_n     : out   std_logic;                                        -- cas_n
			sdram_cke       : out   std_logic;                                        -- cke
			sdram_cs_n      : out   std_logic;                                        -- cs_n
			sdram_dq        : inout std_logic_vector(15 downto 0) := (others => 'X'); -- dq
			sdram_dqm       : out   std_logic_vector(1 downto 0);                     -- dqm
			sdram_ras_n     : out   std_logic;                                        -- ras_n
			sdram_we_n      : out   std_logic;                                        -- we_n
			sw_export       : in    std_logic_vector(9 downto 0)  := (others => 'X'); -- export
			sdram_clk_clk   : out   std_logic                                         -- clk
		);
	end component Nios_display_system;

	u0 : component Nios_display_system
		port map (
			clk_clk         => CONNECTED_TO_clk_clk,         --       clk.clk
			freq_export     => CONNECTED_TO_freq_export,     --      freq.export
			key_export      => CONNECTED_TO_key_export,      --       key.export
			lcd_data_export => CONNECTED_TO_lcd_data_export, --  lcd_data.export
			lcd_e_export    => CONNECTED_TO_lcd_e_export,    --     lcd_e.export
			lcd_rs_export   => CONNECTED_TO_lcd_rs_export,   --    lcd_rs.export
			lcd_rw_export   => CONNECTED_TO_lcd_rw_export,   --    lcd_rw.export
			led_export      => CONNECTED_TO_led_export,      --       led.export
			reset_reset_n   => CONNECTED_TO_reset_reset_n,   --     reset.reset_n
			sdram_addr      => CONNECTED_TO_sdram_addr,      --     sdram.addr
			sdram_ba        => CONNECTED_TO_sdram_ba,        --          .ba
			sdram_cas_n     => CONNECTED_TO_sdram_cas_n,     --          .cas_n
			sdram_cke       => CONNECTED_TO_sdram_cke,       --          .cke
			sdram_cs_n      => CONNECTED_TO_sdram_cs_n,      --          .cs_n
			sdram_dq        => CONNECTED_TO_sdram_dq,        --          .dq
			sdram_dqm       => CONNECTED_TO_sdram_dqm,       --          .dqm
			sdram_ras_n     => CONNECTED_TO_sdram_ras_n,     --          .ras_n
			sdram_we_n      => CONNECTED_TO_sdram_we_n,      --          .we_n
			sw_export       => CONNECTED_TO_sw_export,       --        sw.export
			sdram_clk_clk   => CONNECTED_TO_sdram_clk_clk    -- sdram_clk.clk
		);

