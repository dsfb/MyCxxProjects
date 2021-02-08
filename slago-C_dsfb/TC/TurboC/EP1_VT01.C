#include <stdio.h>
#include <conio.h>

#define ESC 27

main()
{
    char t;

    do {
	printf("\nPressione uma tecla.");
	t = getch();
	if (t != 0) printf("\nCodigo ASCII: %d", t);
	else printf("\nCodigo de varredura: %d", getch());
    } while( t != ESC);
}