# Blinky LED with interrupts
with store parameters into built-in eeprom

![pict01.](/assets/img/img_20210409_01.png "experimental circuit")

## Content

- eeprom/ - short code for flash built-in eeprom
- main/ - main code

## Instructions

To flash eeprom:
```
make eeprom_flash
```

To flash all:
```
make install
```

You need Linux, AVRDude, ArduinoISP and avr-gcc enviroment. I use my own Dev Board with ATtiny2313A and my custom AVRDude config file(for ATtiny2313A)

sq7eqe op pawel  
Radio Amateur, Modeller, Hackers  
Master of Science in Technical Physics  
