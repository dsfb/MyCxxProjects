#include <stdio.h>
#include <conio.h>

void main(void) {
	char n[21];

	printf("Qual o seu nome: ");
	gets(n);
	printf("Ola, %s!", n);
	getch();
}