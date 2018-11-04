#include "header.h"

List *voidList()
{
    return NULL;
}

List *createElement(Plane *plane)
{
  List *element = (List *) malloc(sizeof(List));
  
  if(element == NULL)
  {
    printf("\nError: Fail to allocate memory - element!\n");
    exit(-1);
  }

  element->plane = plane;
  element->next = NULL;

  return element;
}

int voidQueue(Queue *q)
{
  return (q->beginning == NULL && q->end == NULL);
}

Queue *createQueue()
{
  Queue *q = (Queue *) calloc(1,sizeof(Queue));

  if (q == NULL)
  {
    printf("\nError: Fail to allocate memory - Queue!\n");
    exit(-1);
  }

  q->beginning = NULL;
  q->end = NULL;

  return q;
}

void *insertQueue(List *e, Queue *q)
{
  if(voidQueue(q))
  {
    q->beginning = e;
    q->end = e;
  }
  else
  {
    e->next = q->end;
    q->end = e; 
  }
}

void flightOrder(Queue *q)
{

  List *element = q->end;

  while(element != NULL)
  {
    
    if(element->plane->status == 'A')
    {
      printf("[CODE: %s  --  STATUS: %c  --  FUEL: %d]\n", element->plane->flyCode, element->plane->status, element->plane->fuel);
    }
    else if(element->plane->status == 'D')
    {
      printf("[CODE: %s  --  STATUS: %c  -- --NONE--]\n", element->plane->flyCode, element->plane->status);
    }
    
    element = element->next;
  }
}