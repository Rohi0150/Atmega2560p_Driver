void init(){
  volatile char * l_dir = (volatile char *) 0x10A;
  *l_dir = 0XAA;
}
void out(char s){
  volatile char * l_port = (volatile char *)0x10B;
  *l_port=s;
}