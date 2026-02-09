#include "keypad.h"

void setup() {
  init_b(0xFF);   // 7-seg
  init_f(0x0F);   // columns
  init_k(0x00);   // rows 
  init_a(0x0F);
}

void loop() {

  int result = calculator();
  disp_4dig_cal(result);
  
}
