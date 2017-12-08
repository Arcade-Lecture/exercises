#include <stdio.h>

unsigned long a, b, d;

int main(int a, char **c) {
	d = (a += 1), (d = 112);
	b = a = 23,
	b = 42,
	b += (a++ + b);
	{
		int a = b + 5;
		b = a;
	}

	printf("%s", (b-d == 0 ? "Return Type is 0." : "Return Type is not 0."));
	return b - d;
}