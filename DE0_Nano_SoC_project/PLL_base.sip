set_global_assignment -entity "PLL_base" -library "lib_PLL_base" -name IP_TOOL_NAME "altera_pll"
set_global_assignment -entity "PLL_base" -library "lib_PLL_base" -name IP_TOOL_VERSION "16.0"
set_global_assignment -entity "PLL_base" -library "lib_PLL_base" -name IP_TOOL_ENV "mwpim"
set_global_assignment -library "lib_PLL_base" -name SPD_FILE [file join $::quartus(sip_path) "PLL_base.spd"]

set_global_assignment -library "lib_PLL_base" -name MISC_FILE [file join $::quartus(sip_path) "PLL_base_sim/PLL_base.vo"]
