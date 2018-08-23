#include <stdio.h>

int MDC(int a, int b);

int main()
{
    int num1, num2, success;

    scanf("%d%d", &num1, &num2);

    success = MDC(num1, num2);

    printf("%d\n", success);

    return 0;
}

int MDC(int a, int b)
{
    int r;
    r = a % b;
    a = b;
    b = r;


    if (r == 0)
        return a;
    else
        return MDC(a, b);
}