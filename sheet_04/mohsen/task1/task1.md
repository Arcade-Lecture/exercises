# Task 1 DRY: Don’t Repeat Yourself

>(1) Give a code example (favor the C language) that does not follow the principle of DRY!

	// the following code compares two integers, simply prints who is bigger than who

	if (lhs > rhs){
		printf("the lefthand side operand is biggger than the right handside operand \n");
	}else if (lhs < rhs){
		printf("the righthand side operand is biggger than the left handside operand \n");
	} else{
		printf("they are equal \n");
	}

>(2) Give a short description why your code in (1) does not apply the principle of DRY!

maybe in another part of the program we will need to do the same, comparing two integers.
so we will have to do WET style ..... typing the same code snippt again


>(3) Give a DRY code example by modify your code example of (1)!

so simply by making it in a form of a function, so you wouldn't need
to copy and paste code, or retyping it

	int compare_ints(int lhs, int rhs)
	{
		if (lhs > rhs){
			return 1;				
		}else if (lhs < rhs){
			return -1;
		} 
		return 0;
	}
