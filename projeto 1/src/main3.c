#include <stdio.h>

void mov_disk(int disk, char orig, char aux, char dest);

int main()
{
    int disk;
    char A, B, C;

    printf("\nEnter with disc amount:\n");
    scanf("%d", &disk);
    
    mov_disk(disk, 'A', 'B', 'C');

    return 0;
}

void mov_disk(int disk, char orig, char aux, char dest)
{
    if (disk == 1)
    {
        printf("Move disk 1 from %c to %c\n", orig, dest);
        return;
    }
    mov_disk(disk-1, orig, aux, dest);
    printf("Move disc %d from %c to %c\n", disk, orig, dest);
    mov_disk(disk-1, aux, dest, orig);
}

