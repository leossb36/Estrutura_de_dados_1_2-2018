#include "header.h"

int main(){
	int landings, take_off, fly_number;
    
    getFlights(&landings, &take_off, &fly_number);
    //int *fly = fly_number;

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

    printf("--------------------------------------------------\n\n");

    //randomFuel();
    //randomStatus(fly, p_take_off, p_landings);
return 0;
}