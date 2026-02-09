#ifndef KEYPAD_H
#define KEYPAD_H
#include "iomap.h"
#include "gpio.h"
int keypad_scan(Port output , Port input);
// make sure inputs are pulled down as rows.
// (F,K) , K is input and pulled down and F as output that sends 0001,..,1000.
int k_val[4][4]= {{1,2,3,'+'},{4,5,6,'-'},{7,8,9,'*'},{'/',0,'%','='}};

int keypad_scan(Port output , Port input){

  for(int col = 0; col < 4; col++){
    out_port(output,1<<col);
    delayt(0.05);   
    int row_bits = in_port(input) & 0x0F;   
    if(row_bits){
      delayt(0.2);  
      row_bits = in_port(input)  & 0x0F;
      int row = -1;
      if(row_bits == 1) row = 0;
      else if(row_bits == 2) row = 1;
      else if(row_bits == 4) row = 2;
      else if(row_bits == 8) row = 3;
      if(row != -1){
        while(in_port(input) & 0x0F);  
        return k_val[col][row];
      }
    }
  }

  return -1;
}
#endif