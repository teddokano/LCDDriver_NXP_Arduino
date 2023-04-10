/** PCA8561 operation sample
 *  
 */


#include "LCDDriver_NXP.h"

PCA8561 lcdd;

void setup() {
  Serial.begin(9600);
  Serial.println("\r***** Hello, PCA8561! *****");

  Wire.begin();

  uint8_t black[12] = { 0xFF };
  uint8_t white[12] = { 0x00 };
  lcdd.reg_w(PCA8561::Display_ctrl_1, 0x01);
  lcdd.reg_w(PCA8561::COM0_07_00, black, sizeof(black));
  lcdd.reg_w(PCA8561::COM0_07_00, white, sizeof(white));
}

void loop() {

#if 1
  Serial.println("A");
  lcdd.putch('A');
  delay(200);
  lcdd.putch('B');
  delay(200);
  lcdd.putch('C');
  delay(200);
  lcdd.putch('D');
  delay(200);
  lcdd.putch('E');
  delay(200);
  lcdd.putch('F');
  delay(200);
  lcdd.putch('G');
  delay(200);
#endif
  uint8_t black[12] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, };
  uint8_t white[12] = { 0x00 };

  lcdd.reg_w(PCA8561::COM0_07_00, black, sizeof(black));
  delay(200);
  lcdd.reg_w(PCA8561::COM0_07_00, white, sizeof(white));
  delay(200);
  lcdd.reg_w(PCA8561::COM0_07_00, black, sizeof(black));
  delay(200);
  lcdd.reg_w(PCA8561::COM0_07_00, white, sizeof(white));
  delay(200);
  lcdd.reg_w(PCA8561::COM0_07_00, black, sizeof(black));
  delay(200);
  lcdd.reg_w(PCA8561::COM0_07_00, white, sizeof(white));
  delay(200);
}
