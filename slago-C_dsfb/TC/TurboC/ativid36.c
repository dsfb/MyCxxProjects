#include <stdio.h>
#include <conio.h>
#include <string.h>

#define TAM_MAX_CADEIA 2056
#define TESTING 1

void imprimeCadeiaInvertidaRecursiva(char cadeia[], unsigned int i)
{
    if (cadeia[i] != '\0')
    {
        imprimeCadeiaInvertidaRecursiva(cadeia, i + 1);
        printf("%c", cadeia[i]);
    }
}

void imprimeCadeiaInvertida(char cadeia[])
{
    printf("String fornecida: '%s'\n", cadeia);
    printf("Cadeia invertida: '");
    imprimeCadeiaInvertidaRecursiva(cadeia, 0);
    printf("'\n");
}

void main(void)
{
    char cadeia[TAM_MAX_CADEIA];
	
    #ifdef TURBOC
    clrscr();
    #endif

    if(TESTING)
    {
    	printf("=============\n");
    	printf("Testing...\n");
    	printf("-------------\n");
    	strcpy(cadeia, "O Brasil possui um grande potencial turistico.");
    	imprimeCadeiaInvertida(cadeia);
    	strcpy(cadeia, "Nao v\240 embora.");
    	imprimeCadeiaInvertida(cadeia);
    	strcpy(cadeia, "A vida \202 bela!");
    	imprimeCadeiaInvertida(cadeia);
    	strcpy(cadeia, "Sil\210ncio!");
    	imprimeCadeiaInvertida(cadeia);
    	strcpy(cadeia, "O telefone est\240 tocando.");
    	imprimeCadeiaInvertida(cadeia);
    	strcpy(cadeia, "Tchau!!!");
    	imprimeCadeiaInvertida(cadeia);
    	strcpy(cadeia, "Ai!");
    	imprimeCadeiaInvertida(cadeia);
    	strcpy(cadeia, "Rua!");
    	imprimeCadeiaInvertida(cadeia);
    	strcpy(cadeia, "J\240 era!");
    	imprimeCadeiaInvertida(cadeia);
    	strcpy(cadeia, "Beleza!");
    	imprimeCadeiaInvertida(cadeia);
    	printf("=============\n");
    }

	printf("Digite a cadeia desejada: ");
	gets(cadeia);	
    imprimeCadeiaInvertida(cadeia);
		
	puts("Pressione algo para sair!");
	getch();
}