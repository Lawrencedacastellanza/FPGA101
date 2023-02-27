############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
############################################################
open_project testmem
set_top kernel
add_files testmem.cpp
add_files testmem.hpp
add_files -tb testtestmem.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1" -flow_target vivado
set_part {xc7z020-clg400-1}
create_clock -period 10 -name default
config_export -format ip_catalog -output C:/Users/loren/AppData/Roaming/Xilinx/Vitis/testmem2V2/128 -rtl verilog
source "./testmem/solution1/directives.tcl"
csim_design -clean
csynth_design
cosim_design
export_design -rtl verilog -format ip_catalog -output C:/Users/loren/AppData/Roaming/Xilinx/Vitis/testmem2V2/128
