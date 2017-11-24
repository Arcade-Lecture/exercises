Creational Pattern- prototype:

	- new instances are based on a prototypical template
	- the template is copied and customized for the task it was created for
	- it is usefull if the processing of the templates is similar

Structural Pattern- adapter:

	- allows the interface of an existing class to be used as another interface
	- often usded to make existing classing work with others without modifying their source code
	- example is an Adapter that converts the interface of an Document Object Model of an XML document into a tree structure that can be displayed

Behavioral pattern- stategy:

	- enables selecting an algorithm at runime
	- defines a family of alogrithms
	- makes the algorithms in a family interchangeable
	
Concurrency pattern-active object:

	- The goal is to introduce concurrency, by using asynchronous method invocation and a scheduler for handling requests.
	The pattern consists of six elements:[3]
	A proxy, which provides an interface towards clients with publicly accessible methods.
	An interface which defines the method request on an active object.
	A list of pending requests from clients.
	A scheduler, which decides which request to execute next.
	The implementation of the active object method.
	A callback or variable for the client to receive the result.

diverse pattern-null object:

	A null object is an object with no referenced value or with defined neutral "null" behavior.
	The null object pattern describes how to use these objects and their behavior.
	The advantage of this approach over a working default implementation is that a Null Object is very predictable and has no side effects: it does nothing.
	For example, a function may retrieve a list of files in a folder and perform some action on each. 
	In the case of an empty folder, one response may be to throw an exception or return a null reference rather than a list.
	Thus, the code which expects a list must verify that it in fact has one before continuing, which can complicate the design.
	By returning a null object (i.e. an empty list) instead, there is no need to verify that the return value is in fact a list.