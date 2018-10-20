#include "head.h"
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

DataType *newRegister(char *name, char *phone, char *adress, unsigned int cep, char *birth, char *buffer)
{
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

    *rgt->name = name;

    if (rgt->name > size || rgt->name < 2)
    {
        ((rgt->name) > size) ? printf("Invalid adress, max size limited exceeded, try again\n")
                             : printf("Invalid adress, minimum size below allowable, try again\n"); 
    }
    *rgt->phone = phone;
    if(rgt->phone != 12)
        printf("Invalid phone number, try again\n");

    *rgt->adress = adress;
    if (rgt->adress > size || rgt->adress < 10)
    {
        ((rgt->adress) > size) ? printf("Invalid name, max size limited exceeded, try again\n")
                             : printf("Invalid name, minimum size below allowable, try again\n"); 
    }
    rgt->cep = cep;
    cep = atoi(cep);

    if(rgt->cep < 0)
    {
        printf("Invalid cep, try again");
    }

    *rgt->birth = birth;
    int day = 0, mouth = 0, year = 0;
    
    if (day > 31 && mouth > 12 && year < 0)
    {
        printf("Invalid birthday, try again\n");
    }
    char ch = '[^\]';
    itoa(day);
    itoa(mouth);
    itoa(year);

    strcpy(birth, day);
    strcat(birth, ch);
    strcat(birth,mouth);
    strcat(birth, ch);
    strcat(birth, year);
    
    *rgt->buffer = buffer;

    element->type = 1;
    element->info = rgt;
    element->next = NULL;
    element->before = NULL;

    return element;

}
