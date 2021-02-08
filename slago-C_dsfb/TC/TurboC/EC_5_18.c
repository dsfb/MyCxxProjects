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

int strpos(char s[], char c)
{
    int i = 0;

    while (s[i] != '\0')
    {
    	if (s[i] == c)
    	{
    		return i;
    	}
        i++;
    }

    return -1;
}

void strdel(char s[], unsigned int p)
{
    unsigned int i = 0;
    
    while(s[i] != '\0') i++;

    while(p < i)
    {
        s[p] = s[p + 1];
        p++;
    }    
}

void main(void)
{
	char x[35];
	
    strcpy(x, "Daniel Ferreira Bruno");

    printf("\nO comprimento de '%s' eh: %u\n", x, strlen(x));

    strdel(x, 2);

    printf("\nO comprimento de '%s' eh: %u\n", x, strlen(x));    

    strcpy(x, "12%");

    printf("\nO comprimento de '%s' eh: %u\n", x, strlen(x));

    strdel(x, 2);

    printf("\nO comprimento de '%s' eh: %u\n", x, strlen(x));

    strdel(x, 2);

    printf("\nO comprimento de '%s' eh: %u\n", x, strlen(x));

    strcpy(x, "Daniel Silva");

    printf("\nO comprimento de '%s' eh: %u\n", x, strlen(x));

    strdel(x, 0);

    printf("\nO comprimento de '%s' eh: %u\n", x, strlen(x));

    printf("Pressione algo para sair");

	getch();
}