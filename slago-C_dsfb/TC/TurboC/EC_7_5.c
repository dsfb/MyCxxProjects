#include <stdio.h>
#include <conio.h>

#define qtde 5

void carrega(int v[], int n)
{
	int i = 0;

	while(i < n)
	{
		printf("Digite v[%d]: ", i);
		scanf("%d", &v[i]);
		i++;
	}    
}

void main(void)
{
	int v[qtde], i;

	carrega(v, qtde);

	for (i = 0; i < qtde; i++)
	{
		printf("v[%d] = %d\n", i, v[i]);
	}

	printf("\nPressione algo para sair!\n");
	getch();
}