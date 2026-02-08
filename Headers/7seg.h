#include "gpio.h" 
char disp_char_c(int x);
char disp_char_a(int x);
void disp_4dig_val(Port port , Port select ,int result);

char SEG7[10]={0x3F,0x06, 0x5B, 0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

char disp_char_c(int x){
  return SEG7[x];
}
char disp_char_a(int x){
  return (~SEG7[x]);
}
void disp_4dig_val(Port port , Port select ,int result){
  if(result >= 0 && result <= 9999){
    
    out_port(port,0xFF);
    out_port(select,disp_char_c(result%10));
    out_port(port,0xFE);
    delayt(0.05);

    out_port(port,0xFF);
    out_port(select,disp_char_c((result/10)%10));
    out_port(port,0xFD);
    delayt(0.05);
      
    out_port(port,0xFF);
    out_port(select,disp_char_c((result/100)%10));
    out_port(port,0xFB);
    delayt(0.05);
      
    out_port(port,0xFF);
    out_port(select,disp_char_c(result/1000));
    out_port(port,0xF7);
    delayt(0.05);
    out_port(port,0xFF);
  }
}