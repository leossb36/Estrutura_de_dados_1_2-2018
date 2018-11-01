#include "header.h"

void showTime(){
  time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  printf ( "%s", asctime (timeinfo) );
}

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
    char aux;
    
    if(auxNum == 2){
      aux = 'D';
    }
    else if(auxNum == 1){
      aux = 'A';
    }

    if(l != 0 && t != 0){
      
      status[i] = aux;

      if(auxNum == 2){
        l--;
      }
      else if(auxNum == 1){
        t--;
      }
    }

    else if(l == 0){
      status[i] = 'D';
      t--;
    }
    else if(t == 0){
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


/* char airplanePrefix[][7]=
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
  }; */
