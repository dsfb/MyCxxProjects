#include <stdio.h>
#include <conio.h>

#define max 7

void obtem(float t[])
{
	int i;
	puts("Informe as temperaturas: ");
	for(i = 0; i < max; i++)
	{
	    printf("%do valor: ", i + 1);
	    scanf("%f", &t[i]);
	}
}

float media(float t[])
{
	int i;
	float s = 0;
	for(i = 0; i < max; i++)
	    s += t[i];
	return s/max;
}

int conta(float t[], float m)
{
	int i, c = 0;
	for(i = 0; i < max; i++)
    {
        if( t[i] > m )
            c++;
    }
    return c;
}

void main(void)
{
	float temp[max], m;
	obtem(temp);
	m = media(temp);
	printf("Estatistica: %d", conta(temp, m));

	getch();
}
