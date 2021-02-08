#include <stdio.h>
#include <conio.h>
#include <math.h>

double dist(float x1, float y1, float x2, float y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

main()
{
   double raio, xC, yC, x, y;
   unsigned int fora = 0, dentro = 0;

   clrscr();

   printf("Digite o raio da circunferencia: ");
   scanf("%lf", &raio);
   
   printf("Digite o valor do x do centro da circunferencia: ");
   scanf("%lf", &xC);

   printf("Digite o valor do y do centro da circunferencia: ");
   scanf("%lf", &yC);   
   
   do {
      printf("Digite o valor do x do ponto: ");
      scanf("%lf", &x);

      printf("Digite o valor do y do ponto: ");
      scanf("%lf", &y);

      if (dist(x, y, xC, yC) < raio)
      {
      	dentro++;
      }
      else fora++;
   } while((x != xC) || (y != yC));

   printf("Os pontos dentro da circunferencia foram: %u\n", dentro);
   printf("Os pontos fora da circunferencia foram: %u\n", fora);

   getch();
}