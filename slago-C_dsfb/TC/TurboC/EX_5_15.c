#include <stdio.h>
#include <conio.h>

void main(void)
{
	char x[] = "um";
	char y[] = "um";

	printf("\n%s == %s resulta em %s\n", x, y, 
	x == y ? "verdade" : "falso");

	getch();
}