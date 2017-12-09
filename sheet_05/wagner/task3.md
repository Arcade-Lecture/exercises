# Tasks 3

Statement 1 is correct, because a gets modified.

Statement 2 is correct, because --a applies before the assignment.

Statement 3 is incorrect. `foo()` will call the function `foo`. If you get rid of the braces, you will get a function pointer.

Statement 4 is incorrect, because you are not allowed to assign two variables on left side.

Statement 5 is correct.

Statement 6 is correct.

Statement 7 is correct, because allocated storage may not be freeed correctly.

Statement 8..

Statement 9 is correct according to http://en.cppreference.com/w/c/language/operator_precedence

Statement 10 is wrong, because << is a bitshift operation.
