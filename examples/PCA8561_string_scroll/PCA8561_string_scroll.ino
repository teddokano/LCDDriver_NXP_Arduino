/** PCA8561 operation sample
 *
 *  Simple sample for displating "TEST"
 *
 *  @author  Tedd OKANO
 *
 *  Released under the MIT license License
 *
 *  About PCA8561:
 *    https://www.nxp.com/products/peripherals-and-logic/lcd-drivers/lcd-segment-drivers/automotive-18-x-4-lcd-segment-driver:PCA8561
 */


#include <LCDDriver.h>

PCA8561 lcdd;

void setup() {
  Wire.begin();
  lcdd.begin();  // This is necessary to enable display; device goes into power-on mode
}

void loop() {
  lcdd.puts("   0123456789", 150);  // 2nd argument is an option to set scroll speed
}