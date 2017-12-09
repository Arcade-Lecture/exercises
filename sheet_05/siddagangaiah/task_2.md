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

    b. On removal of static keywork scope becomes function scope and state can be referenced only with in state function.

    c.  Yes, state variable will be initilized every time the function state is called. If it was static it would have retained its old value.

5.  No, explicit typecast is not necessary.

6.  Depending on previous calls to the state function the calculated value to be returned can be either positive or negative. But as the return type of the function is long unsigned long it always returns positive value. This can be fixed by dropping the unsigned keyword.




