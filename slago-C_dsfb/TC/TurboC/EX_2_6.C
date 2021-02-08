#include <stdio.h>

main() {
    int x, y;

    printf("\nInforme dois valores: ");
    scanf("%d %d", &x, &y);
    printf("\n Maximo = %d", x > y ? x : y);

    getch();
}