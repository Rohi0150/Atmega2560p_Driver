void init (){
    volatile char *port_Dir = (volatile char *)0x104;
    *port_Dir = 0xFF;
}
void out(char out){
    volatile char *port_dat = (volatile char *)0x105;
    *port_dat = out;
}