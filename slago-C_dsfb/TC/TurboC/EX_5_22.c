#include <stdio.h>
#include <conio.h>

void main(void) {
	static char menu[][7] = {"abrir", "editar", "salvar", "sair"};
	int i;
	#ifdef TURBOC
    clrscr();
    #endif

	for (i = 0; i < 4; i++)
		puts(menu[i]);
	getch();
}