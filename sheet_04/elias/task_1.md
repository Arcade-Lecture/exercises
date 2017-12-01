## Task 1 DRY: Don't Repeat Yourself

a code example that does not follow the principle of DRY:
```c
#include<stdio.h>

int main(){
    //find the avarage of a students marks in a semester
    
    //first semester
    float marksInFirstSemester[4] = {70,80,90,65} ;
    int sum=0;
    for(int i=0;i<=4;i++){
      sum1 = sum1 + marksInFirstSemester[i];
      }
    float avg = sum/4;
    printf("The avarage of semester 1 is: %.2f\n",avg);
 
    //second semester
    float marksInSecondSemester[4] = {60,65,72,84} ;
    int sum2=0;
    for(int i=0;i<=4;i++){
      sum2 = sum2 + marksInSecondSemester[i];
      }
    float avg2 = sum2/4;
    printf("The avarage of semester 2 is: %.2f",avg2);
  
  	return 0;
}
```
This code doesn't follow the principle of DRY because it has a repeated code blocks that find the avarage and print the results to console

We can edit the above code to  follow the principle of DRY so it will be:
```c
#include<stdio.h>

//function to return avarage
float getAvarageOfMarks(float* marksArray)
{
    int sum=0;
    for(int i=0;i<=4;i++)
    {
        sum = sum + marksArray[i];
    }
    float avg = sum/4;
    
    return avg;
}

// function to print on console
void printResult(int nOfSemester,float avg)
{
   printf("The avarage of semester %d is: %.2f\n",nOfSemester,avg); 
}

int main(){
    //find the avarage of your marks in a semester
    
    //first semester
    float marksInFirstSemester[4] = {70,80,90,65} ;
    
    float avg1= getAvarageOfMarks(marksInFirstSemester);
    printResult(1,avg1);
 
   //second semester
    float marksInSecondSemester[4] = {60,65,72,84} ;
    
    float avg2= getAvarageOfMarks(marksInSecondSemester);
    printResult(2,avg2);

  return 0;
}
```