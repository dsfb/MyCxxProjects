#include <stdio.h>
#include <conio.h>

main()
{
    unsigned int n, i;
    unsigned long long int fatorial;
	
    clrscr();
	
    printf("Digite n: ");
    scanf("%u", &n);
	
    for(i = 1, fatorial = 1; i <= n; i++) fatorial *= i;
	
    printf("O fatorial de %u: %u\n", n, fatorial);
	
    printf("\nPressione alguma tecla para sair!");
    getch();
}