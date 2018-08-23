#include <stdio.h>


int fib(int num);

int main()
{
    int value, success;

    printf("Enter with the value: ");

    scanf("%d", &value);

    success = fib(value);

    printf("[position = %d ] fibonacci = %d\n", value, success);

    return 0;
}

int fib(int num)
{
    if (num == 0)
        return 0;
    else if (num == 1)
        return 1;
    else
        return (fib(num - 1) + fib(num - 2));
}
