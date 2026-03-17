#define TCCR1A   (*(volatile uint8_t*)  0x80)
#define TCCR1B   (*(volatile uint8_t*)  0x81)
#define TCNT1    (*(volatile uint16_t*) 0x84)
#define OCR1A    (*(volatile uint16_t*) 0x88)
#define OCR1B    (*(volatile uint16_t*) 0x8A)
#define TIMSK1   (*(volatile uint8_t*)  0x6F)
#define TIFR1    (*(volatile uint8_t*)  0x36)
//Bits
#define WGM12   3
#define CS10    0
#define CS11    1
#define CS12    2

#define TOIE1   0
#define OCIE1A  1

#define TOV1    0
#define OCF1A   1

#ifndef CPU
#define CPU 16000000UL
#endif
//Prescalar : 
typedef enum
{
    TIMER1_NC = 0,
    TIMER1_PRES_1,
    TIMER1_PRES_8,
    TIMER1_PRES_64,
    TIMER1_PRES_256,
    TIMER1_PRES_1024
} timer1_clock;
//Stop timer
void timer1_stop(void)
{
  TCCR1B &= ~((1 << CS10) | (1 << CS11) | (1 << CS12));
}
//start timer 
void timer1_start(timer1_clock clk)
{
  TCCR1B &= ~((1 << CS10) | (1 << CS11) | (1 << CS12));
  switch(clk){
    case TIMER1_PRES_1:
      TCCR1B |= (1 << CS10);
      break;
    case TIMER1_PRES_8:
      TCCR1B |= (1 << CS11);
      break;
    case TIMER1_PRES_64:
      TCCR1B |= (1 << CS10) | (1 << CS11);
      break;
    case TIMER1_PRES_256:
      TCCR1B |= (1 << CS12);
      break;
    case TIMER1_PRES_1024:
      TCCR1B |= (1 << CS10) | (1 << CS12);
      break;
    default:
      break;
  }
}
//timer1_reset
void timer1_reset()
{
  TCNT1 = 0;
}
//Set the counter value : 
void timer1_set_count(uint16_t value)
{
  TCNT1 = value;
}
//set the comp value for a 
void timer1_set_comp_a(uint16_t value)
{
  OCR1A = value;
}


//CTC Mode 

void timer1_ctc(uint16_t value , timer1_clock clk){
  timer1_stop();
  TCCR1A =0;
  TCCR1B =0;
  timer1_reset();
  OCR1A = value ;
  TCCR1B |= (1<<WGM12);
  timer1_start(clk);
}
void timer1_ovf(timer1_clock clk){
  timer1_stop();
  TCCR1A =0;
  TCCR1B =0;
  timer1_reset();
  timer1_start(clk);
}

void timer1_comp_delay(int x)
{
  for (int i = 0 ; i !=x;i++){
    while (!(TIFR1 & (1 << OCF1A)));
    TIFR1 |= (1 << OCF1A); 
  }
}

void timer1_ovf_delay(int x)
{
  for (int i = 0 ; i !=x;i++){
    while (!(TIFR1 & (1 << TOV1)));
    TIFR1 |= (1 << TOV1);
  }
}
void timer1_enb_comp_intr(){
  sei();
  TIMSK1 |= (1<<OCIE1A); 
}
void timer1_dis_comp_intr(){
  TIMSK1 &= ~(1<<OCIE1A); 
}
void timer1_enb_ovf_intr(){
  sei();
  TIMSK1 |= (1<<TOIE1); 
}
void timer1_dis_ovf_intr(){
  TIMSK1 &= ~(1<<TOIE1); 
}
//delay in ms : 
void delay_ms(uint16_t ms)
{
  timer1_ctc(249, TIMER1_PRES_64);
  timer1_comp_delay(ms);
  timer1_stop();
}
