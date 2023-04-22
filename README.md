# LCDDriver_NXP_Arduino
LCD driver device operation sample code for [Arduino](https://www.arduino.cc) 

> **Note**
This library works with [`I2C_device`](https://github.com/teddokano/I2C_device_Arduino) library together. Please be sure the `I2C_device` library is imported in your environment before trying to build. 

![Boards](https://github.com/teddokano/additional_files/blob/main/LCDDriver_NXP_Arduino/board.jpg)  
_PCA8561AHN-ARD : Arduino® Shield Evaluation Board for LCD driver_

## What is this?
An Arduino library for I²C LCD driver with sample code.  
This library provides simple API to display characters on the LCD.  
Include device name header file (`PCA8561.h`) to use those class libraries. 

With `LCDDriver_NXP_Arduino` library, characters can be shown by next sample code. 
```cpp
#include <LCDDriver.h>

PCA8561 lcdd;

void setup() {
  Wire.begin();
  lcdd.begin();  // This is necessary to enable display; device goes into power-on mode

  lcdd.puts("BEER");
}

void loop() {
}
```

## Supported device
Type#|Header file|Features|Interface|Evaluation board
---|---|---|---|---
[PCA8561](https://www.nxp.com/products/peripherals-and-logic/lcd-drivers/lcd-segment-drivers/automotive-18-x-4-lcd-segment-driver:PCA8561)	|`PCA8561.h`	|18 X 4 LCD Segment Driver	|I²C Fast-mode (400KHz)			|[PCA8561 18 × 4 LCD Segment Driver Arduino® Shield](https://www.nxp.com/design/development-boards/analog-toolbox/arduino-shields-solutions/pca8561-18-4-lcd-segment-driver-arduino-shield:PCA8561AHN-ARD)

# Getting started

Use Library manager in Arduino IDE for easy install

# What's inside?

## Examples
Examples are provided as scketch files.

### How to use?

After library install, Choose menu on Arduino-IDE: `File`→`Examples`→`LCDDrivers_NXP_Arduino`→ **sketch for your try**

### List of sample code

Sketch|Target|Feature
---|---|---
PCA8561_simple			|PCA8561	|**Simple** sample for just showing "TEST" on LCD
PCA8561_string_scroll	|PCA8561	|Shows **string scrolling** feature
PCA8561_lib_test		|PCA8561	|Test code for **all library features**

# Document

For details of the library, please find descriptions in [this document](https://teddokano.github.io/LCDDriver_NXP_Arduino/annotated.html).

## Related libraries
Library|Feature|Target devices|Required library
---|---|---|---
[GPIO_NXP_Arduino](https://github.com/teddokano/GPIO_NXP_Arduino)				|LED driver libraries				|PCAL6408A, PCAL6416A, PCAL6524, PCAL6534	|[I2C_device_Arduino](https://github.com/teddokano/I2C_device_Arduino)
[LEDDriver_NXP_Arduino](https://github.com/teddokano/LEDDriver_NXP_Arduino)		|LED driver libraries				|PCA9955B, PCA9956B, PCA9957	|[I2C_device_Arduino](https://github.com/teddokano/I2C_device_Arduino)
[RTC_NXP_Arduino](https://github.com/teddokano/RTC_NXP_Arduino)					|RTC driver libraries				|PCF2131, PCF85063A				|[I2C_device_Arduino](https://github.com/teddokano/I2C_device_Arduino)
[TempSensor_NXP_Arduino](https://github.com/teddokano/TempSensor_NXP_Arduino)	|Temperature sensor libraries		|LM75B, PCT2075, P3T1085		|[I2C_device_Arduino](https://github.com/teddokano/I2C_device_Arduino)
[I2C_device_Arduino](https://github.com/teddokano/I2C_device_Arduino)			|Base library for I²C operations	|none (can be applied as base class for all I²C targets)|---
