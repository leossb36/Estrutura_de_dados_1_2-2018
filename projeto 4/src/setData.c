#include "header.h"


int randomFuel()
{
  int fuel[64];
  srand(time(NULL));

  for(int i = 0; i < 64; i++){
    fuel[i] = rand() % 12;
    printf("Fuel Airplane %d: %d\n", i+1, fuel[i]);
  }
  return fuel[64];
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

void randomStatus(int *take_off, int *landings, int *flynumber)
{
  
  srand(time(NULL));

  int t = *take_off, l = *landings, f = *flynumber;
  char status[f];
  
  for(int i = 0; i < f; i++)
  {

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

      if(auxNum == 2){
        t--;
      }
      if(auxNum == 1){
        l--;
      }
    }

    if(l == 0){
      status[i] = 'D';
      t--;
    }
    if(t == 0){
      status[i] = 'A';
      l--;
    }
    printf("%c\n", status[i]);
  }
}

void *getFlights(int *landings, int *take_off, int *fly_number)
{
    int *p_take_off, *p_landings;

    *landings = randomFly(1);
    *take_off = randomFly(2);

    p_landings = (int*) malloc(sizeof(int));
    
    if(p_landings == NULL)
    {
        printf("\nError: Fail to allocate memory - p_landings!\n");
        exit(0);
    }
    
	  p_take_off = (int*) malloc(sizeof(int));
    
    if(p_take_off == NULL)
    {
        printf("\nError: Fail to allocate memory - p_take_off!\n");
        exit(0);
    }

    *p_landings = *landings;
	  *p_take_off = *take_off;

    *fly_number = *landings + *take_off;

}

void *randomIndex(){
   char airplanePrefix[64][7]=
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
  char chose[64][7];

  srand(time(NULL));
  for(int i = 0; i < 64; i++){
    int aux = rand() % 64;
    for(int j = 0; j < 7; j++){
      chose[i][j] =  airplanePrefix[aux][j];
    }
  }
  //Caso de Testes:
  for(int i = 0; i < 64; i++){
    for(int j = 0; j < 7; j++){
      printf("%c", chose[i][j]);
    }
    printf("\n");
  }
}
