#include <stdio.h>
#include <conio.h>

void perm(int p, int q) {
	int x;
	x = p;
	p = q;
	q = x;
}

void main(void)
{
	int a = 3, b = 7;
	perm(a, b);
	printf("%d %d\n", a, b);

	printf("\nPressione algo para sair!\n");
	getch();
}