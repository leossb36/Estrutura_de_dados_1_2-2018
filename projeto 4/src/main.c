#include "header.h"

int main(){

	int landings, take_off, fly_number;
    Plane *plane;
    List *list;
    
    list = voidList();
    genFlights(&landings, &take_off, &fly_number);
    Queue *planeQueue = createQueue();
    
    char *status = randomStatus(&take_off, &landings, &fly_number);
    int *fuel = randomFuel();

     
    char *codePlane[fly_number];

    for(int i=0;i<fly_number;i++){
       
        codePlane[i] = getRandomCode();
        printf("%s\n",codePlane[i]);
    }
    //list = createElement(plane);
    //planeQueue = insertQueue(list, planeQueue);
    

    printf("\n--------------------------------------------------\n");
    printf("\tAeroporto Internacional de Brasília\n");
    printf("--------------------------------------------------\n\n");

    printf("Hora Inicial: 16:00\n");
    printf("\nFila de Pedidos: \n");
            //flightOrder(planeQueue);
    
    planeQueue = createPlane(codePlane, status, fuel, &fly_number, planeQueue);

    printf("\nNúmero de Voos: ");
    printf("%d\n", fly_number);

    printf("Número de Aproximações: ");
    printf("%d\n", landings);

    printf("Número de Decolagens: ");
    printf("%d\n", take_off);

    printf("--------------------------------------------------\n");
    eventList();

return 0;
}

void eventList()
{
    printf("\n--------------------------------------------------\n");
    printf("Código do voo: \n");
    printf("Status: [aeronave decolou ou aeronave pousou]\n");
    printf("Horário do início do procedimento: \n");
    printf("Número da pista: \n");
    printf("--------------------------------------------------\n\n");
}

void *genFlights(int *landings, int *take_off, int *fly_number)
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