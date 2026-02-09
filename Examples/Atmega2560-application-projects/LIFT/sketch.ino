#include "head.h"
void setup() {
  // put your setup code here, to run once:
  init_a(0xFF);
  init_b(0x00);
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile char x = b_in();
  volatile char y = disp_valc(x);
  static int a = 0 ;
  a_out(disp_valc(a));
  if(x==0x01){
    if(a>0){
     while(a>0){
      a--;
      y = disp_valc(a);
      a_out(y);
      delay1(1);
     }
    }
    a=0;
    y = disp_valc(a);
    a_out(y);
    delay1(1);
  }
  else if(x==0x02){
    while(a<1){
      a++;
      y = disp_valc(a);
      a_out(y);
      delay1(1);
    }
    while(a>1){
      a--;
      y = disp_valc(a);
      a_out(y);
      delay1(1);
    }
    if(a==1){
      y = disp_valc(a);
      a_out(y);
    }
    a=1;
  }
  else if(x==0x04){
    while(a<2){
      a++;
      y = disp_valc(a);
      a_out(y);
      delay1(1);
    }
    while(a>2){
      a--;
      y = disp_valc(a);
      a_out(y);
      delay1(1);
    }
    if(a==2){
      y = disp_valc(a);
      a_out(y);
      delay1(1);
    }
    a=2;
  }
  else if(x==0x08){
    while(a<3){
      a++;
      y = disp_valc(a);
      a_out(y);
      delay1(1);
    }
    if(a==3){
      y = disp_valc(a);
      a_out(y);
      delay1(1);
    }
    a=3;
  }
}
