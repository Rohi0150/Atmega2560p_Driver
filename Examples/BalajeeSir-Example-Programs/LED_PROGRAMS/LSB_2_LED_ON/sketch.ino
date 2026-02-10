#include "porth.h"
void setup() {
  // put your setup code here, to run once:
  init();
}

void loop() {
  // put your main code here, to run repeatedly:
  char *x;
  x = 0x03; // b-> 0000 0011 (2 LSB -> 2LED)
  out(x);
}
