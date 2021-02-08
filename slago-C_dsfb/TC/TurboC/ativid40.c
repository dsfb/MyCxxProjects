#include <stdio.h>
#include <conio.h>
#include <string.h>

void ordena(int *a, int *b)
{
    if (*a > *b)
    {
        int c = *a;
        *a = *b;
        *b = c;
    }
}

void main(void)
{
	int x = 1, y = 0;

    printf("x = %d, y = %d\n", x, y);
    ordena(&x, &y);
    printf("x = %d, y = %d\n", x, y);

    x = 0, y = 0;
    printf("x = %d, y = %d\n", x, y);
    ordena(&x, &y);
    printf("x = %d, y = %d\n", x, y);    

    x = 0, y = 1;
    printf("x = %d, y = %d\n", x, y);
    ordena(&x, &y);
    printf("x = %d, y = %d\n", x, y);        

    x = -1, y = -2;

    printf("x = %d, y = %d\n", x, y);
    ordena(&x, &y);
    printf("x = %d, y = %d\n", x, y);

	printf("\nPressione algo para sair!\n");
	getch();
}