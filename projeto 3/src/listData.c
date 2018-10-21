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

    *rgt->name = *name;
    *rgt->phone = *phone;
    *rgt->adress = *adress;
    rgt->cep = cep;
    *rgt->birth = *birth;

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
