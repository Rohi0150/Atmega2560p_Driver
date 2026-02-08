void init(){
  volatile char * e_dir = (volatile char * ) 0x2D;
  * e_dir =  0x3A;  // 0b0011 1010;
}
void out(char s){
  volatile char * e_port = (volatile char *) 0x2E;
  * e_port = s;
}