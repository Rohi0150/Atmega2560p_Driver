void init(){
  volatile char* b_dir = (volatile char *)0x24;
  *b_dir = 0xF0;
}
void port(char s){
  volatile char* b_port = (volatile char *)0x25;
  *b_port = s;
}