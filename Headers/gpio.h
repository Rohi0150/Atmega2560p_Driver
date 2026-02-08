#include "iomap.h"

volatile char * getregister(Port port , REG reg);
void init_port(Port port , MODE mode);
void init_pin(Port port , MODE mode , char pin);
void out_port(Port port , char bits );
void out_pin(Port port , char pin, STATUS HoL);
char in_port(Port port);
char in_pin(Port port ,char pin);

volatile char * getregister(Port port , REG reg){
  unsigned int base_addr [11]={0x20,0x23,0x26,0x29,0x2C,0x2F,0x32,0x100,0x103,0x106,0x10A};
  return (volatile char *)(base_addr[port]+reg);
}

void init_port(Port port , MODE mode){
  volatile char * dir_reg =  getregister(port,DIR);
  if(mode == OUT) { *dir_reg = 0xFF;}
  else *dir_reg =0x00;
}

void init_pin(Port port , MODE mode , char pin){
  volatile char * dir_reg =  getregister(port,DIR);
  if(mode == OUT) {*dir_reg |=(1<<pin);}
  else *dir_reg &= ~(1<<pin);
}
void out_port(Port port , char bits ){
  volatile char * port_reg = getregister(port,PORT);
  *port_reg = bits;
}
void out_pin(Port port , char pin, STATUS HoL){
  volatile char * pin_reg = getregister(port,PORT);
  if(HoL == high) *pin_reg |=(1<<pin);
  else *pin_reg &= ~(1<<pin);
}
char in_port(Port port){
  volatile char * pin_reg = getregister(port,PIN);
  return *pin_reg;
}
char in_pin(Port port ,char pin){
  volatile char * pin_reg = getregister(port,PIN);
  if(*pin_reg & (1<<pin)) return 1 ;
  return 0;
}
void delayt(float x){
  for(volatile int i =0 ;i<x*20000;i++) ;
}