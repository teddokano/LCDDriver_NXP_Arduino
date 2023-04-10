/** PCA8561 operation sample
 *  
 */


#include "LCDDriver.h"

PCA8561 lcdd;


void setup() {
  Serial.begin(9600);
  Serial.println("\r***** Hello, PCA8561! *****");

  Wire.begin();

  lcdd.begin();
}


void loop() {
  test_putchar();
  test_puts();
  test_puts_with_delay();
  test_COM_SEG_access();
  test_register_access();
}

void test_putchar(void) {
  for (int i = 0; i < 10; i++) {
    lcdd.putchar(i + '0');
    delay(200);
  }

  lcdd.clear();
}

void test_puts(void) {
  const char* test_str[4] = {
    "A\n",
    "BB\n",
    "CCC\n",
    "DDDD\n",
  };

  for (int i = 0; i < 4; i++) {
    lcdd.puts(test_str[i]);
    delay(500);
  }
}

void test_puts_with_delay(void) {
  lcdd.puts("    ABDCEFGHIJKLMNOPQRSTUVWXYZ 0123456789    ", 100);
}

void test_COM_SEG_access(void) {
  for (int b = 1; b < 5; b++) {
    bool on_off = b % 2;
    for (int c = 0; c < PCA8561::N_COM; c++) {
      for (int s = 0; s < PCA8561::N_SEG; s++) {
        lcdd.com_seg(c, s, on_off);
        delay(10);
      }
    }
  }
}

void test_register_access(void) {
  uint8_t fill[12];
  for (int i = 0; i < sizeof(fill); i++) fill[i] = 0xff;
  uint8_t blank[12] = { 0x00 };

  lcdd.reg_w(PCA8561::COM0_07_00, fill, sizeof(fill));
  delay(200);
  lcdd.reg_w(PCA8561::COM0_07_00, blank, sizeof(blank));
  delay(200);
  lcdd.reg_w(PCA8561::COM0_07_00, fill, sizeof(fill));
  delay(200);
  lcdd.reg_w(PCA8561::COM0_07_00, blank, sizeof(blank));
  delay(200);
  lcdd.reg_w(PCA8561::COM0_07_00, fill, sizeof(fill));
  delay(200);
  lcdd.reg_w(PCA8561::COM0_07_00, blank, sizeof(blank));
  delay(200);
}