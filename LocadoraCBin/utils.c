#include <string.h>
#include <stdio.h>

#define MAX 100

int starts_with(const char *a, const char *b)
{
    int result = strncmp(a, b, strlen(b)) == 0;
    #ifdef linux
    free(a);
    free(b);
    #endif // linux
    return result;
}

int pause() {
    printf("\nPressione <Enter> para continuar...");
	scanf("%*c");

	fseek(stdin, 0, SEEK_END);
}

#ifdef linux
#include <stdlib.h>

char *strupr(char *data) {
    char* result = malloc(MAX);
    int i = 0;
    while (*data != '\0') {
        result[i++] = toupper(*data);
        data++;
    }
    return result;
}

#endif // linux
