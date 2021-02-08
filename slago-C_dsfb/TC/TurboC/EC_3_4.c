#include <stdio.h>
#include <conio.h>

main()
{
    float vlrPolegadas;
    float vlrCms;
	
    clrscr();
	
    for (vlrPolegadas = 0; vlrPolegadas <= 10; vlrPolegadas += 0.5)
    {
        vlrCms = vlrPolegadas * 2.54;
		printf("%.1f polegadas = %.2f centimetros\n", vlrPolegadas, vlrCms);
    }
	
    printf("\nPressione algo para sair!");
    getch();
}