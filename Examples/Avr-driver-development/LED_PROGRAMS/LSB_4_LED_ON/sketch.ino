#include "porta.h"
void setup() {
  // put your setup code here, to run once:
  init();
}

void loop() {
  // put your main code here, to run repeatedly:
  char x;
  x=0x0F;
  port(x);
}
