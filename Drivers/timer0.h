#define TCCR0A   (*(volatile uint8_t*)  0x44)
#define TCCR0B   (*(volatile uint8_t*)  0x45)
#define TCNT0    (*(volatile uint8_t*) 0x46)
#define OCR0A    (*(volatile uint8_t*) 0x47)
#define OCR0B    (*(volatile uint8_t*) 0x48)
#define TIMSK0   (*(volatile uint8_t*)  0x6E)
#define TIFR0    (*(volatile uint8_t*)  0x35)
//Bits
#define WGM00 0
#define WGM01 1
#define WGM02 3
#define CS00    0
#define CS01    1
#define CS02    2

#define TOIE0   0
#define OCIE0A  1

#define TOV0    0
#define OCF0A   1

#ifndef CPU
#define CPU 16000000UL
#endif
//Prescalar : 
typedef enum
{
    TIMER0_NC = 0,
    TIMER0_PRES_1,
    TIMER0_PRES_8,
    TIMER0_PRES_64,
    TIMER0_PRES_256,
    TIMER0_PRES_1024
} timer0_clock;
//Stop timer
void timer0_stop()
{
  TCCR0B &= ~((1 << CS00) | (1 << CS01) | (1 << CS02));
}
//start timer 
void timer0_start(timer0_clock clk)
{
  TCCR0B &= ~((1 << CS00) | (1 << CS01) | (1 << CS02));
  switch(clk){
    case TIMER0_PRES_1:
      TCCR0B |= (1 << CS00);
      break;
    case TIMER0_PRES_8:
      TCCR0B |= (1 << CS01);
      break;
    case TIMER0_PRES_64:
      TCCR0B |= (1 << CS00) | (1 << CS01);
      break;
    case TIMER0_PRES_256:
      TCCR0B |= (1 << CS02);
      break;
    case TIMER0_PRES_1024:
      TCCR0B |= (1 << CS00) | (1 << CS02);
      break;
    default:
      break;
  }
}
//timer0_reset
void timer0_reset()
{
  TCNT0 = 0;
}
//Set the counter value : 
void timer0_set_count(uint8_t value)
{
  TCNT0 = value;
}
//set the comp value for a 
void timer0_set_comp_a(uint8_t value)
{
  OCR0A = value;
}


//CTC Mode 

void timer0_ctc(uint8_t value , timer0_clock clk){
  timer0_stop();
  TCCR0A =0;
  TCCR0B =0;
  timer0_reset();
  OCR0A = value ;
  TCCR0A |= (1 << WGM01);
  timer0_start(clk);
}
void timer0_ovf(timer0_clock clk){
  timer0_stop();
  TCCR0A =0;
  TCCR0B =0;
  timer0_reset();
  timer0_start(clk);
}

void timer0_comp_delay(int x)
{
  for (int i = 0 ; i !=x;i++){
    while (!(TIFR0 & (1 << OCF0A)));
    TIFR0 = (1 << OCF0A); 
  }
}

void timer0_ovf_delay(int x)
{
  for (int i = 0; i != x; i++) {
    while (!(TIFR0 & (1 << TOV0)));
    TIFR0 = (1 << TOV0);
  }
}
void timer0_enb_comp_intr(){
  sei();
  TIMSK0 |= (1<<OCIE0A); 
}
void timer0_dis_comp_intr(){
  TIMSK0 &= ~(1<<OCIE0A); 
}
void timer0_enb_ovf_intr(){
  sei();
  TIMSK0 |= (1<<TOIE0); 
}
void timer0_dis_ovf_intr(){
  TIMSK0 &= ~(1<<TOIE0); 
}
//delay in ms : 
void delay_ms0(uint16_t ms)
{
  timer0_ctc(249, TIMER0_PRES_64);
  timer0_comp_delay(ms);
  timer0_stop();
}
