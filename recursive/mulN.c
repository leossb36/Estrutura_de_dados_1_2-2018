#include <stdio.h>
int num1;

int mul_natural(int num1, int num2);


int main()
{
    int num2, calc;

    printf("Enter with the value of number 1: ");

    scanf("%d", &num1);

    printf("Enter with the value of number 2: ");

    scanf("%d", &num2);

    calc = mul_natural(num1, num2);

    printf("The product result of %d and %d is ... %d\n", num1, num2, calc);

    return 0;
}

int mul_natural(int num1, int num2)
{
    if (num2 == 1)
        return num1;
    else
        return mul_natural(num1, num2 - 1) + num1;
}