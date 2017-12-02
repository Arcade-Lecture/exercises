###### 1- Give a code example (favor the C language) that does not follow the principle of DRY!

~~~~
class Exercise
{
    static void Main(string[] args)
    {
        function1();
        function2();
        function3();
        Console.ReadLine();
    }
 
    private static void function1()
    {
        string job = "Teacher";
        string format = "{0} is {1}, who is a {2} and is from {3}";
        Console.WriteLine(format, "Maria", "my sister", job, Berlin);
    }
 
    private static void funtion2()
    {
        string job = "Teacher";
        string format = "{0} is {1}, who is a {2} and is from {3}";
        Console.WriteLine(format, "Alex", "my friend", job, Koln);
    }
    
    private static void function3()
    {
        string job = "Teacher";
        string format = "{0} is {1}, who is a {2} and is from {3}";
        Console.WriteLine(format, "Samir", "my cousin", job, Tehran);
    }
}
~~~~
###### 2- Give a short description why your code in (1) does not apply the principle of DRY!
The above code works but it fails the main logic of DRY("a piece of logic should only be represented once in an application") very badly. obviously, we repeat "job" and "format", bit over and over again which does not apply DIY principle. also, if we want to change these variables, we have to update those in every location.

###### 3- Give a DRY code example by modify your code example of (1)!

```
class Exercise
{
    private static string job = Constants.job;
    private static string format = Constants.StandardFormat;
 
    static void Main(string[] args)
    {
        function1();
        function2();
        function3();
        Console.ReadLine();
    }
 
    private static void function1()
    {
        Console.WriteLine(format, "Maria", "my sister", job, Berlin);
    }
 
    private static void function2()
    {
        Console.WriteLine(format, "Alex", "my friend", job, Koln);
    }
 
    private static void function3()
    {
        Console.WriteLine(format, "Samir", "my cousin", job, Tehran);
    }
}
```
