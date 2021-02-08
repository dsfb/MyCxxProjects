#include <stdio.h>
#include <conio.h>
#include <math.h>

#define quantity 10

double calculaDp();

void main(void)
{
	double dp;
	
    clrscr();

    dp = calculaDp();

	printf("O desvio padrao da colecao eh: %.5lf\n", dp);

	printf("\nPressione algo para sair.");
    getch();
}

double calculaDp()
{
	int i;
	double colecao[quantity];

	double xM, somaX = 0, somaD = 0;

	for(i = 0; i < quantity; i++)
    {
    	printf("Digite o numero real %d:", i + 1);
    	scanf("%lf", &colecao[i]);
    	somaX += colecao[i];
    }
    
    xM = somaX / quantity;

    for(i = 0; i < quantity; i++)
    {
    	somaD += pow(colecao[i] - xM, 2);
    }

    return sqrt(somaD/(quantity - 1));
}