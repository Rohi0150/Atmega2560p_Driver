#include "keypad.h"
void setup() {
  // put your setup code here, to run once:
  init_a(0xFF);
  init_f(0x00);
  init_k(0x00);
  init_c(0xFF);
}
volatile char m=0 ,n=0 ;
void loop() {
  // put your main code here, to run repeatedly:
  for (int i =0 ;i<4 ;i++){
      m=0 ; n=0 ;
      out_f (1<<i);
      volatile char y = in_k();
      out_a(y);
      m =y ;
      if(y!=0){
        out_c(1<<i);
        n = 1<<i ;
        delay1(1);
        break;
      }
      f_port = 0x00;
      c_port = 0x00;
  }

  if(m>=0 && n>=0 ){
    volatile char r = disp_val7(n,m);
    out_b(r);
    delay1(1);
  }
  else {
    out_b(0x00);
  }
}