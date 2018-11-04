#include "header.h"

char *getIndex(int *fly_number)
{

  char *airplanePrefix[64]=
  {
    "VG3001\0", "JJ4404\0", "LN7001\0", "TG1501\0", "GL7602\0", "TT1010\0", "AZ1009\0",
    "AZ1008\0", "AZ1010\0", "TG1506\0", "VG3002\0", "JJ4402\0", "GL7603\0", "RL7880\0", 
    "AL0012\0", "TT4544\0", "TG1505\0", "VG3003\0", "JJ4403\0", "JJ4401\0", "LN7002\0", 
    "AZ1002\0", "AZ1007\0", "GL7604\0", "AZ1006\0", "TG1503\0", "AZ1003\0", "JJ4403\0", 
    "AZ1001\0", "LN7003\0", "AZ1004\0", "TG1504\0", "AZ1005\0", "TG1502\0", "GL7601\0", 
    "TT4500\0", "RL7801\0", "JJ4410\0", "GL7607\0", "AL0029\0", "VV3390\0", "VV3392\0", 
    "GF4681\0", "GF4690\0", "AZ1020\0", "JJ4435\0", "VG3010\0", "LF0920\0", "AZ1065\0", 
    "LF0978\0", "RL7867\0", "TT4502\0", "GL7645\0", "LF0932\0", "JJ4434\0", "TG1510\0", 
    "TT1020\0", "AZ1098\0", "BA2312\0", "VG3030\0", "BA2304\0", "KL5609\0", "KL5610\0", 
    "KL5611\0"
  };

  char *code = (char *) calloc(64*7, sizeof(char));

  for (int i = 0; i < *fly_number; i++)
  {
      int num = rand() % 64;

      strncpy(code, airplanePrefix[num], 7);

  }
  return code;
}

int randomFuel()
{
  int *fuel = malloc(sizeof(int) * 64);
  if(fuel == NULL){
        printf("\nError: Fail to allocate memory - fuel!\n");
        exit(0);
  }

  srand(time(NULL));

  for(int i = 0; i < 64; i++){
    fuel[i] = rand() % 12;
  }
  return *fuel;
}

int randomFly(int n)
{
  int i;
  if(n == 1){
    srand(time(NULL));
  }
  i = rand() % 22;
  i += 10;

  return i;
}

char randomStatus(int *take_off, int *landings, int *flynumber)
{
  
  srand(time(NULL));

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
  return *status;
}

Plane *createPlane(int *landings, int *take_off, int *fly_number)
{ 

  Plane *plane = (Plane *) calloc(1, sizeof(Plane));

  if(plane == NULL)
  {
    printf("\nError: Fail to allocate memory - plane!\n");
    exit(-1);      
  }

  char *code = getIndex(fly_number);

  strcpy(plane->flyCode, code);
  plane->status = randomStatus(take_off, landings, fly_number);
  plane->fuel = randomFuel();
    
  return plane;
}