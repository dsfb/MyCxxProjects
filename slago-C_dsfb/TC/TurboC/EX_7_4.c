#include <stdio.h>
#include <conio.h>

void main(void)
{
	int v = 0x4142;
	char *a;
	int  *b;
	long *c;
	a = b = c = &v;
	printf("%c %x %lx\n", *a, *b, *c);

	printf("\nPressione algo para sair!\n");
	getch();
}