#ifndef IOMAP_H
#define IOMAP_H
typedef enum {
  A,
  B,
  C,
  D,
  E,
  F,
  G,
  H,
  J,
  K,
  L
} Port ;
typedef enum {
  PIN,//0
  DIR,//1
  PORT,//2
} REG ;
typedef enum {
  INP =  0,
  OUT =  1
} MODE ;
typedef enum {
  low =  0,
  high =  1
} STATUS ;
#endif