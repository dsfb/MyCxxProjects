#include <stdio.h>
#include <conio.h>

void strcpy(char s[], char t[])
{
	unsigned int i = 0;

	while(t[i] != '\0')
	{
	    s[i] = t[i];
	    i++;
	}

	s[i] = '\0';
}

unsigned int strlen(char s[])
{
	unsigned int i = 0;

	while(s[i] != '\0') i++;

    return  i;
}

void strcat(char s[], char t[])
{
	unsigned int i = 0, fimS = 0;

    while(s[fimS] != '\0') fimS++;

    while(t[i] != '\0') s[fimS + i] = t[i++];

    s[fimS + i] = '\0';
}

void main(void)
{
	char x[35];

    strcpy(x, "Daniel ");

    strcat(x, "Silva");

	printf("\nO comprimento de '%s' eh: %u\n", x, strlen(x));
    
    printf("\n'%s' em maiusculo eh: ", x);

    strupr(x);

    printf("'%s'\n", x);

    strcpy(x, "1");

    strcat(x, "2");

    strcat(x, "%");

	printf("\nO comprimento de '%s' eh: %u\n", x, strlen(x));

    printf("\n'%s' em maiusculo eh: ", x);

    strupr(x);

    printf("'%s'\n", x);

    strcpy(x, "Daniel ");

    strcat(x, "Silva ");

    strcat(x, "Ferreira ");

    strcat(x, "Bruno");

	printf("\nO comprimento de '%s' eh: %u\n", x, strlen(x));
    
    printf("\n'%s' em maiusculo eh: ", x);

    strupr(x);

    printf("'%s'\n", x);

    printf("Pressione algo para sair");

	getch();
}
