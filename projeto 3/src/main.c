#include "header.h"
#define contacts "../reference/contato.txt"

int main(int argv, char **argc){

  int menu = 1, op;

  DataType *list; //= (DataType *) malloc(sizeof(DataType));
  DataType *newr;
  Schedule *contact;

  do{
  /* Menu functions:
      see all registers
      insert register
      remove register by name
      see register by name
      see in order register
      exit

      @todo
        do the validations for each options
 */
    printf("=========================================\n\n");
    printf("\tAGENDA DE CONTATOS\n\n");
    printf("=========================================\n");
    printf("[0] - Visualizar todos os registros\n");
    printf("[1] - Inserir Registro\n");
    printf("[2] - Remover Registro por nome\n");
    printf("[3] - Visualizar Registro por nome\n");
    printf("[4] - Visualizar em Ordem Alfabética\n");
    printf("[5] - Sair\n");
    printf("=========================================\n\n");
    

    scanf("%d", &op);

    switch(op) {

      case 0:
        printf("=========================================\n\n");
        printf("\tVisualizar Todos os Registros\n\n");
        readDataFile(contacts, list);
        printf("\n=========================================\n\n");
        break;

      case 1:
        printf("=========================================\n\n");
        printf("\tInserir Registro\n\n");

        // list = insertBeginning(list, newr);
        printf("\n=========================================\n\n");
        break;
        
      case 2:
        printf("=========================================\n\n");
        printf("\tRemover Registro por Nome\n\n");

        printf("\n=========================================\n\n");
        break;
        
      case 3:
        printf("=========================================\n\n");
        printf("\tVisualizar Registro por Nome\n\n");

        printf("\n=========================================\n\n");
        break;
        
      case 4:
        printf("=========================================\n\n");
        printf(" Visualizar Todos os Registros em Ordem\n\n");

        printf("\n=========================================\n\n");
        break;
        
      case 5:
        menu = 0;
        break;
        
      default:
        break;
    
    }

  } while(menu == 1);


return 0;
}
