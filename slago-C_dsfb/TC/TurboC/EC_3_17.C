#include <stdio.h>
#include <conio.h>

main() {

    int tecla, frequencia;

    clrscr();
    printf("Piano eletr“nico!\n");
    printf("Tecle:\n");
    printf("1. Nota D¢\n");
    printf("2. Nota R‚\n");
    printf("3. Nota Mi\n");
    printf("4. Nota F \n");
    printf("5. Nota Sol\n");
    printf("6. Nota L \n");
    printf("7. Nota Si\n");
    printf("8. Sair\n");

    do {
	tecla = getch();

	switch(tecla)
	{
	    case 49: /* tecla 1 - Nota D¢ */
		frequencia = 262; break;
	    case 50: /* tecla 2 - Nota R‚ */
		frequencia = 294; break;
	    case 51: /* tecla 3 - Nota Mi */
		frequencia = 330; break;
	    case 52: /* tecla 4 - Nota F  */
		frequencia = 349; break;
	    case 53: /* tecla 5 - Nota Sol */
		frequencia = 392; break;
	    case 54: /* tecla 6 - Nota L  */
		frequencia = 440; break;
	    case 55: /* tecla 7 - Nota Si */
		frequencia = 494; break;
	    case 56: /* tecla 8 - Sair */
		frequencia = 0; break;
	    default: /* tecla inv lida */
		frequencia = -1;
	}
	
	clrscr();
	printf("Piano eletr“nico!\n");
	printf("Tecle:\n");
	printf("1. Nota D¢\n");
	printf("2. Nota R‚\n");
	printf("3. Nota Mi\n");
	printf("4. Nota F \n");
	printf("5. Nota Sol\n");
	printf("6. Nota L \n");
	printf("7. Nota Si\n");
	printf("8. Sair\n");
	
	switch(frequencia)
	{
	    case -1:		
		printf("\nOpa! Vocˆ pressionou uma tecla inv lida!");
		break;
	    case 0:
		break;
	    default:
		sound(frequencia);
	        delay(800);
	        nosound();
	}
    } while (tecla != 56); /* enquanto a tecla for diferente de 8 */
}