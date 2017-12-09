#Task2

>(1) Does this program terminate successfully?
Yes

>(2) Give a statement on the storage class, storage duration and linkage of the following
> variables 

| variable | storage class | storage duration                                        | linkage    |
|----------|---------------|---------------------------------------------------------|------------|
| a        | auto          | automatic means, a lives only with in the main function | no linkage |
| b        | auto          | automatic like a                                        | no linkage |
| c        | register      | automatic                                               | no linkage |
| x        | auto          | automatic lives within the function                     | no linkage |
| y        | register      | automatic lives also within the function                | no linkage |

>3

>a. Is the altered line allowed in C?
i no
ii yes

>b. In case (i) yields yes, how does the linkage change?
ii no change

>(4) The function state uses a variable state that is marked as static.

> a. What is the effect of static in this context?

changes the storage class to static by doing so the storage duration
changes so the variable will be brought to life before main and will 
die after the main finishes.

> b. What changes if you remove static ?

the value of the variable state, since every time
it will be initiated it won't memorize the values
from previous function calls, as the storage duration by doing so
will be automatic

>c. Does the result of the function also change when you remove static and why?

yes, by removing static it won't memorize the values that it had
from previous function calls.

> (5) Is the explicit type cast in line 12 necessary?

no, since the conversion is done by the compiler (implicitily)

> (6) What happens when calling state(-42, -42) ? Suggest a solution to solve the issue! ?

undefined behaviour, a solution by doing assertions
