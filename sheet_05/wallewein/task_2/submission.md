## 1)
This program returns the code 1, terminates not successfully.

## 2)
- a: storage class: auto, storage duration: automatic, linkage: no linkage
- b: storage class: auto, storage duration: automatic, linkage: no linkage
- c: storage class: register, storage duration: automatic, linkage: no linkage
- x: storage class: auto, storage duration: automatic, linkage: no linkage
- y: storage class: register, storage duration: automatic, linkage: no linkage

## 3)
- auto extern int a = 23: Not allowed in c, extern cannot follow auto
- int a = 23: Is allowed in c, linkage das not change.

## 4)
- a) Static in function context means that each call of function references the same instance. Additionally, it is only accessible in the function scope.
- b) Every call of the function references a new instance of the variable state.
- c) Yes the result of the function changes at the call of state(0,b) because x == 0 and state already has a value from the last call in case its static.

## 5)

## 6)
