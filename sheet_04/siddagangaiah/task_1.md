# Task 1 : DRY Principle

1. Example for DRY principle: 
```c
#include <stdio.h>

int main() {
    int a[5] = {0, 1, 2, 3, 4};
    int b[5] = {5, 6, 7, 8, 9};
    int c[5];

//    Add corresponding elements of a and b and store it in c
    c[0] = a[0] + b[0];
    c[1] = a[1] + b[1];
    c[2] = a[2] + b[2];
    c[3] = a[3] + b[3];
    c[4] = a[4] + b[4];

    return 0;
}
```
2. The above example doesn't not conform DRY principle as its repeats lines of codes to add corresponding elements of array A and B.

3. Code conforming DRY principle

```c
#include <stdio.h>

int main() {
    int a[5] = {0, 1, 2, 3, 4};
    int b[5] = {5, 6, 7, 8, 9};
    int c[5] = {0, 0, 0, 0, 0};

//    Add corresponding elements of a and b and store it in c
    for (int i = 0; i < sizeof(a)/sizeof(int); i++) {
        c[i] = a[i] + b[i];
    }

    return 0;
}
```
