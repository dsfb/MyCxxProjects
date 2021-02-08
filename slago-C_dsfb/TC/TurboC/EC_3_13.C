#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>

main() {
	int col=40, lin=12, caractere = 0, cor = 1;
    
    short int ativaRastro = 1,
              ativaBorracha = 0,
              selecionaCor = 0;

	clrscr();
    
    while(1) {
        gotoxy(1, 23);

	    printf("F2 - (des)ativa rastro, F3 - (des)ativa borracha, F4 - seleciona cor, F5 - fim");
        
        if (selecionaCor)
        {
        	gotoxy(1, 24);
            printf("1. YELLOW 2. RED 3. GREEN");
        }
        else
        {
            gotoxy(1, 24);
            printf("                         ");
        }
        
        if (ativaBorracha)
        {
        	textcolor(BLACK);
        }
        else
        {
        	switch(cor)
        	{
        		case 1: textcolor(YELLOW); break;
                case 2: textcolor(RED); break;
                case 3: textcolor(GREEN); break;
        	}
        }

	    gotoxy(col, lin);

	    if (ativaRastro || ativaBorracha)
	    {
            putch(219);	    	
	    }	    
        
        caractere = toupper(getch());
        if (selecionaCor)
        {
        	switch(caractere)
            {
                case 0: break;
                case 49: cor = 1; 
                         selecionaCor = 0;
                         break;
                case 50: cor = 2; 
                         selecionaCor = 0;
                         break;
                case 51: cor = 3; 
                         selecionaCor = 0;
                         break;
                case 62: selecionaCor = !selecionaCor; break;
                case 63: exit(1);
            }
        }
    	else
    	{
    		switch(caractere) 
		    {
		    	case 0: break;
		    	case 60: ativaRastro = !ativaRastro;
	                     break;
		    	case 72: if(lin > 1) lin--; break;
		        case 80: if(lin < 24) lin++; break;
		        case 77: if(col < 80) col++; break;
		        case 75: if(col > 1) col--; break;
                case 61: ativaBorracha = !ativaBorracha; break;
                case 62: selecionaCor = !selecionaCor; break;
		        case 63: exit(1);
		    }
    	}
	}
}