#include <stdio.h>
#include <conio.h>

void imprimeEmBin(unsigned int n)
{
    if (n == 0)
    {
       printf("0");
    }
    else
    {
	imprimeEmBin(n/2);
	printf("%u", n%2);
    }
}

main()
{
    imprimeEmBin(13);

    getch();
}