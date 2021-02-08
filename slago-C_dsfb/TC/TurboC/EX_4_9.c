#include <stdio.h>
#include <conio.h>

int aleat(void)
{
	static unsigned s = 1234;
	auto unsigned n = s%100;

	s += s/10;

	return n;
}

void main(void)
{
    int col, lin, cor;

    #ifdef TURBOC
    clrscr();
    #endif

    while(!kbhit()) {
    	col = aleat() % 80 + 1; /* valores entre 1 e 80 */
    	lin = aleat() % 25 + 1; /* valores entre 1 e 25 */
    	cor = aleat() % 16;     /* valores entre 0 e 15 */
    	gotoxy(col, lin);
    	textcolor(cor);
    	putch('*');
    }
}