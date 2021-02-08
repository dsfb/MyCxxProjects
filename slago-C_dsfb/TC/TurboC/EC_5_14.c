#include <stdio.h>
#include <conio.h>

void strcpy(char s[], char t[])
{
	int i = 0;

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

void main(void)
{
	char x[35];

    strcpy(x, "Daniel Silva");

	printf("\nO comprimento de '%s' eh: %u\n", x, strlen(x));

    strcpy(x, "");

	printf("\nO comprimento de '%s' eh: %u\n", x, strlen(x));

    strcpy(x, "Daniel Silva Ferreira Bruno");

	printf("\nO comprimento de '%s' eh: %u\n", x, strlen(x));

    printf("Pressione algo para sair");

	getch();
}