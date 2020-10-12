set_global_assignment -entity "PLL_All" -library "lib_PLL_All" -name IP_TOOL_NAME "altera_pll"
set_global_assignment -entity "PLL_All" -library "lib_PLL_All" -name IP_TOOL_VERSION "16.0"
set_global_assignment -entity "PLL_All" -library "lib_PLL_All" -name IP_TOOL_ENV "mwpim"
set_global_assignment -library "lib_PLL_All" -name SPD_FILE [file join $::quartus(sip_path) "PLL_All.spd"]

set_global_assignment -library "lib_PLL_All" -name MISC_FILE [file join $::quartus(sip_path) "PLL_All_sim/PLL_All.vo"]
