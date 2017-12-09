1. Right. The variable `a` is increased by 1, but the result of `a++` is the initial value of a.

2. Right. Both decrease `a` by one.

3. Wrong. Either results in the return falue of `foo` or, in case it has type `void`, produces an error when assigned to something (or just executes when not assigned).

4. Right. `(i + j)` is an rvalue because it's just a temporary result of the computation and does not have an identifiable memory location.

5. Right. `register` tells the compiler to store the variable in a CPU register, if possible.

6. Wrong. `static` does not lead to automatic storage duration, it tells that the lifetime of the variable equals the lifetime of the program.

7. Right. Allocated memory must be deallocated explicitely.

8. Wrong. It's not a problem if members of different structures have the same name.

9. Right. They both have the 3rd precedence - https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B#Operator_precedence . However, in the expression `(char)a++`, `a++` would be executed first because it's a bit higher.

10. Wrong. << means a byte shift, not a comparison.