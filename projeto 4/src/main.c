#include "header.h"

int main(){
	int landings, take_off;
    int *p_take_off, *p_landings;
    
    landings = randomFly(1);
    take_off = randomFly(2);

    p_landings = (int*)(malloc(sizeof(int)));
    if(p_landings == NULL){
        printf("\nError: Fail to allocate memory - p_landings!\n");
        exit(0);
    }
    
	p_take_off = (int*)(malloc(sizeof(int)));
    if(p_take_off == NULL){
        printf("\nError: Fail to allocate memory - p_take_off!\n");
        exit(0);
    }
    
	*p_landings = landings;
	*p_take_off = take_off;
    
    int fly_number = landings + take_off;
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
    printf("%d\n", *p_landings);

    printf("Número de Decolagens: ");
    printf("%d\n", *p_take_off);

    //randomFuel();
    //randomStatus(fly, p_take_off, p_landings);
return 0;
}