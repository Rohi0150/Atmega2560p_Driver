void init(){
  volatile char * f_dir = (volatile char *)0x30;
  *f_dir = 0xFF;
}
void out(char s){
  volatile char *f_port = (volatile char *)0x31;
  *f_port=s;
}