#include <stdio.h>
#include <conio.h>

main()
{
    float a, b, m;

    clrscr();
    printf("\n Informe as duas notas obtidas: ");
    scanf("%f %f", &a, &b);

    m = (a+b)/2;

    if (m >= 7.0) {
	textcolor(BLUE);
	cprintf("\n Aprovado");
    }
    else {
	textcolor(RED);
	cprintf("\n Reprovado");
    }

    getch();
}