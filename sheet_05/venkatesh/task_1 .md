# Task 1 - Scoping

  1. Yes the Program terminates successfully
  2. Information on operators and operand: 
     -*Name of operator:*
      - **Line 4** : Comma operator between (a+=1) and (d=112), addition assignment operator in (a+=1) and basic                 assignment in (d=112).
      - **Line 5** : Basic assignment operator between 23 and a and basic assignment operator between a and b.
      - **Line 6** : Basic assignment operator between 42 and b and comma operator with **line 5**.
      - **Line 7** : Postfix increment operator on a and addition operator between this expression and b in (a++ + b).          Addition assignment operator between b and (a++ + b). Comma operator with **Line 6**.
      - **Line 9** : Addition operator between 5 and b and basic assignment operator between b + 5 and a.
      - **Line 10** : Basic assignment operator between a and b.
      - **Line 12** : Subtraction operator between d and b.
     -*Operands Information:*
      -**Line 4** : a:03(function argument list scope), d:01(file scope)
      -**Line 5** : a:03(function argument list scope), b:01(file scope)
      -**Line 6** : b:01(file scope)
      -**Line 7** : a:03(function argument list scope), b:01(file scope)
      -**Line 9** : a:09(block scope), b:01(file scope)
      -**Line 10** : a:09(block scope), b:01(file scope)
      -**Line 12** : b:01(file scope), d:01(file scope)

    


