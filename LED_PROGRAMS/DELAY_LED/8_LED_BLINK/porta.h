void init(){
  volatile char * a_dir = (volatile char *)0x21;
  *a_dir = 0XFF;
}
void out (char s){
  volatile char * a_dir =(volatile char *)0x22;
  *a_dir = s;
}
void delay1(int x){
  for(volatile long int i =0 ; i< (x*250000);i++){
    ;
  }
}