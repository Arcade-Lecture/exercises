## Scoping

### Does this program terminate successfully
Yes, the program terminates. By using `$ echo $?` we can catch the last exit code in our shell and therefore determine that it was indeed 0.

### Every operator on every line ranging from line 4 to 12
```
4	d = (a += 1), (d = 112);
5	b = a = 23, 
6	b = 42,
7 	b += (a++ + b);
8 	{
9 		int a = b + 5;
10 		b = a;
11 	}
12	return b - d;
```

```
04: Assignment operator, Assignment by sum operator, Comma operator, Assignment operator
Assignment operator d:01 File Scope
Assignment by sum operator a:03 function argument list scope
Assignment operator d:01 function argument list scope
```

```
05: Assignment operator, Assignment operator
Assignment operator b:01 File Scope
Assignment operator a:03 File Scope
```

```
06: Assignment operator
Assignment operator b:01 File Scope
```

```
07: Assignment by sum operator, suffix increment operator, Addition operator
Assignment by sum operator b:01 File Scope
suffix increment operator a:03 function argument list scope
Addition operator
```

```
09: Assignment operator, Addition
Assignment operator a:09 Brace Scope
Addition
```

```
10: Assignment operator
Assignment operator b:01 File Scope
```

```
12: Substraction operator
Substraction operator
```

