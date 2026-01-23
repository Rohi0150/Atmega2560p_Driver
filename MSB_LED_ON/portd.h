void init(){
  volatile char *portd_dir= (volatile char *)0x2A;
  *portd_dir = 0x80;
}
void out(char s){
  volatile char *portd_port =(volatile char *)0x2B;
  *portd_port = s;
}