#include "portl.h"
void setup() {
  // put your setup code here, to run once:
  init();
}

void loop() {
  // put your main code here, to run repeatedly:
  char x;
  x=0xAA;
  out(x);
}
