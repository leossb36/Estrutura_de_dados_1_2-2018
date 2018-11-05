#ifndef AIRPLANE_H
#define AIRPLANE_H
#include "header.h"

typedef struct airplane_data
{
  char flyCode[7]; // AA0000 - code
  char status; // A || D - status
  int fuel; // 0 - 12 - airplane fuel
}Plane;

int *randomFuel();
int randomFly(int);
char *getFlight(Plane *);
char *randomStatus(int *, int *, int *);
char *getRandomCode();

#endif