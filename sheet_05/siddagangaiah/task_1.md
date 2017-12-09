# Task 1: Scoping

1. Yes, its will sucessfully terminate.

2.

    2.1
   Line num| Operators used(from left to right)
   --------|----------------------------------
   04|basic assignment, addition assignment, comma
   05|basic assignment, comma
   06|basic assignment, comma
   07|addition assignment, post incement, addition, comma
   08|none
   09|basic assignment, addition
   10|basic assignment
   11|none
   12|subtraction

   2.2
   Line num| Operands| Referred line| Scope
   --------|---------|--------------|-------
   04|d|01|file scope
   04|a|03|function argunment list scope
   05|b|01|file scope
   05|a|04|function argunment list scope
   06|b|05|file scope
   07|b|06|file scope
   07|a|05|function scope
   09|a|09|block scope
   09|b|07|file scope
   10|b|07|file scope
   10|a|09|block scope
   12|b|10|file scope
   12|d|04|file scope