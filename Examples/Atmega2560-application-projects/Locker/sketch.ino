#include "7seg.h"
void setup() {

  init_a(0x0F);
  init_b(0xFF);
  init_f(0x0f);
  init_k(0x00);
}

void loop() {
  
  int pass = 1234; //1234 is the password it will print true 
  int digit = password();
  if(digit==pass) 
    disp_pass();
  
  else 
    disp_fpass(); // XXXX if the password is wrong.
  
}
