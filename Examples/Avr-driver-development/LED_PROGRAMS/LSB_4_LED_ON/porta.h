void init(){
  volatile char * a_dir = (volatile char *) 0x21;
  *a_dir = 0x0F;
}
void port(char s){
  volatile char * a_port = (volatile char * )0x22;
  *a_port = s; 
}