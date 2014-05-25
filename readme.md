teensy-core
===========

Teensy core support libraries for teensy3-toolchain.

This library is designed to be used with https://github.com/filcab/teensy3-toolchain

You may still use this library without that build system, but it might be
best to just get the needed files directly from their source instead of
this repository.

These files will generate the core support library for the teensy3
toolchain. I've based them on the official sources from Paul Stoffregen
(the files are in https://github.com/PaulStoffregen/cores/teensy3), with
minimal changes to make them more standards compliant and minimize
errors/warnings.

The library should have the bare minimum necessary for the teensy3 board
(+ some USB comms stuff, for debugging), with no Arduino support planned.
I might create a library which will contain the minimum required to
support the Arduino, though.


Files were current as of commit: `ce59be18a38119b435d3a439db0b972137e28742`
