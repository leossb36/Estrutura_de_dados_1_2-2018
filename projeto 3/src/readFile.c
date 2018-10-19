#include "head.h"

//#define filename (...)

void *readFile(char *filename){
  
  FILE *fp;
  Schedule *read_data;
  DataType *
  
  fp = fopen(filename, "r+");

  if(fp == NULL){
    perror("\n\n Error: Fail to open File!\n\n");
    exit(1);
  }

  read_data = (Schedule *) calloc(strlen(read_data->name) + strlen(read_data->phone) + strlen(read_data->adress) + 
                                  strlen(read_data->birth) + 16, sizeof(Schedule));

  if (read_data == NULL)
  {
    puts("Error: Fail to allocate memory![1]");
    exit(-2);
  }

  
  fgets(read_data->name, sizeof(read_data->name), fp);

}