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


DEVICE_PROG   = t2313a 
DEVICE     = attiny2313a
CLOCK      = 1000000
PROGRAMMER = -c avrisp -P /dev/ttyUSB0 -b 19200 
OBJECTS    = main.o 
FUSES      = -U lfuse:w:0x64:m -U hfuse:w:0xdf:m -U efuse:w:0xff:m
PRG    = blink-led
TARGET     = $(PRG).elf

######################################################################
######################################################################

# Tune the lines below only if you know what you are doing:

AVRDUDE = avrdude $(PROGRAMMER) -p $(DEVICE_PROG)
COMPILE = avr-gcc -Wall -Os -DF_CPU=$(CLOCK) -mmcu=$(DEVICE)
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
AVRSIZE = avr-size

# symbolic targets:
all:	$(PRG).hex eeprom


# file targets:
$(PRG).elf: $(OBJECTS)
	$(COMPILE) -o $(TARGET) $(OBJECTS)

$(PRG).hex: $(PRG).elf
	rm -f $(PRG).hex
	$(OBJCOPY) -j .text -j .data -O ihex $(TARGET) $(PRG).hex

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

eeprom: ehex ebin esrec

ehex:  $(PRG)_eeprom.eep
ebin:  $(PRG)_eeprom.bin
esrec: $(PRG)_eeprom.srec

%_eeprom.eep: %.elf
	@echo
	@echo $(MSG_EEPROM) $@
	$(OBJCOPY) -j .eeprom --set-section-flags=.eeprom="alloc,load" \
	--change-section-lma .eeprom=0 --no-change-warnings -O ihex $< $@ || exit 0

%_eeprom.srec: %.elf
	@echo
	@echo $(MSG_EEPROM) $@
	$(OBJCOPY) -j .eeprom --set-section-flags=.eeprom="alloc,load" \
	--change-section-lma .eeprom=0 --no-change-warnings -O srec $< $@ || exit 0

%_eeprom.bin: %.elf
	@echo
	@echo $(MSG_EEPROM) $@
	$(OBJCOPY) -j .eeprom --set-section-flags=.eeprom="alloc,load" \
	--change-section-lma .eeprom=0 --no-change-warnings -O binary $< $@ || exit 0

lst:  $(PRG).lst

%.lst: %.elf
	$(OBJDUMP) -h -S $< > $@

text: hex bin srec

hex:  $(PRG).hex
bin:  $(PRG).bin
srec: $(PRG).srec

%.hex: %.elf
	$(OBJCOPY) -j .text -j .data -O ihex $< $@

%.srec: %.elf
	$(OBJCOPY) -j .text -j .data -O srec $< $@

%.bin: %.elf
	$(OBJCOPY) -j .text -j .data -O binary $< $@
	

flash:	all
	$(AVRDUDE) -U flash:w:$(PRG).hex:i

eeprom_flash: 
	$(AVRDUDE) -U eeprom:w:$(PRG)_eeprom.eep

fuse:
	$(AVRDUDE) $(FUSES)

install: flash eeprom_flash fuse

clean:	
	rm -f *.o
	rm -f *.hex
	rm -f *.elf
	rm -f *.eep
	rm -f *.srec
	rm -f *.bin


# Targets for code debugging and analysis:
disasm:	$(TARGET)
	$(OBJDUMP) -d $(TARGET)

size: $(TARGET)
	@echo
	@echo $(CLOCK) Hz operation configured.
	$(AVRSIZE) -C --mcu=$(DEVICE) $(TARGET)	

