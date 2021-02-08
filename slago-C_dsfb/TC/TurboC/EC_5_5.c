#include <stdio.h>
#include <conio.h>
#include <math.h>

#define quantity 2

void main(void)
{
	double x[quantity],
	       pol[quantity], valor;

	int i, j;
    
    clrscr();

	for(i = 0; i < quantity; i++)
	{
		printf("Digite o coef. %d: ", i);
		scanf("%lf", &pol[i]);

		printf("Digite o x%d: ", i);
		scanf("%lf", &x[i]);
	}

	for (i = 0; i < quantity; i++)
	{
        valor = 0;
        for (j = 0; j < quantity; j++)
        {
        	valor += pol[j]*pow(x[i], quantity - j - 1);
        }

        printf("p[%lf] = %lf\n", x[i], valor);
	}

    printf("Pressione algo para sair!");
	getch();
}