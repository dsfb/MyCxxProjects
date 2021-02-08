#include <stdio.h>
#include <conio.h>
#include <time.h>

static unsigned s = 0;

#define debug 0

unsigned prepareSemente(void)
{
	auto unsigned s = 0;
	auto long int t = 0;

	do
	{
		time(&t);
		if (debug)
		{
			printf("\nt candidato = %ld", t);	
		}		
	} while (t % 10000 == 0);

	if (debug)
	{
		printf("\nt inicial = %ld\n", t);	
	}	
    
    s = 0;
	s += t % 10;
	t /= 10;
	s += (t % 10) * 10;
	t /= 10;
	s += (t % 10) * 100;
	t /= 10;
	s += (t % 10) * 1000;

	if (debug)
	{
		printf("s inicial = %u\n", s);	
	}	
	return s;
}

int aleat(void)
{
	auto unsigned n = s%100;

	if (debug)
	{
		printf("Novo n = %u\n", s);	
	}

	s += s/10;

	if (debug)
	{
		printf("Novo s = %u\n", s);
	}

	return n;
}

void main(void)
{
	int i;

	s = prepareSemente();

	printf("\nVoce quer limpar a tela? (1-Sim) (0-Nao) ");
	scanf("%d", &i);

	if(i)
	{
		clrscr();
	}
	
	do {
		printf("Exibindo 5 numeros aleatorios: ");
	    for (i = 0; i < 5; i++)
	    {
	    	printf("%d ", aleat());
	    }

	    printf("\nVoce quer continuar? (1-Sim) (0-Nao) ");
	    scanf("%d", &i);
	} while (i);
    printf("Pressione algo para sair!");
    getch();
}