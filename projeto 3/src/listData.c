#include "header.h"

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

// DataType *insertElement(DataType *list,DataType *element, int position)
// {
//     DataType *aux;
//     int count = 0;

//     for(aux = list; count != position - 1; aux = aux->next)
//         count++;
    
//     element->next = aux->next;
//     element->before = aux->before;

//     if (element->before == NULL)
//         element = insertBeginning(list, element);
    
//     aux->next = element;
//     aux->before = NULL;

//     return element;    
// }


DataType *newRegister(DataType *list, char *name, char *phone, char *adress, unsigned int cep, char *birth)
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
    element->before = list;

    if(list != NULL)
    {
        list->before = element;
    }

    return element;
}

DataType *findRegister(DataType *list, char *name){

    DataType *element;
    int comp = strcmp(element->info->name, name);

    for(element = list; element != NULL; element = element->next)
    {
        if(comp != 0)
        {
            return element;
        }
        else
        {
            // printf("Nome não encontrado");
            return NULL;
        }
    }
    return element;
}

char *inputName()
{
    char *name = (char *) malloc(101*sizeof(char));
    setbuf(stdin, NULL);
    printf("Input with the Name: ");
    scanf("%[^\n]", name);

  return name;
}

DataType *registerData(DataType *list)
{
    DataType *rgt;

    rgt = list;

    char name[101];
    char phone[12];
    char adress[101];
    unsigned int cep;
    char birth[11];

    printf("\n\nNew Contact:\n\n");
    setbuf(stdin, NULL);

    //Name - string
    printf("Insert a Name: ");
    scanf("%[^\n]s", name); 
    setbuf(stdin, NULL);

    //Telephone - string - xxxxx-xxxx
    char phone2[12];

    int examplephone = 5;

    char auxphone1[10];
    char auxphone2[10];

    int sizeScanf1 = 3, sizeScanf2 = 4;

    while(examplephone != sizeScanf1 || examplephone != sizeScanf2){
        printf("Insert a Telephone: ");
        
        scanf("%[^-]s", phone);
        scanf("%[^\n]s", phone2);
        setbuf(stdin, NULL);

        sprintf(auxphone1, "%s", phone);
        sprintf(auxphone2, "%s", phone2);
        setbuf(stdin, NULL);

        sizeScanf1 = strlen(auxphone1);
        sizeScanf2 = strlen(auxphone2);

        /* printf("PHONE 1: %s\n", phone);
        printf("PHONE 2: %s\n", phone2);

        printf("sizeExemple1 = %d(certo)\n", examplephone);
        printf("sizeExemple2 = %d(certo)\n", examplephone);
        printf("sizeScanf1 = %d\n", sizeScanf1);
        printf("sizeScanf2 = %d\n", sizeScanf2); */

        while(examplephone != sizeScanf1 || examplephone != sizeScanf2){
        
            printf("Insert a Correct Telephone - [xxxxx-xxxx]: ");
            
            scanf("%[^-]s", phone);
            scanf("%[^\n]s", phone2);
            setbuf(stdin, NULL);

            sprintf(auxphone1, "%s", phone);
            sprintf(auxphone2, "%s", phone2);
            setbuf(stdin, NULL);

            sizeScanf1 = strlen(auxphone1);
            sizeScanf2 = strlen(auxphone2);        
        }
    }
    while(examplephone == sizeScanf1 || examplephone == sizeScanf2){
        strcat(phone, phone2);
        /* printf("%s", phone);
        printf("DEU CERTO!!\n"); */
        break;
    }

    //Adress - string
    printf("Insert a Adress: ");
    scanf("%[^\n]s", adress);
    setbuf(stdin, NULL);
    
    //CEP - int - xxxxx
    char auxCEP[6];
    int sizeExemple = 5;
    int sizeScanf = 1;
    
    while(sizeExemple != sizeScanf){
        printf("Insert a CEP: ");
        scanf("%u", &cep);
        // inteiro para string. Até 10 algarísmos.
        sprintf(auxCEP, "%u", cep);

        sizeScanf = strlen(auxCEP);

        while(sizeExemple != sizeScanf){
            printf("Insert a Correct CEP - [xxxxx]: ");
            scanf("%u", &cep);
            sprintf(auxCEP, "%u", cep);
            
            sizeScanf = strlen(auxCEP);
        }
    }

    //BirthDay - xx/xx/xxxx
    printf("Insert a Birth Date: ");
    scanf("%s", birth);

    rgt = newRegister(list, name, phone, adress, cep, birth);

    if(rgt == NULL){
        printf("\nRegistro não feito!\n");
    }

    else{
        system("clear");
        printf("=========================================\n");
        printf("\nRegistro Confirmado!\n\n\n"); 

        return rgt;
    }
}

DataType *insertionSort(DataType *list)
{
    DataType *element;
    DataType *temp;  
    DataType *aux = list;  
    
    for(aux = list->next; aux != NULL; aux = aux->next)
        {
            if(strcmp(aux->info->name, element->info->name) > 0)
            {
                if(aux != NULL)
                {
                    temp = aux->next;
                    aux->next = element->next;
                    element->next = temp;

                     temp->before = aux;
                    aux = element->before;
                    element->before = temp->before;
                }
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