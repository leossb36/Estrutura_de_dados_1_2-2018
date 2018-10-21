#include "header.h"

/* @todo
open file
check file
read all lines
close the file 

@todo
  view list
  see list by name
  see list in alphabetical order
*/

DataType *readDataFile(char *filename)
{
  DataType *list;

  char name[101];
  char phone[12];
  char adress[101];
  unsigned int cep;
  char birth[11];
  char buffer = '$';

  FILE * file = getContacts(filename);

  Schedule *readData = (Schedule *) malloc(sizeof(Schedule));

  if (readData == NULL)
  {
    printf("\nError: Fail to allocate memory!\n");
    exit(-2);
  }

  while(!feof(file))
  {
    fscanf(file, "%[^\n]", name);
    getc(file);

    fscanf(file, "%s", phone);
    getc(file);

    fscanf(file, "%[^\n]", adress);
    getc(file);

    fscanf(file, "%u", &cep);
    getc(file);

    fscanf(file, "%s", birth);
    getc(file);

    fscanf(file, "%c", &buffer);
    getc(file);
    // fgets(readData, sizeof readData, fp);

    list = newRegister(list, filename, name, phone, adress, cep, birth);
  }
  fclose(file);

  return list;
}

void *seeByName(DataType *list, char *name)
{
  DataType *findR = findRegister(list, name);

  if(findR == NULL)
  {
    printf("\nCannot find the Register!\n");
    getchar();
  }
  else
  {
    printf("\nRegister of %s\n\n", findR->info->name);
    printf("Name: %s\n", findR->info->name);
    printf("Telephone: %s\n", findR->info->phone);
    printf("Adress: %s\n", findR->info->adress);
    printf("CEP: %u\n", findR->info->cep);
    printf("Birthday: %s\n", findR->info->birth);
  }

}

void *printDataFile(DataType *list)
{
  DataType *aux;

  if(list == NULL)
  {
    printf("\nList doesn't exist!\n");
    exit(-2);
  }

  if(list->info == NULL)
  {
    printf("\nVoid list, please do a new register\n");
    exit(-3);
  }
  for(aux = list; aux->info != NULL; aux = aux->next)
  {
    printf("\nRegister of %s\n\n", aux->info->name);
    printf("Name: %s\n", aux->info->name);
    printf("Telephone: %s\n", aux->info->phone);
    printf("Adress: %s\n", aux->info->adress);
    printf("CEP: %u\n", aux->info->cep);
    printf("Birthday: %s\n", aux->info->birth);
  }
}