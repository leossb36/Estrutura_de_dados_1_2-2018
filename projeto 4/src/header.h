#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct airplane_data
{
  char flyCode[7]; // AA0000 - code
  char status; // A || D - status
  int fuel; // 0 - 12 - airplane fuel
  int time; // how many time the airplay spend
  struct airplane_data *next; // list
}Air;

typedef struct queue_flight
{
  Air *beginning; // first element of queue
  Air *end; // last element of queue
}Queue;

typedef struct runway
{
  int time; // how many time spend in the runway
  int id; // runway id
  Air *airplane; // element of list
}Runway;


/* char airplanePrefix[65][7]=
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

#endif