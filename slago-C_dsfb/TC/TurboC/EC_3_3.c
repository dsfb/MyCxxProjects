#include <stdio.h>
#include <conio.h>

main()
{
    int n;
	
    clrscr();
	
    printf("Digite n: ");
    scanf("%d", &n);
	
    for (; n >= 0; n--) printf("%d\n", n);
	
    printf("\nPressione uma tecla para sair!");
    getch();
}