#include "header.h"
int select_names[64] = {0};

char *getFlight(Plane *plane)
{
  /* int size = strlen(plane->flyCode) + 64;

  char *code = (char *) calloc(size, sizeof(char));

  if(code == NULL)
  {
    printf("\nError: Fail to allocate memory - code!\n");
    exit(1);
  } */

  if(plane->status == 'A')
  {
    printf( "[CODE: %s -- STATUS: %c -- FUEL: %.2d]\n", plane->flyCode, plane->status, plane->fuel);
  }
  else if(plane->status == 'D')
  {
    printf("[CODE: %s -- STATUS: %c -- --NONE--]\n", plane->flyCode, plane->status);    
  }

  //return code;
}

char *getRandomCode()
{
  char *codePlane[64]=
  {
    "VG3001", "JJ4404", "LN7001", "TG1501", "GL7602", "TT1010", "AZ1009",
    "AZ1008", "AZ1010", "TG1506", "VG3002", "JJ4402", "GL7603", "RL7880", 
    "AL0012", "TT4544", "TG1505", "VG3003", "JJ4403", "JJ4401", "LN7002", 
    "AZ1002", "AZ1007", "GL7604", "AZ1006", "TG1503", "AZ1003", "JJ4403", 
    "AZ1001", "LN7003", "AZ1004", "TG1504", "AZ1005", "TG1502", "GL7601", 
    "TT4500", "RL7801", "JJ4410", "GL7607", "AL0029", "VV3390", "VV3392", 
    "GF4681", "GF4690", "AZ1020", "JJ4435", "VG3010", "LF0920", "AZ1065", 
    "LF0978", "RL7867", "TT4502", "GL7645", "LF0932", "JJ4434", "TG1510", 
    "TT1020", "AZ1098", "BA2312", "VG3030", "BA2304", "KL5609", "KL5610", 
    "KL5611"
  };

  int randNum;

  do{
    
    randNum = rand() % 64;

  }while(select_names[randNum] == 1);
  
  select_names[randNum] = 1;

  return codePlane[randNum];
}

int *randomFuel()
{
  int *fuel = malloc(sizeof(int) * 64);
  if(fuel == NULL){
    printf("\nError: Fail to allocate memory - fuel!\n");
    exit(0);
  }

  for(int i = 0; i < 64; i++){
    fuel[i] = rand() % 13;
  }
  return fuel;
}

int randomFly(int n)
{
  int i;
  // if(n == 1){
  // }
  i = rand() % 22;
  i += 10;

  return i;
}

char randomStatus(int *take_off, int *landings, int *flynumber)
{
  int t = *take_off, l = *landings, f = *flynumber;
  char *status = malloc(sizeof(int) * f); 
  if(status == NULL){
    printf("\nError: Fail to allocate memory - status!\n");
    exit(0);
  }
  
  for(int i = 0; i < f; i++){

    int auxNum = rand() % 2; // auxNum(t) = 2 -> D; auxNum(l) = 1 -> A
    auxNum += 1;
    char aux;
    
    if(auxNum == 2){
      aux = 'D';
    }
    if(auxNum == 1){
      aux = 'A';
    }

    if(l > 0 && t > 0){
      
      status[i] = aux;

      if(status[i] == 'D'){
        t--;
      }
      else if(status[i] == 'A'){
        l--;
      }
    }

    else if(l == 0 && t > 0){
      status[i] = 'D';
      t--;
    }
    else if(t == 0 && l > 0){
      status[i] = 'A';
      l--;
    }
  }
  return status;
}

void spendFuel(Plane *plane)
{
  if(plane->fuel >= 0 && plane->status == 'A')
    plane->fuel -= 1;
}

Plane *createPlane(char *code, char status, int fuel)
{ 

  Plane *plane = (Plane *) calloc(1, sizeof(Plane));

  if(plane == NULL)
  {
    printf("\nError: Fail to allocate memory - plane!\n");
    exit(-1);      
  }

  strcpy(plane->flyCode, code);
  plane->status = status;
  plane->fuel = fuel;
    
  return plane;
}

void *freePlane(Plane *plane)
{
  free(plane->flyCode);
  free(plane);
}