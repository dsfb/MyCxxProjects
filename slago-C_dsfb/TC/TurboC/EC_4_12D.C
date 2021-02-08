#include <stdio.h>
#include <conio.h>
#include <math.h>

double dist(float x1, float y1, float x2, float y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

main()
{
   printf("A distancia entre (0,0) e (1, 2) eh: %lf\n", dist(0, 0, 1, 2));
   getch();
}