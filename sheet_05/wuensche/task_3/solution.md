## Right or Wrong

+ 1
	- This is wrong, this operator does not evaluate anything it just increases the given value a by one.

+ 2
	- This is correct, since --a implies that the value a will be modified beforehand and not afterwards like a--.

+ 3
	- This is wrong, somthing like `void (*foo)(int)` will result in a function pointer named `foo` but not `foo()`

+ 4
	- This is wrong, having two left side variables before an assigment operator is not allowed due to C syntax.

+ 5
	- This is correct, register indicates to the compiler that that variable will experience heavy usage and is preferably stored in the processor register.

+ 6
	- This is wrong, the storage duration will be just set to the whole liftime of the program and will not be set automatic to a specific duration.
+ 7
	- This is wrong(depends on the scope of use i will assume working with the storage and freeing it correctly at the end), memory leaks occur when once allocated memory is not freed correctly, during usage a segmentation fault or other overflows can happen if the allocated storage space is overstepped.

+ 8
	- That is wrong, since the structs are seperate Storage constructs the variables inside can be named the same even if they occur in the same scope.

+ 9
	- As seen in the Additional assignment this is correct(linked table of additional assignments includes this)

+ 10
	- This is wrong, the `<<` is a Bitshift operator and therefore it does not return a bool value.