#include <stdio.h>
#include <conio.h>

int aleat(void)
{
	static unsigned s = 1234;
	auto unsigned n = s%100;

	s += s/10;

	return n;
}

void main(void) {
	while(!kbhit())
		printf("\n%d", aleat());
}