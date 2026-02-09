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

int calculator (){
  int c;
  int n1 = 0, n2 = 0;
  char op = 0;

  while(1){
    c = keypad_scan();

    if(c == -1) continue;

    if(c >= 0 && c <= 9){
      n1 = n1 * 10 + c;
      out_b(disp_char(c));   
    }

    if(c == '+'){
      op = '+';
      break;
    }
    if(c == '-'){
      op = '-';
      break;
    }
    if(c == '*'){
      op = '*';
      break;
    }

    if(c=='/'){
      op='/';
      break;
    }

    if(c=='%'){
      op='%';
      break;
    }
  }

  while(1){
    c = keypad_scan();

    if(c == -1) continue;

    if(c >= 0 && c <= 9){
      n2 = n2 * 10 + c;
      out_b(disp_char(c));
    }

    if(c == '='){
      break;
    }
    
  }

  int result = 0;

  if(op == '+')
    result = n1 + n2;
  if(op == '-')
    result = n1 - n2;
  if(op == '*')
    result = n1 * n2;
  if(op=='/')
    result = n1 / n2 ;
  if(op=='%')
    result = n1 % n2 ;
  return result;  
}
disp_4dig_cal(int result){
  if(result >= 0 && result <= 9999){
    long i =0 ;
    while(i<100000){
      out_a(0xFF);
      out_b(disp_char(result%10));
      out_a(0xFE);
      delay1(0.05);

      out_a(0xFF);
      out_b(disp_char((result/10)%10));
      out_a(0xFD);
      delay1(0.05); 
      
      out_a(0xFF);
      out_b(disp_char((result/100)%10));
      out_a(0xFB);
      delay1(0.05); 
      
      out_a(0xFF);
      out_b(disp_char(result/1000));
      out_a(0xF7);
      delay1(0.05); 
      i++;
    }
  }
  if(result> 9999){
    long i =0 ;
    char s = 0x79;
    while(i<100000){
      out_a(0xFF);
      out_b(s);
      out_a(0xFE);
      delay1(0.05);

      out_a(0xFF);
      out_b(s);
      out_a(0xFD);
      delay1(0.05); 
      
      out_a(0xFF);
      out_b(s);
      out_a(0xFB);
      delay1(0.05); 
      
      out_a(0xFF);
      out_b(s);
      out_a(0xF7);
      delay1(0.05); 
      i++;
    }
  }
  
  
}
