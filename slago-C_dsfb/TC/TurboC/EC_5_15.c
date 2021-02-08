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

void strupr(char s[])
{
	unsigned int i = 0;

	while(s[i] != '\0')
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] = s[i] + 'A' - 'a';
		}
		i++;
	}
}

void main(void)
{
	char x[35];

    strcpy(x, "Daniel Silva");

	printf("\nO comprimento de '%s' eh: %u\n", x, strlen(x));
    
    printf("\n'%s' em maiusculo eh: ", x);

    strupr(x);

    printf("'%s'\n", x);

    strcpy(x, "12%");

	printf("\nO comprimento de '%s' eh: %u\n", x, strlen(x));

    printf("\n'%s' em maiusculo eh: ", x);

    strupr(x);

    printf("'%s'\n", x);

    strcpy(x, "Daniel Silva Ferreira Bruno");

	printf("\nO comprimento de '%s' eh: %u\n", x, strlen(x));
    
    printf("\n'%s' em maiusculo eh: ", x);

    strupr(x);

    printf("'%s'\n", x);

    printf("Pressione algo para sair");

	getch();
}