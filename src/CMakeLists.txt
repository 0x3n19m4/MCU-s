cmake_minimum_required(VERSION 3.21)
project(arduino_embedded C)

add_executable(arduino.elf src/main.c)

target_compile_options(arduino.elf PRIVATE -Wall -Wextra)

add_custom_command(TARGET arduino.elf POST_BUILD 
    COMMAND ${CMAKE_OBJCOPY} -O ihex arduino.elf arduino.hex
    COMMAND ${CMAKE_SIZE} arduino.elf
)