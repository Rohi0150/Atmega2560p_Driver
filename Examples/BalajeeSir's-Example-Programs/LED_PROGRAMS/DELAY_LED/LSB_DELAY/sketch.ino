#include "portj.h"
void setup() {
  // put your setup code here, to run once:
  init();
}

void loop() {
  // put your main code here, to run repeatedly:
  char x ;
  x=0x01;
  out(x);
  delay1(1);
  x=0x00;
  out(x);
  delay1(1);
}
