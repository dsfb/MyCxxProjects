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

void main(void)
{
	char x[35];
	char c;

    strcpy(x, "Daniel Ferreira Bruno");

    printf("\nO comprimento de '%s' eh: %u\n", x, strlen(x));
    
    c = 'a';

    printf("O primeiro indice de '%c' em '%s' eh: %d\n", c, x, strpos(x, c));

    c = 'l';

    printf("O primeiro indice de '%c' em '%s' eh: %d\n", c, x, strpos(x, c));

    c = 'F';

    printf("O primeiro indice de '%c' em '%s' eh: %d\n", c, x, strpos(x, c));

    c = 'x';

    printf("O primeiro indice de '%c' em '%s' eh: %d\n", c, x, strpos(x, c));

    strcpy(x, "12%");

    c = '%';

    printf("O primeiro indice de '%c' em '%s' eh: %d\n", c, x, strpos(x, c));

    c = '2';

    printf("O primeiro indice de '%c' em '%s' eh: %d\n", c, x, strpos(x, c));

    c = 'F';

    printf("O primeiro indice de '%c' em '%s' eh: %d\n", c, x, strpos(x, c));

    printf("\nO comprimento de '%s' eh: %u\n", x, strlen(x));

    strcpy(x, "Daniel Silva");

    c = 'S';

    printf("O primeiro indice de '%c' em '%s' eh: %d\n", c, x, strpos(x, c));

    printf("\nO comprimento de '%s' eh: %u\n", x, strlen(x));

    printf("Pressione algo para sair");

	getch();
}