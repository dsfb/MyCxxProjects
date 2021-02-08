#include <stdio.h>
#include <conio.h>

main()
{
    float peso, altura;
    char sexo;

    clrscr();
	
    printf("Digite o sexo (m/f): ");
    scanf("%c", &sexo);

    printf("Digite a altura: ");
    scanf("%f", &altura);

    if (sexo == 'm' || sexo == 'M')
    {
        peso = 72.7*altura - 58;
    }
    else if (sexo == 'f' || sexo == 'F')
    {
        peso = 62.1*altura - 44.7;
    }

    printf("O peso ideal ‚: %.2f\n", peso);

    getch();
}