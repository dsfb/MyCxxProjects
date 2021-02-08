#include <stdio.h>
#include <conio.h>

main() {
    int   h;
    float s;

    clrscr();
    printf("\nHoras trabalhadas ");
    scanf("%d", &h);

    s = h * 19.50;

    if( s > 1500.00 )
	s = 0.90*s;

    printf("\nSalario liquido: R$ %.2f", s);

    getch();
}