# Name: Makefile
# Author: Paweł Sobótka
# Copyright: © Paweł Sobótka, 2019-2020 all rights reserved
# License: GNU GPLv3 or later

# DEVICE ....... The AVR device you compile for
# CLOCK ........ Target AVR clock rate in Hertz
# OBJECTS ...... The object files created from your source files. This list is
#                usually the same as the list of source files with suffix ".o".
# PROGRAMMER ... Options to avrdude which define the hardware you use for
#                uploading to the AVR and the interface where this hardware
#                is connected.
# FUSES ........ Parameters for avrdude to flash the fuses appropriately.


DEVICE_PROG   = t2313
DEVICE     = attiny2313a
CLOCK      = 1000000
PROGRAMMER = -c  avrisp -P /dev/ttyACM0 -b 19200
OBJECTS    = blink-led.o 
FUSES      = -U lfuse:w:0x64:m -U hfuse:w:0xdf:m -U efuse:w:0xff:m
PROJECT    = blink-led
TARGET     = $(PROJECT).elf

######################################################################
######################################################################

# Tune the lines below only if you know what you are doing:

AVRDUDE = avrdude $(PROGRAMMER) -p $(DEVICE_PROG)
COMPILE = avr-gcc -Wall -Os -DF_CPU=$(CLOCK) -mmcu=$(DEVICE)

# symbolic targets:
all:	blink-led.hex

.c.o:
	$(COMPILE) -c $< -o $@

.S.o:
	$(COMPILE) -x assembler-with-cpp -c $< -o $@
# "-x assembler-with-cpp" should not be necessary since this is the default
# file type for the .S (with capital S) extension. However, upper case
# characters are not always preserved on Windows. To ensure WinAVR
# compatibility define the file type manually.

.c.s:
	$(COMPILE) -S $< -o $@

flash:	all
	$(AVRDUDE) -U flash:w:$(PROJECT).hex:i

fuse:
	$(AVRDUDE) $(FUSES)

install: flash fuse

clean:	
	rm -f *.o
	rm -f *.hex
	rm -f *.elf

# file targets:
blink-led.elf: $(OBJECTS)
	$(COMPILE) -o $(TARGET) $(OBJECTS)

blink-led.hex: blink-led.elf
	rm -f $(PROJECT).hex
	avr-objcopy -j .text -j .data -O ihex $(TARGET) $(PROJECT).hex
# If you have an EEPROM section, you must also create a hex file for the
# EEPROM and add it to the "flash" target.

# Targets for code debugging and analysis:
disasm:	blink-led.elf
	avr-objdump -d $(TARGET)

size: blink-led.elf
	@echo
	@echo $(CLOCK) Hz operation configured.
	@avr-size -C --mcu=$(DEVICE) $(TARGET)	

