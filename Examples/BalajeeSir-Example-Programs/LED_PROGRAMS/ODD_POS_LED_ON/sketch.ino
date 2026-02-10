#include "portk.h"
void setup() {
  // put your setup code here, to run once:
  init();
}

void loop() {
  // put your main code here, to run repeatedly:
  char x;
  x= 0x55; //A15->MSB ,A8->LSB;
  out(x);
}
