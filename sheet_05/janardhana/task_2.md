## Task 2

1. Yes, the program terminates successfully.

2.

|variables| Storage class| Storage Duration | Linkage|
|----------|-------------|-------------------|-------|
|a| auto | automatic | no linkage|
|b|auto|automatic| no linkage|
|c|register|automatic|no linkage|
|x|auto|automatic|no linkage|
|y|register|automatic|no linkage|

3 (i)  No

  (ii) Linkage does not change remains no linkage.

4  a. It affects the storage allocation and lifetime of state variable.

   b. Removing static makes it automatic and value of state variable won't be retained, it changes everytime function state is invoked.
   
   c. Yes, since the value of state variable is not retained for every function call.


5. No, conversion will happen implicitly.


6. On calling state(-42, -42), the value depends on the previous value of state variable. The problem can be avoided by dropping the return type to be unsigned. 
