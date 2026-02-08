void init(){
  volatile char * j_dir = (volatile char *)0x104;
  *j_dir = 0x01;
}
void out(char s){
  volatile char * j_port = (volatile char * )0x105;
  *j_port = s;
}
void delay1(int x){
  for ( volatile long  i =0 ;i<(x*250000);i++){
    ;
  }
}