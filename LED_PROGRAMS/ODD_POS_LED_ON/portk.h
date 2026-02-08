void init(){
  volatile char *k_dir = (volatile char *)0x107;
  *k_dir = 0x55;
}
void out(char s){
  volatile char *k_port = (volatile char *)0x108;
  *k_port = s;
}