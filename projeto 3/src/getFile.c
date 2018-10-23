#include "header.h"

FILE *getContacts(char *filename)
{
    FILE *fp;

    fp = fopen(filename, "r+");

    if(fp == NULL){
        perror("\n\n Error: Fail to open File!\n\n");
        fp = fopen(filename, "w+");
    }

    return fp;
}
