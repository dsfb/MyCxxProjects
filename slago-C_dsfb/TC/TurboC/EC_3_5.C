#include <stdio.h>
#include <conio.h>

main()
{
    float x, num;
    unsigned int n, i;
	
    clrscr();
	
    printf("Digite o real x: ");
    scanf("%f", &x);
	
    printf("Digite o natural n: ");
    scanf("%u", &n);
	
    num = 1;
	
    for (i = 0; i < n; i++) num *= x;
	
    printf("%.2f elevado a %u: %.2f\n", x, n, num);
	
    printf("\nPressione uma tecla para sair!\n");
    getch();
}