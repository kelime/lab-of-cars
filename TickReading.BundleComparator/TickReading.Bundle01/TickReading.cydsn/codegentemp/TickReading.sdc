# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\Emmily\!Spring2015\CarLab\TickReading.BundleComparator\TickReading.BundleComparator\TickReading.Bundle01\TickReading.cydsn\TickReading.cyprj
# Date: Tue, 05 May 2015 20:23:59 GMT
#set_units -time ns
create_clock -name {CyBUS_CLK(routed)} -period 41.666666666666664 -waveform {0 20.8333333333333} [get_pins {ClockBlock/clk_bus}]
create_clock -name {ADC_Side_Rangefinder_Ext_CP_Clk(routed)} -period 541.66666666666663 -waveform {0 270.833333333333} [get_pins {ClockBlock/dclk_0}]
create_clock -name {Clock_Hall(routed)} -period 10000 -waveform {0 5000} [get_pins {ClockBlock/dclk_1}]
create_clock -name {CyIMO} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyILO} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyMASTER_CLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {ADC_Side_Rangefinder_Ext_CP_Clk} -source [get_pins {ClockBlock/clk_sync}] -edges {1 13 27} -nominal_period 541.66666666666663 [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {ADC_Side_Rangefinder_theACLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 53 105} -nominal_period 2166.6666666666665 [list [get_pins {ClockBlock/aclk_glb_0}]]
create_generated_clock -name {Clock_Hall} -source [get_pins {ClockBlock/clk_sync}] -edges {1 241 481} [list [get_pins {ClockBlock/dclk_glb_1}]]
create_generated_clock -name {Clock_Steering} -source [get_pins {ClockBlock/clk_sync}] -edges {1 241 481} [list [get_pins {ClockBlock/dclk_glb_2}]]
create_generated_clock -name {Wait_Clock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 96837 480001} [list [get_pins {ClockBlock/dclk_glb_3}]]
create_generated_clock -name {Altimeter_Clock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 96837 480001} [list [get_pins {ClockBlock/dclk_glb_4}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for C:\Users\Emmily\!Spring2015\CarLab\TickReading.BundleComparator\TickReading.BundleComparator\TickReading.Bundle01\TickReading.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\Emmily\!Spring2015\CarLab\TickReading.BundleComparator\TickReading.BundleComparator\TickReading.Bundle01\TickReading.cydsn\TickReading.cyprj
# Date: Tue, 05 May 2015 20:23:42 GMT
