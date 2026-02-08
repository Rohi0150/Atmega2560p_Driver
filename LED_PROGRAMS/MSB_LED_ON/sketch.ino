#include "portd.h"
void setup() {
  // put your setup code here, to run once:
  init();
}

void loop() {
  // put your main code here, to run repeatedly:
  char * x;
  x = 0x80; // b -> 1000 0000 (Msb is on)
  out(x);
}
