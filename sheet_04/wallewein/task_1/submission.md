## Don't repeat yourself

### Example
```c
void parseXml(char* file)
{
  printf("%s [%s]: %s", "ParserImpl", "parseXml", "Opening xml file");
  ...
}

void parseCsv(char* file)
{
  printf("%s [%s]: %s", "ParserImpl", "parseCsv", "Opening csv file");
  ...
}
```

### Why this code does not apply DRY?
This code shows logging in a parser. As you can see for each log entry the main part of the passed parameter is copied, which is not applicable for the DRY idea.

### DRY code
```c
char* logTemplate = "%s [%s]: %s";
char* methodName = NULL;
char* namespaceName = "ParserImpl";

void log(char* message)
{
  printf(logTemplate, namespaceName, methodName, message);
}

void parseXml(char* file)
{
  methodName = "parseXml";
  log("Opening xml file");
  ...
}

void parseCsv(char* file)
{
  methodName = "parseCsv";
  log("Opening csv file");
  ...
}
```
