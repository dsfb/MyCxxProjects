#include <stdio.h>
#include <conio.h>

main()
{
    int dia, mes, ano, perfil;
	int soma1, soma2;
	short int pedaco1, pedaco2; 

	printf("Digite o dia do nascimento: ");
	scanf("%d", &dia);
	
	printf("Digite o mes do nascimento: ");
	scanf("%d", &mes);
	
	printf("Digite o ano do nascimento: ");
	scanf("%d", &ano);
	
    soma1 = (dia * 100 + mes) + ano;
	
	soma2 = (soma1/100) + (soma1 % 100);
	
	perfil = soma2 % 5;
	
	switch(perfil)
	{
		case 0: printf("Timido\n"); break;
		case 1: printf("Sonhador\n"); break;
		case 2: printf("Paquerador\n"); break;
		case 3: printf("Atraente\n"); break;
		case 4: printf("Irresistivel\n"); break;
		default: break;
	}
	
	getch();
}