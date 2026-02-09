#define a_dir *(volatile char * )0x21
#define a_port *(volatile char * )0x22
#define b_dir *(volatile char *) 0x24
#define b_port *(volatile char *) 0x25
#define f_dir *(volatile char *) 0x30
#define f_port *(volatile char *) 0x31
#define k_dir *(volatile char *) 0x107
#define k_port *(volatile char *) 0x108
void init_a(char s){
  a_dir = s;
}
void init_b(char s){
  b_dir = s;
}
void init_f(char s){
  f_dir = s;
}
void init_k(char s){
  k_dir = s;
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
void out_k(char s){
  k_port = s;
}

char a[10]={0x3F ,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
char disp_char_c(char s){
  if(s>'0'&&s<'9'){
    s=s-48;
    return a[s];
  }
}
char disp_valc(int x){
  if(x==0){
    return 0b00111111;
  }
  else if(x==1){
    return 0b00000110;
  }
  else if(x==2){
    return 0b01011011;
  }
  else if(x==3){
    return 0b01001111;
  }
  else if(x==4){
    return 0b01100110;
  }
  else if(x==5){
    return 0b01101101;
  }
  else if(x==6){
    return 0b01111101;
  }
  else if(x==7){
    return 0b00000111;
  }
  else if(x==8){
    return 0b01111111;
  }
  else if(x==9){
    return 0b01101111;
  }
  return 0;
}
char disp_vala(int x){
  if(x==0){
    return ~0b00111111;
  }
  else if(x==1){
    return ~0b00000110;
  }
  else if(x==2){
    return ~0b01011011;
  }
  else if(x==3){
    return ~0b01001111;
  }
  else if(x==4){
    return ~0b01100110;
  }
  else if(x==5){
    return ~0b01101101;
  }
  else if(x==6){
    return ~0b01111101;
  }
  else if(x==7){
    return ~0b00000111;
  }
  else if(x==8){
    return ~0b01111111;
  }
  else if(x==9){
    return ~0b01101111;
  }
  return 0;
}
void delay1(float x){
  for (volatile long int i =0 ;i<x*250000;i++) ;
}