#ifndef QUEUE_H
#define QUEUE_H
#include "header.h"

typedef struct list
{
  Plane *plane;
  struct list *next;
}List;

typedef struct queue_flight
{
  List *beginning; // first element of queue
  List *end; // last element of queue
}Queue;


List *voidList();
List *createElement(Plane *plane);
Plane *createPlane(char *, char , int);
int voidQueue(Queue *);
Queue *createQueue();
void *insertQueue(List *, Queue *);
void *flightOrder(Queue *);

#endif