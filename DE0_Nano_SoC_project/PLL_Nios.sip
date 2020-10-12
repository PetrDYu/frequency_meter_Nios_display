set_global_assignment -entity "PLL_Nios" -library "lib_PLL_Nios" -name IP_TOOL_NAME "altera_pll"
set_global_assignment -entity "PLL_Nios" -library "lib_PLL_Nios" -name IP_TOOL_VERSION "16.0"
set_global_assignment -entity "PLL_Nios" -library "lib_PLL_Nios" -name IP_TOOL_ENV "mwpim"
set_global_assignment -library "lib_PLL_Nios" -name SPD_FILE [file join $::quartus(sip_path) "PLL_Nios.spd"]

set_global_assignment -library "lib_PLL_Nios" -name MISC_FILE [file join $::quartus(sip_path) "PLL_Nios_sim/PLL_Nios.vo"]
