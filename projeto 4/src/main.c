#include "header.h"

int main(){
	int landings, take_off;
    
    landings = randomFly(1);
    take_off = randomFly(2);
    
    int fly_number = landings + take_off;

    printf("\n--------------------------------------------------\n");
    printf("\tAeroporto Internacional de Brasília\n");
    printf("--------------------------------------------------\n\n");

    printf("Hora Inicial: "); 
    showTime();
    printf("Fila de Pedidos: \n");
    
    printf("Número de Voos: ");
    printf("%d\n", fly_number);

    printf("Número de Aproximações: ");
    printf("%d\n", landings);

    printf("Número de Decolagens: ");
    printf("%d\n", take_off);
return 0;
}