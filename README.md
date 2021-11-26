

[![Arduino CI](https://github.com/RobTillaart/float16/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/float16/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/float16/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/float16/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/float16/actions/workflows/jsoncheck.yml)
[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/float16/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/float16.svg?maxAge=3600)](https://github.com/RobTillaart/Complex/releases)


# float16

Arduino library to implement float16 data type.


## Description

This **experimental** library defines the float16 (2 byte) data type, including conversion 
function to and from float32 type. It is definitely **work in progress**.

The library implements the **Printable** interface so one can directly print the 
float16 values in any stream e.g. Serial.

The primary usage of the float16 data type is to efficiently store and transport 
a floating point number. As it is only 2 bytes where float and double have typical 
4 and 8, gains can be made at the price of range and precision.


## Specifications


| attribute | value        |              |
|:---------:|:------------:|:------------:|
| Size      | 2 bytes      |              |
| sign      | 1 bit        |              |
| mantissa  | 11 bit       |              |
| exponent  | 4 bit        |              |
| minimum   | 1.0009765625 |  1 + 2^−10   |
| maximum   | 65504        |              |
|           |              |              |


## Interface

See float16.h for a list of functions implemented.

to elaborate


## Notes


#### comparison functions

First version of inequality operations are implemented by converting data to double and compare those. 
The strategy is to get these working first and optionally optimize them later.


## TODO (future)

not in priority order.

- update documentation
- get basic math working (+-*/)
- divide by zero errors.
- f16tof32() + f32tof16()
- rewrite toDouble with bit magic
- isNan()
- isINF()
- abs()
- sgn()


