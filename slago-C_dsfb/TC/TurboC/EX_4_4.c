#include <stdio.h>
#include <conio.h>

#define SENHA 1234

void alarme(void); /* declaração da função */

void main(void) {
	int s;

	#ifdef TURBOC
	clrscr();
	#endif

	printf("\nSenha: ");
	scanf("%d", &s);

	if (s != SENHA) {
	    printf("\nSenha inválida!");
	    alarme();
	}
	else printf("\nSenha OK!");
	getch();
}

void alarme(void)  /* definição da função */
{
	int f;

	for (f = 100; f <= 5000; f += 20)
	{
	    sound(f);
	    delay(100);
	}

	nosound();
}