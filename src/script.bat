@echo off
cmake -S . -B build -G Ninja -DCMAKE_TOOLCHAIN_FILE=toolchain-avr.cmake
cmake --build build
avrdude -C avrdude.conf -c arduino -p m328p -P COM3 -b 115200 -U flash:w:build/arduino.hex

pause
