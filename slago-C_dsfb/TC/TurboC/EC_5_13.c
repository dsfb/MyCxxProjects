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

void main(void)
{
	char x[35];

	strcpy(x, "teste");
	printf("\n'%s' = 'teste'", x);

	strcpy(x, "Daniel");
	printf("\n'%s' = 'Daniel'\n", x);

	strcpy(x, "Pressione algo para terminar!");
	printf("%s", x);
	getch();
}