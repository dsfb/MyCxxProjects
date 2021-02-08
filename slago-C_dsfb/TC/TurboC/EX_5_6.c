#include <stdio.h>
#include <conio.h>

void main(void)
{
	static char ds[] = {'D', 'S', 'T', 'Q', 'Q', 'S', 'S'};

    clrscr();

	printf("%d\n", sizeof(ds)/sizeof(char));

	getch();
}