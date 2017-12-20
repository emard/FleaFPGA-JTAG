# cygwin makefile for FleaFPGA-JTAG utility

CC	= gcc
CFLAGS	= -O2 -g -Wall -Wshadow -Wextra -lftdi1 -lusb-1.0
# LDFLAGS = -lftdi1
#CFLAGS += -DVME_DEBUG 

INC = hardware.h vmopcode.h Makefile
SRC = ispvm_ui.c ivm_core.c hardware.c
OBJ = $(SRC:.c=.o)

.PHONY: all clean

FleaFPGA-JTAG: $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@ $(CFLAGS)

#	strip -S $@

$(OBJ): $(INC)

all: clean FleaFPGA-JTAG

clean:
	rm -f ./FleaFPGA-JTAG *.o
