#include "keypad.h"
void setup() {
  // put your setup code here, to run once:
  init_b(0xFF);
  init_a(0xFF);
}

void loop() {
  // put your main code here, to run repeatedly.
  volatile int i = 0 ;
  while (i<9999){
  char s = disp_char(i/1000);
  out_a(0xFF);        
  out_b(s);
  out_a(0xFE);        
  delay1(0.05);
  
  s = disp_char((i/100)%10);
  out_a(0xFF);        
  out_b(s);
  out_a(0xFD);
  delay1(0.1);

  s = disp_char((i/10)%10);
  out_a(0xFF);        
  out_b(s);
  out_a(0xFB);
  delay1(0.2); 

  s = disp_char(i%10);
  out_a(0xFF);       
  out_b(s);
  out_a(0xF7);
  delay1(0.2); 
  i++;
   }
}