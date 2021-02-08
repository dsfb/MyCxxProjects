#include <stdio.h>
#include <conio.h>

void minimax(float v[], int n, float *a, float *b)
{
	int i = 0;
	*a = v[0];
	*b = v[0];

	while (i < n)
	{
        if (v[i] < *a)
        {
            *a = v[i];
        }

        if (v[i] > *b)
        {
            *b = v[i];
        }

	    i++;
	}
}

void main(void)
{
	float num[] = {1, 2, 3, 4, 5};

	float min, max;

	minimax(num, 5, &min, &max);

	printf("\nO minimo: %.2f, maximo: %.2f\n", min, max);

    printf("Pressione algo para sair!");

	getch();
}