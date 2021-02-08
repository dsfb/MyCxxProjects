#include <stdio.h>
#include <conio.h>

#define qtde 2

unsigned long int myStrLen(char s[])
{
	if (*s == '\0')
	{
		return 0;
	}

	return 1 + myStrLen(s + 1);
}

void main(void)
{
	char strings[2][10]; 
	int i;

	strcpy(*strings, "");
	strcpy(*(strings + 1), "A vida eh bela!");

	for (i = 0; i < qtde; i++)
	{
		printf("Strlen('%s') = %lu\n", strings[i], myStrLen(strings[i]));
	}

	printf("\nPressione algo para sair!\n");
	getch();
}