#include <stdio.h>
#include <conio.h>
#include <string.h>

void meuPuts(char s[])
{
    int i = 0;

    while (*(s + i) != '\0')
    {
    	putchar(*(s + i));
    	i++;
    }
    putchar('\n');
}

void main(void)
{
	char s[] = "0";

	meuPuts(s);

	strcpy(s, "A vida eh bela!");

	meuPuts(s);

	printf("\nPressione algo para sair!\n");
	getch();
}