#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct PONTO 
{
    double x;
    double y;

}Ponto;

Ponto *criaPonto();
void setPonto(Ponto *, double, double);
void imprimePonto(Ponto *p);
double calcDist(Ponto *p1, Ponto *p2);
void liberaPonto(Ponto *p);


int main()
{
    Ponto *p1, *p2;
    double calc;

    p1 = criaPonto();
    p2 = criaPonto();

    setPonto(p1, 3, 5);
    setPonto(p2, 7, 9);

    imprimePonto(p1);
    imprimePonto(p2);

    calc = calcDist(p1, p2);

    printf("A distância euclidiana entre p1 e p2 é: %.0lf\n", calc);

    liberaPonto(p1);
    liberaPonto(p2);


    return 0;
}

Ponto *criaPonto()
{
    Ponto *p;

    p = (Ponto *) malloc(sizeof(Ponto));

    if (p == NULL)
    {
        printf("Não alocou\n");
        exit(1);
    }

    return p;
}

void setPonto(Ponto *p, double x, double y)
{
    p->x = x;
    p->y = y;
}

void imprimePonto(Ponto *p)
{
    printf("Ponto: (%.0lf %.0lf)\n", p->x, p->y);
}

double calcDist(Ponto *p1, Ponto *p2)
{
    return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
}

void liberaPonto(Ponto *p)
{
    free(p);
}
