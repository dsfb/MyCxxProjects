#include <stdio.h>
#include <conio.h>

void main(void)
{
	int *p = (int *) 0x1000;
	p++;  printf("%p ", p);
	p-=3; printf("%p ", p);
	p+=2; printf("%p ", p);
	p--;  printf("%p ", p);

	printf("\nPressione algo para sair!\n");
	getch();
}