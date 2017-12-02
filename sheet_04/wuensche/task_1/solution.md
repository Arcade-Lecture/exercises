### Task 1 DRY: Don't repeat yourself
Example for DRY in C
```c
#include <stdio.h>

main(){
//This should calculate the largest integer divider for a variable
int a = 16;
int b = 15;

int divider_a = 0;

//Divider for a
for(int i = 1; i < a/2; i++){
	if(a % i == 0){
		divider_a = i;
	}
}

printf("Largest integer divider for %i is %i\n",a,divider_a);

int divider_b = 0;

//Divider for b
for(int i = 1; i < a/2; i++){
	if(b % i == 0){
		divider_b = i;
	}
}

printf("Largest integer divider for %i is %i\n",b,divider_b);
}
```

This code does not fullfil the requirements because the loop for finding the largest divider is repeated and thus unncessary repetition of already written code. This can lead especially in larger projects to high maintaining cost or even unmaintainable code because error fixes in one part of the code do not have to be present in another. This problem can be solved by extracting the repeating part and putting it into it's own method.

DRY Code example in C
```c
#include <stdio.h>

int largestDivider(int number){
	int divider = 0;

	for(int i = 1; i < a/2; i++){
		if(number % i == 0){
			divider = i;
		}
	}

	return divider;
}

main(){
	//This should calculate the largest integer divider for a variable
	int a = 16;
	int b = 15;

	//Divider for a
	int divider_a = largestDivider(a);

	printf("Largest integer divider for %i is %i\n",a,divider_a);

	//Divider for b
	int divider_b = largestDivider(b);	

	printf("Largest integer divider for %i is %i\n",b,divider_b);
}
```

This should solve the problem of repeating the previous problematic loop and make fixes in case of errors easier.