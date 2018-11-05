#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#include "airplane.h"
#include "queue.h"
#include "runway.h"


#define unit_time 5

void *genFlights(int *, int *, int *);
void eventList();

#endif