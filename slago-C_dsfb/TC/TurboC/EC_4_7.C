#include <stdio.h>
#include <conio.h>

void linhaMoldada(int x, int y, int c, int ci, int cf) {
    int i = 0;
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

void moldura(int ci, int li, int cf, int lf)
{
   /* printf("Imprimindo retangulo(%d, %d, %d, %d)\n",
	  ci, li, cf - ci + 1, lf - li + 1); */
    retangulo(ci, li, cf - ci + 1, lf - li + 1);
    retangulo(ci + 2, li + 1, cf - ci - 3, lf - li - 1);
}

main()
{
    clrscr();
    moldura(10, 5, 25, 15);
    getch();
}