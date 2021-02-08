#include <stdio.h>
/*
// Curso C Progressivo: www.cprogessivo.net
// O melhor curso de C! Online e gratuito !
// Apostila online, tutorial completo sobre
// a linguagem de programação C !
*/
int main()
{
    char nome[21], sobrenome[21];
 
    printf("Primeiro nome: ");
    scanf("%s", nome);
 
    printf("Ultimo sobrenome: ");
    scanf("%s", sobrenome);
 
    printf("Ola senhor %s, %s. Bem-vindo ao curso C Progressivo.\n", sobrenome, nome);

    printf("\nPressione algo para sair!\n");
	getch();

    return 0;
}
