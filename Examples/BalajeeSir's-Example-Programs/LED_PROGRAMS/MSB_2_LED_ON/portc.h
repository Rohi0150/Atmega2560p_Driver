void init(){
  volatile char* portc_dir = (volatile char *)0x27;
  *portc_dir = 0xC0; // b-> 1100 0000
}
void out(char s){
  volatile char* portc_data = (volatile char *)0x28;
  *portc_data = s;
}