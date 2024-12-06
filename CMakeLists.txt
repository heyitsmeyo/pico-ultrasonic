

# Specify the minimum CMake version
cmake_minimum_required(VERSION 3.19)

# Set project name and languages, including ASM for assembly support

# Initialize the Raspberry Pi Pico SDK
include(pico_sdk_import.cmake)
project(measure)

# Set project name and languages


# Initialize the Pico SDK
pico_sdk_init()

# Add the executable for the blink project
add_executable(measure
	       ultrasonic.c)

# Link with the Pico standard library (this includes GPIO functionality)
target_link_libraries(measure pico_stdlib)

# Enable additional outputs (like UF2, BIN, and HEX files)
pico_add_extra_outputs(measure)
pico_enable_stdio_usb(measure 1)
