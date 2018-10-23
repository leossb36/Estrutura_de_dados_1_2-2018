#include "header.h"
#define filename "../reference/contato.txt"

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

DataType *readDataFile()
{
  DataType *list = (DataType *) malloc(sizeof(DataType));
  
  

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
    fgetc(file);

    fscanf(file, "%s", phone);
    fgetc(file);

    fscanf(file, "%[^\n]", adress);
    fgetc(file);

    fscanf(file, "%u", &cep);
    fgetc(file);

    fscanf(file, "%s", birth);
    fgetc(file);

    fscanf(file, "%c", &buffer);
    fgetc(file);
    // fgets(readData, sizeof readData, fp);

    list = newRegister(list, name, phone, adress, cep, birth);
    
    printDataFile(list);
    /* printf("%s\n", name);
    printf("%s\n", phone);
    printf("%s\n", adress);
    printf("%u\n", cep);
    printf("%s\n", birth);
    printf("%c\n", buffer); */
  }
  fclose(file);

  return list;
}

void *seeByName(DataType *list, char *name)
{
  //printf("%s", name);
  
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

  char buffer = '$';

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

  for(aux = list; aux != NULL; aux = aux->next)
  {
    printf("Name: %s\n", aux->info->name);
    printf("Telephone: %s\n", aux->info->phone);
    printf("Adress: %s\n", aux->info->adress);
    printf("CEP: %u\n", aux->info->cep);
    printf("Birthday: %s\n", aux->info->birth);
    printf("%c\n", buffer);
  }
}

void *removeByName(DataType *list, char *name){
  
  DataType *rmvr;
  DataType *aux;

  int comp;

  aux = findRegister(list, name);

  for(rmvr = list; rmvr != NULL; rmvr = rmvr->next){
        
    if(comp = strcmp(aux->info->name, name) == 0){
      if(rmvr->next != NULL){
        rmvr->before->next = rmvr->next;
      }
      if(rmvr->before != NULL){
        rmvr->next->before = rmvr->before;
      }
      free(rmvr->info);
    }
  }
  free(rmvr);
}