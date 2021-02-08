#include <stdio.h>
#include <conio.h>

int strcmp(char s[], char t[]) {
	int i = 0;
	while(s[i] == t[i] && s[i] != '\0') i++;
	return s[i] - t[i];
}

void main(void) {
	char x[] = "um";
	char y[] = "um";
	char z[] = "dois";

	printf("\n %s = %s => %s", x, y, strcmp(x,y) == 0 ? "V" : "F");
	printf("\n %s diferente de %s => %s", x, y, strcmp(x,y) != 0 ? "V" : "F");
	printf("\n %s < %s => %s", x, z, strcmp(x,z) < 0 ? "V" : "F");
	printf("\n %s > %s => %s", x, z, strcmp(x,z) > 0 ? "V" : "F");
	printf("\n %s <= %s => %s", z, y, strcmp(z,y) <= 0 ? "V" : "F");
	printf("\n %s >= %s => %s", z, z, strcmp(z,z) >= 0 ? "V" : "F");

	getch();
}