#include <stdio.h>
#include <conio.h>

main()
{
	int anterior1, anterior2, atual, n, i;

	anterior1 = 1;
	anterior2 = 1;
	atual = anterior1 + anterior2;

    printf("Digite n >= 3: ");
    scanf("%d", &n);

    for(i = 3; i < n; i++)
    {
         anterior1 = anterior2;
         anterior2 = atual;
         atual = anterior1 + anterior2;
    }

    printf("O %d-esimo elemento eh: %d\n", n, atual);
    printf("Pressione algo para sair...");
    getch();
}