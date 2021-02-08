#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define tam 10

#define maxAB(a, b) ((a) > (b) ? (a) : (b))

#define minAB(a, b) ((a) < (b) ? (a) : (b))

static short matrizAberta[tam][tam];

void imprimeMatriz(short matriz[tam][tam])
{
	int i, j;

	printf("+ ");
	for (i = 1; i < tam - 1; i++)
		printf("- ");
	printf("+\n");	
	for (i = 1; i < tam - 1; i++)
	{
		printf("| ");
		for (j = 1; j < tam - 1; j++)
		{
			printf("%d ", matriz[i][j]);
		}
		printf("|\n");
	}

	printf("+ ");
	for (i = 1; i < tam - 1; i++)
		printf("- ");
	printf("+\n");
}

int contaBombasAdjacentes(int x, int y, int xB[], int yB[])
{
	int i, j, k, cont = 0;

	for (i = maxAB(x - 1, 1); i < minAB(x + 2, tam - 1); i++)
	{
		for (j = maxAB(y - 1, 1); j < minAB(y + 2, tam - 1); j++)
		{
			for (k = 0; k < tam; k++)
			{
				if ((xB[k] == i) &&
					(yB[k] == j))
				{
					cont++;
				}					
			}
		}
	}

	return cont;
}

void marcaPosicoesLivresMatriz(short matriz[tam][tam])
{
	int i, j, k = 0;
	int xB[tam];
	int yB[tam];

	for (i = 1; i < tam - 1; i++)
	{
		for (j = 1; j < tam - 1; j++)
		{
			if(matriz[i][j] == 9)
			{
				xB[k] = i;
				yB[k++] = j;
			}
		}
	}

	for (i = 1; i < tam - 1; i++)
	{
		for (j = 1; j < tam - 1; j++)
		{
			if (!matriz[i][j])
			{
				matriz[i][j] = 
					contaBombasAdjacentes(i, j, xB, yB);	
			}
		}
	}	
}

int marcaPosicaoComoAberta(short matriz[tam][tam], int x, int y)
{
	int i, j;

	

	if (matriz[x][y] < 9)
	{
		matrizAberta[x][y] = 
			matriz[x][y];

		printf("Certo! Voce digitou uma posicao valida! Continuando o jogo...!\n");

		printf("    1 2 3 4 5 6 7 8\n");
		printf("  + ");
		for (i = 1; i < tam - 1; i++)
			printf("- ");
		printf("+\n");	
		for (i = 1; i < tam - 1; i++)
		{
			printf("%d | ", i);
			for (j = 1; j < tam - 1; j++)
			{
				if (matrizAberta[i][j] == -1)
				{
					printf("? ");
				}
				else 
					printf("%d ", 
						matrizAberta[i][j]);
			}
			printf("|\n");
		}

		printf("  + ");
		for (i = 1; i < tam - 1; i++)
			printf("- ");
		printf("+\n");
	}
	else
	{
		printf("Certo! Voce digitou uma posicao com bomba! Finalizando o jogo...!\n");
	}	

	return 0;
}

void subPreencheMatriz(short matriz[tam][tam], int dificuldade)
{
	int i, j, numBombas;

	i = 0;
	for (j = 0; j < tam; j++)
	{
		matriz[i][j] = 1;
		matriz[j][i] = 1;
	}

	i = tam - 1;
	for (j = 0; j < tam; j++)
	{
		matriz[i][j] = 1;
		matriz[j][i] = 1;
	}

	for (i = 1; i < tam - 1; i++)
	{
		for (j = 1; j < tam - 1; j++)
		{
			matriz[i][j] = 0;
		}
	}

	numBombas = 3*dificuldade;

	while (numBombas--)
	{
		i = (rand() % (tam - 2)) + 1;
		j = (rand() % (tam - 2)) + 1;
		matriz[i][j] = 9;
	}

	for (i = 0; i < tam - 1; i++)
	{
		for (j = 0; j < tam - 1; j++)
		{
			matrizAberta[i][j] = -1;
		}
	}
}

void main(void)
{
	short matriz[tam][tam];

	int dificuldade, posX, posY;

	clrscr();

	do
	{
		printf("Digite o grau de dificuldade:\n");
		printf("1. Facil\n");
		printf("2. Medio\n");
		printf("3. Dificil\n");

		scanf("%d", &dificuldade);
	} while ((dificuldade < 1) ||
		(dificuldade > 3));

	srand(time(NULL));

	subPreencheMatriz(matriz, dificuldade);
	imprimeMatriz(matriz);
	printf("\nImpressao com a marcacao das posicoes livres:\n");
	marcaPosicoesLivresMatriz(matriz);
	imprimeMatriz(matriz);
	
	printf("\nDigite x e y: ");
	scanf("%d %d", &posX, &posY);

	printf("\n");

	marcaPosicaoComoAberta(matriz, posX, posY);

	printf("\nPressione algo para sair!\n");
	getch();
}