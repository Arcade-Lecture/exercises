### Task 2: C Basics: Right or Wrong

- 1: The C language is a high-level programming language that emphasis object-oriented programming.
	+ This is wrong, actually C was initially designed to not include any class structures only structs became early available as a possibility to save data into packages.
- 2: B.W. Kernighan and D. Ritchie are two of the creators of the C language.
	+ This is basically wrong, but Kernighan is the co-author of the book 'The C Programming Language' written by Ritchie, and often associated with early C.
- 3: K. Thompson is famous as the inventor of C++.
	+ This is wrong, the inventor of the C++ language is Bjarne Stroustrup.
- 4: One of the design goals of C was to create a less complex language in exchange of efficiency in terms of runtime and memory footprint.
	+ This is correct.
- 5: Undefined behavior is a behavior where it is not defined how the program behaves (e.g., by illegal memory accesses out of bound, signed integer overflow, null pointer dereference,…)
	+ This is correct, that's why it is named that way.
- 6: C is a non-procedural, structured and declarative language with static variable scoping.
	+ This is wrong, for once C is procedural oritented language, it works step after step after a given procedure, but the rest is correct C is structured and declarative.
- 7: In the C language, the concepts of characters, numbers, and addresses are first-class citizens.
	+ This is right.
- 8: The development of UNIX was driven by the need of C in late 1980s
	+ This is wrong, actually C was developed because of the need of a language to develop on UNIX.
- 9: The printf function is part of the C core-language.
	+ This is wrong, because printf is included in standard library which is not part of the c core.
- 10: With the latest changes, a new string type was added to C (with the specification 2795 as of http://www.faqs.org/rfcs/rfc2795.html).
	+ 
- 11: Object destruction is deterministic in C.
	+ This is right, Object destruction in C is basically executing a free on the desired memory space which is deterministic in C.
- 12: Dynamic memory allocation must be explicitly managed by the programmer.
	+ This is right, since C is not capable of dynamically managing Memory itself the programmer or a library (written by another programmer) must be used.
- 13: Dynamic memory deallocation is managed by the C runtime itself.
	+ This is wrong, all allocated memory must be freed by the programmer or the used library.
- 14: The preprocessor directive “#force” is part of the C language.
	+ This is wrong.
- 15: The C preprocessor supports file inclusion, macro substitution and conditional complication.
	+ 
- 16: Before C11, every C program based on a single-threaded memory model.
	+ This is correct, C11 introduced multithreading.
- 17: Memory leaks will be no longer a problem once Non-Volatile RandomAccess Memory (NVRAM) becomes mainstream.
	+ This is wrong,  because memory without any remaining pointers can still be not accessed.
- 18: C11 comes with a rich standard library that a lot of built-in generic (“templated”) data containers (such as linked-lists, arrays, or vectors) and supports multi-threading out-of-the-box.
	+ This is wrong, the C standard library does include generics but not data containers like linked lists and vectors.
- 19: C’s first implementation traces back before 1989 and was promoted by Brian W. Kernighan und Dennis Ritchie, in their famous book „The C Programming Language”.
	+ This is correct.
- 20: Bjarne Stroustrup (Creator of C++) is famous for his quote: “C is flexible but neither portable nor often available and often not efficient. This was my main motivation for my new language, the C++ language.”.
	+ This is wrong, he actually said the opposite(see lecture ch2 slide 14)
- 21: The following code is a compileable C program in C11 main() { ; }
	+ This is correct.
- 22: When returning from main, the program terminates successfully in case a non-zero value is returned.
	+ This is wrong, the successfull return value is always zero everything else represents an error occured during execution.
- 23: Basic input and output (such as file operations) functionality is available due the standard library of C.
	+ This is correct, since it is included in <stdio.h>.
- 24: A runtime assertion as in <assert.h> can be disabled during runtime
	+ This is wrong, Assertions once compiled in cannot be changed after that.
- 25: The following code is not a valid C program in C11:
	#include <stdio.h>
	#include <stdbool.h>
	#include <iso646.h>
	int main(void) { return true or false; }
	+ This is correct, the return value would be 1.
- 26: The C language nowadays supports atomic data types.
	+ This is correct, atomic types in C can be used by prepending _Atomic.
- 27: The C programming language is a general-purpose language not only intended for system-level programming but weakly typed (with strong enforcement of weakly types).
	+ This is wrong, C is based on the exact opposite(weak enforcement strong types).
- 28: Unspecified behavior is behavior where more than one behavior is possible at one instance in time (e.g., order of evaluation). The result of unspecified behavior may differ when repeated.
	+ This is correct.
- 29: Implementation-defined behavior is undefined behavior which must be specificationcified and implemented by the programmer.
	+ This is wrong, implementation defined behaviour is implmented by the Compiler programmer.
- 30: Single-line comments in C start with #.
	+ This is wrong, they start with //
- 31: Single-line comments cannot be used for code documentation.
	+ This is wrong, in Doxygen commentary can be single line and still be interpreted as documentation.
- 32: /* I believe the compiler ignores all of my comments */
	+ This is correct, it ignores all correctly formed commentary structures.
- 33: A type in C is used to interpret a bunch of binary data.
	+ This is correct, that is why types even exist.
- 34: The C type `byte` is the smallest addressable value in C.
	+ This is correct, but to be noted C type `byte` is not exactly included and is replaced by `char`
- 35: The word bool is a keyword in C11, and is used to express a boolean type.
	+ This is wrong, `bool` is only included in stdbool.h and is an alias for _Bool.
- 36: There is support of complex number types in C since C89 from 1989’s.
	+ This is wrong, the complex.h was introduced in C99.
- 37: The types short and short int have always the same number of bits in C.
	+ This is correct, short is simple an abbrevation of short int.
- 38: The types unsigned int is guaranteed to hold more bits than short.
	+ This is wrong, unsigned int can be larger than short but does not have to be.
- 39: The constant 0x23F is a valid number constant in C.
	+ This is correct, 0x23F is hexadecimal.
- 40: The constant 0x23L is a valid number constant in C.
	+ This is correct, this number is a long 35.
- 41: An enumeration tag defines the type for an enumeration in C, e.g., the type of enum my_emum is my_enum.
	+ This is correct.
- 42: Implicit type conversion take place by the syntax (type) expression.
	+ This is correct, e.g. for some calculations useful.
- 43: Explicit type conversion happens when an expression result differs from the expected type.
	+ This is correct.
- 44: 