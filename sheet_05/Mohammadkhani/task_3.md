| id        | right           | wrong  | reason |
| ------------- |:-------------:| -----:| ----:|
| 1     | right |  | it gets it's value plus 1|
| 2     | right |  | it's exactly equivalent. since a-=1 means a=a-1 |
| 3     |  | wrong | foo() just declares that funcion. to point to the function, we need to define a pointer like void (*foo)(int) = &foo|
| 4    | right  |  | it depends. if we want to store the result at the anoter lvalue, then the answer would be different. the otherwise, it's right
| 5     |  | wrong | it's the compiler choice to put it in the register or not|
| 6     |  | wrong | it leads to static storage duration|
| 7     |  right|  | that's true because It won't get cleaned up automatically|
| 8     |  | wrong | C allows to assign the same identifier to members in both|
| 9     | right |  | thats true. both of them have Precedence of 3|
| 10     | right |   | in general, i think this applies on a bitwise left-shift operator.|