#include "runway.h"

int usingRunway(Plane *plane, Runway *runway){
    int landing = 4 * 5;
    int taking_off = 2 * 5;

    if(runway->plane == NULL && plane != NULL){
        runway->plane = plane;
        if(plane->status == 'A'){
            runway->time = landing;
        }
        else{
            runway->time = taking_off;
        }
        return 1;
    }
    else{
        return 0;
    }
}

List *management(List *list){
    int time_passed = 0, aux = 0;
    List *managed, *plane;
    Runway *runway1, *runway2, *runway3;

    runway1 = (Runway *)malloc(sizeof(Runway));
    runway2 = (Runway *)malloc(sizeof(Runway));
    runway3 = (Runway *)malloc(sizeof(Runway));

    runway1->id = 1;
    runway1->plane = NULL;

    runway2->id = 2;
    runway2->plane = NULL;

    runway3->id = 3;
    runway3->plane = NULL;

    while(plane != NULL){
        if((time_passed != 0) && ((time_passed % 50) == 0)){

        }
        if (runway1->plane != NULL) {
			runway1->time -= 5;
		}
		if (runway2->plane != NULL) {
			runway2->time -= 5;
		}
		if (runway3->plane != NULL) {
			runway3->time -= 5;
		}
		if (runway1->time == 0) {
			free(runway1->plane);
			runway1->plane = NULL;
		}
		if (runway2->time == 0) {
			free(runway2->plane);
			runway2->plane = NULL;
		}
		if (runway3->time == 0) {
			free(runway3->plane);
			runway3->plane = NULL;
		}
    }
}

List *management3(Runway *runway1, Runway *runway2, Runway *runway3, Plane *plane, int time_passed){
    List *element, *before, *list;
	int landing = 4 * 5;
	int taking_off = 2 * 5;

	 if (plane != NULL){
		 if((runway1->plane != NULL) && (runway2->plane != NULL)){
			if (plane->status == 'A' && plane->fuel == 0) {
				if(((time_passed != 0) && ((time_passed % 50) == 0))||
				((time_passed != 0) && ((time_passed % 50) > 30))){
					crashing(plane, time_passed);
					plane = list->next;
					return plane;
				}
			}
		}
		
		if(runway3->plane == NULL){
			if(plane->status == 'D'){
				runway3->plane = plane;
				runway3->time = taking_off;
				eventlist(runway3, time_passed);
				plane = list->next;
				return plane;
			}
            else(list->next != NULL){
				element=plane->next;
				before = plane;
				while (element != NULL){
				    if(element->status == 'D'){
						before->next = element->next;
						element->next = plane;
						plane = element;

						runway3->plane = plane;
						runway3->time = taking_off;
						eventlist(runway3, time_passed);
						plane = list->next;
						return plane;

					}
                    else{
						before = before->next;
						element = element->next;
					}
				}
			}
        }
	}
	return plane;
}

void crashing(Plane *plane, int time_passed){
    printf("\n---------------------------------------\n");
	 printf("---------------------------------------\n");
	 printf("   ALERTA CRÍTICO, AERONAVE IRÁ CAIR   \n");
	 printf("   Hora do alerta: ");
	 printf("   Código do voo: %s\n", plane->flyCode);
	 printf("---------------------------------------\n");
	 printf("---------------------------------------\n");
}
