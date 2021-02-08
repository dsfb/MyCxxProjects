#include <stdio.h>
#include <conio.h>

main() {
    float a, b, c;

    clrscr();
    printf("\nInforme trˆs n£meros: ");
    scanf("%f %f %f", &a, &b, &c);

    if( a < b + c && b < a + c && c < a + b ) {
	printf("\n um triƒngulo: ");
	if( a == b && b == c ) printf("equil tero");
	else if( a == b || a == c || b == c ) printf("is¢sceles");
	else printf("escaleno");
    }
    else printf("\nNao ‚ um triƒngulo");

    getch();
}