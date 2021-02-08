#include <stdio.h>
#include <conio.h>

void main(void)
{
	char   *a = (char *) 0x1000;
	int    *b = (int *) 0x1000;
	float  *c = (float *) 0x1000;
	double *d = (double *) 0x1000;
	printf("%p %p %p %p\n", a + 1, b + 1, c + 1, d + 1);

	printf("\nPressione algo para sair!\n");
	getch();
}