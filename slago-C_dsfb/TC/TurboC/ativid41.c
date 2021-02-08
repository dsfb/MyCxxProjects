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
	float v[] = {0, -3, -10.5, 15.5, 20, 37};
	
	float min, max;
	float x, y;
	int tam = 6;

	minimax(num, 5, &min, &max);
	minimax(v, tam, &x, &y);

	printf("\nO minimo: %.2f, maximo: %.2f\n", min, max);
	printf("\nO minimo: %.2f, maximo: %.2f\n", x, y);

    printf("Pressione algo para sair!");

	getch();
}