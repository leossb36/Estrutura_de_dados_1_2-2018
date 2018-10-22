#include "header.h"
#define size 101
/* @todo
    if doesn't exist list, create a new list
    insert elements in the list
    search elements in the list
    remove elements in the list
    insert elements in a random position(selected) in the list

    int type;
    void *info;
    struct list *next;
    struct list *before;
 */

DataType *voidList()
{
    return NULL;
}

DataType *insertBeginning(DataType *list, DataType *element)
{
    element->next = list;
    element->before = NULL;

    return element;
}

DataType *insertElement(DataType *list,DataType *element, int position)
{
    DataType *aux;
    int count = 0;

    for(aux = list; count != position - 1; aux = aux->next)
        count++;
    
    element->next = aux->next;
    element->before = aux->before;

    if (element->before == NULL)
        element = insertBeginning(list, element);
    
    aux->next = element;
    aux->before = NULL;

    return element;    
}


DataType *newRegister(DataType *list, char *filename, char *name, char *phone, char *adress, unsigned int cep, char *birth)
{

    FILE *fp = getContacts(filename);

    Schedule *rgt = (Schedule *) malloc(sizeof(Schedule));

    if(rgt == NULL)
    {
        perror("\nCannot allocate memory!\n");
        exit(1);
    }

    DataType *element = (DataType *) malloc(sizeof(DataType));

    if(element == NULL)
    {
        perror("\nCannot allocate memory!\n");
        exit(-1);
    }
    for(int i = 0; i < sizeof(rgt->name); i++)
    {
        rgt->name[i] = name[i];
    }
    for(int i = 0; i < sizeof(rgt->phone); i++)
    {
        rgt->phone[i] = phone[i];
    }
    for(int i = 0; i < sizeof(rgt->adress); i++)
    {
        rgt->adress[i] = adress[i];
    }
    for(int i = 0; i < sizeof(rgt->birth); i++)
    {
        rgt->birth[i] = birth[i];
    }
    rgt->cep = cep;
   
    element->info = rgt;
    element->next = NULL;
    element->before = NULL;

    return element;

}

DataType *findRegister(DataType *list, char *name)
{
    DataType *element;

    for(element = list; element->info != NULL; element = element->next)
    {
        if(strcmp(element->info->name, name) == 1)
            return element;
    }
    return element;
}

char *inputName()
{
  char *name = (char *) malloc(101*sizeof(char));

  scanf("%[^\n]", name);

  return name;
}

DataType *registerData(DataType *list, char *filename)
{
  DataType *rgt;

  rgt = list;

  char name[101];
  char phone[12];
  char adress[101];
  unsigned int cep;
  char birth[11];
  char buffer;

  printf("\n\nNew Contact:\n\n");
  printf("Name: ");
  scanf("%[^\n]", name);  
  printf("\nTelephone: ");
  scanf("%c", phone);
  printf("\nAdress: ");
  scanf("%[^\n]", adress);
  printf("\nCEP: ");
  scanf("%u", &cep);
  printf("\nBirthDay: ");
  scanf("%c", birth);

  rgt = newRegister(list, filename, name, phone, adress, cep, birth);

  return rgt;
}

DataType *insertionSort(DataType *list)
{
    DataType *element;
    DataType *temp;
    Schedule *aux;

    for(element = list; element != NULL ; element = element -> next)
    {
        aux = element->info;
        temp = element->before;

        while((temp->before != NULL) && ((strcmp(temp->info->name,aux->name) < 0)))
        {
            temp->next->info = temp->info;
            temp = temp -> before;
        }

        temp->next->info = aux;

    }

    return list;
}

void *freeList(DataType *list)
{
    DataType *current;

    for(current = list; current != NULL; current = current->next);
        free(current);
    
    free(list);
}