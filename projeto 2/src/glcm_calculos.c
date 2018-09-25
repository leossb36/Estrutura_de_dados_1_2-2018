#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv){
  int glcm[8][8], contrast = 0, energy = 0, homog = 0;
  //Contrast
  //Must be 0 in a constant image
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      contrast += pow(abs(i - j),2) * glcm[i][j];
    }
  }
  //Energy
  //Must be 1 in a constant image
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      energy += pow(glcm[i][j], 2);
    }
  }
  //Homogeneity
  //Must be 1 in a diagonal glcm
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      homog += (glcm[i][j] /(1 + abs(i - j)));
    }
  }
}
