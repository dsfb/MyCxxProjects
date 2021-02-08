#include <stdio.h>
#include <conio.h>

void strcpy(char s[], char t[])
{
    unsigned int i = 0;

    while(t[i] != '\0')
    {
        s[i] = t[i];
        i++;
    }

    s[i] = '\0';
}

unsigned int strlen(char s[])
{
    unsigned int i = 0;

    while(s[i] != '\0') i++;

    return  i; 
}

int strContains(char s[], char c)
{
    unsigned int i = 0;

    while(s[i] != '\0')
    {
        if (s[i] == c) return 1;
        i++;
    }

    return 0;
}

void desenha(int xI, int yI, char cF[], int redesenhar);

/* É assumido que cF tem pelo menos 3 caracteres... */
void redesenha(int xI, int yI, char cF[])
{
    /* útil para redesenhar subcadeias como:
        '052', '205', 
        '036' e '603'.
    */
    unsigned int i;
    char newCF[5];

    if (strlen(cF) >= 3)
    {
        if (strContains(cF, '0') &&
            strContains(cF, '5') &&
            strContains(cF, '2'))
        {
            /* redesenho de caso 
                particular: 052! */
            strcpy(newCF, cF);

            switch(cF[2])
            {
                case '0':
                    
                    break;
                case '5':
                    
                    break;
                case '2':
                    newCF[3] = '0';                    
                    break;
            }

            newCF[4] = '\0';

            /*desenha(xI, yI, newCF, 0);*/
        }
        else if (strContains(cF, '0') &&
            strContains(cF, '3') &&
            strContains(cF, '6'))
        {
            /* redesenho de caso 
                particular: 036! */
            gotoxy(0, 0);
            printf("Redesenhando 036...");
            getch();
        }
    }    
}

void desenha(int xI, int yI, char cF[], int redesenhar)
{
    char scF[3];
    int i = 0;

    while(cF[i] != '\0')
    {
        gotoxy(yI, xI);

        switch(cF[i])
        {
            case '0':
                putch('-');
                yI += 1;
                gotoxy(yI, xI);
                putch('-');
                switch(cF[i + 1])
                {
                    case '0':
                        yI += 1;
                        break;
                    case '1':
                        yI += 2;
                        xI -= 1;
                        break;
                    case '2':
                        yI += 1;
                        xI -= 1;
                        break;
                    case '3':
                        yI -= 1;
                        xI -= 1;
                        break;
                    case '4':
                        break;
                    case '5':
                        xI += 1;
                        break;
                    case '6':
                        yI += 1;
                        xI += 1;
                        break;
                }
                break;
            case '1':
                putch('/');
                yI += 2;
                xI -= 1;
                gotoxy(yI, xI);
                putch('/');
                switch(cF[i + 1])
                {
                    case '1':
                        yI += 2;
                        xI -= 1;
                        break;
                    case '3':
                        xI -= 1;
                        break;
                }
                break;
        	case '2':
                putch('|');
                xI -= 1;
                gotoxy(yI, xI);
                putch('|');

                if (redesenhar)
                {
                    if (i >= 2)
                    {
                        switch(cF[i - 1])
                        {
                            case '5':
                                switch(cF[i - 2])
                                {
                                    case '0':
                                        redesenha(xI + 1, yI,
                                            "205");
                                        break;
                                }
                                break;
                        }   
                    }
                }
                
                switch(cF[i + 1])
                {
                    case '2':
                        xI -= 1;
                        break;
                    case '0':
                        xI -= 1;
                        yI += 1;
                        break;
                }
        	    break;
            case '3':
                putch('\\');
                yI -= 2;
                xI -= 1;
                gotoxy(yI, xI);
                putch('\\');
                switch(cF[i + 1])
                {
                    case '3':
                        yI -= 2;
                        xI -= 1;
                        break;
                    case '6':
                       yI -= 1;
                       break;
                }
                break;
            case '4':
                putch('-');
                yI -= 1;
                gotoxy(yI, xI);
                putch('-');
                switch(cF[i + 1])
                {
                    case '4':
                        yI -= 1;
                        break;
                }              
                break;
            case '5':
                putch('/');
                /*
                yI -= 2;
                xI += 1;
                gotoxy(yI, xI);
                putch('/');
                */
                switch(cF[i + 1])
                {
                    case '2':
                        yI -= 2;

                        break;
                    case '5':
                        yI -= 2;
                        xI += 1;
                        break;                    
                }
                break;
            case '6':
                putch('|');
                xI += 1;
                gotoxy(yI, xI);
                putch('|');
                switch(cF[i + 1])
                {
                    case '0':
                        yI += 1;
                        xI += 1;
                        break;
                    case '6':
                        xI += 1;
                        break;    
                }                
                break;
        }

        i++;
    }
}

void main(void)
{
	char cF[128];

    clrscr();

	printf("Digite a cadeia de Freeman: ");
	scanf("%s", &cF);

	desenha(12, 12, cF, 1);

	getch();
}