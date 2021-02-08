/* A very simple text editor. */

#include <stdio.h>

#define MAX 100
#define LEN 80

char text[MAX][LEN];

int main(void)
{
    register int t, x, j;

    printf("Enter an empty line to quit.\n");

    for(t = 0; t < MAX; t++) {
	printf("%d: ", t);
	gets(text[t]);
	if(!*text[t])
	    break; /* quit on blank line */
    }

    for(x = 0; x < t; x++) {
	for(j = 0; text[x][j]; j++)
	    putchar(text[x][j]);
	putchar('\n');
    }

    return 0;
}
