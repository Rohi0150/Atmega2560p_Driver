#ifndef SEG7_H
#define SEG7_H


char disp_char_c(int x); 
// Returns 7-seg data for Common Cathode (COM -> GND) 
char disp_char_a(int x);
// Returns 7-seg data for Common Anode (COM -> VCC)
void disp_1dig_val(Port port , int result); 
// Display a Value in 7seg ( 1Byte from a Port).
// eg : (A,5) -> 5 displays on 7seg.
void disp_2dig_val(Port port , Port select ,int result);
// Display a Value in 7seg ( 1Byte from a Port and select as selection line).
// eg : (A,B,25) -> 25 displays on 2 digit 7seg.
void disp_4dig_val(Port port , Port select ,int result);
// Display a Value in 7seg ( 1Byte from a Port and select as selection line). 
//eg : (A,B,2560) -> 2560 displays on 4 digit 7seg.

char SEG7[10]={0x3F,0x06, 0x5B, 0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

char disp_char_c(int x){
  return SEG7[x];
}
char disp_char_a(int x){
  return (~SEG7[x]);
}
void disp_1dig_val(Port port ,int result){
  if(result>=0 && result<=9){
    out_port(port,disp_char_c(result%10));
    delayt(0.05);
  }
}
void disp_2dig_val(Port port , Port select ,int result){
  if(result>=0 && result<=99){
    out_port(select,0xFF);
    out_port(port,disp_char_c(result%10));
    out_port(select,0xFE);
    delayt(0.05);

    out_port(select,0xFF);
    out_port(port,disp_char_c((result/10)%10));
    out_port(select,0xFD);
    delayt(0.05);
    out_port(select,0xFF);
    }
}

void disp_4dig_val(Port port , Port select ,int result){
  if(result >= 0 && result <= 9999){
    
    out_port(select,0xFF);
    out_port(port,disp_char_c(result%10));
    out_port(select,0xFE);
    delayt(0.05);

    out_port(select,0xFF);
    out_port(port,disp_char_c((result/10)%10));
    out_port(select,0xFD);
    delayt(0.05);
      
    out_port(select,0xFF);
    out_port(port,disp_char_c((result/100)%10));
    out_port(select,0xFB);
    delayt(0.05);
      
    out_port(select,0xFF);
    out_port(port,disp_char_c(result/1000));
    out_port(select,0xF7);
    delayt(0.05);
    out_port(select,0xFF);
  }
}
#endif