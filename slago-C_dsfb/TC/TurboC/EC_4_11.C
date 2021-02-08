#include <stdio.h>
#include <conio.h>
#include <math.h>

double myAbs(double n)
{
    if (n < 0) return -n;

    return n;
}

double mySqrt(float n)
{
    double r = 1;

    while(myAbs((r*r) - n) >= 0.001)
    {
	r = ((r*r) + n)/(2*r);
    }

    return r;
}

main()
{
    clrscr();
    printf("A raiz quadrada de 2 eh: %.f\n", mySqrt(2));
    printf("A raiz quadrada de 2 eh: %.f\n", sqrt(2));
    printf("A raiz quadrada de 3 eh: %.f\n", mySqrt(3));
    printf("A raiz quadrada de 3 eh: %.f\n", sqrt(3));
    printf("A raiz quadrada de 4 eh: %.f\n", mySqrt(4));
    printf("A raiz quadrada de 4 eh: %.f\n", sqrt(4));
    getch();
}