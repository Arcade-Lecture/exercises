#Task 1

## Part 1

A program terminates successfully, if the return code, which is returned from `main` function, is equal to 0.

I added this code to the given sourcecode to determine, if `b-d` is 0. 

```c
	printf("%s", (b-d == 0 ? "Return Type is 0." : "Return Type is not 0."));
	
```

Console Output:

```
	Return Type is 0.
```

The program terminates successfully.

## Part 2


```c
#include <stdio.h>

unsigned long a, b, d;

int main(int a, char **c) {
	d = /* Assignment d:01 File Scope*/ (a += 1) /* Addition Assignment a:03 Function Argument Scope List */, (d = /* Assignment d:01 File Scope */ 112);
	b = a = 23 /* Assignment a:03 Function Argument Scope List b:01 File Scope */ ,
	b = 42 /* Assignment b:01 File Scope*/ ,
	b += /* Addition Assignment  b:01 File Scope */ (a++ + b);
	{
		int a = /* Assignment a:09 Inner Scope*/ b + /* Addition */ 5;
		b = /* Assignment  b:01 File Scope */ a;
	}

	return b - /* Substraction */ d;
}
```