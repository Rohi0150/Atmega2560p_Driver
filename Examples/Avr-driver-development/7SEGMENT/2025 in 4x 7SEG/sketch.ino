#include "7seg.h"
void setup() {
  // put your setup code here, to run once:
  init_a(0xFF);
  init_b(0xFF);
  init_f(0xFF);
  init_k(0xFF);
}

void loop() {
  // put your main code here, to run repeatedly:
  out_a(disp_valc(5));
  init_a(0x00);
  out_a(0x00);
  out_b(disp_valc(2));
  init_b(0x00);
  out_b(0x00);
  out_k(disp_valc(0));
  init_k(0x00);
  out_k(0x00);
  out_f(disp_valc(2));
  init_f(0x00);
  out_f(0x00);
}
