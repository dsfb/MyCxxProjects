#include <stdio.h>
#include <conio.h>
#include <string.h>

#define TAM_MAX_CADEIA 2056
#define TESTING 1

int strpos(char s[], char c)
{
    unsigned int i = 0;
    char mc = s[i]; /* variável "meu caractere"...!!! */

    while(mc != '\0')
    {
        if(mc == c)
            return i;
        mc = s[++i];        
    }

    return -1;
}

void main(void)
{
    char cadeia[TAM_MAX_CADEIA];
	char c;

    #ifdef TURBOC
    clrscr();
    #endif

    if(TESTING)
    {
    	printf("=============\n");
    	printf("Testing...\n");
    	printf("-------------\n");
    	strcpy(cadeia, "O Brasil possui um grande potencial turistico.");
        c = 'O';
    	printf("strpos(%s, %c) = %d\n", cadeia, c, strpos(cadeia, c));
    	strcpy(cadeia, "Nao v\240 embora.");
        c = '\240';
    	printf("strpos(%s, %c) = %d\n", cadeia, c, strpos(cadeia, c));
    	strcpy(cadeia, "A vida \202 bela!");
        c = '\202';
    	printf("strpos(%s, %c) = %d\n", cadeia, c, strpos(cadeia, c));
    	strcpy(cadeia, "Sil\210ncio!");        
    	printf("strpos(%s, %c) = %d\n", cadeia, c, strpos(cadeia, c));
    	strcpy(cadeia, "O telefone est\240 tocando.");
        c = '\240';
    	printf("strpos(%s, %c) = %d\n", cadeia, c, strpos(cadeia, c));
    	strcpy(cadeia, "Tchau!!!");
        c = '!';
    	printf("strpos(%s, %c) = %d\n", cadeia, c, strpos(cadeia, c));
    	strcpy(cadeia, "Ai!");
        c = 'a';
    	printf("strpos(%s, %c) = %d\n", cadeia, c, strpos(cadeia, c));
    	strcpy(cadeia, "Rua!");
        c = 'u';
    	printf("strpos(%s, %c) = %d\n", cadeia, c, strpos(cadeia, c));
    	strcpy(cadeia, "J\240 era!");
        c = 'r';
    	printf("strpos(%s, %c) = %d\n", cadeia, c, strpos(cadeia, c));
    	strcpy(cadeia, "Beleza!");
        c = 'e';
    	printf("strpos(%s, %c) = %d\n", cadeia, c, strpos(cadeia, c));
    	printf("=============\n");
    }

	printf("Digite a cadeia desejada: ");
	gets(cadeia);
    printf("Digite o caractere a ser encontrado: ");
    scanf("%c", &c);
    printf("strpos(%s, %c) = %d\n", cadeia, c, strpos(cadeia, c));
		
	puts("Pressione algo para sair!");
	getch();
}