Example of the code that violates the DRY principle:

```c
int main(void) {
	char method = 'A';
	int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int result[10];
	printf("Values of the matrix:\n");
	for (int i = 0; i < 10; i++) {
		printf ("Value of the element № %d: %d\n", i+1, matrix[i]);
	}
	if (method == 'A') {
		printf("Executing A...\n");
		A(matrix, result);
		for (int i = 0; i < 10; i++) {
			printf ("Value of the element № %d: %d\n", i+1, result[i]);
		}
	}
	else {
		printf("Executing B...\n");
		B(matrix, result);
		for (int i = 0; i < 10; i++) {
			printf ("Value of the element № %d: %d\n", i+1, result[i]);
		}
	}
}
```

The code violates the principle, because there are 3 identical blocks that print the values. If something is changed, e.g. the message or the number of dimensions, it has to be changed for all the blocks.

This would be better:

```c
void printValues(int* matrix, int dim) {
	for (int i = 0; i < dim; i++) {
		printf ("Value of the element № %d: %d\n", i+1, matrix[i]);
	}
}

int main(void) {
	char method = 'A';
	const int dim = 10;
	int array[dim] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int result[dim];
	printf("Values of the matrix:\n");
	printValues(matrix, dim);
	if (method == 'A') {
		printf("Executing A...\n");
		A(matrix, result); \\ some function A
		printValues(result, dim);
	}
	else {
		printf("Executing B...\n");
		B(matrix, result); \\ some function B
		printValues(result, dim);
	}
}
```