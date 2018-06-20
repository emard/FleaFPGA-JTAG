FleaFPGA-JTAG utility
Based on Lattice ispVME software. Copyright 2008 Lattice Semiconductor Corp.  See license.txt file.

From linux this can build executables for both linux and windows.

For linux:

    make clean
    make -f Makefile.linux

For windows (needs ftdi d2xx unzipped to /tmp/ftdi):

    make clean
    make -f Makefile.win32

----------------------------

For a full tutorial, please see the FleaFPGA Quickstart Guide for your FleaFPGA board.

Linux Note: FleaFPGA-JTAG uses libusb and libftdi1 (note the "1", needed support of FTDI FT231x chip) libraries.  You may need to install libftdi1 if your distribution only has libftdi.

In normal use, you would typically use the Lattice Diamond Programmer to setup the JTAG operation as normal and save the programmer project ".XCF" file.

Typically select Edit|Device Properties (or double click on "Operation" column) then the typical options you would use are:

Access mode "Static RAM Cell Mode" and operation "SRAM Fast Program" (with ".bit" format FPGA bitstream) for fast programming of volatile FPGA SRAM configuration (design lasts until power cycle).  Use this for quick iteration while testing designs.

or

Access mode "Flash Programming Mode" and operation "FLASH Program" (with ".jed" format FPGA bitstream) for programming the non-volatile internal flash memory of the FPGA (design will be re-loaded from flash at power on).  This mode is slower so use this when your design is completed or when you want to test without a PC connected.

After setting the mode and operation select the programming file (again, make sure "*.bit" file for SRAM, or "*.jed" for Flash) and hit "OK" and then make sure to save your project (File|Save or control-S).  You will see the "*" go away in the title bar when saved.

Now you can exit the Diamond Programmer and run FleaFPGA-JTAG and select the ".XCF" project file you saved.

At this point you probably want to make sure your FleaFPGA board is connected to your PC.  It is recommended to use a USB hub for the FleaFPGA board for best speed (either powered or un-powered is fine).  This doesn't matter much for fast SRAM programming, but does help Flash programming or (especially) if you are doing a slow verify operation (which can be extremely slow without a hub).

The first time you run FleaFPGA-JTAG (or when the configuration changes), you will be prompted to select the Lattice "ddtcmd" utility (which FleaFPGA-JTAG uses to process the FPGA bitstream).  This should have been installed when you installed Lattice Diamond programmer (or full suite).

When an ".XCF" file is processed it will produce a ".VME" file which is used to configure the FleaFPGA board.  One a ".VME" file has been created, you can also select it directly to program a board (so this can be considered a "binary bitstream" if you wanted to distribute your design to other FleaFPGA users).

It is also possible to configure Lattice Diamond to associate ".XCF" files with FleaFPGA-JTAG and then it is very convenient to double-click on the XCF file in your Diamond project to program the FleaFPGA board.  To do this add a Diamond Programmer ".XCF" file and then right-click on it to select "Open with..." (and use "Open with..." to invoke Diamond programmer when desired if FleaFPGA-JTAG is set to the default).  This process is outlined in more detail in the FleaFPGA Quickstart Guide.

You can select "Modify FleaFPGA-JTAG Setting" from the "FleaFPGA-JTAG" start menu entry to edit a file with advanced configuration settings for FleaFPGA-JTAG.  When editing this file avoid adding any extra tabs or quotes as the options are read "as is" directly by FleaFPGA-JTAG utility (spaces and all).

The advanced configuration settings available are:

FleaFPGA-JTAG: JTAG utility for FleaFPGA using Lattice FPGA.

Usage: FleaFPGA-JTAG [-f | -s | -t] [-l] [-v] [-p] [-m <desc>] [-c <path>]
                     [ <XCF_file | VME_file> ... ]

  -f        = Fast FTDI bit-bang JTAG with CBUS read
               (RTS=TDI, CB1=TDO, TX=TMS, CTS=TCK)
  -s        = Prototype board FTDI all CBUS JTAG
               (CB0=TDI, CB1=TDO, CB2=TMS, CB3=TCK)
  -t        = Test JTAG (fake JTAG with no actual hardware)
  -c <path> = Full path to Lattice Diamond Programmer "ddtcmd" utility
               (used for automatic XCF processing to generate VME JTAG files)
  -l        = List information about all available FTDI devices
  -m <desc> = Search for FleaFPGA FTDI device description <desc> or #<serial>
  -p        = Paranoia mode (slower conservative settings for troubleshooting)
  -v        = Verbose output (show all JTAG output as ">" and input as "=")
  -w        = Write current options to settings file (new defaults)
  -?        = This help text
  
It is unlikely users will have need for the options "-f" (the default), "-s" or "-t" as these were used during development.

The "-c" option will be prompted for if not present (and then written back to this file).

The "-l" option can be useful to see what FTDI devices are detected on your system.

The "-m" option can be used to specify a specific board if you have multiple FleaFPGA boards (or other FTDI devices detected).

The "-p" mode slows down the bit-rate and extends timeout options for trouble-shooting (but likely not needed).

The "-v" option will "spam" you with all the details of the JTAG communication. :-)

The "-w" option can be used when invoking FleaFPGA-JTAG from the command line and causes it to write the selected options to the default options file.

The "-?" option (or any unrecognized option) will produce the list above.

Enjoy using FleaFPGA-JTAG with your FleaFPGA board. - Xark
