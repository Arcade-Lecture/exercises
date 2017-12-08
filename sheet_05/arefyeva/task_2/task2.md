1. No, it terminates but returns 1.  

2.  
`a` - auto storage class, stored in RAM, "lives" until the end of the `main` function. Internal linkage.  
`b` - the same as `a`.  
`c` - register storage class, stored in a CPU register, "lives" until the end of the `main` function.  Internal linkage.  
`x` - auto storage class, stored in RAM until the end of the `state` function.  Internal linkage.  
`y` - register storage class, stored in a CPU register until the end of the `state` function.  Internal linkage.  

3.  
a. The first option is not allowed, the second is.
b. In the second case nothing changes. Variables are `auto` by default.  

4.  
a. The value of this variable is kept between invocations of the function, the variable isn't deleted after the call.  
b. On each invocation a new variable would be created, the value would equal to whatever was in the memory before.  
c. No, the result does not change because the variable `state` isn't returned and doesn't affect the values of `x` and `y`.  

5. No, it's not necessary  

6. The function returns not the value -84, but 4294967212. This happens because -82 is a negative number, but `state` has `long unsigned long` type. Can be fixed by removing `unsigned`.