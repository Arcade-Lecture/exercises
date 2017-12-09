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
return b - d;
}