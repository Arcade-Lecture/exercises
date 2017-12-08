## Task 2 Storage Classes
###1. 
   It returns 1 so it's unsuccessful

###2.
  a.  `a` :  storage class: **auto** - storage : **RAM** - storage duration : until the **end** of the `main` function - linkage: **internal**.  
  b. `b` :  storage class: **auto** - storage : **RAM** - storage duration : until the **end** of the `main` function - linkage: **internal**.
  c. `c`:  storage class: **register** - storage : **CPU register or RAM** - storage duration : until the **end** of the `main` function - linkage: internal. 
  d. `x` :  storage class: **auto** - storage : **RAM** - storage duration : until the **end** of the `state` function - linkage: **internal**.
  e. `y` - **register storage** class, stored in a CPU register, "lives" until the end of the `state` function.  Internal linkage.  
###3.
 1- not allowed because we can't use `extern` with`auto`
 2- It's allowed but It will not change anything because it'll take `auto` by default

###4.
 a. the value of a `static` varibale doesn't change in the next call of function. this mean that the value will not be deleted at the ent of the function.
 b. in each function call the varibale will be reset to the value saved in memory before the function executed
 c. No , because the `state` varible doesn't efect the returne of the function or the output of the program (it's not used)
 
 ###5.
 No
 
 ###6.
the return will be fault value because the return of the `static` function is `unsigned long` and it's only accept the positive values
to fix it just remove the keyword `unsigned` to let the function return nigative values



