# Task 1

**The idea behind DRY principle is simple, Code that is common to at least two different parts of the system should be factored into a single location. Here the variable initialization
and printing of student details is repeated in every case block.**

```c
#include <stdio.h>
#include <string.h>
int main()
{
  int val;
 int i;
      printf("Enter Student Id to print details :");
          scanf("%d", &val);
          switch(val){
              case 1:
                  printf("Details for entered ID : %d\n", val);
                  char std1_name[6]="Steve";
                  char std1_country[5]="USA";
                  printf("Name : %s\n", std1_name);
                  printf("Country: %s\n", std1_country);
                  break;
              case 2:
                  printf("Details for entered ID : %d\n", val);
                  char std2_name[15]="Mathew Hayden";
                  char std2_country[10]="Australia";
                  printf("Name : %s\n", std2_name);
                  printf("Country: %s\n", std2_country);
                  break;
             case 3 :
                  printf("Details for entered ID : %d\n", val);
                  char std3_name[15]="Jimmy fallon";
                  char std3_country[20]="United Kingdom";
                  printf("Name : %s\n", std3_name);
                  printf("Country: %s\n", std3_country);
                  break;
             case 4 :
                  printf("Details for entered ID : %d\n", val);
                  char std4_name[8]="Adithya";
                  char std4_country[6]="India";
                  printf("Name : %s\n", std4_name);
                  printf("Country: %s\n", std4_country);
                  break;
            default :
                  printf("Please check the entered Id!!\n");
          }
  return 0;
}

```
**The repeatation of print statements can be factored into one single function called printDetails(id, name, country)as input parameters and the initialization of variables can generalised.**
```c
#include <stdio.h>
#include <string.h>

int main () {
	 int val;
	 int i;
	 char *name;
	 char *country;
	 printf("Enter Student Id to print details :");
	 scanf("%d", &val);
	 switch(val){
          case 1:
                name="Steve";
                country="USA";
                printDetails(val, name, country);
                break;			
	   case 2:
                name="Mathew Hayden";
                country="Australia";
                printDetails(val, name, country);
                break;
	   case 3:
                name="Jimmy fallon";
                country="United Kingdom";
                printDetails(val, name, country);
                break;
	   case 4:
                name="Adithya";
                country="India";
                printDetails(val, name, country);
                break;
	    default :
                  printf("Please check the entered Id!!\n");
	}
  return 0;
}

void printDetails(int *id, char *name, char *country){
    printf("Details for entered ID : %d\n", id);
    printf("Name : %s\n", name);
    printf("Country: %s\n", country);
}
```



