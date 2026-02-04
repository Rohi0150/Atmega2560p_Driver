#define a_port *(volatile char *)0x22
#define a_dir *(volatile char *)0x21
#define b_port *(volatile char *)0x25
#define b_dir *(volatile char *)0x24
#define f_port *(volatile char *)0x31
#define f_dir *(volatile char *)0x30
#define k_in *(volatile char *)0x106
#define k_dir *(volatile char *)0x107
void init_a(char s){
  a_dir = s;
}
void init_b(char s){
  b_dir = s;
}
void init_k(char s){
  k_dir = s;
}
void init_f(char s){
  f_dir = s;
}
void out_a(char s){
  a_port = s;
}
void out_b(char s){
  b_port = s;
}
void out_f(char s){
  f_port = s;
}
char in_k(){
  return k_in;
}
char A[10]={0x3F,0x06, 0x5B, 0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
char disp_char(int x){
  return A[x];
}
void delay1(float x){
  for(volatile int i =0 ;i<x*20000;i++) ; 
}