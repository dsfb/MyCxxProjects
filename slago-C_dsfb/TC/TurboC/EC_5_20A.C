#include <stdio.h>
#include <conio.h>

float calculaPerimetro(char cF[])
{
	float perimetro = 0;
    unsigned int i = 0;
    while (cF[i] != '\0')
    {
    	switch(cF[i])
    	{
            case '1':
            case '3':
            case '5':
            case '7':
                perimetro += 1.42F;
                break;
            case '0':
            case '2':
            case '4':
            case '6':
                perimetro += 1F;
    	}

    	i++;
    }

	return perimetro;
}

void main(void)
{
	int xI, yI;
	char cF[128];

	printf("\nDigite o xI: ");
	scanf("%d", &xI);

	printf("Digite o yI: ");
	scanf("%d", &yI);

	printf("Digite a cadeia de Freeman: ");
	scanf("%s", &cF);

	printf("O perimetro desta cadeia eh: %.2f\n",
		calculaPerimetro(cF));

	printf("Pressione algo para sair!");
	getch();
}