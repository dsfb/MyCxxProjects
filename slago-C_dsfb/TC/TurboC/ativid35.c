#include <stdio.h>
#include <conio.h>
#include <string.h>

#define TAM_FRASE_MAX 512

#define TESTING 1

int strContains(char str[], char c)
{
	unsigned int i;

	for(i = 0; str[i] != '\0'; i++)
	{
		if(c == str[i])
			return 1;
	}

	return 0;
}

int ehCaractereValidoEspecial(char c)
{
	return strContains("ÁÀÃÂÉÊÍÓÔÕÚáàãâéêíóôõúÇç'", c);
}

int ehCaractereValido(char c)
{
	if(ehCaractereValidoEspecial(c))
	{
		return 1;
	}

	if ((c >= 65) && (c <= 90))
	{
		return 1;
	}
	
	if ((c >= 97) && (c <= 122))
	{
		return 1;
	}

	return 0;
}

unsigned int leQtdePalavras(char frase[])
{
	unsigned int qtde = 0, i = 0;
	/*
	char c = frase[i];
	int ok = 0;
	char carFinEsp[] = ",?;.!";

	while (c != '\0')
	{
		if(ehCaractereValido(c))
		{
			if (!ok)
		   	{
			   ok = 1;
		   	}
		}
		else if((c == ' ') || 
			(strContains(carFinEsp, c)))
		{
			if(ok)
			{
				qtde++;
				ok = 0;
			}			
		}
		else
		{
			ok = 0;
		}

		c = frase[++i];
	}
	*/

	while (frase[i] != '\0')
	{
		if (frase[i] != ' ') i++;
		else
		{
			qtde++;
			while (frase[i] == ' ') i++;
		}
	} qtde++;

	return qtde;
}

void main(void)
{
    char frase[TAM_FRASE_MAX];
	
    #ifdef TURBOC
    clrscr();
    #endif

    if(TESTING)
    {
    	printf("=============\n");
    	printf("Testing...\n");
    	printf("-------------\n");
    	strcpy(frase, "O Brasil possui um grande potencial turistico.");
    	printf("leQtdePalavras(%s) = %u\n", frase, leQtdePalavras(frase));
    	strcpy(frase, "Espantoso!");
    	printf("leQtdePalavras(%s) = %u\n", frase, leQtdePalavras(frase));
    	strcpy(frase, "Nao v\240 embora.");
    	printf("leQtdePalavras(%s) = %u\n", frase, leQtdePalavras(frase));
    	strcpy(frase, "A vida \202 bela!");
    	printf("leQtdePalavras(%s) = %u\n", frase, leQtdePalavras(frase));
    	strcpy(frase, "Joao e Maria.");
    	printf("leQtdePalavras(%s) = %u\n", frase, leQtdePalavras(frase));
    	strcpy(frase, "Sil\210ncio!");
    	printf("leQtdePalavras(%s) = %u\n", frase, leQtdePalavras(frase));
    	strcpy(frase, "O telefone est\240 tocando.");
    	printf("leQtdePalavras(%s) = %u\n", frase, leQtdePalavras(frase));
    	strcpy(frase, "Tchau!");
    	printf("leQtdePalavras(%s) = %u\n", frase, leQtdePalavras(frase));
    	strcpy(frase, "Tchau!!!");
    	printf("leQtdePalavras(%s) = %u\n", frase, leQtdePalavras(frase));
    	strcpy(frase, "Ai!");
    	printf("leQtdePalavras(%s) = %u\n", frase, leQtdePalavras(frase));
    	strcpy(frase, "Rua!");
    	printf("leQtdePalavras(%s) = %u\n", frase, leQtdePalavras(frase));
    	strcpy(frase, "J\240 era!");
    	printf("leQtdePalavras(%s) = %u\n", frase, leQtdePalavras(frase));
    	strcpy(frase, "Beleza!");
    	printf("leQtdePalavras(%s) = %u\n", frase, leQtdePalavras(frase));
    	printf("=============\n");
    }

	printf("Digite a frase desejada: ");
	gets(frase);
	
	printf("A qtde de palavras na frase '%s' \202: %u.\n",
		frase, leQtdePalavras(frase));
		
	puts("Pressione algo para sair!");
	getch();
}