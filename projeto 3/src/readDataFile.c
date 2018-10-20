#include "head.h"

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

void *readDataFile(char *filename){

  FILE *fp;
  Schedule *e;

  fp = fopen(filename, "r+");

  if(fp == NULL){
    perror("\n\n Error: Fail to open File!\n\n");
    exit(1);
  }
  /* 9 - > 1001 1001 1001 1001 1001 -> 4 * 2bytes + 1bit = 9 size of cep
  9 is the max numb to input to decribe a cep 
  get $
  char 4bytes -> 4 * 4 = 16
  sum buffer values -> 16+9 = 25 */

  Schedule *readData = (Schedule *) calloc(strlen(e->name) + strlen(e->phone) + strlen(e->adress) + strlen(e->birth) + strlen(e->buffer), sizeof(Schedule));

  if (readData == NULL)
  {
    printf("\nError: Fail to allocate memory![1]\n");
    exit(-2);
  }

  while(!feof(fp))
  {
    fscanf(fp, "%[^\n]", e->name);
    fgetc(fp);

    fscanf(fp, "%s", e->phone);
    fgetc(fp);

    fscanf(fp, "%[^\n]", e->adress);
    fgetc(fp);

    fscanf(fp, "%u", &e->cep);
    fgetc(fp);

    fscanf(fp, "%s", e->birth);
    fgetc(fp);

    fscanf(fp, "%c", e->buffer);
    fgetc(fp);
    // fgets(readData, sizeof readData, fp);

    printf("%s\n", e->name);
    printf("%s\n", e->phone);
    printf("%s\n", e->adress);
    printf("%u\n", e->cep);
    printf("%s\n", e->birth);
    printf("%c\n", *e->buffer);

  }

  fclose(fp);

}