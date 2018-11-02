#include "header.h"

int main(){

	int landings, take_off, fly_number;
    
    getFlights(&landings, &take_off, &fly_number);
    //randomStatus(&take_off, &landings, &fly_number);


    system("clear");
    printf("\n--------------------------------------------------\n");
    printf("\tAeroporto Internacional de Brasília\n");
    printf("--------------------------------------------------\n\n");

    printf("Hora Inicial: 16:00\n");
    printf("\nFila de Pedidos: \n");

    int *fuel = randomFuel();
    char *status = randomStatus(&take_off, &landings, &fly_number);
    flightOrder(fuel, status, &fly_number);


    printf("\nNúmero de Voos: ");
    printf("%d\n", fly_number);

    printf("Número de Aproximações: ");
    printf("%d\n", landings);

    printf("Número de Decolagens: ");
    printf("%d\n", take_off);

    printf("--------------------------------------------------\n\n");

return 0;
}