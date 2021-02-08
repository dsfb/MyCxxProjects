#include <stdio.h>
#include <conio.h>

main()
{
	int i, j, m, n;
    
    clrscr();
	printf("Digite m: ");
	scanf("%d", &m);
	printf("Digite n: ");
	scanf("%d", &n);

    for(j = 0; j < m; j++)
    {
    	printf("\n");
        for(i = 0; i < n; i++)
        {
            if ((i + j) % 2 == 0) textcolor(YELLOW);
            else textcolor(GREEN);
            cprintf("%c", 219);
        }       
    }

    printf("\n\nPressione algo para sair!\n");
    getch();
}