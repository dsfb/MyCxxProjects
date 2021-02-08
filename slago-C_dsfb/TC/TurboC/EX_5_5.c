#include <stdio.h>
#include <conio.h>

#define max 5

void main(void)
{
	static int A[max] = {9, 3, 2, 7};

	auto int i;

	for(i = 0; i < max; i++)
	    printf("%d\n", A[i]);

	getch();
}