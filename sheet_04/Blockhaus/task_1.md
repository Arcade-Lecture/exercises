```C
#include <stdio.h>
#include <stdlib.h>

struct address {
	char *street;
	char *town;
	unsigned int zip;
	unsigned int number;
};

void print_address(struct address *address)
{
	printf("Street name: %s\n",address->street);
	printf("House number: %d\n",address->number);
	printf("Town: %s\n",address->town);
	printf("Postal Code:%d\n",address->zip);
	printf("Addressee's name: Bob\n");
}
void print_address2(struct address *address)
{
	printf("Street name: %s\n",address->street);
	printf("House number: %d\n",address->number);
	printf("Town: %s\n",address->town);
	printf("Postal Code:%d\n",address->zip);
	printf("Addressee's name: John\n");
}

void print_address3(struct address *address)
{
	printf("Street name: %s\n",address->street);
	printf("House number: %d\n",address->number);
	printf("Town: %s\n",address->town);
	printf("Postal Code:%d\n",address->zip);
	printf("Addressee's name: Alice\n");
}
	
int main(void){
	struct address addr =  {"Asinusstraße", "Deppendorf", 33739,23};
	print_address(&addr);
	print_address2(&addr);
	print_address3(&addr);

	return EXIT_SUCCESS;
}

```

The code clearly doesn't follow the DRY because in every print_address* function the first four printf calls are the same.
Every of them prints out the saved data in the address struct plus one name which is hardcoded in the function this generated alot of code duplicats.
So it is easy to see, that all of these functions have the same logic. 
But this exactly contradicts the DTY. A program follows the DRY, when every point of program logic is only available on one point of the program.
A rewrite of the code that follows the DRY could look like this:

```C
#include <stdio.h>
#include <stdlib.h>

struct address {
	char *street;
	char *town;
	unsigned int zip;
	unsigned int number;
};

void print_address(struct address *address)
{
	printf("Street name: %s\n",address->street);
	printf("House number: %d\n",address->number);
	printf("Town: %s\n",address->town);
	printf("Postal Code:%d\n",address->zip);
}

void print_address_name(struct address *address, char *name)
{
	print_address(address);
	printf("Addressee's name:%s\n",name);
}

int main(void){
	struct address addr =  {"Asinusstraße", "Deppendorf", 33739,23};
	char *bob = "Bob";
	char *alice = "Alice";
	char *john = "John";

	print_address_name(&addr, bob);
	print_address_name(&addr, john);
	print_address_name(&addr, alice);

	return EXIT_SUCCESS;
}

```
