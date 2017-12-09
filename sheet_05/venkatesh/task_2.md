# Task 2 - Storage Classes

  1. Yes the Program terminates successfully
  2. | Variable/feature | a | b | c | x | y |
     |     :---:    |     :---:      |     :---:     |     :---:    |     :---:      |     :---:     |
     | **storage class**   | auto     | auto   |     register    |     auto     |     register     |
     | **storage duration**     | automatic       | automatic      |     automatic   |     automatic      |     automatic     |
     | **linkage**     | no linkage       | no linkage      |    no linkage    |     no linkage      |     no linkage     |
  3. Alterations:
    -**a.** Alteration I is not allowed since, the correct usage must be done in the header file of the source code. Wheras, Alteration II is allowed as the auto keyword is applied by default if nothing is mentioned alongside the declaration.
     -**b.** Alteration I is not allowed.

  4. Arguments on variable state:
     -**a.** Lifetime of the state variable would be untill the end of main function (or return from main function). In other words, the value of variable state is retained on subsequent function calls from the main. 
     -**b.** If static is removed, everytime the function state is called, the value of variable state will be initialized, changing the duration to automatic.
     -**c.** Yes the result changes due to the re-initialization of the state variable on every subsequent call from the main due to automatic storage duration. 

  5. It is neccesaary as the return type of the function state is long, and the target variable is of the type short. Implicit conversion is not applicable in conversion of larger datatype to smaller datatype.
  
  6. The function call returns negative result, but the return type is set to unsigned. We need to remove 'unsigned' keyword in order to execute the file correctly. 
  
     
     
  
    


