#include <stdio.h>
#include <conio.h>

void main(void)
{
	int frequencias[] = {749, 749, 841, 749, 1000, 844, 749, 749, 841, 749, 1122,
	    1000, 749, 749, 1498, 1260, 1000, 944, 841, 1335, 1335, 1260, 1000, 1122,
	    1000},
	    duracoes[] = {400, 400, 400, 400, 400, 800, 400, 400, 400, 400, 400, 800, 
	    400, 400, 400, 400, 400, 400, 800, 400, 400, 400, 400, 400, 800};
    int i;

    for (i = 0; i < sizeof(frequencias)/sizeof(int); i++)
    {
    	sound(frequencias[i]);
    	delay(duracoes[i]);
    	nosound();
    }

	getch();

}