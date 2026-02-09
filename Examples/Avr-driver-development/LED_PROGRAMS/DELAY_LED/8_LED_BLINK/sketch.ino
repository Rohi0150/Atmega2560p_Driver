#include "porta.h"
void setup() {
  // put your setup code here, to run once:
  init();
}

void loop() {
  // put your main code here, to run repeatedly:
  char s;
  s= 0XFF;
  out(s);
  delay1(1);
  s= 0x00;
  out(s);
  delay1(1);
}
