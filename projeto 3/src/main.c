#include "head.h"

int main(){

int menu = 1, op;

do{
  /*Menu com as seguintes opçoes
      Inserir Registro
      Remover registro com string X
      Visualizar Registro
      Visualisar TUDO em ordem Alfabetica
      Sair
  */
  printf("\tAGENDA DE CONTATOS\n\n");
  printf("[0] - Inserir Registro\n");
  printf("[1] - Remover Registro\n");
  printf("[2] - Visualizar Registro\n");
  printf("[3] - Visualizar em Ordem Alfabética\n");
  printf("[4] - Sair\n");

  scanf("%d", &op);
  switch{
    case(0):
      
      break;
    case(1):

      break;
    case(2):

      break;
    case(3):

      break;
    case(4):
      printf("Gloria a Deuxxxx!\n");
      menu = 0;
      break;
    case(default):
      break;
  }

}while(menu == 1);


return 0;
}
