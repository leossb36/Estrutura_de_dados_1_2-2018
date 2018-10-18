#include "head.h"

//#define filename (...)

void *readFile(char *filename){
  FILE *fp;
  fp = fopen(filename, "w+");

  if(fp == NULL){
    printf("\n\n Error: Fail to open File!\n\n");
    exit(1);
  }

  char Nome_completo[101];
  char Telefone[11];
  char Endereço[101];
  int cep;
  char Data_Nascimento[11];

  fgets(Nome_completo, sizeof(Nome_completo), fp);

}
