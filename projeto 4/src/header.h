#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct airplane_data
{
  char flyCode[7]; // AA0000 - code
  char status; // A || D - status
  int fuel; // 0 - 12 - airplane fuel
  int time // how many time the airplay spend
  struct airplane_data *next; // list
}Air;

typedef struct queue_flight
{
  Air *beginning; // first element of queue
  Air *end; // last element of queue
}Queue;

typedef struct runway
{
  int time; // how many time spend in the runway
  int id; // runway id
  Air *airplane; // element of list
}Runway;


#endif