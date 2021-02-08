#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>

main() {
	int col=40, lin=12, caractere;

	clrscr();

	while(1) {
	    gotoxy(col, lin);
	    putch(219);

        caractere = toupper(getch());
	    switch(caractere) 
	    {
	    	case 0: break;
	    	case 72:
	        case 'N': if(lin > 1) lin--; break;
	        case 80:
	        case 'S': if(lin < 24) lin++; break;
	        case 77:
	        case 'L': if(col < 80) col++; break;
	        case 75:
	        case 'O': if(col > 1) col--; break;
	        case 'F': exit(1); break;
	        case 'C': clrscr(); break;
	        default: printf("\nVoce digitou: %d", caractere);
	    }
	}
}