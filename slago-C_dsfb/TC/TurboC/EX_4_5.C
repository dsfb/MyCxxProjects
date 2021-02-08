#include <stdio.h>
#include <conio.h>

void linha(int x, int y, int c) {
    int i;
    gotoxy(x, y);
    for(i = 0; i < c; i++) putch(196);
}

void linhaMoldada(int x, int y, int c, int ci, int cf) {
     int i;
     gotoxy(x, y);
     putch(ci);
     for(i = 1; i < c - 1; i++) putch(196);
     putch(cf);
}

void coluna(int x, int y, int c) {
     int i;

     for(i = 0; i < c; i++)
     {
	 gotoxy(x, y + i);
	 putch(179);
     }
}

void retangulo(int x, int y, int largura, int altura)
{
    linhaMoldada(x, y, largura, 218, 191);
    coluna(x, y + 1, altura);
    coluna(x + largura - 1, y + 1, altura);
    linhaMoldada(x, y + altura + 1, largura, 192, 217);
}

main() {
    clrscr();
    linhaMoldada(2, 5, 5, 218, 191);
    coluna(6, 6, 5);
    coluna(2, 6, 5);
    linhaMoldada(2, 11, 5, 192, 217);

    retangulo(20, 20, 6, 4);
    /*
    linhaMoldada(10, 15, 6, 218, 191);
    coluna(10, 16, 5);
    coluna(15, 16, 5);
    linhaMoldada(10, 21, 6, 192, 217);
    */
    retangulo(10, 15, 6, 5);

    retangulo(50, 15, 10, 5);
    getch();
}