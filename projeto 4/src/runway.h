#ifndef RUNWAY_H
#define RUNWAY_H
#include "header.h"

typedef struct runway
{
  int time; // how many time spend in the runway
  int id; // runway id
  Plane *plane; // element of list
}Runway;

#endif