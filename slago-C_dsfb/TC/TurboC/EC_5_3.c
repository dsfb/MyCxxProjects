#include <stdio.h>
#include <stdlib.h>

void main()
{
	int n[5], i;

    clrscr();

    for(i = 0; i < 5; i++)
    {
        printf("Digite n[%d]: ", i);
        scanf("%d", &n[i]);
    }

    printf("\nA impressao inversa deste vetor:\n");

    for(i = 4; i > -1; i--)
    {
        printf("%d\n", n[i]);
    }

    getch();
}