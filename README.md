# frequency_meter_Nios_display
Проект для кита **Terasic DE1-SoC** с чипом **Altera Cyclone V**.  
Собран в среде **Quartus Prime 16.0**.  
Сделан с использованием дисплея **DV-20400-S1FBLY/R22**.  
Проект частотомера с выводом значений на подключенный дисплей.
В проекте применяется [модуль частотомера](https://github.com/FlexlabCompany/frequency_meter_Nios_display/tree/master/freq_m_module) и [библиотека](https://github.com/FlexlabCompany/frequency_meter_Nios_display/tree/master/hd44780) для общения с дисплеем в ОС FreeRtos.  
Без дисплея работу частотомера можно посмотреть подробнее в проекте [частотомер + SPI](https://github.com/PetrDYu/frequency_meter).  
Работу с дисплеем без частотомера можно посмотреть в проекте по [сылке](https://github.com/PetrDYu/freertos_niosII/tree/master/freertos_niosII_display).