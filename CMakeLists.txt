cmake_minimum_required(VERSION 2.8.10)
project(teensy-core C)

# Example flags that should allow us to compile teensy-core for the teensy3
#if (NOT CMAKE_C_FLAGS)
#  message("* Setting up default CFLAGS for the teensy-core")
#set(TEENSY3_TARGET "arm-none-eabi")
#set(TEENSY3_FLAGS "--target=${TEENSY3_TARGET} -mcpu=cortex-m4 -mthumb -D__MK20DX128__ -DF_CPU=48000000" CACHE STRING "Teensy3 specific flags")
##set(TEENSY3_ARDUINO_FLAGS "-DARDUIO=105 -DTEENSYDUINO=118")
#set(COMMON_FLAGS "-ffunction-sections -fdata-sections -fcolor-diagnostics -fno-exceptions ${TEENSY3_FLAGS}" CACHE STRING "Common compilation flags")
#set(CMAKE_C_FLAGS "-std=c11 ${COMMON_FLAGS} ${CMAKE_C_FLAGS}")
#set(CMAKE_SIZEOF_VOID_P 4)
#endif()

include_directories(include)
add_definitions(-fno-builtin -nostdinc)

add_library(teensy-core
  mk20dx128.c
  )

# Special-case this crap because cmake hates us and has a broken
# add_library(... OBJECT ...), which doesn't allow us to install that
# object file
add_library(mk20dx128-rt OBJECT
  mk20dx128.c)
# Hackity-hack-hack because cmake
install(FILES
  "${CMAKE_BINARY_DIR}/CMakeFiles/mk20dx128-rt.dir/mk20dx128.c.obj"
  RENAME mk20dx128.o
  DESTINATION lib)

install(TARGETS teensy-core
  ARCHIVE DESTINATION lib)
# Install the linker script to $prefix/lib, for now
install(FILES
  mk20dx128.ld
  DESTINATION lib)
install(DIRECTORY include/
  DESTINATION include
  FILES_MATCHING
  PATTERN "*.h")
  #include/mk20dx128.h
  #include/mk20dx128-compat.h
  #include/core_cm4.h
  #include/core_cm4_simd.h
