#include <stdio.h>

int mov(int disc_amount, int disc, char bas_left, char bas_middle, char bas_right, int movs);
int check_pin(int disc);


int main()
{
    return 0;
}

int mov(int disc_amount, int disc, char bas_left, char bas_middle, char bas_right, int movs)
{
    disc_amount = check_disc(disc);

    
}

int check_disc(int disc)
{
    do
    {
        printf("Enter with amount of disc: ");

        scanf("%d", &disc);

    } while (disc == NULL);

    
    if (disc == 1)

        return 1;
    else

        return disc - check_pin(disc - 1);
}