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
int k_val[4][4]= {{1,2,3,'+'},{4,5,6,'-'},{7,8,9,'*'},{'/',0,'%','='}};
int keypad_scan(){

  for(int col = 0; col < 4; col++){

    out_f(1 << col);

    delay1(0.05);   

    int row_bits = in_k() & 0x0F;   

    if(row_bits){

      delay1(0.2);  

      row_bits = in_k() & 0x0F;

      int row = -1;

      if(row_bits == 1) row = 0;
      else if(row_bits == 2) row = 1;
      else if(row_bits == 4) row = 2;
      else if(row_bits == 8) row = 3;

      if(row != -1){

        while(in_k() & 0x0F);  

        return k_val[col][row];
      }
    }
  }

  return -1;
}
int password(){
  int c , n1 =0 ;
  while(1){
    c = keypad_scan();
    if(c==-1) continue ;
    if(c>=0 && c <=9) {
      n1 = n1 *10 +c;
      out_a(0xFF);
      out_b(disp_char(n1%10));
      out_a(0xFE);
    }
    if(c=='='){
      break;
    }
  }
  return n1;
}
void disp_pass(){
  volatile int i =0 ;
  while (i<500){
    out_a(0xFF);
    out_b(0x31);
    out_a(0XF7);
    delay1(0.05);
    out_a(0xFF);
    out_b(0x50);
    out_a(0XFb);
    delay1(0.05);
    out_a(0xFF);
    out_b(0x3E);
    out_a(0XFd);
    delay1(0.05);
    out_a(0xFF);
    out_b(0x79);
    out_a(0XFE);
    delay1(0.05);
    i++;
  }
  out_a(0xFF);
}
void disp_fpass(){
  volatile int i =0 ;
  int c =0 ;
  while (i<50){
    out_a(0xFF);
    out_b(0x76);
    out_a(0XF7);
    delay1(0.05);
    out_a(0xFF);
    out_b(0x76);
    out_a(0XFb);
    delay1(0.05);
    out_a(0xFF);
    out_b(0x76);
    out_a(0XFd);
    delay1(0.05);
    out_a(0xFF);
    out_b(0x76);
    out_a(0XFe);
    delay1(0.05);
    i++;
  }
  out_a(0xFF);
}