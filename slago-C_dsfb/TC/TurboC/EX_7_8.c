#include <stdio.h>
#include <conio.h>

void main(void)
{
	static int v[5] = {17, 29, 36,  44, 51};

	int i;

	for (i = 0; i < 5; i++)
		printf("\n%d ", *(v + i));

	getch();
}