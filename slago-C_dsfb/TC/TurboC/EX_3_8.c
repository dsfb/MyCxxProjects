#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>

main() {
	int col=40, lin=12;

	clrscr();

	while(1) {
	    gotoxy(col, lin);
	    putch(219);

	    switch(toupper(getch())) 
	    {
	        case 'N': if(lin > 1) lin--; break;
	        case 'S': if(lin < 24) lin++; break;
	        case 'L': if(col < 80) col++; break;
	        case 'O': if(col > 1) col--; break;
	        case 'F': exit(1);
	    }
	}
}