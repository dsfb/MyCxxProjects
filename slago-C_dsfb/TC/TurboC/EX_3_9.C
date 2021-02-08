#include <stdio.h>
#include <conio.h>

main() {
    int x=1, y=1;
    int dx=-1, dy=-1;

    clrscr();

    do {
	gotoxy(x,y);
	putch(01);
	delay(800);
	gotoxy(x,y);
	putch(32);

	if(x == 1 || x == 80) {
	    sound(500);
	    delay(800);
	    nosound();

	    dx = -dx;
	}

	if(y == 1 || y == 24) {
	    sound(500);
	    delay(800);
	    nosound();

	    dy = -dy;
	}

	x += dx;
	y += dy;
    } while( !kbhit() );
}