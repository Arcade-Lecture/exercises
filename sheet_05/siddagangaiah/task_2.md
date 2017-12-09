# Task 2

1. No, the program wont terminate sucessfully.

2. 
    variables|storage duration|linkage
    ---------|----------------|-------
    a|automatic(from start of main till it terminates)|no linkage
    b|automatic(from start of main till it terminates)|no linkage
    c|automatic(from start of main till it terminates|no linkage
    x|automatic(from start of state func till it's termination)|no linkage
    y|automatic(from start of state func till it's termination)|no linkage

3.  
    Line|Allowed in C?|Linkage changes to?
    ----|-------------|------------------
    auto extern int a = 23|no|NA 
    int a = 23;|yes|no change

4.  

    a.   static keyword makes the state variable lifetime to be same as process life time and can be accessed from all scopes in its translation unit.

    b. On removal of static keywork scope becomes automatic and state can be referenced only with in state function.

    c.  No, result doesnt change. state variable is only target of assignment operator, It has not been used anywhere else.

5.  No, explicit typecast is not necessary.

6.  state function only returns long unsigned long. So the left most bit of the return value will not be considered as sign and a positive value will be returned by the function even though the result was -84. 
We can drop the unsigned key word from the function return type to fix the isssue.




