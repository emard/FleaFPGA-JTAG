# FleaFPGA-JTAG utility for ULX3S

Original linux version of FleaFPGA-JTAG is patched by EMARD
to work with FT231X and Lattice ECP5 FPGA. On ULX3S boards it
uploads 1MB bitstream.vme file in about 22 seconds.

Active source is [FleaFPGA-JTAG-linux](FleaFPGA-JTAG-linux), contains 
"makefile" rules to compile for linux and win32.

Obsolete win32-only source is [FleaFPGA-JTAG-win32](FleaFPGA-JTAG-win32).

Original readme follows:

## FleaFPGA-JTAG utility source (for Windows and Linux)

###### Based on Lattice ispVME software.  Copyright 2008 Lattice Semiconductor Corp.  See license.txt file.

This is the source code for the FleaFPGA-JTAG utility used to program the MachXO2 FPGA internal configuration flash or SRAM on http://Fleasystems.com FleaFPGA boards (via USB FTDI FT231x JTAG).

For a full tutorial, please see the FleaFPGA Quickstart Guide for your FleaFPGA board.
