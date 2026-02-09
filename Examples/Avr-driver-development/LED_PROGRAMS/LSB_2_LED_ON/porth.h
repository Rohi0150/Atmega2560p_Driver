void init(){
  volatile char *porth_dir = (volatile char *)0x101;
  *porth_dir = 0x03;
}
void out(char s){
  volatile char *porth_out = (volatile char *)0x102;
  *porth_out = s;
}