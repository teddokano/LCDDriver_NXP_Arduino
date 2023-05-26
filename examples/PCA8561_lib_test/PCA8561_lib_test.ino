/** PCA8561 operation sample
 *
 *  Code for test features of this library. 
 *
 *  @author  Tedd OKANO
 *
 *  Released under the MIT license License
 *
 *  About PCA8561:
 *    https://www.nxp.com/products/peripherals-and-logic/lcd-drivers/lcd-segment-drivers/automotive-18-x-4-lcd-segment-driver:PCA8561
 */


#include <PCA8561.h>

PCA8561 lcdd;

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;

  Wire.begin();
  lcdd.begin();  // This is necessary to enable display; device goes into power-on mode

  Serial.println("\r***** Hello, PCA8561! *****");
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
  const int size = 12;
  uint8_t test_bf[2][size];

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < size; j++)
      test_bf[i][j] = (i) ? 0xFF : 0x00;

  for (int i = 0; i < 6; i++) {
    lcdd.reg_w(PCA8561::COM0_07_00, test_bf[i % 2], size);
    delay(200);
  }
}