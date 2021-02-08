#include <stdio.h>
#include <conio.h>

void main(void)
{
	#ifdef TURBOC
    clrscr();
    #endif
	puts("");
	puts("   | O | X ");
	puts("---+---+---");
	puts(" O | X | O ");
	puts("---+---+---");
	puts(" X |   |   ");
	getch();
}